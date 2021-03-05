#ifndef _matrix_operations_cpp_
#define _matrix_operations_cpp_

#include <matrix_operations.hpp>

/// Method to initialize values of a Matrix object using a scalar
template <typename T>
Matrix<T> MatrixOp::init(T val) {
    Matrix<T> result;
    std::vector<std::vector<T>> vec(1);
    vec[0].push_back(val);
    result.data_mat = vec;

    return result;
}

/// Method to initialize values of a Matrix object using a 1D vector
template <typename T>
Matrix<T> MatrixOp::init(std::vector<T> inner) {
    Matrix<T> result;
    std::vector<std::vector<T>> vec(1, inner);
    result.data_mat = vec;

    return result;
}

/// Method to initialize values of a Matrix object using a 2D vector
template <typename T>
Matrix<T> MatrixOp::init(std::vector<std::vector<T>> vec) {
    Matrix<T> result;
    result.data_mat = vec;

    return result;
}

/// Method to read a csv file and return a Matrix object
template <typename T>
Matrix<T> MatrixOp::genfromtxt(std::string filename, char delim) {
    Matrix<T> mat;
    std::ifstream file(filename);

    std::string line, cell;
    std::vector<T> cells;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        while (std::getline(ss, cell, delim)) {
            if constexpr (std::is_same<T, char>::value) {
                if (cell.size() != 1)
                    assert(("CSV file cannot be loaded to Matrix<char> object.", false));
                cells.push_back(cell[0]);
            } else if constexpr (std::is_same<T, std::string>::value) {
                cells.push_back(cell);
            } else {
                cells.push_back(std::stold(cell));
            }
        }
        mat.data_mat.push_back(cells);
        cells.clear();
    }

    return mat;
}

/// Method to create an Matrix of all elements 0
template <typename T>
Matrix<T> MatrixOp::zeros(int row, int col) {
    Matrix<T> result;
    std::vector<T> vec;

    if constexpr (std::is_same<T, char>::value)
        vec.assign(col, '0');
    else if constexpr (std::is_same<T, std::string>::value)
        vec.assign(col, "0");
    else
        vec.assign(col, 0);

    std::vector<std::vector<T>> mat(row, vec);
    result.data_mat = mat;

    return result;
}

/// Method to create an Matrix of all elements 1
template <typename T>
Matrix<T> MatrixOp::ones(int row, int col) {
    Matrix<T> result;
    std::vector<T> vec;

    if constexpr (std::is_same<T, char>::value)
        vec.assign(col, '1');
    else if constexpr (std::is_same<T, std::string>::value)
        vec.assign(col, "1");
    else
        vec.assign(col, 1);

    std::vector<std::vector<T>> mat(row, vec);
    result.data_mat = mat;

    return result;
}

/// Method to create an identity Matrix
template <typename T>
Matrix<T> MatrixOp::eye(int size) {
    Matrix<T> result = zeros<T>(size, size);

    if constexpr (std::is_same<T, char>::value)
        for (int i = 0; i < size; i++)
            result.data_mat[i][i] = '1';
    else if constexpr (std::is_same<T, std::string>::value)
        for (int i = 0; i < size; i++)
            result.data_mat[i][i] = "1";
    else
        for (int i = 0; i < size; i++)
            result.data_mat[i][i] = 1;

    return result;
}

/// Method to concatenate/join two Matrix objects
template <typename T>
Matrix<T> MatrixOp::concatenate(Matrix<T> mat1, Matrix<T> mat2, std::string dim) {
    if (dim == "column") {
        if (mat1.row_length() != mat2.row_length())
            assert(("The Matrix objects should be of compatible dimensions.", false));
        for (int i = 0; i < mat1.row_length(); i++) {
            mat1.data_mat[i].insert(mat1.data_mat[i].end(), mat2.data_mat[i].begin(),
                                    mat2.data_mat[i].end());
        }
    } else if (dim == "row") {
        if (mat1.col_length() != mat2.col_length())
            assert(("The Matrix objects should be of compatible dimensions.", false));
        mat1.data_mat.insert(mat1.data_mat.end(), mat2.data_mat.begin(), mat2.data_mat.end());

    } else {
        assert(("Concatenate dimension wrong.", false));
    }

    return mat1;
}

