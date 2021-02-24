#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_ones(benchmark::State &state) {
    for (auto _ : state)
        matrix.ones<int>(3, 4);
}
BENCHMARK(BM_ones);

BENCHMARK_MAIN();