#include "gtest/gtest.h"
#include <Matrix.hpp>
#include <cmath>

namespace {

class MatrixLogicalOpTest : public ::testing::Test {
  protected:
    Matrix<int> mat;

    MatrixLogicalOpTest() {
        mat = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    }
};

TEST_F(MatrixLogicalOpTest, EqualityOperation1) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    EXPECT_TRUE(mat == test_with);
}

TEST_F(MatrixLogicalOpTest, EqualityOperation2) {
    Matrix<int> test_with;
    EXPECT_FALSE(mat == test_with);
}

TEST_F(MatrixLogicalOpTest, EqualityOperation3) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    test_with = test_with.slice(0, 1, 0, test_with.col_length());
    EXPECT_FALSE(mat == test_with);
}

TEST_F(MatrixLogicalOpTest, NotEqualOperation1) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    EXPECT_FALSE(mat != test_with);
}

TEST_F(MatrixLogicalOpTest, NotEqualOperation2) {
    Matrix<int> test_with;
    EXPECT_TRUE(mat != test_with);
}

TEST_F(MatrixLogicalOpTest, NotEqualOperation3) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    test_with = test_with.slice(0, 1, 0, test_with.col_length());
    EXPECT_TRUE(mat != test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanOperation1) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    EXPECT_FALSE(mat < test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanOperation2) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    test_with = test_with.slice(0, 1, 0, test_with.col_length());
    EXPECT_FALSE(mat < test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanOperation3) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    test_with = test_with.slice(0, 1, 0, test_with.col_length());
    test_with(0, 0) = 5;
    EXPECT_TRUE(mat < test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanOperation4) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    test_with(0, 0) = 5;
    EXPECT_TRUE(mat < test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanOperation5) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<int> mat2 = mat;
    test_with(0, 1) = 5;
    mat2(1, 2) = 100;
    EXPECT_TRUE(mat2 < test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanOperation6) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<int> mat2 = mat;
    mat2(1, 2) = 100;
    EXPECT_FALSE(mat2 < test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanOperation7) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<int> mat2 = mat;
    test_with(0, 1) = 5;
    mat2(0, 0) = 4;
    EXPECT_FALSE(mat2 < test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanEqualOperation1) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    EXPECT_TRUE(mat <= test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanEqualOperation2) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    test_with = test_with.slice(0, 1, 0, test_with.col_length());
    EXPECT_FALSE(mat <= test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanEqualOperation3) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    test_with = test_with.slice(0, 1, 0, test_with.col_length());
    test_with(0, 0) = 5;
    EXPECT_TRUE(mat <= test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanEqualOperation4) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    test_with(0, 0) = 5;
    EXPECT_TRUE(mat <= test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanEqualOperation5) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<int> mat2 = mat;
    test_with(0, 1) = 5;
    mat2(1, 2) = 100;
    EXPECT_TRUE(mat2 <= test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanEqualOperation6) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<int> mat2 = mat;
    mat2(1, 2) = 100;
    EXPECT_FALSE(mat2 <= test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanEqualOperation7) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<int> mat2 = mat;
    test_with(0, 1) = 5;
    mat2(0, 0) = 4;
    EXPECT_FALSE(mat2 <= test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanEqualOperation8) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<int> mat2 = mat;
    test_with(0, 1) = 5;
    mat2(0, 1) = 5;
    EXPECT_TRUE(mat2 <= test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanOperation1) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    EXPECT_FALSE(mat > test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanOperation2) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    test_with = test_with.slice(0, 1, 0, test_with.col_length());
    EXPECT_TRUE(mat > test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanOperation3) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    test_with = test_with.slice(0, 1, 0, test_with.col_length());
    test_with(0, 0) = 5;
    EXPECT_FALSE(mat > test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanOperation4) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    test_with(0, 0) = 5;
    EXPECT_FALSE(mat > test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanOperation5) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<int> mat2 = mat;
    test_with(0, 1) = 5;
    mat2(1, 2) = 100;
    EXPECT_FALSE(mat2 > test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanOperation6) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<int> mat2 = mat;
    mat2(1, 2) = 100;
    EXPECT_TRUE(mat2 > test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanOperation7) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<int> mat2 = mat;
    test_with(0, 1) = 5;
    mat2(0, 0) = 4;
    EXPECT_TRUE(mat2 > test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanEqualOperation1) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    EXPECT_TRUE(mat >= test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanEqualOperation2) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    test_with = test_with.slice(0, 1, 0, test_with.col_length());
    EXPECT_TRUE(mat >= test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanEqualOperation3) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    test_with = test_with.slice(0, 1, 0, test_with.col_length());
    test_with(0, 0) = 5;
    EXPECT_FALSE(mat >= test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanEqualOperation4) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    test_with(0, 0) = 5;
    EXPECT_FALSE(mat >= test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanEqualOperation5) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<int> mat2 = mat;
    test_with(0, 1) = 5;
    mat2(1, 2) = 100;
    EXPECT_FALSE(mat2 >= test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanEqualOperation6) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<int> mat2 = mat;
    mat2(1, 2) = 100;
    EXPECT_TRUE(mat2 >= test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanEqualOperation7) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<int> mat2 = mat;
    test_with(0, 1) = 5;
    mat2(0, 0) = 4;
    EXPECT_TRUE(mat2 >= test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanEqualOperation8) {
    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<int> mat2 = mat;
    test_with(0, 1) = 5;
    mat2(0, 1) = 5;
    EXPECT_TRUE(mat2 >= test_with);
}

} // namespace