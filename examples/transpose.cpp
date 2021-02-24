#include <Matrix.hpp>
/* Example program

Read a csv file and get a Matrix object.
Get the Transpose of the Matrix object and then print it.
*/
int main() {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./examples/datasets/dataset0.csv", ',');
    Matrix<std::string> mat_transpose = mat.transpose();
    mat_transpose.print();

    return 0;
}
