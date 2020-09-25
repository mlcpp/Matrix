#include <Matrix.hpp>

/* Example program

Read csv files to get Matrix objects.
Slice the Matrix object and then convert it to double.
Then operate the sliced Matrix object with sqrt() method.
*/
int main() {
    Matrix mat = read_csv("./datasets/boston/boston.csv");
    Matrix sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());
    sliced_mat.to_double();

    // sqrt() on a Matrix object
    Matrix mat_sqrt = matrix.sqrt(sliced_mat);
    mat_sqrt.head();

    return 0;
}