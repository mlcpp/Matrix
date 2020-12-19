#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_log(benchmark::State &state) {
    Matrix mat = matrix.genfromtxt("./datasets/boston/boston.csv",',');
    Matrix sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());
    sliced_mat.to_double();
    for (auto _ : state)
        matrix.log(sliced_mat);
}
BENCHMARK(BM_log);

BENCHMARK_MAIN();
