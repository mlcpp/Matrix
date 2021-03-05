#include <Matrix.hpp>
#include <benchmark/benchmark.h>

static void BM_abs(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());
    sliced_mat = -sliced_mat;

    for (auto _ : state)
        matrix.abs(sliced_mat);
}
BENCHMARK(BM_abs);

static void BM_add_n_assign_mat_mat(benchmark::State &state) {
    Matrix<std::string> mat1 =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<std::string> mat2 =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat1 = mat1.slice(1, mat1.row_length(), 0, mat1.col_length());
    Matrix<double> sliced_mat2 = mat2.slice(1, mat2.row_length(), 0, mat2.col_length());

    for (auto _ : state)
        sliced_mat1 += sliced_mat2;
}
BENCHMARK(BM_add_n_assign_mat_mat);

static void BM_add_n_assign_mat_sca(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        sliced_mat += 1;
}
BENCHMARK(BM_add_n_assign_mat_sca);

static void BM_add_n_assign_mat_vec(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        sliced_mat += sliced_mat.slice(1, 2, 0, sliced_mat.col_length());
}
BENCHMARK(BM_add_n_assign_mat_vec);

static void BM_addition_mat_mat(benchmark::State &state) {
    Matrix<std::string> mat1 =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<std::string> mat2 =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat1 = mat1.slice(1, mat1.row_length(), 0, mat1.col_length());
    Matrix<double> sliced_mat2 = mat2.slice(1, mat2.row_length(), 0, mat2.col_length());

    for (auto _ : state)
        sliced_mat1 + sliced_mat2;
}
BENCHMARK(BM_addition_mat_mat);

static void BM_addition_mat_sca(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        sliced_mat + 1;
}
BENCHMARK(BM_addition_mat_sca);

static void BM_addition_mat_vec(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        sliced_mat + sliced_mat.slice(1, 2, 0, sliced_mat.col_length());
}
BENCHMARK(BM_addition_mat_vec);

static void BM_argmax_row(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        matrix.argmax(sliced_mat, "row");
}
BENCHMARK(BM_argmax_row);

static void BM_argmax_column(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        matrix.argmax(sliced_mat, "column");
}
BENCHMARK(BM_argmax_column);

static void BM_argmin_row(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        matrix.argmin(sliced_mat, "row");
}
BENCHMARK(BM_argmin_row);

static void BM_argmin_column(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        matrix.argmin(sliced_mat, "column");
}
BENCHMARK(BM_argmin_column);

static void BM_concatenate_row(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<std::string> matr1_5 = mat.slice(1, 5, 0, mat.col_length());
    Matrix<std::string> matr7_9 = mat.slice(7, 9, 0, mat.col_length());

    for (auto _ : state)
        matrix.concatenate(matr1_5, matr7_9, "row");
}
BENCHMARK(BM_concatenate_row);

static void BM_concatenate_column(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<std::string> matc0_3 = mat.slice(1, 10, 0, 3);
    Matrix<std::string> matc5_9 = mat.slice(1, 10, 5, 9);

    for (auto _ : state)
        matrix.concatenate(matc0_3, matc5_9, "column");
}
BENCHMARK(BM_concatenate_column);

static void BM_pre_decrement(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        --sliced_mat;
}
BENCHMARK(BM_pre_decrement);

static void BM_post_decrement(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        sliced_mat--;
}
BENCHMARK(BM_post_decrement);

static void BM_delete_row(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');

    for (auto _ : state)
        matrix.delete_(mat, 2, "row");
}
BENCHMARK(BM_delete_row);

static void BM_delete_column(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');

    for (auto _ : state)
        matrix.delete_(mat, 1, "column");
}
BENCHMARK(BM_delete_column);

static void BM_determinant(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sq_mat = mat.slice(1, 4, 0, 3);

    for (auto _ : state)
        matrix.determinant(sq_mat, sq_mat.col_length());
}
BENCHMARK(BM_determinant);

static void BM_element_wise_mult_n_assign_mat_mat(benchmark::State &state) {
    Matrix<std::string> mat1 =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<std::string> mat2 =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat1 = mat1.slice(1, mat1.row_length(), 0, mat1.col_length());
    Matrix<double> sliced_mat2 = mat2.slice(1, mat2.row_length(), 0, mat2.col_length());

    for (auto _ : state)
        sliced_mat1 *= sliced_mat2;
}
BENCHMARK(BM_element_wise_mult_n_assign_mat_mat);

static void BM_element_wise_mult_n_assign_mat_sca(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        sliced_mat *= 2;
}
BENCHMARK(BM_element_wise_mult_n_assign_mat_sca);

static void BM_element_wise_mult_n_assign_mat_vec(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        sliced_mat *= sliced_mat.slice(1, 2, 0, sliced_mat.col_length());
}
BENCHMARK(BM_element_wise_mult_n_assign_mat_vec);

static void BM_element_wise_multiplication_mat_mat(benchmark::State &state) {
    Matrix<std::string> mat1 =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<std::string> mat2 =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat1 = mat1.slice(1, mat1.row_length(), 0, mat1.col_length());
    Matrix<double> sliced_mat2 = mat2.slice(1, mat2.row_length(), 0, mat2.col_length());

    for (auto _ : state)
        sliced_mat1 *sliced_mat2;
}
BENCHMARK(BM_element_wise_multiplication_mat_mat);

