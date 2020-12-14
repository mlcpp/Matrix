#include "gtest/gtest.h"
#include <Matrix.hpp>

namespace {

TEST(MatrixInitTest, MethodCreatesMatrixObject) {
    std::vector<std::vector<double>> vec;
    Matrix mat;
    EXPECT_EQ(typeid(mat).name(), typeid(matrix.init(vec)).name());
}

TEST(MatrixInitTest, MethodCreatesZeroMatrix) {
    Matrix zero = matrix.zeros(3, 3);
    std::vector<double> vec(3, 0);
    std::vector<std::vector<double>> mat(3, vec);
    Matrix test_with = matrix.init(mat);
    EXPECT_EQ(zero, test_with);
}

TEST(MatrixInitTest, MethodCreatesOneMatrix) {
    Matrix zero = matrix.ones(3, 3);
    std::vector<double> vec(3, 1);
    std::vector<std::vector<double>> mat(3, vec);
    Matrix test_with = matrix.init(mat);
    EXPECT_EQ(zero, test_with);
}

TEST(MatrixInitTest, MethodCreatesIdentityMatrix) {
    Matrix zero = matrix.eye(3);
    std::vector<double> vec(3, 0);
    std::vector<std::vector<double>> mat(3, vec);
    for (int i = 0; i < 3; i++)
        mat[i][i] = 1;
    Matrix test_with = matrix.init(mat);
    EXPECT_EQ(zero, test_with);
}

} // namespace

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}