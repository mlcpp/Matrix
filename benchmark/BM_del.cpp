#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_del_row(benchmark::State &state) {
    Matrix mat = genfromtxt("./datasets/boston/boston.csv", ',');
    for (auto _ : state)
        matrix.del(mat, 2, "row");
}
BENCHMARK(BM_del_row);

static void BM_del_column(benchmark::State &state) {
    Matrix mat = genfromtxt("./datasets/boston/boston.csv", ',');
    for (auto _ : state)
        matrix.del(mat, 2, "row");
}
BENCHMARK(BM_del_column);

BENCHMARK_MAIN();