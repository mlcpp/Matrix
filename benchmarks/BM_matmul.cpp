#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_matmul(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> mat1 = mat.slice(1, 5, 0, 2);
    Matrix<double> mat2 = mat.slice(7, 9, 0, 3);

    for (auto _ : state)
        matrix.matmul(mat1, mat2);
}
BENCHMARK(BM_matmul);

BENCHMARK_MAIN();
