#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_sum_row(benchmark::State &state) {
    Matrix mat = matrix.genfromtxt("./datasets/boston/boston.csv",',');
    Matrix sliced_mat = mat.slice(1, 6, 2, 5);
    sliced_mat.to_double();
    for (auto _ : state)
        matrix.sum(sliced_mat, "row");
}
BENCHMARK(BM_sum_row);

static void BM_sum_column(benchmark::State &state) {
    Matrix mat = matrix.genfromtxt("./datasets/boston/boston.csv",',');
    Matrix sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());
    sliced_mat.to_double();
    for (auto _ : state)
        matrix.sum(sliced_mat, "column");
}
BENCHMARK(BM_sum_column);

BENCHMARK_MAIN();
