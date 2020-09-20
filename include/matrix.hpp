#ifndef _matrix_hpp_
#define _matrix_hpp_

#include <all.h>

class Matrix {
  private:
    std::vector<std::vector<double>> dob_mat;

    Matrix scalar_to_mat(int);
    Matrix vector_to_mat(Matrix);

  public:
    std::vector<std::vector<std::string>> str_mat;

    // Member functions
    std::vector<std::vector<double>> get();
    std::vector<double> get_row(int);
    std::vector<double> get_col(int);
    int col_length();
    int row_length();
    void print();
    void head();
    void tail();
    void view(int, int);
    void view(int, int, int, int);
    Matrix slice(int, int, int, int);
    Matrix T();
    void to_double();

    // Overloaded Operators
    Matrix operator+(Matrix);
    Matrix operator+(int);
    Matrix operator-(Matrix);
    Matrix operator-(int);
    Matrix operator*(Matrix);
    Matrix operator*(int);
    Matrix operator/(Matrix);
    Matrix operator/(int);
};

// Method to return the matrix in the form of vector
std::vector<std::vector<double>> Matrix::get() {
    bool error = !dob_mat.empty();
    if (!error)
        assert(("The Matrix should be first converted to double using to_double() method", error));
    return dob_mat;
}

// Method to return a row of the matrix in the form of a vector
std::vector<double> Matrix::get_row(int row) {
    bool error = !dob_mat.empty();
    if (!error)
        assert(("The Matrix should be first converted to double using to_double() method", error));

    std::vector<double> row_vec;
    for (int i = 0; i < col_length(); i++)
        row_vec.push_back(dob_mat[row][i]);
    return row_vec;
}

// Method to return a column of the matrix in the form of a vector
std::vector<double> Matrix::get_col(int col) {
    bool error = !dob_mat.empty();
    if (!error)
        assert(("The Matrix should be first converted to double using to_double() method", error));

    std::vector<double> col_vec;
    for (int i = 0; i < row_length(); i++)
        col_vec.push_back(dob_mat[i][col]);
    return col_vec;
}

// Method to return the number of columns
int Matrix::col_length() { return str_mat[0].size(); }

// Method to return the number of rows
int Matrix::row_length() { return str_mat.size(); }

// Method to print a Matrix object
void Matrix::print() {
    for (int i = 0; i < str_mat.size(); i++) {
        for (int j = 0; j < str_mat[i].size(); j++)
            std::cout << str_mat[i][j] << "\t";
        std::cout << std::endl;
    }
}

// Method to print a single cell (row, col) of a Matrix object
void Matrix::view(int row, int col) { std::cout << str_mat[row][col] << std::endl; }

// Method to print a range of rows and columns of a Matrix object
void Matrix::view(int row_start, int row_end, int col_start, int col_end) {
    for (int i = row_start; i < row_end; i++) {
        for (int j = col_start; j < col_end; j++)
            std::cout << str_mat[i][j] << "\t";
        std::cout << std::endl;
    }
}

// Method to print first 5 rows of a Matrix object
void Matrix::head() {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < str_mat[i].size(); j++)
            std::cout << str_mat[i][j] << "\t";
        std::cout << std::endl;
    }
}

// Method to print last 5 rows of a Matrix object
void Matrix::tail() {
    for (int i = str_mat.size() - 5; i < str_mat.size(); i++) {
        for (int j = 0; j < str_mat[i].size(); j++)
            std::cout << str_mat[i][j] << "\t";
        std::cout << std::endl;
    }
}

/* Method to slice a Matrix object
   The method will return a Matrix object whose dimensions will be (row_end-row_start,
   col_end-col_start)
*/
Matrix Matrix::slice(int row_start, int row_end, int col_start, int col_end) {
    Matrix mat;
    std::vector<std::string> row;

    for (int i = row_start; i < row_end; i++) {
        for (int j = col_start; j < col_end; j++)
            row.push_back(str_mat[i][j]);
        mat.str_mat.push_back(row);
        row.clear();
    }
    if (!dob_mat.empty()) {
        mat.to_double();
    }

    return mat;
}

/* Method to return the Tranpose of a Matrix
   The method will return a Matrix object whose dimensions will be (col_length(), row_length())
*/
Matrix Matrix::T() {
    Matrix mat;
    std::vector<std::string> row;

    for (int i = 0; i < col_length(); i++) {
        for (int j = 0; j < row_length(); j++)
            row.push_back(str_mat[j][i]);
        mat.str_mat.push_back(row);
        row.clear();
    }
    if (!dob_mat.empty()) {
        mat.to_double();
    }

    return mat;
}

