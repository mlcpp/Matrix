#include <Matrix.hpp>

/* Example program

Read a csv file and get a Matrix object.
This Matrix object is then get as a std::vector object:

1. For a row
2. For a column
3. Full Matrix
*/
int main() {
    Matrix<std::string> mat =
        matrix.genfromtxt<std::string>("./examples/datasets/dataset0.csv", ',');

    // Getting a vector of rows
    std::vector<std::string> row_2 = mat.get_row(1);
    for (int i = 0; i < row_2.size(); i++)
        std::cout << row_2[i] << "\t";
    std::cout << std::endl;

    std::cout << std::endl;

    // Getting a vector of columns
    std::vector<std::string> col_3 = mat.get_col(3);
    for (int i = 0; i < col_3.size(); i++)
        std::cout << col_3[i] << "\t";
    std::cout << std::endl;

    std::cout << std::endl;

    // Getting the Matrix object as a vector
    std::vector<std::vector<std::string>> vec_mat = mat.get();
    for (int i = 0; i < vec_mat.size(); i++) {
        for (int j = 0; j < vec_mat[i].size(); j++)
            std::cout << vec_mat[i][j] << "\t";
        std::cout << std::endl;
    }

    return 0;
}
