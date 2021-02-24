#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_reciprocal(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        matrix.reciprocal(sliced_mat);
}
BENCHMARK(BM_reciprocal);

BENCHMARK_MAIN();
