#include <Matrix.hpp>

/* Example program

Read csv files to get Matrix objects.
Then operate with max and min on the Matrix object.
*/
int main() {
    Matrix<int> mat = matrix.genfromtxt<int>("./examples/datasets/dataset0.csv", ',');

    // min() across a row
    Matrix<int> mat_minr = matrix.min(mat, "row");
    mat_minr.head();

    std::cout << std::endl << std::endl;

    // min() across a column
    Matrix<int> mat_minc = matrix.min(mat, "column");
    mat_minc.head();

    std::cout << std::endl << std::endl;

    // max() across a row
    Matrix<int> mat_maxr = matrix.max(mat, "row");
    mat_maxr.head();

    std::cout << std::endl << std::endl;

    // max() across a column
    Matrix<int> mat_maxc = matrix.max(mat, "column");
    mat_maxc.head();

    return 0;
}
