#include <Matrix.hpp>

/* Example program

Read csv files to get Matrix objects.
Then operate the Matrix object with sqrt() method.
*/
int main() {
    Matrix<double> mat = matrix.genfromtxt<double>("./examples/datasets/dataset0.csv", ',');

    // sqrt() on a Matrix object
    Matrix<double> mat_sqrt = matrix.sqrt(mat);
    mat_sqrt.head();

    return 0;
}
