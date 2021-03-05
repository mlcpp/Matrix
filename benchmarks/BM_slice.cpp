#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_slice(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    for (auto _ : state)
        mat.slice(1, mat.row_length(), 0, mat.col_length());
}
BENCHMARK(BM_slice);

BENCHMARK_MAIN();
