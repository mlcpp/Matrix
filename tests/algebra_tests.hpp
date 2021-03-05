#include "gtest/gtest.h"
#include <Matrix.hpp>
#include <cmath>

namespace {

template <typename T>
::testing::AssertionResult CheckNear(Matrix<T> mat1, Matrix<T> mat2, double delta) {
    if ((mat1.row_length() != mat2.row_length()) || (mat1.col_length() != mat2.col_length()))
        return ::testing::AssertionFailure() << "Row/Column length of Matrix objects do not match.";

    for (int i = 0; i < mat1.row_length(); i++) {
        for (int j = 0; j < mat1.col_length(); j++) {
            if (std::abs(mat1(i, j) - mat2(i, j)) > delta)
                return ::testing::AssertionFailure()
                       << "Matrix objects differ by more than " << delta;
        }
    }

    return ::testing::AssertionSuccess();
}

class MatrixAlgebraTest : public ::testing::Test {
  protected:
    Matrix<double> mat;

    MatrixAlgebraTest() {
        mat = matrix.genfromtxt<double>("./tests/datasets/test_dataset0.csv", ',');
    }
};

TEST_F(MatrixAlgebraTest, Transpose) {
    Matrix<double> transpose = mat.transpose();

    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++)
            v.push_back(3 * j + i + 1);
        vec.push_back(v);
        v.clear();
    }
    Matrix<double> test_with = matrix.init(vec);

    EXPECT_EQ(transpose, test_with);
}

TEST_F(MatrixAlgebraTest, MatrixMultiplication) {
    Matrix<double> mat_mul = matrix.matmul(mat, mat.transpose());

    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    v.push_back(14);
    v.push_back(32);
    vec.push_back(v);
    v.clear();
    v.push_back(32);
    v.push_back(77);
    vec.push_back(v);
    Matrix<double> test_with = matrix.init(vec);

    EXPECT_EQ(mat_mul, test_with);
}

TEST_F(MatrixAlgebraTest, Determinant) {
    Matrix<double> sq_mat = mat.slice(0, mat.row_length(), 0, 2);
    double det = matrix.determinant(sq_mat, sq_mat.col_length());
    EXPECT_EQ(det, -3);
}

TEST_F(MatrixAlgebraTest, Inverse) {
    Matrix<double> sq_mat = mat.slice(0, mat.row_length(), 0, 2);
    Matrix<double> inv = matrix.inverse(sq_mat);

    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    v.push_back(-1.666667);
    v.push_back(0.666667);
    vec.push_back(v);
    v.clear();
    v.push_back(1.333333);
    v.push_back(-0.333333);
    vec.push_back(v);
    Matrix<double> test_with = matrix.init(vec);

    EXPECT_TRUE(CheckNear(inv, test_with, 0.00001));
}

} // namespace