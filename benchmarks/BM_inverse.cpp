#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_inverse(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sq_mat = mat.slice(1, 4, 0, 3);

    for (auto _ : state)
        matrix.inverse(sq_mat);
}
BENCHMARK(BM_inverse);

BENCHMARK_MAIN();
