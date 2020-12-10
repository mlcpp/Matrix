#include <Matrix.hpp>

/* Example program

Read a csv file and get a Matrix object.
Slice the Matrix object to remove the rows and columns which cannot be converted to double.
The sliced Matrix object is then converted to double and then the reciprocal() method is applied to
it.
*/
int main() {
    Matrix mat = genfromtxt("./datasets/boston/boston.csv",',');
    Matrix sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());
    sliced_mat.to_double();

    Matrix reciprocal_mat = matrix.reciprocal(sliced_mat);

    reciprocal_mat.print();

    return 0;
}
