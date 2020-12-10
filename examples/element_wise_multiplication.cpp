#include <Matrix.hpp>

/* Example program

Read csv files to get Matrix objects.
Slice the Matrix object and then convert it to double.
Then the element wise mulitplicaiton is done in four ways:

1. Matrix(x,y) * Matrix(x,y)
2. Matrix(x,y) * scalar
3. Matrix(x,y) * Matrix(1,y)
4. Matrix(x,y) * Matrix(x,1)
*/
int main() {
    Matrix mat1 = genfromtxt("./datasets/boston/boston.csv",',');
    Matrix mat2 = genfromtxt("./datasets/boston/boston.csv",',');
    Matrix sliced_mat1 = mat1.slice(1, mat1.row_length(), 0, mat1.col_length());
    Matrix sliced_mat2 = mat2.slice(1, mat2.row_length(), 0, mat2.col_length());
    sliced_mat1.to_double();
    sliced_mat2.to_double();

    // Adding two Matrix object of same dimensions
    Matrix mat_add = sliced_mat1 * sliced_mat2;
    mat_add.head();

    std::cout << std::endl << std::endl;

    // Adding a Matrix object and a scalar
    Matrix scl_add = sliced_mat1 * 2;
    scl_add.head();

    std::cout << std::endl << std::endl;

    // Adding a Matrix object and a row vector i.e., Matrix object with row length 1
    Matrix row_vec_add = sliced_mat1 * sliced_mat1.slice(1, 2, 0, sliced_mat1.col_length());
    row_vec_add.head();

    std::cout << std::endl << std::endl;

    // Adding a Matrix object and a column vector i.e., Matrix object with column length 1
    Matrix col_vec_add = sliced_mat1 * sliced_mat1.slice(0, sliced_mat1.row_length(), 0, 1);
    col_vec_add.head();

    return 0;
}
