#include <Matrix.hpp>

/* Example program

Read csv files to get a Matrix object.
Slice the Matrix object in different ways to perform concatenation operations.
The Matrix concatenation is done in two ways:

1. row-wise
2. column-wise
*/
int main() {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./examples/datasets/dataset0.csv", ',');

    // Concatinating two Matrix objects with same number of columns
    Matrix<std::string> row_con = matrix.concatenate(mat, mat, "row");
    row_con.print();

    std::cout << std::endl << std::endl;

    // Concatinating two Matrix objects with same number of rows
    Matrix<std::string> col_con = matrix.concatenate(mat, mat, "column");
    col_con.print();

    return 0;
}
