#include "gtest/gtest.h"
#include <Matrix.hpp>
#include <cmath>

namespace {

class MatrixStatOpTest : public ::testing::Test {
  protected:
    Matrix mat;

    MatrixStatOpTest() {
        mat = matrix.genfromtxt("./tests/test_dataset.csv", ',');
        mat.to_double();
    }
};

TEST_F(MatrixStatOpTest, SumColumn) {
    Matrix sumc = matrix.sum(mat, "column");
    std::vector<double> v;
    for (int i = 0; i < 3; i++)
        v.push_back((2 * i) + 5);
    std::vector<std::vector<double>> vec;
    vec.push_back(v);
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(sumc, test_with);
}

TEST_F(MatrixStatOpTest, SumRow) {
    Matrix sumr = matrix.sum(mat, "row");
    std::vector<double> v1(1, 6);
    std::vector<double> v2(1, 15);
    std::vector<std::vector<double>> vec;
    vec.push_back(v1);
    vec.push_back(v2);
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(sumr, test_with);
}

TEST_F(MatrixStatOpTest, MeanColumn) {
    Matrix meanc = matrix.mean(mat, "column");
    std::vector<double> v;
    for (int i = 0; i < 3; i++)
        v.push_back((double)((2 * i) + 5) / 2);
    std::vector<std::vector<double>> vec;
    vec.push_back(v);
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(meanc, test_with);
}

TEST_F(MatrixStatOpTest, MeanRow) {
    Matrix meanr = matrix.mean(mat, "row");
    std::vector<double> v1(1, 6.0 / 3);
    std::vector<double> v2(1, 15.0 / 3);
    std::vector<std::vector<double>> vec;
    vec.push_back(v1);
    vec.push_back(v2);
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(meanr, test_with);
}

TEST_F(MatrixStatOpTest, StDColumn) {
    Matrix stdc = matrix.std(mat, "column");
    std::vector<double> v(3, 2.25);
    std::vector<std::vector<double>> vec;
    vec.push_back(v);
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(stdc, test_with);
}

TEST_F(MatrixStatOpTest, StDRow) {
    Matrix stdr = matrix.std(mat, "row");
    double val = stdr(0, 0);
    std::vector<double> v(1, val);
    std::vector<std::vector<double>> vec;
    vec.push_back(v);
    vec.push_back(v);
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(stdr, test_with);
}

} // namespace