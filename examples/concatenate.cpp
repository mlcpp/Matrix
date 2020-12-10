#include <Matrix.hpp>

/* Example program

Read csv files to get a Matrix object.
Slice the Matrix object in different ways to perform concatenation operations.
The Matrix concatenation is done in two ways:

1. row-wise
2. column-wise
*/
int main() {
    Matrix mat = genfromtxt("./datasets/boston/boston.csv",',');

    // Concatinating two Matrix objects with same number of columns
    Matrix matr1_5 = mat.slice(1, 5, 0, mat.col_length());
    Matrix matr7_9 = mat.slice(7, 9, 0, mat.col_length());
    matr1_5.to_double();
    matr7_9.to_double();
    Matrix row_con = matrix.concatenate(matr1_5, matr7_9, "row");
    row_con.print();

    std::cout << std::endl << std::endl;

    // Concatinating two Matrix objects with same number of rows
    Matrix matc0_3 = mat.slice(1, 10, 0, 3);
    Matrix matc5_9 = mat.slice(1, 10, 5, 9);
    Matrix col_con = matrix.concatenate(matc0_3, matc5_9, "column");
    col_con.print();

    return 0;
}
