#include <Matrix.hpp>
#include <iostream>

/* Example program

Read a csv file and get a Matrix object.
Print a part of the Matrix object or the full Matrix object in the different ways:

1. Using head() method - Prints the first 5 rows of the Matrix object
2. Using tail() method - Prints the last 5 rows of the Matrix object
3. Using view() method - Prints the rows and columns given in the parameters
4. Using print() method - Prints the whole Matrix object
5. Using std::cout - Prints the whole Matrix object
*/
int main() {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./examples/datasets/dataset1.csv", ',');

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

    std::cout << std::endl << std::endl;

    // Using print() method to print whole Matrix object
    mat.print();

    std::cout << std::endl << std::endl;

    // Using std::cout
    std::cout << mat;

    return 0;
}
