#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_pre_decrement(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        --sliced_mat;
}
BENCHMARK(BM_pre_decrement);

static void BM_post_decrement(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        sliced_mat--;
}
BENCHMARK(BM_post_decrement);

BENCHMARK_MAIN();
