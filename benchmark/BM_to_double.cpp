#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_to_double(benchmark::State &state) {
    Matrix mat = genfromtxt("./datasets/boston/boston.csv", ',');
    Matrix sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());
    for (auto _ : state)
        sliced_mat.to_double();
}
BENCHMARK(BM_to_double);

BENCHMARK_MAIN();