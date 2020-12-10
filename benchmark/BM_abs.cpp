#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_abs(benchmark::State &state) {
    Matrix mat = genfromtxt("./datasets/boston/boston.csv",',');
    Matrix sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());
    sliced_mat.to_double();

    sliced_mat = -sliced_mat;
    for (auto _ : state)
        matrix.abs(sliced_mat);
}
BENCHMARK(BM_abs);

BENCHMARK_MAIN();
