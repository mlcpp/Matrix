#ifndef _matrix_operations_hpp_
#define _matrix_operations_hpp_

#include <matrix_basic.hpp>

class MatrixOp {
  public:
    template <typename T>
    Matrix<T> init(T);
    template <typename T>
    Matrix<T> init(std::vector<T>);
    template <typename T>
    Matrix<T> init(std::vector<std::vector<T>>);
    template <typename T>
    Matrix<T> genfromtxt(std::string, char);
    template <typename T>
    Matrix<T> zeros(int, int);
    template <typename T>
    Matrix<T> ones(int, int);
    template <typename T>
    Matrix<T> eye(int);
    template <typename T>
    Matrix<T> concatenate(Matrix<T>, Matrix<T>, std::string);
    template <typename T, typename U>
    Matrix<T> matmul(Matrix<T>, Matrix<U>);
    template <typename T>
    double determinant(Matrix<T>, int);
    template <typename T>
    Matrix<T> inverse(Matrix<T>);
    template <typename T>
    Matrix<T> sum(Matrix<T>, std::string);
    template <typename T>
    Matrix<T> mean(Matrix<T>, std::string);
    template <typename T>
    Matrix<T> std(Matrix<T>, std::string);
    template <typename T>
    Matrix<T> min(Matrix<T>, std::string);
    template <typename T>
    Matrix<T> max(Matrix<T>, std::string);
    template <typename T>
    Matrix<int> argmin(Matrix<T>, std::string);
    template <typename T>
    Matrix<int> argmax(Matrix<T>, std::string);
    template <typename T>
    Matrix<T> sqrt(Matrix<T>);
    template <typename T, typename U>
    Matrix<T> power(Matrix<T>, Matrix<U>);
    template <typename T, typename U>
    Matrix<T> power(Matrix<T>, U);
    template <typename T, typename U>
    Matrix<T> slice_select(Matrix<T>, Matrix<U>, U, int);
    template <typename T>
    Matrix<T> delete_(Matrix<T>, int, std::string);
    template <typename T>
    Matrix<T> exp(Matrix<T>);
    template <typename T>
    Matrix<T> log(Matrix<T>);
    template <typename T>
    Matrix<T> abs(Matrix<T>);
    template <typename T>
    Matrix<T> reciprocal(Matrix<T>);

  private:
    template <typename T>
    Matrix<T> cofactor(Matrix<T>, Matrix<T>, int, int);
    template <typename T>
    Matrix<T> adjoint(Matrix<T>);
};

static MatrixOp matrix;

#include <matrix_operations.cpp>

#endif /* _matrix_operations_hpp_ */