/// Method to calculate matrix multiplication
template <typename T, typename U>
Matrix<T> MatrixOp::matmul(Matrix<T> mat1, Matrix<U> mat2) {
    if (mat1.col_length() != mat2.row_length())
        assert(("The Matrix objects should be of compatible dimensions", false));

    Matrix<T> mat = zeros<T>(mat1.row_length(), mat2.col_length());
    for (unsigned long long int i = 0; i < mat1.row_length(); i++) {
        for (unsigned long long int j = 0; j < mat2.col_length(); j++) {
            for (unsigned long long int k = 0; k < mat2.row_length(); k++) {
                mat.data_mat[i][j] += (mat1.data_mat[i][k] * mat2.data_mat[k][j]);
            }
        }
    }

    return mat;
}

/// Method to calculate the Determinant of a Matrix
template <typename T>
double MatrixOp::determinant(Matrix<T> mat, int n) {
    if (mat.row_length() != mat.col_length())
        assert(("The Matrix must be a square matrix", false));

    double D = 0;
    if (n == 1)
        return mat.data_mat[0][0];

    int sign = 1;
    Matrix<T> temp = zeros<T>(n, n);

    for (int f = 0; f < n; f++) {
        temp = cofactor(mat, temp, 0, f);
        D += sign * mat.data_mat[0][f] * determinant(temp, n - 1);
        sign = -sign;
    }

    return D;
}

/// Method to calculate the Inverse of a Matrix
template <typename T>
Matrix<T> MatrixOp::inverse(Matrix<T> mat) {
    if (mat.row_length() != mat.col_length())
        assert(("The Matrix must be a square matrix", false));

    double det = determinant(mat, mat.col_length());
    if (det == 0)
        assert(("The Matrix is singular", false));

    return adjoint(mat) / det;
}

/// Method to calculate the sum over an axis of a Matrix
template <typename T>
Matrix<T> MatrixOp::sum(Matrix<T> mat, std::string dim) {
    Matrix<T> result;

    if (dim == "column") {
        result = zeros<T>(1, mat.col_length());
        for (int i = 0; i < mat.row_length(); i++) {
            for (int j = 0; j < mat.col_length(); j++)
                result(0, j) = result(0, j) + mat(i, j);
        }
    } else if (dim == "row") {
        result = zeros<T>(mat.row_length(), 1);
        for (int i = 0; i < mat.col_length(); i++) {
            for (int j = 0; j < mat.row_length(); j++)
                result(j, 0) = result(j, 0) + mat(j, i);
        }
    } else {
        assert(("Second parameter 'dimension' wrong", false));
    }

    return result;
}

/// Method to calculate the mean over an axis of a Matrix
template <typename T>
Matrix<T> MatrixOp::mean(Matrix<T> mat, std::string dim) {
    Matrix<T> result;

    if (dim == "column") {
        int n = mat.row_length();
        result = sum(mat, dim) / n;
    } else if (dim == "row") {
        int n = mat.col_length();
        result = sum(mat, dim) / n;
    } else {
        assert(("Second parameter 'dimension' wrong", false));
    }

    return result;
}

/// Method to calculate the standard deviation over an axis of a Matrix
template <typename T>
Matrix<T> MatrixOp::std(Matrix<T> mat, std::string dim) {
    Matrix<T> result;

    if (dim == "column") {
        int n = mat.row_length();
        Matrix mean = sum(mat, dim) / n;
        Matrix temp = mat - mean;
        result = sum((temp * temp), dim) / n;
    } else if (dim == "row") {
        int n = mat.col_length();
        Matrix mean = sum(mat, dim) / n;
        Matrix temp = mat - mean;
        result = sum((temp * temp), dim) / n;
    } else {
        assert(("Second parameter 'dimension' wrong", false));
    }

    return result;
}

