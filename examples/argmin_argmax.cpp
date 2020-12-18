#include <Matrix.hpp>

/* Example program

Read csv files to get Matrix objects.
Slice the Matrix object and then convert it to double.
Then operate with argmax and argmin on the sliced Matrix object.
*/
int main() {
    Matrix mat = matrix.genfromtxt("./datasets/boston/boston.csv",',');
    Matrix sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());
    sliced_mat.to_double();

    // argmin() across a row
    Matrix mat_argminr = matrix.argmin(sliced_mat, "row");
    mat_argminr.head();

    std::cout << std::endl << std::endl;

    // argmin() across a column
    Matrix mat_argminc = matrix.argmin(sliced_mat, "column");
    mat_argminc.head();

    std::cout << std::endl << std::endl;

    // argmax() across a row
    Matrix mat_argmaxr = matrix.argmax(sliced_mat, "row");
    mat_argmaxr.head();

    std::cout << std::endl << std::endl;

    // argmax() across a column
    Matrix mat_argmaxc = matrix.argmax(sliced_mat, "column");
    mat_argmaxc.head();

    return 0;
}
