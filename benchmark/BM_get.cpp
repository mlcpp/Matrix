#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_get(benchmark::State &state) {
    Matrix mat = genfromtxt("./datasets/boston/boston.csv", ',');
    Matrix sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());
    sliced_mat.to_double();
    for (auto _ : state)
        sliced_mat.get();
}
BENCHMARK(BM_get);

static void BM_get_row(benchmark::State &state) {
    Matrix mat = genfromtxt("./datasets/boston/boston.csv", ',');
    Matrix sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());
    sliced_mat.to_double();
    for (auto _ : state)
        sliced_mat.get_row(2);
}
BENCHMARK(BM_get_row);

static void BM_get_col(benchmark::State &state) {
    Matrix mat = genfromtxt("./datasets/boston/boston.csv", ',');
    Matrix sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());
    sliced_mat.to_double();
    for (auto _ : state)
        sliced_mat.get_col(3);
}
BENCHMARK(BM_get_col);

BENCHMARK_MAIN();