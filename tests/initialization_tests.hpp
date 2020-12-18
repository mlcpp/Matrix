#include "gtest/gtest.h"
#include <Matrix.hpp>

namespace {

TEST(MatrixInitTest, CreatesMatrixObject) {
    std::vector<std::vector<double>> vec;
    Matrix mat;

    EXPECT_EQ(typeid(mat).name(), typeid(matrix.init(vec)).name());
}

TEST(MatrixInitTest, CreatesZeroMatrix) {
    Matrix zero = matrix.zeros(3, 3);
    std::vector<double> vec(3, 0);
    std::vector<std::vector<double>> mat(3, vec);
    Matrix test_with = matrix.init(mat);

    EXPECT_EQ(zero, test_with);
}

TEST(MatrixInitTest, CreatesOneMatrix) {
    Matrix zero = matrix.ones(3, 3);
    std::vector<double> vec(3, 1);
    std::vector<std::vector<double>> mat(3, vec);
    Matrix test_with = matrix.init(mat);

    EXPECT_EQ(zero, test_with);
}

TEST(MatrixInitTest, CreatesIdentityMatrix) {
    Matrix zero = matrix.eye(3);
    std::vector<double> vec(3, 0);
    std::vector<std::vector<double>> mat(3, vec);
    for (int i = 0; i < 3; i++)
        mat[i][i] = 1;
    Matrix test_with = matrix.init(mat);

    EXPECT_EQ(zero, test_with);
}

TEST(MatrixInitTest, CreatesMatrixFromCSV) {
    Matrix mat = matrix.genfromtxt("test_dataset.csv", ',');
    mat.to_double();
    std::vector<std::vector<double>> vec;
    std::vector<double> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(3 * i + j + 1);
        vec.push_back(v);
        v.clear();
    }
    Matrix test_with = matrix.init(vec);

    EXPECT_EQ(mat, test_with);
}

} // namespace