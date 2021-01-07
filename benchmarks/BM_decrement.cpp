#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_pre_decrement(benchmark::State &state) {
    Matrix mat = matrix.genfromtxt("./datasets/boston/boston.csv", ',');
    Matrix sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());
    sliced_mat.to_double();
    for (auto _ : state)
        --sliced_mat;
}
BENCHMARK(BM_pre_decrement);

static void BM_post_decrement(benchmark::State &state) {
    Matrix mat = matrix.genfromtxt("./datasets/boston/boston.csv", ',');
    Matrix sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());
    sliced_mat.to_double();
    for (auto _ : state)
        sliced_mat--;
}
BENCHMARK(BM_post_decrement);

BENCHMARK_MAIN();
