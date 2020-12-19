#include "gtest/gtest.h"
#include <Matrix.hpp>
#include <cmath>

namespace {

class MatrixBasicOpTest : public ::testing::Test {
  protected:
    Matrix mat;

    MatrixBasicOpTest() {
        mat = matrix.genfromtxt("test_dataset.csv", ',');
        mat.to_double();
    }
};

TEST_F(MatrixBasicOpTest, AddingTwoMatrix) {
    Matrix add = mat + mat;
    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(2 * (3 * i + j + 1));
        vec.push_back(v);
        v.clear();
    }
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(add, test_with);
}

TEST_F(MatrixBasicOpTest, AddingMatrixScalar) {
    Matrix add = mat + 1;
    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(3 * i + j + 2);
        vec.push_back(v);
        v.clear();
    }
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(add, test_with);
}

TEST_F(MatrixBasicOpTest, AddingMatrixColumnVector) {
    Matrix add = mat + mat.slice(0, mat.row_length(), 0, 1);
    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(6 * i + j + 2);
        vec.push_back(v);
        v.clear();
    }
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(add, test_with);
}

TEST_F(MatrixBasicOpTest, AddingMatrixRowVector) {
    Matrix add = mat + mat.slice(0, 1, 0, mat.col_length());
    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(3 * i + 2 * j + 2);
        vec.push_back(v);
        v.clear();
    }
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(add, test_with);
}

TEST_F(MatrixBasicOpTest, SubtractingTwoMatrix) {
    Matrix sub = mat - mat;
    std::vector<double> v(3, 0);
    std::vector<std::vector<double>> vec(2, v);
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(sub, test_with);
}

TEST_F(MatrixBasicOpTest, SubtractingMatrixScalar) {
    Matrix sub = mat - 1;
    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(3 * i + j);
        vec.push_back(v);
        v.clear();
    }
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(sub, test_with);
}

TEST_F(MatrixBasicOpTest, SubtractingMatrixColumnVector) {
    Matrix sub = mat - mat.slice(0, mat.row_length(), 0, 1);
    std::vector<double> v;
    for (int i = 0; i < 3; i++)
        v.push_back(i);
    std::vector<std::vector<double>> vec;
    vec.push_back(v);
    vec.push_back(v);
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(sub, test_with);
}

TEST_F(MatrixBasicOpTest, SubtractingMatrixRowVector) {
    Matrix sub = mat - mat.slice(0, 1, 0, mat.col_length());
    std::vector<double> v1(3, 0);
    std::vector<double> v2(3, 3);
    std::vector<std::vector<double>> vec;
    vec.push_back(v1);
    vec.push_back(v2);
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(sub, test_with);
}

TEST_F(MatrixBasicOpTest, MultiplyingTwoMatrix) {
    Matrix mult = mat * mat;
    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back((3 * i + j + 1) * (3 * i + j + 1));
        vec.push_back(v);
        v.clear();
    }
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(mult, test_with);
}

TEST_F(MatrixBasicOpTest, MultiplyingMatrixScalar) {
    Matrix mult = mat * 2;
    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back((3 * i + j + 1) * 2);
        vec.push_back(v);
        v.clear();
    }
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(mult, test_with);
}

TEST_F(MatrixBasicOpTest, MultiplyingMatrixColumnVector) {
    Matrix mult = mat * mat.slice(0, mat.row_length(), 0, 1);
    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back((3 * i + j + 1) * (std::pow(4, i)));
        vec.push_back(v);
        v.clear();
    }
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(mult, test_with);
}

TEST_F(MatrixBasicOpTest, MultiplyingMatrixRowVector) {
    Matrix mult = mat * mat.slice(0, 1, 0, mat.col_length());
    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back((3 * i + j + 1) * (j + 1));
        vec.push_back(v);
        v.clear();
    }
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(mult, test_with);
}

TEST_F(MatrixBasicOpTest, DividingTwoMatrix) {
    Matrix div = mat / mat;
    std::vector<double> v(3, 1);
    std::vector<std::vector<double>> vec(2, v);
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(div, test_with);
}

TEST_F(MatrixBasicOpTest, DividingMatrixScalar) {
    Matrix div = mat / 2;
    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back((double)(3 * i + j + 1) / 2);
        vec.push_back(v);
        v.clear();
    }
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(div, test_with);
}

TEST_F(MatrixBasicOpTest, DividingMatrixColumnVector) {
    Matrix div = mat / mat.slice(0, mat.row_length(), 0, 1);
    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back((double)(3 * i + j + 1) / (std::pow(4, i)));
        vec.push_back(v);
        v.clear();
    }
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(div, test_with);
}

TEST_F(MatrixBasicOpTest, DividingMatrixRowVector) {
    Matrix div = mat / mat.slice(0, 1, 0, mat.col_length());
    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back((double)(3 * i + j + 1) / (j + 1));
        vec.push_back(v);
        v.clear();
    }
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(div, test_with);
}

TEST_F(MatrixBasicOpTest, UnaryMinus) {
    Matrix minus = -mat;
    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(-(3 * i + j + 1));
        vec.push_back(v);
        v.clear();
    }
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(minus, test_with);
}

} // namespace