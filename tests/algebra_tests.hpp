#include "gtest/gtest.h"
#include <Matrix.hpp>
#include <cmath>

namespace {

class MatrixAlgebraTest : public ::testing::Test {
  protected:
    Matrix mat;

    MatrixAlgebraTest() {
        mat = matrix.genfromtxt("test_dataset.csv", ',');
        mat.to_double();
    }
};

TEST_F(MatrixAlgebraTest, Transpose) {
    Matrix transpose = mat.T();
    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++)
            v.push_back(3 * j + i + 1);
        vec.push_back(v);
        v.clear();
    }
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(transpose, test_with);
}

TEST_F(MatrixAlgebraTest, MatrixMultiplication) {
    Matrix mat_mul = matrix.matmul(mat, mat.T());
    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    v.push_back(14);
    v.push_back(32);
    vec.push_back(v);
    v.clear();
    v.push_back(32);
    v.push_back(77);
    vec.push_back(v);
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(mat_mul, test_with);
}

TEST_F(MatrixAlgebraTest, Determinant) {
    Matrix sq_mat = mat.slice(0, mat.row_length(), 0, 2);
    double det = matrix.determinant(sq_mat, sq_mat.col_length());
    EXPECT_EQ(det, -3);
}

TEST_F(MatrixAlgebraTest, Inverse) {
    Matrix sq_mat = mat.slice(0, mat.row_length(), 0, 2);
    Matrix inv = matrix.inverse(sq_mat);
    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    v.push_back(-1.666667);
    v.push_back(0.666667);
    vec.push_back(v);
    v.clear();
    v.push_back(1.333333);
    v.push_back(-0.333333);
    vec.push_back(v);
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(inv, test_with);
}

} // namespace