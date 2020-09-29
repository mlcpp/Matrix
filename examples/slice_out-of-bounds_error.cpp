#include <Matrix.hpp>

/* Example program

Read a csv file and get a Matrix object.
Slice the Matrix object.
The sliced Matrix object is then printed to the console.
*/
int main() {
    Matrix mat = read_csv("./datasets/boston/boston.csv");
    Matrix sliced_mat = mat.slice(0, 5, 0, 100);
    sliced_mat.print();

				  return 0;
}
