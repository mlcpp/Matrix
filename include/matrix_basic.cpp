#include <matrix_basic.hpp>

/// Method to return the matrix in the form of vector
std::vector<std::vector<double>> Matrix::get() {
    bool error = if_double;
    if (!error)
        assert(("The Matrix should be first converted to double using to_double() method", error));
    return double_mat;
}

/// Method to return a row of the matrix in the form of a vector
std::vector<double> Matrix::get_row(int row) {
    bool error = if_double;
    if (!error)
        assert(("The Matrix should be first converted to double using to_double() method", error));

    bool is_within_range = (double_mat.size() >= row);
    if (!is_within_range) {
        assert(("The row parameter is out of bounds of the matrix size.", is_within_range));
    }

    std::vector<double> row_vec;
    for (int i = 0; i < col_length(); i++)
        row_vec.push_back(double_mat[row][i]);
    return row_vec;
}

/// Method to return a column of the matrix in the form of a vector
std::vector<double> Matrix::get_col(int col) {
    bool error = if_double;
    if (!error)
        assert(("The Matrix should be first converted to double using to_double() method", error));

    bool is_within_range = (double_mat[0].size() >= col);
    if (!is_within_range) {
        assert(("The col parameter is out of bounds of the matrix size.", is_within_range));
    }

    std::vector<double> col_vec;
    for (int i = 0; i < row_length(); i++)
        col_vec.push_back(double_mat[i][col]);
    return col_vec;
}

/// Method to return the number of columns
int Matrix::col_length() const { return str_mat[0].size(); }

/// Method to return the number of rows
int Matrix::row_length() const { return str_mat.size(); }

/// Method to print a Matrix object
void Matrix::print() {
    for (int i = 0; i < str_mat.size(); i++) {
        for (int j = 0; j < str_mat[i].size(); j++)
            std::cout << str_mat[i][j] << "\t";
        std::cout << std::endl;
    }
}

/// Method to print a single cell (row, col) of a Matrix object
void Matrix::view(int row, int col) { std::cout << str_mat[row][col] << std::endl; }

/// Method to print a range of rows and columns of a Matrix object
void Matrix::view(int row_start, int row_end, int col_start, int col_end) {
    bool is_within_range = (str_mat.size() >= row_end) && (str_mat[0].size() >= col_end);
    if (!is_within_range) {
        assert(("The slicing parameters are out of bounds of the matrix size.", is_within_range));
    }

    for (int i = row_start; i < row_end; i++) {
        for (int j = col_start; j < col_end; j++)
            std::cout << str_mat[i][j] << "\t";
        std::cout << std::endl;
    }
}

/// Method to print first 5 rows of a Matrix object
void Matrix::head() {
    int row = row_length() < 5 ? row_length() : 5;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < str_mat[i].size(); j++)
            std::cout << str_mat[i][j] << "\t";
        std::cout << std::endl;
    }
}

/// Method to print last 5 rows of a Matrix object
void Matrix::tail() {
    int row = row_length() < 5 ? row_length() : 5;
    for (int i = str_mat.size() - row; i < str_mat.size(); i++) {
        for (int j = 0; j < str_mat[i].size(); j++)
            std::cout << str_mat[i][j] << "\t";
        std::cout << std::endl;
    }
}

