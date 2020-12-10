#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_slice_select(benchmark::State &state) {
    Matrix mat = genfromtxt("./datasets/boston/boston.csv",',');
    Matrix X = mat.slice(1, 5, 0, 2);
    Matrix Y = mat.slice(1, 5, 2, 3);
    X.to_double();
    Y.to_double();
    for (auto _ : state)
        matrix.slice_select(X, Y, 7.07, 0);
}
BENCHMARK(BM_slice_select);

BENCHMARK_MAIN();
