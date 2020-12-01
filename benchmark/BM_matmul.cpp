#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_matmul(benchmark::State &state) {
    Matrix mat = genfromtxt("./datasets/boston/boston.csv", ',');
    Matrix mat1 = mat.slice(1, 5, 0, 2);
    Matrix mat2 = mat.slice(7, 9, 0, 3);
    mat1.to_double();
    mat2.to_double();
    for (auto _ : state)
        matrix.matmul(mat1, mat2);
}
BENCHMARK(BM_matmul);

BENCHMARK_MAIN();