#include <Matrix.hpp>

/* Example program

Read csv files to get a Matrix object.
Slice the Matrix object, if necessary, such that calculating determinant is possible.
The determinant is then calculated and printed.
*/
int main() {
    Matrix<double> mat = matrix.genfromtxt<double>("./examples/datasets/dataset1.csv", ',');

    double det = matrix.determinant(mat, mat.col_length());
    std::cout << det << std::endl;

    return 0;
}