/// Method to get the minimum value along an axis
template <typename T>
Matrix<T> MatrixOp::min(Matrix<T> mat, std::string dim) {
    if (dim == "column") {
        std::vector<T> min_indices;

        for (int i = 0; i < mat.col_length(); i++) {
            std::vector<T> vec = mat.get_col(i);
            min_indices.push_back(*std::min_element(vec.begin(), vec.end()));
        }

        return matrix.init(min_indices);
    } else if (dim == "row") {
        std::vector<T> temp;
        std::vector<std::vector<T>> min_indices;

        for (int i = 0; i < mat.row_length(); i++) {
            std::vector<T> vec = mat.get_row(i);
            temp.push_back(*std::min_element(vec.begin(), vec.end()));
            min_indices.push_back(temp);
            temp.clear();
        }

        return matrix.init(min_indices);
    } else {
        assert(("Second parameter 'dimension' wrong", false));
    }
}

/// Method to get the maximum value along an axis
template <typename T>
Matrix<T> MatrixOp::max(Matrix<T> mat, std::string dim) {
    if (dim == "column") {
        std::vector<T> max_indices;

        for (int i = 0; i < mat.col_length(); i++) {
            std::vector<T> vec = mat.get_col(i);
            max_indices.push_back(*std::max_element(vec.begin(), vec.end()));
        }

        return matrix.init(max_indices);
    } else if (dim == "row") {
        std::vector<T> temp;
        std::vector<std::vector<T>> max_indices;

        for (int i = 0; i < mat.row_length(); i++) {
            std::vector<T> vec = mat.get_row(i);
            temp.push_back(*std::max_element(vec.begin(), vec.end()));
            max_indices.push_back(temp);
            temp.clear();
        }

        return matrix.init(max_indices);
    } else {
        assert(("Second parameter 'dimension' wrong", false));
    }
}

/// Method to get the index of minimum value along an axis
template <typename T>
Matrix<int> MatrixOp::argmin(Matrix<T> mat, std::string dim) {
    if (dim == "column") {
        std::vector<int> min_indices;

        for (int i = 0; i < mat.col_length(); i++) {
            std::vector<T> vec = mat.get_col(i);
            min_indices.push_back(std::min_element(vec.begin(), vec.end()) - vec.begin());
        }

        return matrix.init(min_indices);
    } else if (dim == "row") {
        std::vector<int> temp;
        std::vector<std::vector<int>> min_indices;

        for (int i = 0; i < mat.row_length(); i++) {
            std::vector<T> vec = mat.get_row(i);
            temp.push_back(std::min_element(vec.begin(), vec.end()) - vec.begin());
            min_indices.push_back(temp);
            temp.clear();
        }

        return matrix.init(min_indices);
    } else {
        assert(("Second parameter 'dimension' wrong", false));
    }
}

/// Method to get the index of maximum value along an axis
template <typename T>
Matrix<int> MatrixOp::argmax(Matrix<T> mat, std::string dim) {
    if (dim == "column") {
        std::vector<int> max_indices;

        for (int i = 0; i < mat.col_length(); i++) {
            std::vector<T> vec = mat.get_col(i);
            max_indices.push_back(std::max_element(vec.begin(), vec.end()) - vec.begin());
        }

        return matrix.init(max_indices);
    } else if (dim == "row") {
        std::vector<int> temp;
        std::vector<std::vector<int>> max_indices;

        for (int i = 0; i < mat.row_length(); i++) {
            std::vector<T> vec = mat.get_row(i);
            temp.push_back(std::max_element(vec.begin(), vec.end()) - vec.begin());
            max_indices.push_back(temp);
            temp.clear();
        }

        return matrix.init(max_indices);
    } else {
        assert(("Second parameter 'dimension' wrong", false));
    }
}

