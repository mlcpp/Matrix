#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_argmax_row(benchmark::State &state) {
    Matrix mat = genfromtxt("./datasets/boston/boston.csv", ',');
    Matrix sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());
    sliced_mat.to_double();
    for (auto _ : state)
        matrix.argmax(sliced_mat, "row");
}
BENCHMARK(BM_argmax_row);

static void BM_argmax_column(benchmark::State &state) {
    Matrix mat = genfromtxt("./datasets/boston/boston.csv", ',');
    Matrix sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());
    sliced_mat.to_double();
    for (auto _ : state)
        matrix.argmax(sliced_mat, "column");
}
BENCHMARK(BM_argmax_column);

BENCHMARK_MAIN();