static void BM_element_wise_multiplication_mat_sca(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        sliced_mat * 2;
}
BENCHMARK(BM_element_wise_multiplication_mat_sca);

static void BM_element_wise_multiplication_mat_vec(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        sliced_mat *sliced_mat.slice(1, 2, 0, sliced_mat.col_length());
}
BENCHMARK(BM_element_wise_multiplication_mat_vec);

static void BM_exp(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        matrix.exp(sliced_mat);
}
BENCHMARK(BM_exp);

static void BM_eye(benchmark::State &state) {
    for (auto _ : state)
        matrix.eye<int>(4);
}
BENCHMARK(BM_eye);

static void BM_genfromtxt(benchmark::State &state) {
    for (auto _ : state)
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
}
BENCHMARK(BM_genfromtxt);

static void BM_get(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        sliced_mat.get();
}
BENCHMARK(BM_get);

static void BM_get_row(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        sliced_mat.get_row(2);
}
BENCHMARK(BM_get_row);

static void BM_get_col(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        sliced_mat.get_col(3);
}
BENCHMARK(BM_get_col);

static void BM_pre_increment(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        ++sliced_mat;
}
BENCHMARK(BM_pre_increment);

static void BM_post_increment(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        sliced_mat++;
}
BENCHMARK(BM_post_increment);

static void BM_index_assign(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        sliced_mat(1, 2) = 5;
}
BENCHMARK(BM_index_assign);

static void BM_index_get(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        sliced_mat(1, 2);
}
BENCHMARK(BM_index_get);

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

static void BM_inverse(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sq_mat = mat.slice(1, 4, 0, 3);

    for (auto _ : state)
        matrix.inverse(sq_mat);
}
BENCHMARK(BM_inverse);

static void BM_log(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        matrix.log(sliced_mat);
}
BENCHMARK(BM_log);

static void BM_matmul(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> mat1 = mat.slice(1, 5, 0, 2);
    Matrix<double> mat2 = mat.slice(7, 9, 0, 3);

    for (auto _ : state)
        matrix.matmul(mat1, mat2);
}
BENCHMARK(BM_matmul);

static void BM_max_row(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        matrix.max(sliced_mat, "row");
}
BENCHMARK(BM_max_row);

static void BM_max_column(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        matrix.max(sliced_mat, "column");
}
BENCHMARK(BM_max_column);

static void BM_mean_row(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, 6, 2, 5);

    for (auto _ : state)
        matrix.mean(sliced_mat, "row");
}
BENCHMARK(BM_mean_row);

static void BM_mean_column(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        matrix.mean(sliced_mat, "column");
}
BENCHMARK(BM_mean_column);

static void BM_min_row(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        matrix.min(sliced_mat, "row");
}
BENCHMARK(BM_min_row);

static void BM_min_column(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        matrix.min(sliced_mat, "column");
}
BENCHMARK(BM_min_column);

static void BM_ones(benchmark::State &state) {
    for (auto _ : state)
        matrix.ones<int>(3, 4);
}
BENCHMARK(BM_ones);

static void BM_power_mat_mat(benchmark::State &state) {
    Matrix<std::string> mat1 =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<std::string> mat2 =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat1 = mat1.slice(1, mat1.row_length(), 0, mat1.col_length());
    Matrix<double> sliced_mat2 = mat2.slice(1, mat2.row_length(), 0, mat2.col_length());

    for (auto _ : state)
        matrix.power(sliced_mat1, sliced_mat2);
}
BENCHMARK(BM_power_mat_mat);

static void BM_power_mat_sca(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        matrix.power(sliced_mat, 2);
}
BENCHMARK(BM_power_mat_sca);

static void BM_reciprocal(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        matrix.reciprocal(sliced_mat);
}
BENCHMARK(BM_reciprocal);

static void BM_slice_select(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> X = mat.slice(1, 5, 0, 2);
    Matrix<double> Y = mat.slice(1, 5, 2, 3);

    for (auto _ : state)
        matrix.slice_select(X, Y, 7.07, 0);
}
BENCHMARK(BM_slice_select);

static void BM_slice(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    for (auto _ : state)
        mat.slice(1, mat.row_length(), 0, mat.col_length());
}
BENCHMARK(BM_slice);

static void BM_sqrt(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        matrix.sqrt(sliced_mat);
}
BENCHMARK(BM_sqrt);

static void BM_std_row(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, 6, 2, 5);

    for (auto _ : state)
        matrix.std(sliced_mat, "row");
}
BENCHMARK(BM_std_row);

static void BM_std_column(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        matrix.std(sliced_mat, "column");
}
BENCHMARK(BM_std_column);

static void BM_sum_row(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, 6, 2, 5);

    for (auto _ : state)
        matrix.sum(sliced_mat, "row");
}
BENCHMARK(BM_sum_row);

static void BM_sum_column(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        matrix.sum(sliced_mat, "column");
}
BENCHMARK(BM_sum_column);

static void BM_transpose(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');

    for (auto _ : state)
        mat.transpose();
}
BENCHMARK(BM_transpose);

static void BM_unary_minus(benchmark::State &state) {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./benchmarks/datasets/boston/boston.csv", ',');
    Matrix<double> sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());

    for (auto _ : state)
        -sliced_mat;
}
BENCHMARK(BM_unary_minus);

static void BM_zeros(benchmark::State &state) {
    for (auto _ : state)
        matrix.zeros<int>(3, 4);
}
BENCHMARK(BM_zeros);

BENCHMARK_MAIN();
