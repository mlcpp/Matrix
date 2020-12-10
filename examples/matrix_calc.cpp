#include <Matrix.hpp>

/* Example program

Read csv files to get a Matrix object.
Slice the Matrix object according to our needs.
Then we can calculate the respective values of sum, mean and std.
*/
int main() {
    Matrix mat = genfromtxt("./datasets/boston/boston.csv",',');

    Matrix sliced_mat = mat.slice(1, 6, 2, 5);
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
