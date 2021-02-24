#include <Matrix.hpp>

/* Example program

Read a csv file and get a Matrix object
The Matrix object is then printed to the console.
*/
int main() {
    Matrix<int> mat_int = matrix.genfromtxt<int>("./examples/datasets/dataset0.csv", ',');
    mat_int.print();

    std::cout << std::endl;

    Matrix<double> mat_double = matrix.genfromtxt<double>("./examples/datasets/dataset1.csv", ',');
    mat_double.print();

    return 0;
}
