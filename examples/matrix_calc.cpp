#include <Matrix.hpp>

/* Example program

Read csv files to get a Matrix object.
Slice the Matrix objects such that inverse is possible.
The inverse is then calculated and printed.
*/
int main() {
    Matrix mat = read_csv("./datasets/boston/boston.csv");

    // Calculating inverse of a Matrix object
    Matrix sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());
    sliced_mat.to_double();

    std::cout << std::endl;

    Matrix sum_r = matrix.sum(sliced_mat, "row");
    sum_r.print();

    std::cout << std::endl;

    Matrix sum_c = matrix.sum(sliced_mat, "column");
    sum_c.print();

    std::cout << std::endl;

    Matrix mean_r = matrix.mean(sliced_mat, "row");
    mean_r.print();

    std::cout << std::endl;

    Matrix mean_c = matrix.mean(sliced_mat, "column");
    mean_c.print();

    std::cout << std::endl;

    Matrix std_r = matrix.std(sliced_mat, "row");
    std_r.print();

    std::cout << std::endl;

    Matrix std_c = matrix.std(sliced_mat, "column");
    std_c.print();

    return 0;
}