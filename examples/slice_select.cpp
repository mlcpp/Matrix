#include <Matrix.hpp>

/* Example program

Read a csv file and get two Matrix objects X and Y.
Slice a selected column of those values of X into a new matrix where values of Y is equal to val.
The select Matrix object is then printed to the console.
*/
int main() {
    Matrix<std::string> mat1 =
        matrix.genfromtxt<std::string>("./examples/datasets/dataset0.csv", ',');
    Matrix<int> mat2 = mat1.slice(0, mat1.row_length(), 0, 1);

    Matrix<std::string> select = matrix.slice_select(mat1, mat2, 4, 1);
    select.print();

    return 0;
}
