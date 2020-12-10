#include <Matrix.hpp>

/* Example program

Read a csv file and get a Matrix object.
Delete a row and delete a column.
*/
int main() {
    Matrix mat = matrix.genfromtxt("./datasets/boston/boston.csv",',');

    // Deleting a row
    Matrix delr = matrix.delete_(mat, 2, "row");
    delr.print();

    std::cout << std::endl;

    // Deleting a row
    Matrix delc = matrix.delete_(mat, 1, "column");
    delc.print();

    return 0;
}
