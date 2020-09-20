#include <matrix.hpp>
#include <matrix_operations.hpp>

/* Example program

Read a csv file and get a Matrix object.
Get the Transpose of the Matrix object and then print it.
*/
int main() {
    MatrixOp ops;
    Matrix mat = ops.read_csv("./datasets/boston/boston.csv");
    Matrix mat_transpose = mat.T();
    mat_transpose.print();

    return 0;
}