// Method convert the elements of a Matrix from std::string to double
void Matrix::to_double() {
    std::vector<double> row;
    dob_mat.clear();
    for (int i = 0; i < str_mat.size(); i++) {
        for (int j = 0; j < str_mat[i].size(); j++)
            row.push_back(std::stod(str_mat[i][j]));
        dob_mat.push_back(row);
        row.clear();
    }
}

// Operator overloading functions

Matrix Matrix::operator+(Matrix mat) {
    bool error1 = ((!dob_mat.empty()) && (!mat.dob_mat.empty()));
    if (!error1)
        assert(("The Matrix objects should be first converted to double using to_double() method",
                error1));

    if ((row_length() == mat.row_length()) && (col_length() == mat.col_length())) {
        Matrix result;
        std::vector<std::string> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(std::to_string(dob_mat[i][j] + mat.dob_mat[i][j]));
            result.str_mat.push_back(row);
            row.clear();
        }
        result.to_double();
        return result;
    } else if ((row_length() == mat.row_length()) && (mat.col_length() == 1)) {
        mat = vector_to_mat(mat);
        Matrix result;
        std::vector<std::string> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(std::to_string(dob_mat[i][j] + mat.dob_mat[i][j]));
            result.str_mat.push_back(row);
            row.clear();
        }
        result.to_double();
        return result;
    } else if ((col_length() == mat.col_length()) && (mat.row_length() == 1)) {
        mat = vector_to_mat(mat);
        Matrix result;
        std::vector<std::string> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(std::to_string(dob_mat[i][j] + mat.dob_mat[i][j]));
            result.str_mat.push_back(row);
            row.clear();
        }
        result.to_double();
        return result;
    } else {
        assert(("The Matrix objects should be of compatible dimensions", false));
    }
}

Matrix Matrix::operator+(int val) {
    bool error = !dob_mat.empty();
    if (!error)
        assert(("The Matrix should be first converted to double using to_double() method", error));

    Matrix mat_val = scalar_to_mat(val);

    Matrix result;
    std::vector<std::string> row;

    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            row.push_back(std::to_string(dob_mat[i][j] + mat_val.dob_mat[i][j]));
        result.str_mat.push_back(row);
        row.clear();
    }
    result.to_double();
    return result;
}

Matrix Matrix::operator-(Matrix mat) {
    bool error1 = ((!dob_mat.empty()) && (!mat.dob_mat.empty()));
    if (!error1)
        assert(("The Matrix objects should be first converted to double using to_double() method",
                error1));

    if ((row_length() == mat.row_length()) && (col_length() == mat.col_length())) {
        Matrix result;
        std::vector<std::string> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(std::to_string(dob_mat[i][j] - mat.dob_mat[i][j]));
            result.str_mat.push_back(row);
            row.clear();
        }
        result.to_double();
        return result;
    } else if ((row_length() == mat.row_length()) && (mat.col_length() == 1)) {
        mat = vector_to_mat(mat);
        Matrix result;
        std::vector<std::string> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(std::to_string(dob_mat[i][j] - mat.dob_mat[i][j]));
            result.str_mat.push_back(row);
            row.clear();
        }
        result.to_double();
        return result;
    } else if ((col_length() == mat.col_length()) && (mat.row_length() == 1)) {
        mat = vector_to_mat(mat);
        Matrix result;
        std::vector<std::string> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(std::to_string(dob_mat[i][j] - mat.dob_mat[i][j]));
            result.str_mat.push_back(row);
            row.clear();
        }
        result.to_double();
        return result;
    } else {
        assert(("The Matrix objects should be of compatible dimensions", false));
    }
}

Matrix Matrix::operator-(int val) {
    bool error = !dob_mat.empty();
    if (!error)
        assert(("The Matrix should be first converted to double using to_double() method", error));

    Matrix mat_val = scalar_to_mat(val);

    Matrix result;
    std::vector<std::string> row;

    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            row.push_back(std::to_string(dob_mat[i][j] - mat_val.dob_mat[i][j]));
        result.str_mat.push_back(row);
        row.clear();
    }
    result.to_double();
    return result;
}

