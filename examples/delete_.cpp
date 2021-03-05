#include <Matrix.hpp>

/* Example program

Read a csv file and get a Matrix object.
Delete a row and delete a column.
*/
int main() {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./examples/datasets/dataset1.csv", ',');

    // Deleting a row
    Matrix<std::string> delr = matrix.delete_(mat, 2, "row");
    delr.print();

    std::cout << std::endl;

    // Deleting a row
    Matrix<std::string> delc = matrix.delete_(mat, 1, "column");
    delc.print();

    return 0;
}
