#include <Matrix.hpp>

/* Example program

Read csv files to get a Matrix object.
Slice the Matrix objects such that inverse is possible.
The inverse is then calculated and printed.
*/
int main() {
    Matrix mat = genfromtxt("./datasets/boston/boston.csv",',');
    Matrix sq_mat = mat.slice(1, 4, 0, 3);
    sq_mat.to_double();

    double det = matrix.determinant(sq_mat, sq_mat.col_length());
    std::cout << det << std::endl;

    return 0;
}
