#include "gtest/gtest.h"
#include <Matrix.hpp>
#include <cmath>

namespace {

class MatrixMiscTest : public ::testing::Test {
  protected:
    Matrix<double> mat;

    MatrixMiscTest() { mat = matrix.genfromtxt<double>("./tests/datasets/test_dataset0.csv", ','); }
};

TEST_F(MatrixMiscTest, ConcatenateColumn) {
    Matrix<double> concat = matrix.concatenate(mat, mat, "column");

    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(3 * i + j + 1);
        for (int j = 0; j < 3; j++)
            v.push_back(3 * i + j + 1);
        vec.push_back(v);
        v.clear();
    }
    Matrix<double> test_with = matrix.init(vec);

    EXPECT_EQ(concat, test_with);
}

TEST_F(MatrixMiscTest, ConcatenateRow) {
    Matrix<double> concat = matrix.concatenate(mat, mat, "row");

    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(3 * i + j + 1);
        vec.push_back(v);
        v.clear();
    }
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(3 * i + j + 1);
        vec.push_back(v);
        v.clear();
    }
    Matrix<double> test_with = matrix.init(vec);

    EXPECT_EQ(concat, test_with);
}

TEST_F(MatrixMiscTest, Get) {
    std::vector<std::vector<double>> get_vec = mat.get();

    std::vector<std::vector<double>> test_with;
    std::vector<double> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(3 * i + j + 1);
        test_with.push_back(v);
        v.clear();
    }

    EXPECT_EQ(get_vec, test_with);
}

TEST_F(MatrixMiscTest, GetColumn) {
    std::vector<double> get_vec = mat.get_col(0);

    std::vector<double> test_with;
    test_with.push_back(1);
    test_with.push_back(4);

    EXPECT_EQ(get_vec, test_with);
}

TEST_F(MatrixMiscTest, GetRow) {
    std::vector<double> get_vec = mat.get_row(0);

    std::vector<double> test_with;
    for (int i = 0; i < 3; i++)
        test_with.push_back(i + 1);

    EXPECT_EQ(get_vec, test_with);
}

TEST_F(MatrixMiscTest, DeleteColumn) {
    Matrix<double> del = matrix.delete_(mat, 2, "column");

    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            v.push_back(3 * i + j + 1);
        vec.push_back(v);
        v.clear();
    }
    Matrix<double> test_with = matrix.init(vec);

    EXPECT_EQ(del, test_with);
}

TEST_F(MatrixMiscTest, DeleteRow) {
    Matrix<double> del = matrix.delete_(mat, 0, "row");

    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    for (int i = 0; i < 3; i++)
        v.push_back(i + 4);
    vec.push_back(v);
    Matrix<double> test_with = matrix.init(vec);

    EXPECT_EQ(del, test_with);
}

TEST_F(MatrixMiscTest, Reciprocal) {
    Matrix<double> rec = matrix.reciprocal(mat);

    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(1.0 / (3 * i + j + 1));
        vec.push_back(v);
        v.clear();
    }
    Matrix<double> test_with = matrix.init(vec);

    EXPECT_EQ(rec, test_with);
}

TEST_F(MatrixMiscTest, ColumnLength) {
    int len = mat.col_length();
    EXPECT_EQ(len, 3);
}

TEST_F(MatrixMiscTest, RowLength) {
    int len = mat.row_length();
    EXPECT_EQ(len, 2);
}

} // namespace