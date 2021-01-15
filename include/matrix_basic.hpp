#ifndef _matrix_hpp_
#define _matrix_hpp_

#include <algorithm>
#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Matrix {
  public:
    std::vector<std::vector<double>> double_mat;
    std::vector<std::vector<std::string>> str_mat;
    bool if_double = false;

    // Member functions
    std::vector<std::vector<double>> get();
    std::vector<double> get_row(int);
    std::vector<double> get_col(int);
    int col_length() const;
    int row_length() const;
    void print();
    void head();
    void tail();
    void view(int, int);
    void view(int, int, int, int);
    Matrix slice(int, int, int, int);
    Matrix T();
    void to_double();
    void to_string();

    // Overloaded Operators
    Matrix operator+(Matrix);
    Matrix operator+(double);
    Matrix operator-(Matrix);
    Matrix operator-(double);
    Matrix operator*(Matrix);
    Matrix operator*(double);
    Matrix operator/(Matrix);
    Matrix operator/(double);
    Matrix operator-();
    double &operator()(int, int);
    Matrix operator+=(Matrix);
    Matrix operator+=(double);
    Matrix operator-=(Matrix);
    Matrix operator-=(double);
    Matrix operator*=(Matrix);
    Matrix operator*=(double);
    Matrix operator/=(Matrix);
    Matrix operator/=(double);
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
    friend std::ostream &operator<<(std::ostream &, const Matrix &);
    friend std::istream &operator>>(std::istream &, Matrix &);
};

#endif /* _matrix_hpp_ */