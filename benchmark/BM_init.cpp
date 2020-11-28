#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_init_double(benchmark::State &state) {
    std::vector<double> row_d(4, 6.786);
    std::vector<std::vector<double>> vec_d(6, row_d);
    for (auto _ : state)
        matrix.init(vec_d);
}
BENCHMARK(BM_init_double);

static void BM_init_string(benchmark::State &state) {
    std::vector<std::string> row_s(3, "10");
    std::vector<std::vector<std::string>> vec_s(5, row_s);
    for (auto _ : state)
        matrix.init(vec_s);
}
BENCHMARK(BM_init_string);

BENCHMARK_MAIN();