#include <Matrix.hpp>

/* Example program

Read csv files to get a Matrix object.
Slice the Matrix objects such that inverse is possible.
The inverse is then calculated and printed.
*/
int main() {
    Matrix mat = read_csv("./datasets/boston/boston.csv");

    // Calculating inverse of a Matrix object
    Matrix sq_mat = mat.slice(1, 4, 0, 3);
    sq_mat.to_double();
    Matrix inv = matrix.inverse(sq_mat);
    inv.print();

    return 0;
}