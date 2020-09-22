#ifndef _matrix_hpp_
#define _matrix_hpp_

#include <all.hpp>

class Matrix {
  private:
    Matrix scalar_to_mat(double);
    Matrix vector_to_mat(Matrix);
    Matrix cofactor(Matrix, int, int);
    Matrix adjoint();

  public:
    std::vector<std::vector<double>> double_mat;
    std::vector<std::vector<std::string>> str_mat;
    bool if_double = false;

    // Member functions
    void init(std::vector<std::vector<double>>);
    void init(std::vector<std::vector<std::string>>);
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
    double determinant(int);
    Matrix inverse();
    void to_double();
    void to_string();
    void zeros(int, int);
    void ones(int, int);
    void eye(int);

    // Overloaded Operators
    Matrix operator+(Matrix);
    Matrix operator+(double);
    Matrix operator-(Matrix);
    Matrix operator-(double);
    Matrix operator*(Matrix);
    Matrix operator*(double);
    Matrix operator/(Matrix);
    Matrix operator/(double);
    double &operator()(int, int);
};

// Method to initialize values of a Matrix object using a 2D vector
void Matrix::init(std::vector<std::vector<double>> vec) {
    double_mat = vec;
    to_string();
}

// Method to initialize values of a Matrix object using a 2D vector
void Matrix::init(std::vector<std::vector<std::string>> vec) {
    str_mat = vec;
    to_double();
}

// Method to return the matrix in the form of vector
std::vector<std::vector<double>> Matrix::get() {
    bool error = if_double;
    if (!error)
        assert(("The Matrix should be first converted to double using to_double() method", error));
    return double_mat;
}

// Method to return a row of the matrix in the form of a vector
std::vector<double> Matrix::get_row(int row) {
    bool error = if_double;
    if (!error)
        assert(("The Matrix should be first converted to double using to_double() method", error));

    std::vector<double> row_vec;
    for (int i = 0; i < col_length(); i++)
        row_vec.push_back(double_mat[row][i]);
    return row_vec;
}

// Method to return a column of the matrix in the form of a vector
std::vector<double> Matrix::get_col(int col) {
    bool error = if_double;
    if (!error)
        assert(("The Matrix should be first converted to double using to_double() method", error));

    std::vector<double> col_vec;
    for (int i = 0; i < row_length(); i++)
        col_vec.push_back(double_mat[i][col]);
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
    if (if_double) {
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
    if (if_double) {
        mat.to_double();
    }

    return mat;
}

// Method convert the elements of a Matrix from std::string to double
void Matrix::to_double() {
    std::vector<double> row;
    double_mat.clear();
    for (int i = 0; i < str_mat.size(); i++) {
        for (int j = 0; j < str_mat[i].size(); j++)
            row.push_back(std::stod(str_mat[i][j]));
        double_mat.push_back(row);
        row.clear();
    }
    if_double = true;
}

// Method convert the elements of a Matrix from double to std::string
void Matrix::to_string() {
    std::vector<std::string> row;
    str_mat.clear();
    for (int i = 0; i < double_mat.size(); i++) {
        for (int j = 0; j < double_mat[i].size(); j++)
            row.push_back(std::to_string(double_mat[i][j]));
        str_mat.push_back(row);
        row.clear();
    }
    if_double = true;
}

// Method to calculate the Determinant of a Matrix
double Matrix::determinant(int n) {
    if (row_length() != col_length())
        assert(("The Matrix must be a square matrix", false));

    double D = 0;
    if (n == 1)
        return double_mat[0][0];

    Matrix temp;
    for (int i = 0; i < n; i++) {
        std::vector<double> row;
        for (int j = 0; j < n; j++) {
            row.push_back(0);
        }
        temp.double_mat.push_back(row);
    }
    temp.to_string();
    int sign = 1;
    for (int f = 0; f < n; f++) {
        temp = cofactor(temp, 0, f);
        D += sign * double_mat[0][f] * temp.determinant(n - 1);
        sign = -sign;
    }
    return D;
}

// Method to calculate the Inverse of a Matrix
Matrix Matrix::inverse() {
    if (row_length() != col_length())
        assert(("The Matrix must be a square matrix", false));
    double det = determinant(col_length());
    if (det == 0)
        assert(("The Matrix is singular", false));

    Matrix adj = adjoint();
    Matrix result = adj / det;
    return result;
}

// Method to create an Matrix of all elements 0
void Matrix::zeros(int row, int col) {
    std::vector<std::string> vec(col, std::to_string(0));
    std::vector<std::vector<std::string>> mat(row, vec);
    str_mat = mat;
    to_double();
}

// Method to create an Matrix of all elements 1
void Matrix::ones(int row, int col) {
    std::vector<std::string> vec(col, std::to_string(1));
    std::vector<std::vector<std::string>> mat(row, vec);
    str_mat = mat;
    to_double();
}

// Method to create an identity Matrix
void Matrix::eye(int size) {
    zeros(size, size);
    for (int i = 0; i < size; i++) {
        str_mat[i][i] = "1";
        double_mat[i][i] = 1;
    }
}

// Operator overloading functions

Matrix Matrix::operator+(Matrix mat) {
    bool error1 = ((if_double) && (mat.if_double));
    if (!error1)
        assert(("The Matrix objects should be first converted to double using to_double() method",
                error1));

    if ((row_length() == mat.row_length()) && (col_length() == mat.col_length())) {
        Matrix result;
        std::vector<std::string> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(std::to_string(double_mat[i][j] + mat.double_mat[i][j]));
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
                row.push_back(std::to_string(double_mat[i][j] + mat.double_mat[i][j]));
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
                row.push_back(std::to_string(double_mat[i][j] + mat.double_mat[i][j]));
            result.str_mat.push_back(row);
            row.clear();
        }
        result.to_double();
        return result;
    } else {
        assert(("The Matrix objects should be of compatible dimensions", false));
    }
}