/** Method to slice a Matrix object
   The method will return a Matrix object whose dimensions will be (row_end-row_start,
   col_end-col_start)
*/
Matrix Matrix::slice(int row_start, int row_end, int col_start, int col_end) {
    bool is_within_range = (str_mat.size() >= row_end) && (str_mat[0].size() >= col_end);
    if (!is_within_range) {
        assert(("The slicing parameters are out of bounds of the matrix size.", is_within_range));
    }
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

/** Method to return the Tranpose of a Matrix
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

/// Method convert the elements of a Matrix from std::string to double
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

/// Method convert the elements of a Matrix from double to std::string
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

// Operator overloading functions

Matrix Matrix::operator+(Matrix mat) {
    bool error1 = ((if_double) && (mat.if_double));
    if (!error1)
        assert(("The Matrix objects should be first converted to double using to_double() method",
                error1));

    if ((row_length() == mat.row_length()) && (col_length() == mat.col_length())) {
        Matrix result;
        std::vector<double> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(double_mat[i][j] + mat.double_mat[i][j]);
            result.double_mat.push_back(row);
            row.clear();
        }
        result.to_string();
        return result;
    } else if ((row_length() == mat.row_length()) && (mat.col_length() == 1)) {
        Matrix result;
        std::vector<double> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(double_mat[i][j] + mat.double_mat[i][0]);
            result.double_mat.push_back(row);
            row.clear();
        }
        result.to_string();
        return result;
    } else if ((col_length() == mat.col_length()) && (mat.row_length() == 1)) {
        Matrix result;
        std::vector<double> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(double_mat[i][j] + mat.double_mat[0][j]);
            result.double_mat.push_back(row);
            row.clear();
        }
        result.to_string();
        return result;
    } else {
        assert(("The Matrix objects should be of compatible dimensions", false));
    }
}

Matrix Matrix::operator+(double val) {
    bool error = if_double;
    if (!error)
        assert(("The Matrix should be first converted to double using to_double() method", error));

    Matrix result;
    std::vector<double> row;

    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            row.push_back(double_mat[i][j] + val);
        result.double_mat.push_back(row);
        row.clear();
    }
    result.to_string();
    return result;
}

Matrix Matrix::operator-(Matrix mat) {
    bool error1 = ((if_double) && (mat.if_double));
    if (!error1)
        assert(("The Matrix objects should be first converted to double using to_double() method",
                error1));

    if ((row_length() == mat.row_length()) && (col_length() == mat.col_length())) {
        Matrix result;
        std::vector<double> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(double_mat[i][j] - mat.double_mat[i][j]);
            result.double_mat.push_back(row);
            row.clear();
        }
        result.to_string();
        return result;
    } else if ((row_length() == mat.row_length()) && (mat.col_length() == 1)) {
        Matrix result;
        std::vector<double> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(double_mat[i][j] - mat.double_mat[i][0]);
            result.double_mat.push_back(row);
            row.clear();
        }
        result.to_string();
        return result;
    } else if ((col_length() == mat.col_length()) && (mat.row_length() == 1)) {
        Matrix result;
        std::vector<double> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(double_mat[i][j] - mat.double_mat[0][j]);
            result.double_mat.push_back(row);
            row.clear();
        }
        result.to_string();
        return result;
    } else {
        assert(("The Matrix objects should be of compatible dimensions", false));
    }
}

Matrix Matrix::operator-(double val) {
    bool error = if_double;
    if (!error)
        assert(("The Matrix should be first converted to double using to_double() method", error));

    Matrix result;
    std::vector<double> row;

    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            row.push_back(double_mat[i][j] - val);
        result.double_mat.push_back(row);
        row.clear();
    }
    result.to_string();
    return result;
}

Matrix Matrix::operator*(Matrix mat) {
    bool error1 = ((if_double) && (mat.if_double));
    if (!error1)
        assert(("The Matrix objects should be first converted to double using to_double() method",
                error1));

    if ((row_length() == mat.row_length()) && (col_length() == mat.col_length())) {
        Matrix result;
        std::vector<double> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(double_mat[i][j] * mat.double_mat[i][j]);
            result.double_mat.push_back(row);
            row.clear();
        }
        result.to_string();
        return result;
    } else if ((row_length() == mat.row_length()) && (mat.col_length() == 1)) {
        Matrix result;
        std::vector<double> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(double_mat[i][j] * mat.double_mat[i][0]);
            result.double_mat.push_back(row);
            row.clear();
        }
        result.to_string();
        return result;
    } else if ((col_length() == mat.col_length()) && (mat.row_length() == 1)) {
        Matrix result;
        std::vector<double> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(double_mat[i][j] * mat.double_mat[0][j]);
            result.double_mat.push_back(row);
            row.clear();
        }
        result.to_string();
        return result;
    } else {
        assert(("The Matrix objects should be of compatible dimensions", false));
    }
}

Matrix Matrix::operator*(double val) {
    bool error = if_double;
    if (!error)
        assert(("The Matrix should be first converted to double using to_double() method", error));

    Matrix result;
    std::vector<double> row;

    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            row.push_back(double_mat[i][j] * val);
        result.double_mat.push_back(row);
        row.clear();
    }
    result.to_string();
    return result;
}

Matrix Matrix::operator/(Matrix mat) {
    bool error1 = ((if_double) && (mat.if_double));
    if (!error1)
        assert(("The Matrix objects should be first converted to double using to_double() method",
                error1));

    if ((row_length() == mat.row_length()) && (col_length() == mat.col_length())) {
        Matrix result;
        std::vector<double> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++) {
                double val;
                if (mat.double_mat[i][j] == 0)
                    val = std::numeric_limits<double>::infinity();
                else
                    val = double_mat[i][j] / mat.double_mat[i][j];
                row.push_back(val);
            }
            result.double_mat.push_back(row);
            row.clear();
        }
        result.to_string();
        return result;
    } else if ((row_length() == mat.row_length()) && (mat.col_length() == 1)) {
        Matrix result;
        std::vector<double> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++) {
                double val;
                if (mat.double_mat[i][0] == 0)
                    val = std::numeric_limits<double>::infinity();
                else
                    val = double_mat[i][j] / mat.double_mat[i][0];
                row.push_back(val);
            }
            result.double_mat.push_back(row);
            row.clear();
        }
        result.to_string();
        return result;
    } else if ((col_length() == mat.col_length()) && (mat.row_length() == 1)) {
        Matrix result;
        std::vector<double> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++) {
                double val;
                if (mat.double_mat[0][j] == 0)
                    val = std::numeric_limits<double>::infinity();
                else
                    val = double_mat[i][j] / mat.double_mat[0][j];
                row.push_back(val);
            }
            result.double_mat.push_back(row);
            row.clear();
        }
        result.to_string();
        return result;
    } else {
        assert(("The Matrix objects should be of compatible dimensions", false));
    }
}

Matrix Matrix::operator/(double val) {
    bool error = if_double;
    if (!error)
        assert(("The Matrix should be first converted to double using to_double() method", error));

    if (val == 0) {
        Matrix result;
        std::vector<double> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(std::numeric_limits<double>::infinity());
            result.double_mat.push_back(row);
            row.clear();
        }
        result.to_string();
        return result;
    }

    Matrix result;
    std::vector<double> row;

    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            row.push_back(double_mat[i][j] / val);
        result.double_mat.push_back(row);
        row.clear();
    }
    result.to_string();
    return result;
}

Matrix Matrix::operator-() {
    bool error1 = if_double;
    if (!error1)
        assert(("The Matrix should be first converted to double using to_double() method", error1));

    Matrix result;
    std::vector<double> row;

    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            row.push_back(-double_mat[i][j]);
        result.double_mat.push_back(row);
        row.clear();
    }
    result.to_string();
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

Matrix Matrix::operator+=(Matrix mat) {
    bool error1 = ((if_double) && (mat.if_double));
    if (!error1)
        assert(("The Matrix objects should be first converted to double using to_double() method",
                error1));

    if ((row_length() == mat.row_length()) && (col_length() == mat.col_length())) {
        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                double_mat[i][j] = double_mat[i][j] + mat.double_mat[i][j];
        }
        return *this;
    } else if ((row_length() == mat.row_length()) && (mat.col_length() == 1)) {
        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                double_mat[i][j] = double_mat[i][j] + mat.double_mat[i][0];
        }
        return *this;
    } else if ((col_length() == mat.col_length()) && (mat.row_length() == 1)) {
        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                double_mat[i][j] = double_mat[i][j] + mat.double_mat[0][j];
        }
        return *this;
    } else {
        assert(("The Matrix objects should be of compatible dimensions", false));
    }
}

Matrix Matrix::operator+=(double val) {
    bool error = if_double;
    if (!error)
        assert(("The Matrix should be first converted to double using to_double() method", error));

    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            double_mat[i][j] = double_mat[i][j] + val;
    }
    return *this;
}

Matrix Matrix::operator-=(Matrix mat) {
    bool error1 = ((if_double) && (mat.if_double));
    if (!error1)
        assert(("The Matrix objects should be first converted to double using to_double() method",
                error1));

    if ((row_length() == mat.row_length()) && (col_length() == mat.col_length())) {
        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                double_mat[i][j] = double_mat[i][j] - mat.double_mat[i][j];
        }
        return *this;
    } else if ((row_length() == mat.row_length()) && (mat.col_length() == 1)) {
        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                double_mat[i][j] = double_mat[i][j] - mat.double_mat[i][0];
        }
        return *this;
    } else if ((col_length() == mat.col_length()) && (mat.row_length() == 1)) {
        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                double_mat[i][j] = double_mat[i][j] - mat.double_mat[0][j];
        }
        return *this;
    } else {
        assert(("The Matrix objects should be of compatible dimensions", false));
    }
}

Matrix Matrix::operator-=(double val) {
    bool error = if_double;
    if (!error)
        assert(("The Matrix should be first converted to double using to_double() method", error));

    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            double_mat[i][j] = double_mat[i][j] - val;
    }
    return *this;
}

Matrix Matrix::operator*=(Matrix mat) {
    bool error1 = ((if_double) && (mat.if_double));
    if (!error1)
        assert(("The Matrix objects should be first converted to double using to_double() method",
                error1));

    if ((row_length() == mat.row_length()) && (col_length() == mat.col_length())) {
        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                double_mat[i][j] = double_mat[i][j] * mat.double_mat[i][j];
        }
        return *this;
    } else if ((row_length() == mat.row_length()) && (mat.col_length() == 1)) {
        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                double_mat[i][j] = double_mat[i][j] * mat.double_mat[i][0];
        }
        return *this;
    } else if ((col_length() == mat.col_length()) && (mat.row_length() == 1)) {
        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                double_mat[i][j] = double_mat[i][j] * mat.double_mat[0][j];
        }
        return *this;
    } else {
        assert(("The Matrix objects should be of compatible dimensions", false));
    }
}

Matrix Matrix::operator*=(double val) {
    bool error = if_double;
    if (!error)
        assert(("The Matrix should be first converted to double using to_double() method", error));

    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            double_mat[i][j] = double_mat[i][j] * val;
    }
    return *this;
}

Matrix Matrix::operator/=(Matrix mat) {
    bool error1 = ((if_double) && (mat.if_double));
    if (!error1)
        assert(("The Matrix objects should be first converted to double using to_double() method",
                error1));

    if ((row_length() == mat.row_length()) && (col_length() == mat.col_length())) {
        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++) {
                double val;
                if (mat.double_mat[i][j] == 0)
                    val = std::numeric_limits<double>::infinity();
                else
                    val = double_mat[i][j] / mat.double_mat[i][j];

                double_mat[i][j] = val;
            }
        }
        return *this;
    } else if ((row_length() == mat.row_length()) && (mat.col_length() == 1)) {
        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++) {
                double val;
                if (mat.double_mat[i][0] == 0)
                    val = std::numeric_limits<double>::infinity();
                else
                    val = double_mat[i][j] / mat.double_mat[i][0];

                double_mat[i][j] = val;
            }
        }
        return *this;
    } else if ((col_length() == mat.col_length()) && (mat.row_length() == 1)) {
        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++) {
                double val;
                if (mat.double_mat[0][j] == 0)
                    val = std::numeric_limits<double>::infinity();
                else
                    val = double_mat[i][j] / mat.double_mat[0][j];

                double_mat[i][j] = val;
            }
        }
        return *this;
    } else {
        assert(("The Matrix objects should be of compatible dimensions", false));
    }
}

Matrix Matrix::operator/=(double val) {
    bool error = if_double;
    if (!error)
        assert(("The Matrix should be first converted to double using to_double() method", error));

    if (val == 0) {
        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                double_mat[i][j] = std::numeric_limits<double>::infinity();
        }
        return *this;
    }

    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            double_mat[i][j] = double_mat[i][j] / val;
    }
    return *this;
}

Matrix &Matrix::operator++() {
    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            double_mat[i][j] = double_mat[i][j] + 1;
    }
    return *this;
}

Matrix Matrix::operator++(int) {
    bool error = if_double;
    if (!error)
        assert(("The Matrix should be first converted to double using to_double() method", error));

    Matrix tmp(*this);
    operator++();
    return tmp;
}

Matrix &Matrix::operator--() {
    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            double_mat[i][j] = double_mat[i][j] - 1;
    }
    return *this;
}

Matrix Matrix::operator--(int) {
    bool error = if_double;
    if (!error)
        assert(("The Matrix should be first converted to double using to_double() method", error));

    Matrix tmp = *this;
    operator--();
    return tmp;
}

bool Matrix::operator==(Matrix mat) const {
    if (if_double && mat.if_double) {
        if (double_mat == mat.double_mat)
            return true;
        else
            return false;
    } else {
        if (str_mat == mat.str_mat)
            return true;
        else
            return false;
    }
}

bool Matrix::operator!=(Matrix mat) const {
    if (if_double && mat.if_double) {
        if (double_mat != mat.double_mat)
            return true;
        else
            return false;
    } else {
        if (str_mat != mat.str_mat)
            return true;
        else
            return false;
    }
}

bool Matrix::operator<(Matrix mat) const {
    if (if_double && mat.if_double) {
        if (double_mat < mat.double_mat)
            return true;
        else
            return false;
    } else {
        if (str_mat < mat.str_mat)
            return true;
        else
            return false;
    }
}

bool Matrix::operator<=(Matrix mat) const {
    if (if_double && mat.if_double) {
        if (double_mat <= mat.double_mat)
            return true;
        else
            return false;
    } else {
        if (str_mat <= mat.str_mat)
            return true;
        else
            return false;
    }
}

bool Matrix::operator>(Matrix mat) const {
    if (if_double && mat.if_double) {
        if (double_mat > mat.double_mat)
            return true;
        else
            return false;
    } else {
        if (str_mat > mat.str_mat)
            return true;
        else
            return false;
    }
}

bool Matrix::operator>=(Matrix mat) const {
    if (if_double && mat.if_double) {
        if (double_mat >= mat.double_mat)
            return true;
        else
            return false;
    } else {
        if (str_mat >= mat.str_mat)
            return true;
        else
            return false;
    }
}

std::ostream &operator<<(std::ostream &os, const Matrix &obj) {
    for (int i = 0; i < obj.row_length(); i++) {
        for (int j = 0; j < obj.col_length(); j++)
            os << obj.str_mat[i][j] << "\t";
        os << "\n";
    }
    return os;
}

std::istream &operator>>(std::istream &is, Matrix &obj) {
    int r, c;
    std::cout << "Enter number of rows = ";
    is >> r;
    std::cout << "Enter number of columns = ";
    is >> c;

    std::cout << "Enter Matrix:\n";

    std::string temp;
    for (int i = 0; i < r; i++) {
        std::vector<std::string> t;
        obj.str_mat.push_back(t);
        for (int j = 0; j < c; j++) {
            is >> temp;
            obj.str_mat[i].push_back(temp);
        }
    }

    return is;
}