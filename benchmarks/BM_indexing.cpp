#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_index_assign(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        sliced_mat(1, 2) = 5;
}
BENCHMARK(BM_index_assign);

static void BM_index_get(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        sliced_mat(1, 2);
}
BENCHMARK(BM_index_get);

BENCHMARK_MAIN();
