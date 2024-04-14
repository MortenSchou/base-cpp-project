#include "cards.h"

#include <future>
#include <queue>

#include <cxxopts.hpp>
#include <coro/coro.hpp>
#include <tao/pegtl.hpp>
#include <tao/pegtl/contrib/analyze.hpp>


namespace pegtl = tao::pegtl;
struct sign : pegtl::one< '+', '-' > {};
struct integer : pegtl::seq< pegtl::opt< sign >, pegtl::plus< pegtl::digit > > {};
using grammar = pegtl::must< integer, pegtl::eof >;


template <typename T> concept Arithmetic = std::is_arithmetic_v<T>;
template<Arithmetic T>
coro::generator<T> fibonacci(const T ceiling = std::numeric_limits<T>::max()) {
    T i = 0;
    T j = 1;
    while (j <= ceiling) {
        co_yield j;
        if (j > ceiling - i) co_return; // Avoid overflow
        T tmp = j;
        j += i;
        i = tmp;
    }
}

template<typename F>
auto parallel(F&& f, size_t count) {
    using R = decltype(f());
    coro::thread_pool tp{coro::thread_pool::options{.thread_count = std::thread::hardware_concurrency()}};
    auto task = [&tp,f=std::forward<F>(f)]() -> coro::task<R> {
        co_await tp.schedule(); // Schedule onto the thread pool.
        co_return f();          // Executed on the thread pool.
    };
    std::vector<coro::task<R>> tasks{};
    for (std::size_t i = 0; i < count; ++i) {
        tasks.emplace_back(task());
    }
    return coro::sync_wait(coro::when_all(std::move(tasks))) | std::ranges::views::transform([](const auto& result){ return result.return_value(); });
}


int main(int argc, char *argv[]) {
    cxxopts::Options options("MyProgram", "One line description of MyProgram");
    options.add_options()
        ("i,integer", "Int param", cxxopts::value<int>()->default_value("10"))
        ("f,file", "File name", cxxopts::value<std::string>())
        ("v,verbose", "Verbose output", cxxopts::value<bool>()->default_value("false"))
        ("h,help", "Print usage");
    auto result = options.parse(argc, argv);
    if (result.count("help")) {
        std::cout << options.help() << std::endl;
        exit(0);
    }
    std::string file;
    if (result.count("file"))
        file = result["file"].as<std::string>();

    int i = result["integer"].as<int>();
    for (auto fib : fibonacci<int>() | std::views::take(i)) {
        std::cout << fib << ", ";
    }
    std::cout << std::endl;

    card_map_t<size_t> card_counts;
    std::vector<card_t> cards;
    for (auto&& card : deck(3)) {
        card_counts[card]++;
        cards.emplace_back(card);
    }
    std::cout << card_counts.size() << " different cards" << std::endl;

    json(cards).get_to(cards);  // To JSON object and back.

    std::mt19937 gen{std::random_device{}()};
    std::ranges::shuffle(cards, gen);
    std::cout << json(cards).dump() << std::endl;
    std::ranges::sort(cards);
    std::cout << json(cards).dump() << std::endl;

    if(pegtl::analyze<grammar>() != 0) {
        std::cerr << "cycles without progress detected!\n";
        return 1;
    }

    return 0;
}
