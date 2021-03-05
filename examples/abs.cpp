#include <Matrix.hpp>

/* Example program

Read a csv file and get a Matrix object.
Then the abs() method is applied to it.
*/
int main() {
    Matrix<int> mat = matrix.genfromtxt<int>("./examples/datasets/dataset0.csv", ',');

    mat = -mat;

    Matrix<int> abs_mat = matrix.abs(mat);

    abs_mat.print();

    return 0;
}
