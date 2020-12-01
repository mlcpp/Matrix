#include <Matrix.hpp>

/* Example program

Read a csv file and get a Matrix object.
Print a part of the Matrix object in the different ways:

1. Using head() method - Prints the first 5 rows of the Matrix object
2. Using tail() method - Prints the last 5 rows of the Matrix object
3. Using view() method - Prints the rows and columns given in the parameters
*/
int main() {
    Matrix mat = genfromtxt("./datasets/boston/boston.csv", ',');

    // Using head() method
    mat.head();

    std::cout << std::endl << std::endl;

    // Using tail() method
    mat.tail();

    std::cout << std::endl << std::endl;

    // Using view() method print a single cell
    mat.view(3, 5);

    std::cout << std::endl << std::endl;

    // Using view() method print a range of rows and columns
    mat.view(2, 6, 1, 4);

    return 0;
}