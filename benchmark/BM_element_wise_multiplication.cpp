#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_element_wise_multiplication_mat_mat(benchmark::State &state) {
    Matrix mat1 = genfromtxt("./datasets/boston/boston.csv", ',');
    Matrix mat2 = genfromtxt("./datasets/boston/boston.csv", ',');
    Matrix sliced_mat1 = mat1.slice(1, mat1.row_length(), 0, mat1.col_length());
    Matrix sliced_mat2 = mat2.slice(1, mat2.row_length(), 0, mat2.col_length());
    sliced_mat1.to_double();
    sliced_mat2.to_double();
    for (auto _ : state)
        sliced_mat1 *sliced_mat2;
}
BENCHMARK(BM_element_wise_multiplication_mat_mat);

static void BM_element_wise_multiplication_mat_sca(benchmark::State &state) {
    Matrix mat = genfromtxt("./datasets/boston/boston.csv", ',');
    Matrix sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());
    sliced_mat.to_double();
    for (auto _ : state)
        sliced_mat * 2;
}
BENCHMARK(BM_element_wise_multiplication_mat_sca);

static void BM_element_wise_multiplication_mat_vec(benchmark::State &state) {
    Matrix mat = genfromtxt("./datasets/boston/boston.csv", ',');
    Matrix sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());
    sliced_mat.to_double();
    for (auto _ : state)
        sliced_mat *sliced_mat.slice(1, 2, 0, sliced_mat.col_length());
}
BENCHMARK(BM_element_wise_multiplication_mat_vec);

BENCHMARK_MAIN();