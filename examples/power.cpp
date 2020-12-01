#include <Matrix.hpp>

/* Example program

Read csv files to get Matrix objects.
Slice the Matrix object and then convert it to double.
Then operate the sliced Matrix object with power() method.
*/
int main() {
    Matrix mat1 = genfromtxt("./datasets/boston/boston.csv", ',');
    Matrix mat2 = genfromtxt("./datasets/boston/boston.csv", ',');
    Matrix sliced_mat1 = mat1.slice(1, mat1.row_length(), 0, mat1.col_length());
    Matrix sliced_mat2 = mat2.slice(1, mat2.row_length(), 0, mat2.col_length());
    sliced_mat1.to_double();
    sliced_mat2.to_double();

    // power() on two Matrix objects of same dimensions
    Matrix mat_pow = matrix.power(sliced_mat1, sliced_mat2);
    mat_pow.head();

    std::cout << std::endl << std::endl;

    // power() on a Matrix object and a scalar
    Matrix scl_pow = matrix.power(sliced_mat1, 2);
    scl_pow.head();

    return 0;
}