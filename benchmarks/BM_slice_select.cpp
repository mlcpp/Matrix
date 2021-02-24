#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_slice_select(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> X = mat.slice(1, 5, 0, 2);
    Matrix<double> Y = mat.slice(1, 5, 2, 3);

    for (auto _ : state)
        matrix.slice_select(X, Y, 7.07, 0);
}
BENCHMARK(BM_slice_select);

BENCHMARK_MAIN();
