#include "gtest/gtest.h"
#include <Matrix.hpp>
#include <cmath>

namespace {

class MatrixLogicalOpTest : public ::testing::Test {
  protected:
    Matrix mat;

    MatrixLogicalOpTest() { mat = matrix.genfromtxt("test_dataset.csv", ','); }
};

TEST_F(MatrixLogicalOpTest, EqualityOperation1) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    EXPECT_TRUE(mat == test_with);
}

TEST_F(MatrixLogicalOpTest, EqualityOperation2) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    mat.to_double();
    test_with.to_double();
    EXPECT_TRUE(mat == test_with);
}

TEST_F(MatrixLogicalOpTest, EqualityOperation3) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    mat.to_double();
    EXPECT_TRUE(mat == test_with);
}

TEST_F(MatrixLogicalOpTest, EqualityOperation4) {
    Matrix test_with;
    EXPECT_FALSE(mat == test_with);
}

TEST_F(MatrixLogicalOpTest, EqualityOperation5) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with = test_with.slice(0, 1, 0, test_with.col_length());
    EXPECT_FALSE(mat == test_with);
}

TEST_F(MatrixLogicalOpTest, NotEqualOperation1) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    EXPECT_FALSE(mat != test_with);
}

TEST_F(MatrixLogicalOpTest, NotEqualOperation2) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    mat.to_double();
    test_with.to_double();
    EXPECT_FALSE(mat != test_with);
}

TEST_F(MatrixLogicalOpTest, NotEqualOperation3) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    mat.to_double();
    EXPECT_FALSE(mat != test_with);
}

TEST_F(MatrixLogicalOpTest, NotEqualOperation4) {
    Matrix test_with;
    EXPECT_TRUE(mat != test_with);
}

TEST_F(MatrixLogicalOpTest, NotEqualOperation5) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with = test_with.slice(0, 1, 0, test_with.col_length());
    EXPECT_TRUE(mat != test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanOperation1) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    EXPECT_FALSE(mat < test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanOperation2) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    mat.to_double();
    test_with.to_double();
    EXPECT_FALSE(mat < test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanOperation3) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    mat.to_double();
    EXPECT_FALSE(mat < test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanOperation4) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with = test_with.slice(0, 1, 0, test_with.col_length());
    EXPECT_FALSE(mat < test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanOperation5) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with.to_double();
    test_with = test_with.slice(0, 1, 0, test_with.col_length());
    test_with(0, 0) = 5;
    EXPECT_TRUE(mat < test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanOperation6) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with.to_double();
    test_with(0, 0) = 5;
    EXPECT_TRUE(mat < test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanOperation7) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with.to_double();
    Matrix mat2 = mat;
    mat2.to_double();
    test_with(0, 1) = 5;
    mat2(1, 2) = 100;
    EXPECT_TRUE(mat2 < test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanOperation8) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with.to_double();
    Matrix mat2 = mat;
    mat2.to_double();
    mat2(1, 2) = 100;
    EXPECT_FALSE(mat2 < test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanOperation9) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with.to_double();
    Matrix mat2 = mat;
    mat2.to_double();
    test_with(0, 1) = 5;
    mat2(0, 0) = 4;
    EXPECT_FALSE(mat2 < test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanEqualOperation1) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    EXPECT_TRUE(mat <= test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanEqualOperation2) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    mat.to_double();
    test_with.to_double();
    EXPECT_TRUE(mat <= test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanEqualOperation3) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    mat.to_double();
    EXPECT_TRUE(mat <= test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanEqualOperation4) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with = test_with.slice(0, 1, 0, test_with.col_length());
    EXPECT_FALSE(mat <= test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanEqualOperation5) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with.to_double();
    test_with = test_with.slice(0, 1, 0, test_with.col_length());
    test_with(0, 0) = 5;
    EXPECT_TRUE(mat <= test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanEqualOperation6) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with.to_double();
    test_with(0, 0) = 5;
    EXPECT_TRUE(mat <= test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanEqualOperation7) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with.to_double();
    Matrix mat2 = mat;
    mat2.to_double();
    test_with(0, 1) = 5;
    mat2(1, 2) = 100;
    EXPECT_TRUE(mat2 <= test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanEqualOperation8) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with.to_double();
    Matrix mat2 = mat;
    mat2.to_double();
    mat2(1, 2) = 100;
    EXPECT_FALSE(mat2 <= test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanEqualOperation9) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with.to_double();
    Matrix mat2 = mat;
    mat2.to_double();
    test_with(0, 1) = 5;
    mat2(0, 0) = 4;
    EXPECT_FALSE(mat2 <= test_with);
}

