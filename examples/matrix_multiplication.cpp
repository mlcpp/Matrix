#include <Matrix.hpp>

/* Example program

Read csv files to get a Matrix object.
Slice the Matrix objects such that matrix multiplication is possible.
The Matrix mulitplication is then performed and the result is printed.
*/
int main() {
    Matrix<double> mat = matrix.genfromtxt<double>("./examples/datasets/dataset1.csv", ',');

    // Multiplying two Matrix objects
    Matrix<double> mul = matrix.matmul(mat, mat);
    mul.print();

    return 0;
}
