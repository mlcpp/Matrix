#include <Matrix.hpp>

/* Example program

Read csv files to get Matrix objects.
Slice the Matrix object and then convert it to double.
Then operate with max and min on the sliced Matrix object.
*/
int main() {
    Matrix mat = matrix.genfromtxt("./datasets/boston/boston.csv",',');
    Matrix sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());
    sliced_mat.to_double();

    // min() across a row
    Matrix mat_minr = matrix.min(sliced_mat, "row");
    mat_minr.head();

    std::cout << std::endl << std::endl;

    // min() across a column
    Matrix mat_minc = matrix.min(sliced_mat, "column");
    mat_minc.head();

    std::cout << std::endl << std::endl;

    // max() across a row
    Matrix mat_maxr = matrix.max(sliced_mat, "row");
    mat_maxr.head();

    std::cout << std::endl << std::endl;

    // max() across a column
    Matrix mat_maxc = matrix.max(sliced_mat, "column");
    mat_maxc.head();

    return 0;
}
