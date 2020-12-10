#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_T(benchmark::State &state) {
    Matrix mat = genfromtxt("./datasets/boston/boston.csv",',');
    for (auto _ : state)
        mat.T();
}
BENCHMARK(BM_T);

BENCHMARK_MAIN();
