#include <Matrix.hpp>

/* Example program

Read a csv file and get a Matrix object.
The reciprocal() method is applied to it.
*/
int main() {
    Matrix<float> mat = matrix.genfromtxt<float>("./examples/datasets/dataset0.csv", ',');

    Matrix<float> reciprocal_mat = matrix.reciprocal(mat);

    reciprocal_mat.print();

    return 0;
}
