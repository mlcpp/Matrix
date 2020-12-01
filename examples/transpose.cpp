#include <Matrix.hpp>
/* Example program

Read a csv file and get a Matrix object.
Get the Transpose of the Matrix object and then print it.
*/
int main() {
    Matrix mat = genfromtxt("./datasets/boston/boston.csv", ',');
    Matrix mat_transpose = mat.T();
    mat_transpose.print();

    return 0;
}