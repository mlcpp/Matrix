#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_transpose(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');

    for (auto _ : state)
        mat.transpose();
}
BENCHMARK(BM_transpose);

BENCHMARK_MAIN();
