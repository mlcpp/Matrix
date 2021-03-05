#include <Matrix.hpp>

/* Example program

Read csv files to get a Matrix object.
Slice the Matrix object, if necessary, such that inverse is possible.
The inverse is then calculated and printed.
*/
int main() {
    Matrix<double> mat = matrix.genfromtxt<double>("./examples/datasets/dataset1.csv", ',');

    // Calculating inverse of a Matrix object
    Matrix<double> inv = matrix.inverse(mat);
    inv.print();

    return 0;
}
