#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_genfromtxt(benchmark::State &state) {
    for (auto _ : state)
        genfromtxt("./datasets/boston/boston.csv", ',');
}
BENCHMARK(BM_genfromtxt);

BENCHMARK_MAIN();