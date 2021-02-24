#include <Matrix.hpp>
#include <iostream>

/* Example program

Create a Matrix object in different ways.

1. Passing a double value.
2. Passing a std::string value.
3. Passing a 1D vector of double values.
4. Passing a 1D vector of std::string values.
5. Passing a 2D vector of double values.
6. Passing a 2D vector of std::string values.
7. Using eye() to create an Identity Matrix.
8. Using zeros() to create a Matrix of all elements 0.
9. Using ones() to create a Matrix of all elements 1.
10. Using std::cin

*/
int main() {
    // Using a double value
    double val_d = 6.786;
    Matrix<double> mat_d1 = matrix.init(val_d);
    mat_d1.print();

    std::cout << std::endl;

    // Using a std::string value
    std::string val_s = "10";
    Matrix<std::string> mat_s1 = matrix.init(val_s);
    mat_s1.print();

    std::cout << std::endl;

    // Using a 1D vector of double values
    std::vector<double> row_d(4, 6.786);
    Matrix<double> mat_d2 = matrix.init(row_d);
    mat_d2.print();

    std::cout << std::endl;

    // Using a 1D vector of std::string values
    std::vector<std::string> row_s(3, "10");
    Matrix<std::string> mat_s2 = matrix.init(row_s);
    mat_s2.print();

    std::cout << std::endl;

    // Using a 2D vector of double values
    std::vector<std::vector<double>> vec_d(6, row_d);
    Matrix<double> mat_d3 = matrix.init<double>(vec_d);
    mat_d3.print();

    std::cout << std::endl;

    // Using a 2D vector of std::string values
    std::vector<std::vector<std::string>> vec_s(5, row_s);
    Matrix<std::string> mat_s3 = matrix.init(vec_s);
    mat_s3.print();

    std::cout << std::endl;

    // Using eye() method
    Matrix<char> I = matrix.eye<char>(4);
    I.print();

    std::cout << std::endl;

    // Using zeros() method
    Matrix<int> O = matrix.zeros<int>(3, 4);
    O.print();

    std::cout << std::endl;

    // Using ones() method
    Matrix<std::string> one = matrix.ones<std::string>(3, 2);
    one.print();

    std::cout << std::endl;

    // Using std::cin
    Matrix<double> input;
    std::cin >> input;
    input.print();

    return 0;
}