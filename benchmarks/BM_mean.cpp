#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_mean_row(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, 6, 2, 5);

    for (auto _ : state)
        matrix.mean(sliced_mat, "row");
}
BENCHMARK(BM_mean_row);

static void BM_mean_column(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        matrix.mean(sliced_mat, "column");
}
BENCHMARK(BM_mean_column);

BENCHMARK_MAIN();
