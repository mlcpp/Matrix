#include <Matrix.hpp>

/* Example program

Read a csv file and get a Matrix object.
Slice the Matrix object.
The sliced Matrix object is then printed to the console.
*/
int main() {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./examples/datasets/dataset1.csv", ',');
    Matrix<std::string> sliced_mat = mat.slice(0, 1, 0, mat.col_length());
    sliced_mat.print();

    return 0;
}
