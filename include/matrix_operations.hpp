#ifndef _matrix_operations_hpp_
#define _matrix_operations_hpp_

#include <matrix_basic.hpp>

class MatrixOp {
  private:
    Matrix cofactor(Matrix, Matrix, int, int);
    Matrix adjoint(Matrix);

  public:
    Matrix init(std::vector<std::vector<double>>);
    Matrix init(std::vector<std::vector<std::string>>);
    Matrix init(double);
    Matrix init(std::string);
    Matrix init(std::vector<double>);
    Matrix init(std::vector<std::string>);
    Matrix concatenate(Matrix, Matrix, std::string);
    Matrix matmul(Matrix, Matrix);
    Matrix zeros(int, int);
    Matrix ones(int, int);
    Matrix eye(int);
    double determinant(Matrix, int);
    Matrix inverse(Matrix);
    Matrix sum(Matrix, std::string);
    Matrix mean(Matrix, std::string);
    Matrix std(Matrix, std::string);
    Matrix min(Matrix, std::string);
    Matrix max(Matrix, std::string);
    Matrix argmin(Matrix, std::string);
    Matrix argmax(Matrix, std::string);
    Matrix sqrt(Matrix);
    Matrix power(Matrix, Matrix);
    Matrix power(Matrix, double);
    Matrix slice_select(Matrix, Matrix, double, int);
    Matrix delete_(Matrix, int, std::string);
    Matrix exp(Matrix);
    Matrix log(Matrix);
    Matrix abs(Matrix);
    Matrix reciprocal(Matrix);
    Matrix genfromtxt(std::string, char);

} matrix;

#endif /* _matrix_operations_hpp_ */
