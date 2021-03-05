#include <Matrix.hpp>

/* Example program

Read a csv file and get a Matrix object.
The unary minus operator is applied to it.
*/
int main() {
    Matrix<int> mat = matrix.genfromtxt<int>("./examples/datasets/dataset0.csv", ',');
    mat = -mat;

    mat.print();

    return 0;
}
