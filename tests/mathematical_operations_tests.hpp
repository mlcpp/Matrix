#include "gtest/gtest.h"
#include <Matrix.hpp>
#include <cmath>

namespace {

class MatrixMathOpTest : public ::testing::Test {
  protected:
    Matrix<double> mat;

    MatrixMathOpTest() {
        mat = matrix.genfromtxt<double>("./tests/datasets/test_dataset0.csv", ',');
    }
};

TEST_F(MatrixMathOpTest, SquareRoot) {
    Matrix<double> sqrt_mat = matrix.sqrt(mat);

    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(sqrt(3 * i + j + 1));
        vec.push_back(v);
        v.clear();
    }
    Matrix<double> test_with = matrix.init(vec);

    EXPECT_EQ(sqrt_mat, test_with);
}

TEST_F(MatrixMathOpTest, PowerMatrixMatrix) {
    Matrix<double> mat_pow = matrix.power(mat, mat);

    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(std::pow(3 * i + j + 1, 3 * i + j + 1));
        vec.push_back(v);
        v.clear();
    }
    Matrix<double> test_with = matrix.init(vec);

    EXPECT_EQ(mat_pow, test_with);
}

TEST_F(MatrixMathOpTest, PowerMatrixScalar) {
    Matrix<double> mat_pow = matrix.power(mat, 2);

    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(std::pow(3 * i + j + 1, 2));
        vec.push_back(v);
        v.clear();
    }
    Matrix<double> test_with = matrix.init(vec);

    EXPECT_EQ(mat_pow, test_with);
}

TEST_F(MatrixMathOpTest, Exponent) {
    Matrix<double> mat_exp = matrix.exp(mat);

    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(std::exp(3 * i + j + 1));
        vec.push_back(v);
        v.clear();
    }
    Matrix<double> test_with = matrix.init(vec);

    EXPECT_EQ(mat_exp, test_with);
}

TEST_F(MatrixMathOpTest, Logarithm) {
    Matrix<double> mat_log = matrix.log(mat);

    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(std::log(3 * i + j + 1));
        vec.push_back(v);
        v.clear();
    }
    Matrix<double> test_with = matrix.init(vec);

    EXPECT_EQ(mat_log, test_with);
}

TEST_F(MatrixMathOpTest, AbsoluteValue) {
    Matrix<double> temp = -mat;
    Matrix<double> mat_abs = matrix.abs(temp);

    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(3 * i + j + 1);
        vec.push_back(v);
        v.clear();
    }
    Matrix<double> test_with = matrix.init(vec);

    EXPECT_EQ(mat_abs, test_with);
}

} // namespace