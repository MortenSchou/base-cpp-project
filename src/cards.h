#include <random>
#include <ranges>
#include <concepts>

#include "absl_hash.h"
#include <coro/coro.hpp>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

struct card_t {
    enum class suit_t: uint8_t {NONE, DIAMONDS, CLUBS, HEARTS, SPADES};
    static constexpr suit_t suits[] = {suit_t::DIAMONDS, suit_t::CLUBS, suit_t::HEARTS, suit_t::SPADES};
    bool is_joker = false;
    suit_t suit = suit_t::NONE;
    uint8_t value = 0;

    auto operator<=>(const card_t& other) const = default;

    template<typename H>
    friend H AbslHashValue(H h, const card_t& card) {
        return H::combine(std::move(h), card.value, card.suit, card.is_joker);
    }
};
void to_json(json& j, const card_t& c) {
    if (c.is_joker) j = "joker";
    else j = json{{"suit", c.suit}, {"value", c.value}};
}
void from_json(const json& j, card_t& c) {
    if (j == "joker") {
        c.is_joker = true;
    } else {
        j.at("suit").get_to(c.suit);
        j.at("value").get_to(c.value);
    }
}

using card_set_t = std::unordered_set<card_t, absl::Hash<card_t>>;
template<typename Value> using card_map_t = std::unordered_map<card_t, Value, absl::Hash<card_t>>;

coro::generator<card_t> deck(size_t jokers = 0) {
    for (auto suit : card_t::suits) {
        for (uint8_t value = 0; value <= 13; ++value) {
            co_yield card_t{.suit=suit, .value=value};
        }
    }
    for (size_t i = 0; i < jokers; ++i) {
        co_yield card_t{.is_joker=true};
    }
    co_return;
}