Matrix Matrix::operator*(Matrix mat) {
    bool error1 = ((!dob_mat.empty()) && (!mat.dob_mat.empty()));
    if (!error1)
        assert(("The Matrix objects should be first converted to double using to_double() method",
                error1));

    if ((row_length() == mat.row_length()) && (col_length() == mat.col_length())) {
        Matrix result;
        std::vector<std::string> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(std::to_string(dob_mat[i][j] * mat.dob_mat[i][j]));
            result.str_mat.push_back(row);
            row.clear();
        }
        result.to_double();
        return result;
    } else if ((row_length() == mat.row_length()) && (mat.col_length() == 1)) {
        mat = vector_to_mat(mat);
        Matrix result;
        std::vector<std::string> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(std::to_string(dob_mat[i][j] * mat.dob_mat[i][j]));
            result.str_mat.push_back(row);
            row.clear();
        }
        result.to_double();
        return result;
    } else if ((col_length() == mat.col_length()) && (mat.row_length() == 1)) {
        mat = vector_to_mat(mat);
        Matrix result;
        std::vector<std::string> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(std::to_string(dob_mat[i][j] * mat.dob_mat[i][j]));
            result.str_mat.push_back(row);
            row.clear();
        }
        result.to_double();
        return result;
    } else {
        assert(("The Matrix objects should be of compatible dimensions", false));
    }
}

Matrix Matrix::operator*(int val) {
    bool error = !dob_mat.empty();
    if (!error)
        assert(("The Matrix should be first converted to double using to_double() method", error));

    Matrix mat_val = scalar_to_mat(val);

    Matrix result;
    std::vector<std::string> row;

    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            row.push_back(std::to_string(dob_mat[i][j] * mat_val.dob_mat[i][j]));
        result.str_mat.push_back(row);
        row.clear();
    }
    result.to_double();
    return result;
}

Matrix Matrix::operator/(Matrix mat) {
    bool error1 = ((!dob_mat.empty()) && (!mat.dob_mat.empty()));
    if (!error1)
        assert(("The Matrix objects should be first converted to double using to_double() method",
                error1));

    if ((row_length() == mat.row_length()) && (col_length() == mat.col_length())) {
        Matrix result;
        std::vector<std::string> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(std::to_string(dob_mat[i][j] / mat.dob_mat[i][j]));
            result.str_mat.push_back(row);
            row.clear();
        }
        result.to_double();
        return result;
    } else if ((row_length() == mat.row_length()) && (mat.col_length() == 1)) {
        mat = vector_to_mat(mat);
        Matrix result;
        std::vector<std::string> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(std::to_string(dob_mat[i][j] / mat.dob_mat[i][j]));
            result.str_mat.push_back(row);
            row.clear();
        }
        result.to_double();
        return result;
    } else if ((col_length() == mat.col_length()) && (mat.row_length() == 1)) {
        mat = vector_to_mat(mat);
        Matrix result;
        std::vector<std::string> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(std::to_string(dob_mat[i][j] / mat.dob_mat[i][j]));
            result.str_mat.push_back(row);
            row.clear();
        }
        result.to_double();
        return result;
    } else {
        assert(("The Matrix objects should be of compatible dimensions", false));
    }
}

Matrix Matrix::operator/(int val) {
    bool error = !dob_mat.empty();
    if (!error)
        assert(("The Matrix should be first converted to double using to_double() method", error));

    Matrix mat_val = scalar_to_mat(val);

    Matrix result;
    std::vector<std::string> row;

    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            row.push_back(std::to_string(dob_mat[i][j] / mat_val.dob_mat[i][j]));
        result.str_mat.push_back(row);
        row.clear();
    }
    result.to_double();
    return result;
}

// Helper functions

Matrix Matrix::scalar_to_mat(int val) {
    Matrix result;

    std::vector<std::string> row(col_length(), std::to_string(val));
    std::vector<std::vector<std::string>> mat(row_length(), row);
    result.str_mat = mat;
    result.to_double();
    return result;
}

Matrix Matrix::vector_to_mat(Matrix vec) {
    Matrix result;
    std::vector<std::string> row;
    if (row_length() == vec.row_length()) {
        for (int i = 0; i < row_length(); i++) {
            row.assign(col_length(), vec.str_mat[i][0]);
            result.str_mat.push_back(row);
            row.clear();
        }
    } else if (col_length() == vec.col_length()) {
        for (int i = 0; i < row_length(); i++) {
            result.str_mat.push_back(vec.str_mat[0]);
        }
    }
    result.to_double();
    return result;
}

#endif /* _matrix_hpp_ */