#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_slice(benchmark::State &state) {
    Matrix mat = matrix.genfromtxt("./datasets/boston/boston.csv",',');
        mat.slice(1, mat.row_length(), 0, mat.col_length());
}
BENCHMARK(BM_slice);

BENCHMARK_MAIN();
