#include <Matrix.hpp>

/* Example program

Read a csv file and get a Matrix object.
The exp() method is applied to it.
*/
int main() {
    Matrix<float> mat = matrix.genfromtxt<float>("./examples/datasets/dataset1.csv", ',');

    Matrix<float> exp_mat = matrix.exp(mat);

    exp_mat.print();

    return 0;
}
