#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_delete_row(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');

    for (auto _ : state)
        matrix.delete_(mat, 2, "row");
}
BENCHMARK(BM_delete_row);

static void BM_delete_column(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');

    for (auto _ : state)
        matrix.delete_(mat, 1, "column");
}
BENCHMARK(BM_delete_column);

BENCHMARK_MAIN();
