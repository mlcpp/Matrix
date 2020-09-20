#include <matrix.hpp>
#include <matrix_operations.hpp>

/* Example program

Read a csv file and get a Matrix object
The Matrix object is then printed to the console.
*/
int main() {
    MatrixOp ops;
    Matrix mat = ops.read_csv("./datasets/boston/boston.csv");
    mat.print();

    return 0;
}