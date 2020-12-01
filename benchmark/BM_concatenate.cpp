#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_concatenate_row(benchmark::State &state) {
    Matrix mat = read_csv("./datasets/boston/boston.csv");
    Matrix matr1_5 = mat.slice(1, 5, 0, mat.col_length());
    Matrix matr7_9 = mat.slice(7, 9, 0, mat.col_length());
    for (auto _ : state)
        matrix.concatenate(matr1_5, matr7_9, "row");
}
BENCHMARK(BM_concatenate_row);

static void BM_concatenate_column(benchmark::State &state) {
    Matrix mat = read_csv("./datasets/boston/boston.csv");
    Matrix matc0_3 = mat.slice(1, 10, 0, 3);
    Matrix matc5_9 = mat.slice(1, 10, 5, 9);
    for (auto _ : state)
        matrix.concatenate(matc0_3, matc5_9, "column");
}
BENCHMARK(BM_concatenate_column);

BENCHMARK_MAIN();