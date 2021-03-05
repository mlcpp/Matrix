#include <Matrix.hpp>

/* Example program

Read csv files to get a Matrix object.
The indexing can then be performed.
*/
int main() {
    Matrix<int> mat = matrix.genfromtxt<int>("./examples/datasets/dataset0.csv", ',');

    // The value of a particular index can be get as double
    double val = mat(1, 2);
    std::cout << val << std::endl;

    std::cout << std::endl;

    // The value can be assigned to a particular index
    mat(1, 2) = 5;
    mat.print();

    return 0;
}
