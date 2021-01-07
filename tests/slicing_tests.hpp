#include "gtest/gtest.h"
#include <Matrix.hpp>

namespace {

class MatrixSliceTest : public ::testing::Test {
  protected:
    Matrix mat;

    MatrixSliceTest() {
        mat = matrix.genfromtxt("./tests/test_dataset.csv", ',');
        mat.to_double();
    }
};

TEST_F(MatrixSliceTest, SlicesTillColumns) {
    Matrix sliced = mat.slice(0, 1, 0, mat.col_length());
    std::vector<double> v;
    for (int i = 0; i < 3; i++)
        v.push_back(i + 1);
    std::vector<std::vector<double>> vec;
    vec.push_back(v);
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(sliced, test_with);
}

TEST_F(MatrixSliceTest, SlicesTillRows) {
    Matrix sliced = mat.slice(0, mat.row_length(), 0, 1);
    std::vector<double> v;
    v.push_back(1);
    std::vector<std::vector<double>> vec;
    vec.push_back(v);
    v.clear();
    v.push_back(4);
    vec.push_back(v);
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(sliced, test_with);
}

TEST_F(MatrixSliceTest, SliceOutOfBoundError) {
    ASSERT_DEATH(mat.slice(0, 5, 0, 100),
                 "The slicing parameters are out of bounds of the matrix size.");
}

TEST_F(MatrixSliceTest, SliceSelect) {
    Matrix X = mat.slice(0, mat.row_length(), 0, 2);
    Matrix Y = mat.slice(0, mat.row_length(), 2, mat.col_length());
    Matrix select = matrix.slice_select(X, Y, 3, 0);
    std::vector<double> v;
    v.push_back(1);
    std::vector<std::vector<double>> vec;
    vec.push_back(v);
    Matrix test_with = matrix.init(vec);
    EXPECT_EQ(select, test_with);
}

} // namespace