#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_zeros(benchmark::State &state) {
    for (auto _ : state)
        matrix.zeros<int>(3, 4);
}
BENCHMARK(BM_zeros);

BENCHMARK_MAIN();