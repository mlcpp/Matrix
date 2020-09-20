#include <matrix.hpp>
#include <matrix_read.hpp>

/* Example program

Read a csv file and get a Matrix object
The Matrix object is then printed to the console.
*/
int main() {
    Matrix mat = read_csv("./datasets/boston/boston.csv");
    mat.print();

    return 0;
}