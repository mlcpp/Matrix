#include <Matrix.hpp>

/* Example program

Read csv files to get Matrix objects.
Then operate with argmax and argmin on the Matrix object.
*/
int main() {
    Matrix<float> mat = matrix.genfromtxt<float>("./examples/datasets/dataset1.csv", ',');

    // argmin() across a row
    Matrix<int> mat_argminr = matrix.argmin(mat, "row");
    mat_argminr.head();

    std::cout << std::endl << std::endl;

    // argmin() across a column
    Matrix<int> mat_argminc = matrix.argmin(mat, "column");
    mat_argminc.head();

    std::cout << std::endl << std::endl;

    // argmax() across a row
    Matrix<int> mat_argmaxr = matrix.argmax(mat, "row");
    mat_argmaxr.head();

    std::cout << std::endl << std::endl;

    // argmax() across a column
    Matrix<int> mat_argmaxc = matrix.argmax(mat, "column");
    mat_argmaxc.head();

    return 0;
}
