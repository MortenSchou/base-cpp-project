#include <benchmark/benchmark.h>

static void BM_StringCreation(benchmark::State& state) {
    for (auto _ : state) {
        std::string empty_string;
        benchmark::DoNotOptimize(empty_string);
        benchmark::ClobberMemory();
    }
}
// Register the function as a benchmark
BENCHMARK(BM_StringCreation);

// Define another benchmark
static void BM_StringCopy(benchmark::State& state) {
    std::string x = "hello";
    for (auto _ : state) {
        std::string copy(x);
        benchmark::DoNotOptimize(copy);
        benchmark::ClobberMemory();
    }
}
BENCHMARK(BM_StringCopy);


static void BM_DenseRange(benchmark::State& state) {
    for(auto _ : state) {
        std::vector<int64_t> v(state.range(0), state.range(0));
        auto data = v.data();
        benchmark::DoNotOptimize(data);
        benchmark::ClobberMemory();
    }
}
BENCHMARK(BM_DenseRange)->DenseRange(0, 1024, 128);