Matrix Matrix::operator+(double val) {
    bool error = if_double;
    if (!error)
        assert(("The Matrix should be first converted to double using to_double() method", error));

    Matrix mat_val = scalar_to_mat(val);

    Matrix result;
    std::vector<std::string> row;

    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            row.push_back(std::to_string(double_mat[i][j] + mat_val.double_mat[i][j]));
        result.str_mat.push_back(row);
        row.clear();
    }
    result.to_double();
    return result;
}

Matrix Matrix::operator-(Matrix mat) {
    bool error1 = ((if_double) && (mat.if_double));
    if (!error1)
        assert(("The Matrix objects should be first converted to double using to_double() method",
                error1));

    if ((row_length() == mat.row_length()) && (col_length() == mat.col_length())) {
        Matrix result;
        std::vector<std::string> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(std::to_string(double_mat[i][j] - mat.double_mat[i][j]));
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
                row.push_back(std::to_string(double_mat[i][j] - mat.double_mat[i][j]));
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
                row.push_back(std::to_string(double_mat[i][j] - mat.double_mat[i][j]));
            result.str_mat.push_back(row);
            row.clear();
        }
        result.to_double();
        return result;
    } else {
        assert(("The Matrix objects should be of compatible dimensions", false));
    }
}

Matrix Matrix::operator-(double val) {
    bool error = if_double;
    if (!error)
        assert(("The Matrix should be first converted to double using to_double() method", error));

    Matrix mat_val = scalar_to_mat(val);

    Matrix result;
    std::vector<std::string> row;

    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            row.push_back(std::to_string(double_mat[i][j] - mat_val.double_mat[i][j]));
        result.str_mat.push_back(row);
        row.clear();
    }
    result.to_double();
    return result;
}