template <typename T>
Matrix<T> MatrixOp::sqrt(Matrix<T> mat) {
    std::vector<T> row;
    std::vector<std::vector<T>> res;

    for (int i = 0; i < mat.row_length(); i++) {
        for (int j = 0; j < mat.col_length(); j++)
            row.push_back(std::sqrt(mat.data_mat[i][j]));
        res.push_back(row);
        row.clear();
    }

    return matrix.init(res);
}

template <typename T, typename U>
Matrix<T> MatrixOp::power(Matrix<T> mat1, Matrix<U> mat2) {
    if ((mat1.row_length() == mat2.row_length()) && (mat1.col_length() == mat2.col_length())) {
        std::vector<T> row;
        std::vector<std::vector<T>> res;

        for (int i = 0; i < mat1.row_length(); i++) {
            for (int j = 0; j < mat1.col_length(); j++)
                row.push_back(std::pow(mat1.data_mat[i][j], mat2.data_mat[i][j]));
            res.push_back(row);
            row.clear();
        }

        return matrix.init(res);
    } else if ((mat1.row_length() == mat2.row_length()) && (mat2.col_length() == 1)) {
        std::vector<T> row;
        std::vector<std::vector<T>> res;

        for (int i = 0; i < mat1.row_length(); i++) {
            for (int j = 0; j < mat1.col_length(); j++)
                row.push_back(std::pow(mat1.data_mat[i][j], mat2.data_mat[i][0]));
            res.push_back(row);
            row.clear();
        }

        return matrix.init(res);
    } else if ((mat1.col_length() == mat2.col_length()) && (mat2.row_length() == 1)) {
        std::vector<T> row;
        std::vector<std::vector<T>> res;

        for (int i = 0; i < mat1.row_length(); i++) {
            for (int j = 0; j < mat1.col_length(); j++)
                row.push_back(std::pow(mat1.data_mat[i][j], mat2.data_mat[0][j]));
            res.push_back(row);
            row.clear();
        }

        return matrix.init(res);
    } else {
        assert(("The Matrix objects should be of compatible dimensions", false));
    }
}

template <typename T, typename U>
Matrix<T> MatrixOp::power(Matrix<T> mat, U val) {
    std::vector<T> row;
    std::vector<std::vector<T>> res;

    for (int i = 0; i < mat.row_length(); i++) {
        for (int j = 0; j < mat.col_length(); j++)
            row.push_back(std::pow(mat.data_mat[i][j], val));
        res.push_back(row);
        row.clear();
    }

    return matrix.init(res);
}

/** In Y, find list of indices of element whose value is val,
   then return the col'th column of the Matrix containing elements of those indices
*/
template <typename T, typename U>
Matrix<T> MatrixOp::slice_select(Matrix<T> X, Matrix<U> Y, U val, int col) {
    X = X.slice(0, X.row_length(), col, col + 1);

    bool is_compatible = (X.row_length() == Y.row_length());
    if (!is_compatible) {
        assert(("The Matrix objects should be of same dimensions", is_compatible));
    }

    std::vector<std::vector<T>> res;
    for (int i = 0; i < X.row_length(); i++) {
        if (Y.data_mat[i][0] == val) {
            res.push_back(X.get_row(i));
        }
    }

    return init(res);
}

