#include <Matrix.hpp>

/* Example program

Read a csv file and get a Matrix object.
Delete a row and delete a column.
*/
int main() {
    Matrix mat = read_csv("./datasets/boston/boston.csv");

    // Deleting a row
    Matrix delr = matrix.del(mat, 2, "row");
    delr.print();

    std::cout << std::endl;

    // Deleting a row
    Matrix delc = matrix.del(mat, 1, "column");
    delc.print();

    return 0;
}