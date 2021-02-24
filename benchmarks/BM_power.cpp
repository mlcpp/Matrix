#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_power_mat_mat(benchmark::State &state) {
    Matrix<std::string> mat1 =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<std::string> mat2 =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat1 = mat1.slice(1, mat1.row_length(), 0, mat1.col_length());
    Matrix<double> sliced_mat2 = mat2.slice(1, mat2.row_length(), 0, mat2.col_length());

    for (auto _ : state)
        matrix.power(sliced_mat1, sliced_mat2);
}
BENCHMARK(BM_power_mat_mat);

static void BM_power_mat_sca(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        matrix.power(sliced_mat, 2);
}
BENCHMARK(BM_power_mat_sca);

BENCHMARK_MAIN();
