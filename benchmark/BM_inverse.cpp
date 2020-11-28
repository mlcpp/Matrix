#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_inverse(benchmark::State &state) {
    Matrix mat = read_csv("./datasets/boston/boston.csv");
    Matrix sq_mat = mat.slice(1, 4, 0, 3);
    sq_mat.to_double();
    for (auto _ : state)
        matrix.inverse(sq_mat);
}
BENCHMARK(BM_inverse);

BENCHMARK_MAIN();