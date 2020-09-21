#include <Matrix.hpp>

/* Example program

Read a csv file and get a Matrix object.
Slice the Matrix object to remove the rows and columns which cannot be converted to double.
The sliced Matrix object is then converted to double.

This Matrix object is then get as a std::vector object:

1. For a row
2. For a column
3. Full Matrix
*/
int main() {
    Matrix mat = read_csv("./datasets/boston/boston.csv");
    Matrix sliced_mat = mat.slice(1, mat.row_length(), 0, mat.col_length());
    sliced_mat.to_double();

    // Getting a vector of rows
    std::vector<double> row_2 = sliced_mat.get_row(2);
    for (int i = 0; i < row_2.size(); i++)
        std::cout << row_2[i] << "\t";
    std::cout << std::endl;

    // Getting a vector of columns
    std::vector<double> col_3 = sliced_mat.get_col(3);
    for (int i = 0; i < col_3.size(); i++)
        std::cout << col_3[i] << "\t";
    std::cout << std::endl;

    // Getting the Matrix object as a vector
    std::vector<std::vector<double>> vec_mat = sliced_mat.get();
    for (int i = 0; i < vec_mat.size(); i++) {
        for (int j = 0; j < vec_mat[i].size(); j++)
            std::cout << vec_mat[i][j] << "\t";
        std::cout << std::endl;
    }

    return 0;
}