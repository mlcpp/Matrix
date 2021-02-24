#include <Matrix.hpp>

/* Example program

Read csv files to get Matrix objects.
Slice the Matrix objects.
Then operate the sliced Matrix objects with power() method.
*/
int main() {
    Matrix<float> mat1 = matrix.genfromtxt<float>("./examples/datasets/dataset1.csv", ',');
    mat1 = mat1.slice(0, 2, 0, mat1.col_length());
    Matrix<int> mat2 = matrix.genfromtxt<int>("./examples/datasets/dataset0.csv", ',');
    mat2 = mat2.slice(0, mat2.row_length(), 0, 3);

    // power() on two Matrix objects of same dimensions
    Matrix<float> mat_pow = matrix.power(mat1, mat2);
    mat_pow.head();

    std::cout << std::endl << std::endl;

    // power() on a Matrix object and a scalar
    Matrix<float> scl_pow = matrix.power(mat1, 2);
    scl_pow.head();

    return 0;
}
