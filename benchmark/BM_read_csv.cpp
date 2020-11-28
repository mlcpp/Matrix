#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_read_csv(benchmark::State &state) {
    for (auto _ : state)
        read_csv("./datasets/boston/boston.csv");
}
BENCHMARK(BM_read_csv);

BENCHMARK_MAIN();