#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_unary_minus(benchmark::State &state) {
    Matrix mat = genfromtxt("./datasets/boston/boston.csv",',');
    Matrix sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());
    sliced_mat.to_double();
    for (auto _ : state)
        -sliced_mat;
}
BENCHMARK(BM_unary_minus);

BENCHMARK_MAIN();
