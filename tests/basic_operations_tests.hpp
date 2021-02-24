#include "gtest/gtest.h"
#include <Matrix.hpp>
#include <cmath>

namespace {

class IntMatrixBasicOpTest : public ::testing::Test {
  protected:
    Matrix<int> mat;

    IntMatrixBasicOpTest() {
        mat = matrix.genfromtxt<int>("./tests/datasets/test_dataset0.csv", ',');
    }
};

TEST_F(IntMatrixBasicOpTest, AddingTwoMatrix) {
    Matrix<int> add = mat + mat;

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(2 * (3 * i + j + 1));
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(add, test_with);
}

TEST_F(IntMatrixBasicOpTest, AddingTwoMatrixWithAssignment) {
    Matrix<int> add = mat;
    add += mat;

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(2 * (3 * i + j + 1));
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(add, test_with);
}

TEST_F(IntMatrixBasicOpTest, AddingMatrixScalar) {
    Matrix<int> add = mat + 1;

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(3 * i + j + 2);
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(add, test_with);
}

TEST_F(IntMatrixBasicOpTest, AddingMatrixScalarWithAssignment) {
    Matrix<int> add = mat;
    add += 1;

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(3 * i + j + 2);
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(add, test_with);
}

TEST_F(IntMatrixBasicOpTest, AddingMatrixColumnVector) {
    Matrix<int> add = mat + mat.slice(0, mat.row_length(), 0, 1);

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(6 * i + j + 2);
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(add, test_with);
}

TEST_F(IntMatrixBasicOpTest, AddingMatrixColumnVectorWithAssignment) {
    Matrix<int> add = mat;
    add += mat.slice(0, mat.row_length(), 0, 1);

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(6 * i + j + 2);
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(add, test_with);
}

TEST_F(IntMatrixBasicOpTest, AddingMatrixRowVector) {
    Matrix<int> add = mat + mat.slice(0, 1, 0, mat.col_length());

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(3 * i + 2 * j + 2);
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(add, test_with);
}

TEST_F(IntMatrixBasicOpTest, AddingMatrixRowVectorWithAssignment) {
    Matrix<int> add = mat;
    add += mat.slice(0, 1, 0, mat.col_length());

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(3 * i + 2 * j + 2);
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(add, test_with);
}

TEST_F(IntMatrixBasicOpTest, SubtractingTwoMatrix) {
    Matrix<int> sub = mat - mat;

    std::vector<int> v(3, 0);
    std::vector<std::vector<int>> vec(2, v);
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(sub, test_with);
}

TEST_F(IntMatrixBasicOpTest, SubtractingTwoMatrixWithAssignment) {
    Matrix<int> sub = mat;
    sub -= mat;

    std::vector<int> v(3, 0);
    std::vector<std::vector<int>> vec(2, v);
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(sub, test_with);
}

TEST_F(IntMatrixBasicOpTest, SubtractingMatrixScalar) {
    Matrix<int> sub = mat - 1;

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(3 * i + j);
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(sub, test_with);
}

TEST_F(IntMatrixBasicOpTest, SubtractingMatrixScalarWithAssignment) {
    Matrix<int> sub = mat;
    sub -= 1;

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(3 * i + j);
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(sub, test_with);
}

TEST_F(IntMatrixBasicOpTest, SubtractingMatrixColumnVector) {
    Matrix<int> sub = mat - mat.slice(0, mat.row_length(), 0, 1);

    std::vector<int> v;
    for (int i = 0; i < 3; i++)
        v.push_back(i);
    std::vector<std::vector<int>> vec;
    vec.push_back(v);
    vec.push_back(v);
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(sub, test_with);
}

TEST_F(IntMatrixBasicOpTest, SubtractingMatrixColumnVectorWithAssignment) {
    Matrix<int> sub = mat;
    sub -= mat.slice(0, mat.row_length(), 0, 1);

    std::vector<int> v;
    for (int i = 0; i < 3; i++)
        v.push_back(i);
    std::vector<std::vector<int>> vec;
    vec.push_back(v);
    vec.push_back(v);
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(sub, test_with);
}

TEST_F(IntMatrixBasicOpTest, SubtractingMatrixRowVector) {
    Matrix<int> sub = mat - mat.slice(0, 1, 0, mat.col_length());

    std::vector<int> v1(3, 0);
    std::vector<int> v2(3, 3);
    std::vector<std::vector<int>> vec;
    vec.push_back(v1);
    vec.push_back(v2);
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(sub, test_with);
}

TEST_F(IntMatrixBasicOpTest, SubtractingMatrixRowVectorWithAssignment) {
    Matrix<int> sub = mat;

    sub -= mat.slice(0, 1, 0, mat.col_length());
    std::vector<int> v1(3, 0);
    std::vector<int> v2(3, 3);
    std::vector<std::vector<int>> vec;
    vec.push_back(v1);
    vec.push_back(v2);
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(sub, test_with);
}

TEST_F(IntMatrixBasicOpTest, MultiplyingTwoMatrix) {
    Matrix<int> mult = mat * mat;

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back((3 * i + j + 1) * (3 * i + j + 1));
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(mult, test_with);
}

TEST_F(IntMatrixBasicOpTest, MultiplyingTwoMatrixWithAssignment) {
    Matrix<int> mult = mat;
    mult *= mat;

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back((3 * i + j + 1) * (3 * i + j + 1));
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(mult, test_with);
}

TEST_F(IntMatrixBasicOpTest, MultiplyingMatrixScalar) {
    Matrix<int> mult = mat * 2;

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back((3 * i + j + 1) * 2);
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(mult, test_with);
}

TEST_F(IntMatrixBasicOpTest, MultiplyingMatrixScalarWithAssignment) {
    Matrix<int> mult = mat;
    mult *= 2;

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back((3 * i + j + 1) * 2);
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(mult, test_with);
}

TEST_F(IntMatrixBasicOpTest, MultiplyingMatrixColumnVector) {
    Matrix<int> mult = mat * mat.slice(0, mat.row_length(), 0, 1);

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back((3 * i + j + 1) * (std::pow(4, i)));
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(mult, test_with);
}

TEST_F(IntMatrixBasicOpTest, MultiplyingMatrixColumnVectorWithAssignment) {
    Matrix<int> mult = mat;
    mult *= mat.slice(0, mat.row_length(), 0, 1);

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back((3 * i + j + 1) * (std::pow(4, i)));
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(mult, test_with);
}

TEST_F(IntMatrixBasicOpTest, MultiplyingMatrixRowVector) {
    Matrix<int> mult = mat * mat.slice(0, 1, 0, mat.col_length());

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back((3 * i + j + 1) * (j + 1));
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(mult, test_with);
}

TEST_F(IntMatrixBasicOpTest, MultiplyingMatrixRowVectorWithAssignment) {
    Matrix<int> mult = mat;
    mult *= mat.slice(0, 1, 0, mat.col_length());

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back((3 * i + j + 1) * (j + 1));
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(mult, test_with);
}

TEST_F(IntMatrixBasicOpTest, DividingTwoMatrix) {
    Matrix<int> div = mat / mat;

    std::vector<int> v(3, 1);
    std::vector<std::vector<int>> vec(2, v);
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(div, test_with);
}

TEST_F(IntMatrixBasicOpTest, DividingTwoMatrixWithAssignment) {
    Matrix<int> div = mat;
    div /= mat;

    std::vector<int> v(3, 1);
    std::vector<std::vector<int>> vec(2, v);
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(div, test_with);
}

TEST_F(IntMatrixBasicOpTest, DividingMatrixScalar) {
    Matrix<int> div = mat / 2;

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back((int)(3 * i + j + 1) / 2);
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(div, test_with);
}

TEST_F(IntMatrixBasicOpTest, DividingMatrixScalarWithAssignment) {
    Matrix<int> div = mat;
    div /= 2;

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back((int)(3 * i + j + 1) / 2);
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(div, test_with);
}

TEST_F(IntMatrixBasicOpTest, DividingMatrixColumnVector) {
    Matrix<int> div = mat / mat.slice(0, mat.row_length(), 0, 1);

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back((int)(3 * i + j + 1) / (std::pow(4, i)));
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(div, test_with);
}

TEST_F(IntMatrixBasicOpTest, DividingMatrixColumnVectorWithAssignment) {
    Matrix<int> div = mat;
    div /= mat.slice(0, mat.row_length(), 0, 1);

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back((int)(3 * i + j + 1) / (std::pow(4, i)));
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(div, test_with);
}

TEST_F(IntMatrixBasicOpTest, DividingMatrixRowVector) {
    Matrix<int> div = mat / mat.slice(0, 1, 0, mat.col_length());

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back((int)(3 * i + j + 1) / (j + 1));
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(div, test_with);
}

TEST_F(IntMatrixBasicOpTest, DividingMatrixRowVectorWithAssignment) {
    Matrix<int> div = mat;
    div /= mat.slice(0, 1, 0, mat.col_length());

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back((int)(3 * i + j + 1) / (j + 1));
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(div, test_with);
}

TEST_F(IntMatrixBasicOpTest, DividingByZeroMatrix) {
    Matrix<int> div = mat / matrix.zeros<int>(2, 3);

    Matrix<int> test_with = matrix.ones<int>(2, 3) * std::numeric_limits<int>::infinity();

    EXPECT_EQ(div, test_with);
}

TEST_F(IntMatrixBasicOpTest, DividingByZeroMatrixWithAssignment) {
    Matrix<int> div = mat;
    div /= matrix.zeros<int>(2, 3);

    Matrix<int> test_with = matrix.ones<int>(2, 3) * std::numeric_limits<int>::infinity();

    EXPECT_EQ(div, test_with);
}

TEST_F(IntMatrixBasicOpTest, DividingByZero) {
    Matrix<int> div = mat / 0;

    Matrix<int> test_with = matrix.ones<int>(2, 3) * std::numeric_limits<int>::infinity();

    EXPECT_EQ(div, test_with);
}

TEST_F(IntMatrixBasicOpTest, DividingByZeroWithAssignment) {
    Matrix<int> div = mat;
    div /= 0;

    Matrix<int> test_with = matrix.ones<int>(2, 3) * std::numeric_limits<int>::infinity();

    EXPECT_EQ(div, test_with);
}

TEST_F(IntMatrixBasicOpTest, PreIncrement) {
    Matrix<int> add = mat;
    ++add;

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(3 * i + j + 2);
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(add, test_with);
}

TEST_F(IntMatrixBasicOpTest, PostIncrement) {
    Matrix<int> add = mat;
    add++;

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(3 * i + j + 2);
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(add, test_with);
}

TEST_F(IntMatrixBasicOpTest, PreDecrement) {
    Matrix<int> sub = mat;
    --sub;

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(3 * i + j);
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(sub, test_with);
}

TEST_F(IntMatrixBasicOpTest, PostDecrement) {
    Matrix<int> sub = mat;
    sub--;

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(3 * i + j);
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(sub, test_with);
}

TEST_F(IntMatrixBasicOpTest, UnaryMinus) {
    Matrix<int> minus = -mat;

    std::vector<std::vector<int>> vec;
    std::vector<int> v;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++)
            v.push_back(-(3 * i + j + 1));
        vec.push_back(v);
        v.clear();
    }
    Matrix<int> test_with = matrix.init(vec);

    EXPECT_EQ(minus, test_with);
}

} // namespace