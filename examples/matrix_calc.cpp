#include <Matrix.hpp>

/* Example program

Read csv files to get a Matrix object.
Then we can calculate the respective values of sum, mean and std.
*/
int main() {
    Matrix<float> mat = matrix.genfromtxt<float>("./examples/datasets/dataset1.csv", ',');

    Matrix<float> sum_r = matrix.sum(mat, "row");
    sum_r.print();

    std::cout << std::endl;

    Matrix<float> sum_c = matrix.sum(mat, "column");
    sum_c.print();

    std::cout << std::endl;

    Matrix<float> mean_r = matrix.mean(mat, "row");
    mean_r.print();

    std::cout << std::endl;

    Matrix<float> mean_c = matrix.mean(mat, "column");
    mean_c.print();

    std::cout << std::endl;

    Matrix<float> std_r = matrix.std(mat, "row");
    std_r.print();

    std::cout << std::endl;

    Matrix<float> std_c = matrix.std(mat, "column");
    std_c.print();

    return 0;
}
