#include <Matrix.hpp>

/* Example program

Read csv files to get a Matrix object.
Slice the Matrix object and convert it to double.
The indexing can then be performed.
*/
int main() {
    Matrix mat = read_csv("./datasets/boston/boston.csv");
    Matrix sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());
    sliced_mat.to_double();

    // The value of a particular index can be get as double
    double val = sliced_mat(1, 2);
    std::cout << val << std::endl;

    // The value can be assigned to a particular index
    sliced_mat(1, 2) = 5;
    std::cout << sliced_mat(1, 2) << std::endl;

    // An index value can also be printed using the view() method
    sliced_mat.view(1, 2);
    return 0;
}