/// Method to delete a row or column of a Matrix object
template <typename T>
Matrix<T> MatrixOp::delete_(Matrix<T> mat, int index, std::string dim) {
    if (dim == "row") {
        Matrix sl1 = mat.slice(0, index, 0, mat.col_length());
        Matrix sl2 = mat.slice(index + 1, mat.row_length(), 0, mat.col_length());

        if (sl1.row_length() == 0)
            return sl2;
        if (sl2.row_length() == 0)
            return sl1;

        return concatenate(sl1, sl2, "row");
    } else if (dim == "column") {
        Matrix sl1 = mat.slice(0, mat.row_length(), 0, index);
        Matrix sl2 = mat.slice(0, mat.row_length(), index + 1, mat.col_length());

        if (sl1.col_length() == 0)
            return sl2;
        if (sl2.col_length() == 0)
            return sl1;

        return concatenate(sl1, sl2, "column");
    } else
        assert(("Second parameter 'dimension' wrong.", false));
}

/// Method to calculate exponential of all elements in the Matrix object
template <typename T>
Matrix<T> MatrixOp::exp(Matrix<T> mat) {
    std::vector<T> row;
    std::vector<std::vector<T>> res;

    for (int i = 0; i < mat.row_length(); i++) {
        for (int j = 0; j < mat.col_length(); j++)
            row.push_back(std::exp(mat.data_mat[i][j]));
        res.push_back(row);
        row.clear();
    }

    return init(res);
}

/// Method to calculate natural logarithm of all elements in the Matrix object
template <typename T>
Matrix<T> MatrixOp::log(Matrix<T> mat) {
    std::vector<T> row;
    std::vector<std::vector<T>> res;

    for (int i = 0; i < mat.row_length(); i++) {
        for (int j = 0; j < mat.col_length(); j++)
            row.push_back(std::log(mat.data_mat[i][j]));
        res.push_back(row);
        row.clear();
    }

    return init(res);
}

/// Method to get absolute value of all elements in the Matrix object
template <typename T>
Matrix<T> MatrixOp::abs(Matrix<T> mat) {
    std::vector<T> row;
    std::vector<std::vector<T>> res;

    for (int i = 0; i < mat.row_length(); i++) {
        for (int j = 0; j < mat.col_length(); j++)
            row.push_back(std::abs(mat.data_mat[i][j]));
        res.push_back(row);
        row.clear();
    }

    return init(res);
}

/// Method to calculate reciprocal of all elements in the Matrix object
template <typename T>
Matrix<T> MatrixOp::reciprocal(Matrix<T> mat) {
    std::vector<T> row;
    std::vector<std::vector<T>> res;

    for (int i = 0; i < mat.row_length(); i++) {
        for (int j = 0; j < mat.col_length(); j++)
            row.push_back(1 / mat.data_mat[i][j]);
        res.push_back(row);
        row.clear();
    }

    return init(res);
}

// Helper methods

/// Helper method to calculate cofactor
template <typename T>
Matrix<T> MatrixOp::cofactor(Matrix<T> mat, Matrix<T> temp, int p, int q) {
    int i = 0, j = 0;
    for (int row = 0; row < mat.row_length(); row++) {
        for (int col = 0; col < mat.col_length(); col++) {
            if (row != p && col != q) {
                temp.data_mat[i][j++] = mat.data_mat[row][col];
                if (j == mat.col_length() - 1) {
                    j = 0;
                    i++;
                }
            }
        }
    }

    return temp;
}

/// Helper method to calculate the Adjoint of a Matrix
template <typename T>
Matrix<T> MatrixOp::adjoint(Matrix<T> mat) {
    Matrix<T> result = zeros<T>(mat.row_length(), mat.col_length());

    if (mat.col_length() == 1) {
        result.data_mat[0][0] = 1;
        return result;
    }

    int sign = 1;
    Matrix<T> temp = zeros<T>(mat.row_length(), mat.col_length());

    for (int i = 0; i < mat.row_length(); i++) {
        for (int j = 0; j < mat.col_length(); j++) {
            temp = cofactor(mat, temp, i, j);
            sign = ((i + j) % 2 == 0) ? 1 : -1;
            result.data_mat[j][i] = (sign) * (determinant(temp, temp.col_length() - 1));
        }
    }

    return result;
}

#endif /* _matrix_operations_cpp_ */