Matrix Matrix::operator*(Matrix mat) {
    bool error1 = ((if_double) && (mat.if_double));
    if (!error1)
        assert(("The Matrix objects should be first converted to double using to_double() method",
                error1));

    if ((row_length() == mat.row_length()) && (col_length() == mat.col_length())) {
        Matrix result;
        std::vector<std::string> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(std::to_string(double_mat[i][j] * mat.double_mat[i][j]));
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
                row.push_back(std::to_string(double_mat[i][j] * mat.double_mat[i][j]));
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
                row.push_back(std::to_string(double_mat[i][j] * mat.double_mat[i][j]));
            result.str_mat.push_back(row);
            row.clear();
        }
        result.to_double();
        return result;
    } else {
        assert(("The Matrix objects should be of compatible dimensions", false));
    }
}

Matrix Matrix::operator*(double val) {
    bool error = if_double;
    if (!error)
        assert(("The Matrix should be first converted to double using to_double() method", error));

    Matrix mat_val = scalar_to_mat(val);

    Matrix result;
    std::vector<std::string> row;

    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            row.push_back(std::to_string(double_mat[i][j] * mat_val.double_mat[i][j]));
        result.str_mat.push_back(row);
        row.clear();
    }
    result.to_double();
    return result;
}

Matrix Matrix::operator/(Matrix mat) {
    bool error1 = ((if_double) && (mat.if_double));
    if (!error1)
        assert(("The Matrix objects should be first converted to double using to_double() method",
                error1));

    if ((row_length() == mat.row_length()) && (col_length() == mat.col_length())) {
        Matrix result;
        std::vector<std::string> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(std::to_string(double_mat[i][j] / mat.double_mat[i][j]));
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
                row.push_back(std::to_string(double_mat[i][j] / mat.double_mat[i][j]));
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
                row.push_back(std::to_string(double_mat[i][j] / mat.double_mat[i][j]));
            result.str_mat.push_back(row);
            row.clear();
        }
        result.to_double();
        return result;
    } else {
        assert(("The Matrix objects should be of compatible dimensions", false));
    }
}

Matrix Matrix::operator/(double val) {
    bool error = if_double;
    if (!error)
        assert(("The Matrix should be first converted to double using to_double() method", error));

    Matrix mat_val = scalar_to_mat(val);

    Matrix result;
    std::vector<std::string> row;

    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            row.push_back(std::to_string(double_mat[i][j] / mat_val.double_mat[i][j]));
        result.str_mat.push_back(row);
        row.clear();
    }
    result.to_double();
    return result;
}

double &Matrix::operator()(int row, int col) {
    bool error1 = if_double;
    if (!error1)
        assert(("The Matrix should be first converted to double using to_double() method", error1));
    bool error2 = (((row >= 0) && (row < row_length())) && ((col >= 0) && (col < col_length())));
    if (!error2)
        assert(("Index is out of range", false));

    to_string();
    return double_mat[row][col];
}

// Helper methods

Matrix Matrix::scalar_to_mat(double val) {
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

// Helper method to calculate cofactor
Matrix Matrix::cofactor(Matrix temp, int p, int q) {
    int i = 0, j = 0;
    for (int row = 0; row < row_length(); row++) {
        for (int col = 0; col < col_length(); col++) {
            if (row != p && col != q) {
                temp.double_mat[i][j++] = double_mat[row][col];
                if (j == col_length() - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }
    temp.to_string();
    return temp;
}

// Helper method to calculate the Adjoint of a Matrix
Matrix Matrix::adjoint() {
    Matrix result;
    for (int i = 0; i < row_length(); i++) {
        std::vector<double> row;
        for (int j = 0; j < col_length(); j++) {
            row.push_back(0);
        }
        result.double_mat.push_back(row);
    }
    if (col_length() == 1) {
        result.double_mat[0][0] = 1;
        result.to_string();
        return result;
    }

    int sign = 1;
    Matrix temp;
    for (int i = 0; i < row_length(); i++) {
        std::vector<double> row;
        for (int j = 0; j < col_length(); j++) {
            row.push_back(0);
        }
        temp.double_mat.push_back(row);
    }
    temp.to_string();
    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++) {
            temp = cofactor(temp, i, j);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            result.double_mat[j][i] = (sign) * (temp.determinant(temp.col_length() - 1));
        }
    }
    result.to_string();
    return result;
}

#endif /* _matrix_hpp_ */