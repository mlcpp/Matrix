#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_argmin_row(benchmark::State &state) {
    Matrix mat = matrix.genfromtxt("./datasets/boston/boston.csv",',');
    Matrix sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());
    sliced_mat.to_double();
    for (auto _ : state)
        matrix.argmin(sliced_mat, "row");
}
BENCHMARK(BM_argmin_row);

static void BM_argmin_column(benchmark::State &state) {
    Matrix mat = matrix.genfromtxt("./datasets/boston/boston.csv",',');
    Matrix sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());
    sliced_mat.to_double();
    for (auto _ : state)
        matrix.argmin(sliced_mat, "column");
}
BENCHMARK(BM_argmin_column);

BENCHMARK_MAIN();
