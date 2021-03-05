#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_log(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        matrix.log(sliced_mat);
}
BENCHMARK(BM_log);

BENCHMARK_MAIN();
