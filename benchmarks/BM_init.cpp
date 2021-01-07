#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_init_double(benchmark::State &state) {
    double val_d = 6.786;
    for (auto _ : state)
        matrix.init(val_d);
}
BENCHMARK(BM_init_double);

static void BM_init_string(benchmark::State &state) {
    std::string val_s = "10";
    for (auto _ : state)
        matrix.init(val_s);
}
BENCHMARK(BM_init_string);

static void BM_init_1Ddouble(benchmark::State &state) {
    std::vector<double> row_d(4, 6.786);
    for (auto _ : state)
        matrix.init(row_d);
}
BENCHMARK(BM_init_1Ddouble);

static void BM_init_1Dstring(benchmark::State &state) {
    std::vector<std::string> row_s(3, "10");
    for (auto _ : state)
        matrix.init(row_s);
}
BENCHMARK(BM_init_1Dstring);

static void BM_init_2Ddouble(benchmark::State &state) {
    std::vector<double> row_d(4, 6.786);
    std::vector<std::vector<double>> vec_d(6, row_d);
    for (auto _ : state)
        matrix.init(vec_d);
}
BENCHMARK(BM_init_2Ddouble);

static void BM_init_2Dstring(benchmark::State &state) {
    std::vector<std::string> row_s(3, "10");
    std::vector<std::vector<std::string>> vec_s(5, row_s);
    for (auto _ : state)
        matrix.init(vec_s);
}
BENCHMARK(BM_init_2Dstring);

BENCHMARK_MAIN();