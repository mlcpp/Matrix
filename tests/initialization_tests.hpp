#include "gtest/gtest.h"
#include <Matrix.hpp>

namespace {

TEST(MatrixInitTest, CreatesMatrixObject) {
    std::vector<std::vector<double>> vec;
    Matrix<double> mat;

    EXPECT_EQ(typeid(mat).name(), typeid(matrix.init(vec)).name());
}

TEST(MatrixInitTest, CreatesZeroMatrixOfInt) {
    Matrix<int> zero = matrix.zeros<int>(3, 3);
    std::vector<int> vec(3, 0);
    std::vector<std::vector<int>> mat(3, vec);
    Matrix<int> test_with = matrix.init(mat);

    EXPECT_EQ(zero, test_with);
}

TEST(MatrixInitTest, CreatesZeroMatrixOfChar) {
    Matrix<char> zero = matrix.zeros<char>(3, 3);
    std::vector<char> vec(3, '0');
    std::vector<std::vector<char>> mat(3, vec);
    Matrix<char> test_with = matrix.init(mat);

    EXPECT_EQ(zero, test_with);
}

TEST(MatrixInitTest, CreatesZeroMatrixOfString) {
    Matrix<std::string> zero = matrix.zeros<std::string>(3, 3);
    std::vector<std::string> vec(3, "0");
    std::vector<std::vector<std::string>> mat(3, vec);
    Matrix<std::string> test_with = matrix.init(mat);

    EXPECT_EQ(zero, test_with);
}

TEST(MatrixInitTest, CreatesZeroMatrixOfFloat) {
    Matrix<float> zero = matrix.zeros<float>(3, 3);
    std::vector<float> vec(3, 0);
    std::vector<std::vector<float>> mat(3, vec);
    Matrix<float> test_with = matrix.init(mat);

    EXPECT_EQ(zero, test_with);
}

TEST(MatrixInitTest, CreatesZeroMatrixOfDouble) {
    Matrix<double> zero = matrix.zeros<double>(3, 3);
    std::vector<double> vec(3, 0);
    std::vector<std::vector<double>> mat(3, vec);
    Matrix<double> test_with = matrix.init(mat);

    EXPECT_EQ(zero, test_with);
}

TEST(MatrixInitTest, CreatesZeroMatrixOfLongLong) {
    Matrix<long long> zero = matrix.zeros<long long>(3, 3);
    std::vector<long long> vec(3, 0);
    std::vector<std::vector<long long>> mat(3, vec);
    Matrix<long long> test_with = matrix.init(mat);

    EXPECT_EQ(zero, test_with);
}

TEST(MatrixInitTest, CreatesOneMatrixOfInt) {
    Matrix<int> one = matrix.ones<int>(3, 3);
    std::vector<int> vec(3, 1);
    std::vector<std::vector<int>> mat(3, vec);
    Matrix<int> test_with = matrix.init(mat);

    EXPECT_EQ(one, test_with);
}

TEST(MatrixInitTest, CreatesOneMatrixOfChar) {
    Matrix<char> one = matrix.ones<char>(3, 3);
    std::vector<char> vec(3, '1');
    std::vector<std::vector<char>> mat(3, vec);
    Matrix<char> test_with = matrix.init(mat);

    EXPECT_EQ(one, test_with);
}

TEST(MatrixInitTest, CreatesOneMatrixOfString) {
    Matrix<std::string> one = matrix.ones<std::string>(3, 3);
    std::vector<std::string> vec(3, "1");
    std::vector<std::vector<std::string>> mat(3, vec);
    Matrix<std::string> test_with = matrix.init(mat);

    EXPECT_EQ(one, test_with);
}

TEST(MatrixInitTest, CreatesOneMatrixOfFloat) {
    Matrix<float> one = matrix.ones<float>(3, 3);
    std::vector<float> vec(3, 1);
    std::vector<std::vector<float>> mat(3, vec);
    Matrix<float> test_with = matrix.init(mat);

    EXPECT_EQ(one, test_with);
}

TEST(MatrixInitTest, CreatesOneMatrixOfDouble) {
    Matrix<double> one = matrix.ones<double>(3, 3);
    std::vector<double> vec(3, 1);
    std::vector<std::vector<double>> mat(3, vec);
    Matrix<double> test_with = matrix.init(mat);

    EXPECT_EQ(one, test_with);
}

TEST(MatrixInitTest, CreatesOneMatrixOfLongLong) {
    Matrix<long long> one = matrix.ones<long long>(3, 3);
    std::vector<long long> vec(3, 1);
    std::vector<std::vector<long long>> mat(3, vec);
    Matrix<long long> test_with = matrix.init(mat);

    EXPECT_EQ(one, test_with);
}

TEST(MatrixInitTest, CreatesIdentityMatrixOfInt) {
    Matrix<int> I = matrix.eye<int>(3);
    std::vector<int> vec(3, 0);
    std::vector<std::vector<int>> mat(3, vec);
    for (int i = 0; i < 3; i++)
        mat[i][i] = 1;
    Matrix<int> test_with = matrix.init(mat);

    EXPECT_EQ(I, test_with);
}

TEST(MatrixInitTest, CreatesIdentityMatrixOfChar) {
    Matrix<char> I = matrix.eye<char>(3);
    std::vector<char> vec(3, '0');
    std::vector<std::vector<char>> mat(3, vec);
    for (int i = 0; i < 3; i++)
        mat[i][i] = '1';
    Matrix<char> test_with = matrix.init(mat);

    EXPECT_EQ(I, test_with);
}

TEST(MatrixInitTest, CreatesIdentityMatrixOfString) {
    Matrix<std::string> I = matrix.eye<std::string>(3);
    std::vector<std::string> vec(3, "0");
    std::vector<std::vector<std::string>> mat(3, vec);
    for (int i = 0; i < 3; i++)
        mat[i][i] = "1";
    Matrix<std::string> test_with = matrix.init(mat);

    EXPECT_EQ(I, test_with);
}

TEST(MatrixInitTest, CreatesIdentityMatrixOfFloat) {
    Matrix<float> I = matrix.eye<float>(3);
    std::vector<float> vec(3, 0);
    std::vector<std::vector<float>> mat(3, vec);
    for (int i = 0; i < 3; i++)
        mat[i][i] = 1;
    Matrix<float> test_with = matrix.init(mat);

    EXPECT_EQ(I, test_with);
}

TEST(MatrixInitTest, CreatesIdentityMatrixOfDouble) {
    Matrix<double> I = matrix.eye<double>(3);
    std::vector<double> vec(3, 0);
    std::vector<std::vector<double>> mat(3, vec);
    for (int i = 0; i < 3; i++)
        mat[i][i] = 1;
    Matrix<double> test_with = matrix.init(mat);

    EXPECT_EQ(I, test_with);
}

TEST(MatrixInitTest, CreatesIdentityMatrixOfLongLong) {
    Matrix<long long> I = matrix.eye<long long>(3);
    std::vector<long long> vec(3, 0);
    std::vector<std::vector<long long>> mat(3, vec);
    for (int i = 0; i < 3; i++)
        mat[i][i] = 1;
    Matrix<long long> test_with = matrix.init(mat);

    EXPECT_EQ(I, test_with);
}

TEST(MatrixInitTest, CreatesMatrixFromCSV) {
    Matrix<int> mat = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(3 * i + j + 1);
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(mat, test_with);
}

TEST(MatrixInitTest, CreatesMatrixObjectFromString) {
    Matrix<std::string> mat;
    std::string str = "";

    EXPECT_EQ(typeid(mat).name(), typeid(matrix.init(str)).name());
}

TEST(MatrixInitTest, CreatesMatrixObjectFromDouble) {
    Matrix<double> mat;

    EXPECT_EQ(typeid(mat).name(), typeid(matrix.init(0.0)).name());
}

TEST(MatrixInitTest, CreatesMatrixObjectFromString1DVector) {
    std::vector<std::string> vec;
    Matrix<std::string> mat;

    EXPECT_EQ(typeid(mat).name(), typeid(matrix.init(vec)).name());
}

TEST(MatrixInitTest, CreatesMatrixObjectFromDouble1DVector) {
    std::vector<double> vec;
    Matrix<double> mat;

    EXPECT_EQ(typeid(mat).name(), typeid(matrix.init(vec)).name());
}

TEST(MatrixInitTest, InitializesMatrixFromString) {
    std::string str = "1";
    Matrix<std::string> mat = matrix.init(str);

    Matrix<std::string> test_with =
        matrix.genfromtxt<std::string>("./tests/datasets/test_dataset0.csv", ',');
    test_with = test_with.slice(0, 1, 0, 1);

    EXPECT_EQ(mat, test_with);
}

TEST(MatrixInitTest, InitializesMatrixFromInt) {
    Matrix<int> mat = matrix.init(1);

    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    test_with = test_with.slice(0, 1, 0, 1);

    EXPECT_EQ(mat, test_with);
}

TEST(MatrixInitTest, InitializesMatrixFromString1DVector) {
    std::vector<std::string> vec;
    vec.push_back("1");
    vec.push_back("2");
    vec.push_back("3");

    Matrix<std::string> mat = matrix.init(vec);

    Matrix<std::string> test_with =
        matrix.genfromtxt<std::string>("./tests/datasets/test_dataset0.csv", ',');
    test_with = test_with.slice(0, 1, 0, test_with.col_length());

    EXPECT_EQ(mat, test_with);
}

TEST(MatrixInitTest, InitializesMatrixFromDouble1DVector) {
    std::vector<double> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);

    Matrix<double> mat = matrix.init(vec);

    Matrix<double> test_with = matrix.genfromtxt<double>("./tests/datasets/test_dataset0.csv", ',');
    test_with = test_with.slice(0, 1, 0, test_with.col_length());

    EXPECT_EQ(mat, test_with);
}

} // namespace