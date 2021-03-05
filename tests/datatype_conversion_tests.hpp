#include "gtest/gtest.h"
#include <Matrix.hpp>

namespace {
TEST(MatrixConversionTest, BoolToChar) {
    Matrix<bool> bool_mat = matrix.genfromtxt<bool>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<bool> char_mat = bool_mat;

    Matrix<char> test_with = matrix.ones<char>(2, 3);

    EXPECT_EQ(char_mat, test_with);
}

TEST(MatrixConversionTest, BoolToInt) {
    Matrix<bool> bool_mat = matrix.genfromtxt<bool>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<int> int_mat = bool_mat;

    Matrix<int> test_with = matrix.ones<int>(2, 3);

    EXPECT_EQ(int_mat, test_with);
}

TEST(MatrixConversionTest, BoolToString) {
    Matrix<bool> bool_mat = matrix.genfromtxt<bool>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<std::string> str_mat = bool_mat;

    Matrix<std::string> test_with = matrix.ones<std::string>(2, 3);

    EXPECT_EQ(str_mat, test_with);
}

TEST(MatrixConversionTest, BoolToFloat) {
    Matrix<bool> bool_mat = matrix.genfromtxt<bool>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<float> float_mat = bool_mat;

    Matrix<float> test_with = matrix.ones<float>(2, 3);

    EXPECT_EQ(float_mat, test_with);
}

TEST(MatrixConversionTest, BoolToDouble) {
    Matrix<bool> bool_mat = matrix.genfromtxt<bool>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<double> double_mat = bool_mat;

    Matrix<double> test_with = matrix.ones<double>(2, 3);

    EXPECT_EQ(double_mat, test_with);
}

TEST(MatrixConversionTest, CharToBool) {
    Matrix<char> char_mat = matrix.genfromtxt<char>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<bool> bool_mat = char_mat;

    Matrix<bool> test_with = matrix.genfromtxt<bool>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(bool_mat, test_with);
}

TEST(MatrixConversionTest, CharToInt) {
    Matrix<char> char_mat = matrix.genfromtxt<char>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<char> int_mat = char_mat;

    Matrix<char> test_with = matrix.genfromtxt<char>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(int_mat, test_with);
}

TEST(MatrixConversionTest, CharToString) {
    Matrix<char> char_mat = matrix.genfromtxt<char>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<std::string> str_mat = char_mat;

    Matrix<std::string> test_with =
        matrix.genfromtxt<std::string>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(str_mat, test_with);
}

TEST(MatrixConversionTest, CharToFloat) {
    Matrix<char> char_mat = matrix.genfromtxt<char>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<float> float_mat = char_mat;

    Matrix<float> test_with = matrix.genfromtxt<float>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(float_mat, test_with);
}

TEST(MatrixConversionTest, CharToDouble) {
    Matrix<char> char_mat = matrix.genfromtxt<char>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<double> double_mat = char_mat;

    Matrix<double> test_with = matrix.genfromtxt<double>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(double_mat, test_with);
}

// TEST(MatrixConversionTest, CharToLongLong) {
//     Matrix<char> char_mat = matrix.genfromtxt<char>("./tests/datasets/test_dataset0.csv", ',');
//     Matrix<long long> long_long_mat = char_mat;

//     Matrix<long long> test_with = matrix.genfromtxt<long
//     long>("./tests/datasets/test_dataset0.csv", ',');

//     EXPECT_EQ(long_long_mat, test_with);
// }

TEST(MatrixConversionTest, IntToBool) {
    Matrix<int> int_mat = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<bool> bool_mat = int_mat;

    Matrix<bool> test_with = matrix.genfromtxt<bool>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(bool_mat, test_with);
}

TEST(MatrixConversionTest, IntToChar) {
    Matrix<int> int_mat = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<char> char_mat = int_mat;

    Matrix<char> test_with = matrix.genfromtxt<char>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(char_mat, test_with);
}

TEST(MatrixConversionTest, IntToString) {
    Matrix<int> int_mat = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<std::string> str_mat = int_mat;

    Matrix<std::string> test_with =
        matrix.genfromtxt<std::string>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(str_mat, test_with);
}

TEST(MatrixConversionTest, IntToUnsignedInt) {
    Matrix<int> int_mat = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<unsigned int> usint_mat = int_mat;

    Matrix<unsigned int> test_with =
        matrix.genfromtxt<unsigned int>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(usint_mat, test_with);
}

TEST(MatrixConversionTest, IntToSignedInt) {
    Matrix<int> int_mat = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<signed int> sint_mat = int_mat;

    Matrix<signed int> test_with =
        matrix.genfromtxt<signed int>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(sint_mat, test_with);
}

TEST(MatrixConversionTest, IntToShortInt) {
    Matrix<int> int_mat = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<short int> sint_mat = int_mat;

    Matrix<short int> test_with =
        matrix.genfromtxt<short int>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(sint_mat, test_with);
}

TEST(MatrixConversionTest, IntToUnsignedShortInt) {
    Matrix<int> int_mat = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<unsigned short int> usint_mat = int_mat;

    Matrix<unsigned short int> test_with =
        matrix.genfromtxt<unsigned short int>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(usint_mat, test_with);
}

TEST(MatrixConversionTest, IntToSignedShortInt) {
    Matrix<int> int_mat = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<signed short int> sint_mat = int_mat;

    Matrix<signed short int> test_with =
        matrix.genfromtxt<signed short int>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(sint_mat, test_with);
}

TEST(MatrixConversionTest, IntToLongInt) {
    Matrix<int> int_mat = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<long int> lint_mat = int_mat;

    Matrix<long int> test_with =
        matrix.genfromtxt<long int>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(lint_mat, test_with);
}

TEST(MatrixConversionTest, IntToUnsignedLongInt) {
    Matrix<int> int_mat = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<unsigned long int> uslint_mat = int_mat;

    Matrix<unsigned long int> test_with =
        matrix.genfromtxt<unsigned long int>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(uslint_mat, test_with);
}

TEST(MatrixConversionTest, IntToSignedLongInt) {
    Matrix<int> int_mat = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<signed long int> slint_mat = int_mat;

    Matrix<signed long int> test_with =
        matrix.genfromtxt<signed long int>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(slint_mat, test_with);
}

TEST(MatrixConversionTest, IntToLongLongInt) {
    Matrix<int> int_mat = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<long long int> llint_mat = int_mat;

    Matrix<long long int> test_with =
        matrix.genfromtxt<long long int>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(llint_mat, test_with);
}

TEST(MatrixConversionTest, IntToUnsignedLongLongInt) {
    Matrix<int> int_mat = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<unsigned long long int> usllint_mat = int_mat;

    Matrix<unsigned long long int> test_with =
        matrix.genfromtxt<unsigned long long int>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(usllint_mat, test_with);
}

TEST(MatrixConversionTest, IntToSignedLongLongInt) {
    Matrix<int> int_mat = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<signed long long int> sllint_mat = int_mat;

    Matrix<signed long long int> test_with =
        matrix.genfromtxt<signed long long int>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(sllint_mat, test_with);
}

TEST(MatrixConversionTest, IntToFloat) {
    Matrix<int> int_mat = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<float> float_mat = int_mat;

    Matrix<float> test_with = matrix.genfromtxt<float>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(float_mat, test_with);
}

TEST(MatrixConversionTest, IntToDouble) {
    Matrix<int> int_mat = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<double> double_mat = int_mat;

    Matrix<double> test_with = matrix.genfromtxt<double>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(double_mat, test_with);
}

TEST(MatrixConversionTest, IntToLongDouble) {
    Matrix<int> int_mat = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<long double> ldouble_mat = int_mat;

    Matrix<long double> test_with =
        matrix.genfromtxt<long double>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(ldouble_mat, test_with);
}

TEST(MatrixConversionTest, StringToBool) {
    Matrix<std::string> str_mat =
        matrix.genfromtxt<std::string>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<bool> bool_mat = str_mat;

    Matrix<bool> test_with = matrix.genfromtxt<bool>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(bool_mat, test_with);
}

TEST(MatrixConversionTest, StringToChar) {
    Matrix<std::string> str_mat =
        matrix.genfromtxt<std::string>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<char> char_mat = str_mat;

    Matrix<char> test_with = matrix.genfromtxt<char>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(char_mat, test_with);
}

TEST(MatrixConversionTest, StringToInt) {
    Matrix<std::string> str_mat =
        matrix.genfromtxt<std::string>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<int> int_mat = str_mat;

    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(int_mat, test_with);
}

TEST(MatrixConversionTest, StringToFloat) {
    Matrix<std::string> str_mat =
        matrix.genfromtxt<std::string>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<float> float_mat = str_mat;

    Matrix<float> test_with = matrix.genfromtxt<float>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(float_mat, test_with);
}

TEST(MatrixConversionTest, StringToDouble) {
    Matrix<std::string> str_mat =
        matrix.genfromtxt<std::string>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<double> double_mat = str_mat;

    Matrix<double> test_with = matrix.genfromtxt<double>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(double_mat, test_with);
}

TEST(MatrixConversionTest, StringToLongDouble) {
    Matrix<std::string> str_mat =
        matrix.genfromtxt<std::string>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<long double> ldouble_mat = str_mat;

    Matrix<long double> test_with =
        matrix.genfromtxt<long double>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(ldouble_mat, test_with);
}

TEST(MatrixConversionTest, FloatToBool) {
    Matrix<float> float_mat = matrix.genfromtxt<float>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<bool> bool_mat = float_mat;

    Matrix<bool> test_with = matrix.genfromtxt<bool>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(bool_mat, test_with);
}

TEST(MatrixConversionTest, FloatToChar) {
    Matrix<float> float_mat = matrix.genfromtxt<float>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<char> char_mat;

    ASSERT_DEATH(char_mat = float_mat, "Cannot convert to Matrix<char> object.");
}

TEST(MatrixConversionTest, FloatToInt) {
    Matrix<float> float_mat = matrix.genfromtxt<float>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<int> int_mat = float_mat;

    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(int_mat, test_with);
}

// TEST(MatrixConversionTest, FloatToString) {
//     Matrix<float> float_mat = matrix.genfromtxt<float>("./tests/datasets/test_dataset1.csv",
//     ','); Matrix<std::string> str_mat = float_mat;

//     Matrix<std::string> test_with =
//         matrix.genfromtxt<std::string>("./tests/datasets/test_dataset1.csv", ',');

//     EXPECT_EQ(str_mat, test_with);
// }

TEST(MatrixConversionTest, FloatToDouble) {
    Matrix<float> float_mat = matrix.genfromtxt<float>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<double> double_mat = float_mat;

    Matrix<double> test_with = matrix.genfromtxt<double>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(double_mat, test_with);
}

TEST(MatrixConversionTest, FloatToLongDouble) {
    Matrix<float> float_mat = matrix.genfromtxt<float>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<long double> ldouble_mat = float_mat;

    Matrix<long double> test_with =
        matrix.genfromtxt<long double>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(ldouble_mat, test_with);
}

TEST(MatrixConversionTest, DoubleToBool) {
    Matrix<double> double_mat =
        matrix.genfromtxt<double>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<bool> bool_mat = double_mat;

    Matrix<bool> test_with = matrix.genfromtxt<bool>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(bool_mat, test_with);
}

TEST(MatrixConversionTest, DoubleToChar) {
    Matrix<double> double_mat =
        matrix.genfromtxt<double>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<char> char_mat;

    ASSERT_DEATH(char_mat = double_mat, "Cannot convert to Matrix<char> object.");
}

TEST(MatrixConversionTest, DoubleToInt) {
    Matrix<double> double_mat =
        matrix.genfromtxt<double>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<int> int_mat = double_mat;

    Matrix<int> test_with = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(int_mat, test_with);
}

// TEST(MatrixConversionTest, DoubleToString) {
//     Matrix<double> double_mat = matrix.genfromtxt<double>("./tests/datasets/test_dataset1.csv",
//     ','); Matrix<std::string> str_mat = double_mat;

//     Matrix<std::string> test_with =
//         matrix.genfromtxt<std::string>("./tests/datasets/test_dataset1.csv", ',');

//     EXPECT_EQ(str_mat, test_with);
// }

TEST(MatrixConversionTest, DoubleToFloat) {
    Matrix<double> double_mat =
        matrix.genfromtxt<double>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<float> float_mat = double_mat;

    Matrix<float> test_with = matrix.genfromtxt<float>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(float_mat, test_with);
}

TEST(MatrixConversionTest, DoubleToLongDouble) {
    Matrix<double> double_mat =
        matrix.genfromtxt<double>("./tests/datasets/test_dataset0.csv", ',');
    Matrix<long double> ldouble_mat = double_mat;

    Matrix<long double> test_with =
        matrix.genfromtxt<long double>("./tests/datasets/test_dataset0.csv", ',');

    EXPECT_EQ(ldouble_mat, test_with);
}

} // namespace