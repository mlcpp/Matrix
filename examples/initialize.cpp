#include <Matrix.hpp>

/* Example program

Create a Matrix object in five ways.

1. Passing a 2D vector of double values.
2. Passing a 2D vector of std::string values.
3. Using eye() to create an Identity Matrix.
4. Using zeros() to create a Matrix of all elements 0.
5. Using ones() to create a Matrix of all elements 1.

*/
int main() {
    // Using a 2D vector of double values
    std::vector<double> row_d(4, 6.786);
    std::vector<std::vector<double>> vec_d(6, row_d);
    Matrix mat_d = matrix.init(vec_d);
    mat_d.print();

    std::cout << std::endl;

    // Using a 2D vector of std::string values
    std::vector<std::string> row_s(3, "10");
    std::vector<std::vector<std::string>> vec_s(5, row_s);
    Matrix mat_s = matrix.init(vec_s);
    mat_s.print();

    std::cout << std::endl;

    // Using eye() method
    Matrix I = matrix.eye(4);
    I.print();

    std::cout << std::endl;

    // Using zeros() method
    Matrix O = matrix.zeros(3, 4);
    O.print();

    std::cout << std::endl;

    // Using ones() method
    Matrix one = matrix.ones(3, 2);
    one.print();

    return 0;
}