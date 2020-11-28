#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_eye(benchmark::State &state) {
    for (auto _ : state)
        matrix.eye(4);
}
BENCHMARK(BM_eye);

BENCHMARK_MAIN();