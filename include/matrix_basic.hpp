#ifndef _matrix_basic_hpp_
#define _matrix_basic_hpp_

#include <algorithm>
#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

template <typename T>
class Matrix {
  public:
    std::vector<std::vector<T>> data_mat;

    // Constructors
    Matrix() {}
    template <typename U>
    Matrix(const Matrix<U> &);

    // Member functions
    std::vector<std::vector<T>> get();
    std::vector<T> get_row(int);
    std::vector<T> get_col(int);
    int col_length() const;
    int row_length() const;
    void print();
    void head();
    void tail();
    void view(int, int);
    void view(int, int, int, int);
    Matrix slice(int, int, int, int);
    Matrix transpose();

    // Overloaded Operators
    Matrix operator+(Matrix);
    Matrix operator+(T);
    Matrix operator-(Matrix);
    Matrix operator-(T);
    Matrix operator*(Matrix);
    Matrix operator*(T);
    Matrix operator/(Matrix);
    Matrix operator/(T);
    Matrix operator-();
    T &operator()(int, int);
    Matrix operator+=(Matrix);
    Matrix operator+=(T);
    Matrix operator-=(Matrix);
    Matrix operator-=(T);
    Matrix operator*=(Matrix);
    Matrix operator*=(T);
    Matrix operator/=(Matrix);
    Matrix operator/=(T);
    Matrix &operator++();
    Matrix operator++(int);
    Matrix &operator--();
    Matrix operator--(int);
    bool operator==(Matrix) const;
    bool operator!=(Matrix) const;
    bool operator<(Matrix) const;
    bool operator<=(Matrix) const;
    bool operator>(Matrix) const;
    bool operator>=(Matrix) const;
    template <typename U>
    friend std::ostream &operator<<(std::ostream &, const Matrix<U> &);
    template <typename U>
    friend std::istream &operator>>(std::istream &, Matrix<U> &);
};

#include <matrix_basic.cpp>

#endif /* _matrix_basic_hpp_ */