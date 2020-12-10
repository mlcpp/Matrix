#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_determinant(benchmark::State &state) {
    Matrix mat = matrix.genfromtxt("./datasets/boston/boston.csv",',');
    Matrix sq_mat = mat.slice(1, 4, 0, 3);
    sq_mat.to_double();
    for (auto _ : state)
        matrix.determinant(sq_mat, sq_mat.col_length());
}
BENCHMARK(BM_determinant);

BENCHMARK_MAIN();
