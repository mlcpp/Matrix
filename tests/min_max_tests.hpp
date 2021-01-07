#include "gtest/gtest.h"
#include <Matrix.hpp>

namespace {

class MatrixMinMaxTest : public ::testing::Test {
  protected:
    Matrix mat;

    MatrixMinMaxTest() {
        mat = matrix.genfromtxt("./tests/test_dataset.csv", ',');
        mat.to_double();
    }
};

TEST_F(MatrixMinMaxTest, MaxAlongColumn) {
    Matrix maxc = matrix.max(mat, "column");
    std::vector<double> v;
    for (int i = 0; i < 3; i++)
        v.push_back(i + 4);
    std::vector<std::vector<double>> vec;
    vec.push_back(v);
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(maxc, test_with);
}

TEST_F(MatrixMinMaxTest, MaxAlongRow) {
    Matrix maxr = matrix.max(mat, "row");
    std::vector<double> v;
    v.push_back(3);
    std::vector<std::vector<double>> vec;
    vec.push_back(v);
    v.clear();
    v.push_back(6);
    vec.push_back(v);
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(maxr, test_with);
}

TEST_F(MatrixMinMaxTest, MinAlongColumn) {
    Matrix minc = matrix.min(mat, "column");
    std::vector<double> v;
    for (int i = 0; i < 3; i++)
        v.push_back(i + 1);
    std::vector<std::vector<double>> vec;
    vec.push_back(v);
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(minc, test_with);
}

TEST_F(MatrixMinMaxTest, MinAlongRow) {
    Matrix minr = matrix.min(mat, "row");
    std::vector<double> v;
    v.push_back(1);
    std::vector<std::vector<double>> vec;
    vec.push_back(v);
    v.clear();
    v.push_back(4);
    vec.push_back(v);
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(minr, test_with);
}

TEST_F(MatrixMinMaxTest, MaxIndexAlongColumn) {
    Matrix argmaxc = matrix.argmax(mat, "column");
    std::vector<double> v(3, 1);
    std::vector<std::vector<double>> vec;
    vec.push_back(v);
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(argmaxc, test_with);
}

TEST_F(MatrixMinMaxTest, MaxIndexAlongRow) {
    Matrix argmaxr = matrix.argmax(mat, "row");
    std::vector<double> v;
    v.push_back(2);
    std::vector<std::vector<double>> vec;
    vec.push_back(v);
    vec.push_back(v);
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(argmaxr, test_with);
}

TEST_F(MatrixMinMaxTest, MinIndexAlongColumn) {
    Matrix argminc = matrix.argmin(mat, "column");
    std::vector<double> v(3, 0);
    std::vector<std::vector<double>> vec;
    vec.push_back(v);
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(argminc, test_with);
}

TEST_F(MatrixMinMaxTest, MinIndexAlongRow) {
    Matrix argminr = matrix.argmin(mat, "row");
    std::vector<double> v;
    v.push_back(0);
    std::vector<std::vector<double>> vec;
    vec.push_back(v);
    vec.push_back(v);
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(argminr, test_with);
}

} // namespace