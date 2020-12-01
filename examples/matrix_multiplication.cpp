#include <Matrix.hpp>

/* Example program

Read csv files to get a Matrix object.
Slice the Matrix objects such that matrix multiplication is possible.
The Matrix mulitplication is then performed and the result is printed.
*/
int main() {
    Matrix mat = genfromtxt("./datasets/boston/boston.csv", ',');

    // Multiplying two Matrix objects
    Matrix mat1 = mat.slice(1, 5, 0, 2);
    Matrix mat2 = mat.slice(7, 9, 0, 3);
    mat1.to_double();
    mat2.to_double();
    Matrix mul = matrix.matmul(mat1, mat2);
    mul.print();

    return 0;
}