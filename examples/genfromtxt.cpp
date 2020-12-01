#include <Matrix.hpp>

/* Example program

Read a text file and get a Matrix object
The Matrix object is then printed to the console.
*/
int main() {
    Matrix mat = genfromtxt("./datasets/boston/boston.csv", ',');
    mat.print();

    return 0;
}