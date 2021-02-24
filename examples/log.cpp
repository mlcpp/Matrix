#include <Matrix.hpp>

/* Example program

Read a csv file and get a Matrix object.
The log() method is applied to it.
*/
int main() {
    Matrix<double> mat = matrix.genfromtxt<double>("./examples/datasets/dataset1.csv", ',');

    Matrix<double> log_mat = matrix.log(mat);

    log_mat.print();

    return 0;
}
