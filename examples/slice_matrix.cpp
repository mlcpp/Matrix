#include <Matrix.hpp>

/* Example program

Read a csv file and get a Matrix object.
Slice the Matrix object.
The sliced Matrix object is then printed to the console.
*/
int main() {
    Matrix mat = matrix.genfromtxt("./datasets/boston/boston.csv",',');
    Matrix sliced_mat = mat.slice(0, 5, 0, mat.col_length());
    sliced_mat.print();

    return 0;
}