TEST_F(MatrixLogicalOpTest, LessThanEqualOperation10) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with.to_double();
    Matrix mat2 = mat;
    mat2.to_double();
    test_with(0, 1) = 5;
    mat2(0, 1) = 5;
    EXPECT_TRUE(mat2 <= test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanOperation1) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    EXPECT_FALSE(mat > test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanOperation2) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    mat.to_double();
    test_with.to_double();
    EXPECT_FALSE(mat > test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanOperation3) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    mat.to_double();
    EXPECT_FALSE(mat > test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanOperation4) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with = test_with.slice(0, 1, 0, test_with.col_length());
    EXPECT_TRUE(mat > test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanOperation5) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with.to_double();
    test_with = test_with.slice(0, 1, 0, test_with.col_length());
    test_with(0, 0) = 5;
    EXPECT_FALSE(mat > test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanOperation6) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with.to_double();
    test_with(0, 0) = 5;
    EXPECT_FALSE(mat > test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanOperation7) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with.to_double();
    Matrix mat2 = mat;
    mat2.to_double();
    test_with(0, 1) = 5;
    mat2(1, 2) = 100;
    EXPECT_FALSE(mat2 > test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanOperation8) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with.to_double();
    Matrix mat2 = mat;
    mat2.to_double();
    mat2(1, 2) = 100;
    EXPECT_TRUE(mat2 > test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanOperation9) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with.to_double();
    Matrix mat2 = mat;
    mat2.to_double();
    test_with(0, 1) = 5;
    mat2(0, 0) = 4;
    EXPECT_TRUE(mat2 > test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanEqualOperation1) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    EXPECT_TRUE(mat >= test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanEqualOperation2) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    mat.to_double();
    test_with.to_double();
    EXPECT_TRUE(mat >= test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanEqualOperation3) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    mat.to_double();
    EXPECT_TRUE(mat >= test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanEqualOperation4) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with = test_with.slice(0, 1, 0, test_with.col_length());
    EXPECT_TRUE(mat >= test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanEqualOperation5) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with.to_double();
    test_with = test_with.slice(0, 1, 0, test_with.col_length());
    test_with(0, 0) = 5;
    EXPECT_FALSE(mat >= test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanEqualOperation6) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with.to_double();
    test_with(0, 0) = 5;
    EXPECT_FALSE(mat >= test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanEqualOperation7) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with.to_double();
    Matrix mat2 = mat;
    mat2.to_double();
    test_with(0, 1) = 5;
    mat2(1, 2) = 100;
    EXPECT_FALSE(mat2 >= test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanEqualOperation8) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with.to_double();
    Matrix mat2 = mat;
    mat2.to_double();
    mat2(1, 2) = 100;
    EXPECT_TRUE(mat2 >= test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanEqualOperation9) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with.to_double();
    Matrix mat2 = mat;
    mat2.to_double();
    test_with(0, 1) = 5;
    mat2(0, 0) = 4;
    EXPECT_TRUE(mat2 >= test_with);
}

TEST_F(MatrixLogicalOpTest, GreaterThanEqualOperation10) {
    Matrix test_with = matrix.genfromtxt("test_dataset.csv", ',');
    test_with.to_double();
    Matrix mat2 = mat;
    mat2.to_double();
    test_with(0, 1) = 5;
    mat2(0, 1) = 5;
    EXPECT_TRUE(mat2 >= test_with);
}

} // namespace