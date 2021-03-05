#ifndef _matrix_basic_cpp_
#define _matrix_basic_cpp_

#include <matrix_basic.hpp>

template <typename T>
template <typename U>
Matrix<T>::Matrix(const Matrix<U> &mat) {
    std::vector<T> row;
    if constexpr (std::is_same<T, bool>::value) {
        // std::vector<bool> row;

        for (int i = 0; i < mat.row_length(); i++) {
            for (int j = 0; j < mat.col_length(); j++) {
                if constexpr (std::is_same<U, std::string>::value) {
                    bool val;
                    if (mat.data_mat[i][j] == "False" || mat.data_mat[i][j] == "false" ||
                        mat.data_mat[i][j] == "0")
                        val = false;
                    else
                        val = true;

                    row.push_back(val);
                } else
                    row.push_back(mat.data_mat[i][j]);
            }
            data_mat.push_back(row);
            row.clear();
        }
    } else if constexpr (std::is_same<T, char>::value) {
        // std::vector<char> row;

        for (int i = 0; i < mat.row_length(); i++) {
            for (int j = 0; j < mat.col_length(); j++) {
                std::string val;
                if constexpr (std::is_same<U, std::string>::value) {
                    val = mat.data_mat[i][j];
                } else {
                    val = std::to_string(mat.data_mat[i][j]);
                }
                if (val.size() != 1)
                    assert(("Cannot convert to Matrix<char> object.", false));
                row.push_back(val[0]);
            }
            data_mat.push_back(row);
            row.clear();
        }
    } else if constexpr (std::is_same<T, std::string>::value) {
        // std::vector<std::string> row;

        for (int i = 0; i < mat.row_length(); i++) {
            for (int j = 0; j < mat.col_length(); j++) {
                if constexpr (std::is_same<U, char>::value) {
                    std::string s(1, mat.data_mat[i][j]);
                    row.push_back(s);
                } else {
                    row.push_back(std::to_string(mat.data_mat[i][j]));
                }
            }
            data_mat.push_back(row);
            row.clear();
        }
        // } else if constexpr (std::is_same<T, int>::value) {
        //     std::vector<int> row;

        //     for (int i = 0; i < mat.row_length(); i++) {
        //         for (int j = 0; j < mat.col_length(); j++) {
        //             if constexpr (std::is_same<U, std::string>::value) {
        //                 row.push_back(std::stoi(mat.data_mat[i][j]));
        //             } else if constexpr (std::is_same<U, char>::value) {
        //                 row.push_back((int)(mat.data_mat[i][j] - '0'));
        //             } else {
        //                 row.push_back((int)mat.data_mat[i][j]);
        //             }
        //         }
        //         data_mat.push_back(row);
        //         row.clear();
        //     }
        // } else if constexpr (std::is_same<T, unsigned int>::value) {
        //     std::vector<unsigned int> row;

        //     for (int i = 0; i < mat.row_length(); i++) {
        //         for (int j = 0; j < mat.col_length(); j++) {
        //             if constexpr (std::is_same<U, std::string>::value) {
        //                 row.push_back(std::stoul(mat.data_mat[i][j]));
        //             } else if constexpr (std::is_same<U, char>::value) {
        //                 row.push_back((unsigned int)(mat.data_mat[i][j] - '0'));
        //             } else {
        //                 row.push_back((unsigned int)mat.data_mat[i][j]);
        //             }
        //         }
        //         data_mat.push_back(row);
        //         row.clear();
        //     }
        // } else if constexpr (std::is_same<T, short int>::value) {
        //     std::vector<short int> row;

        //     for (int i = 0; i < mat.row_length(); i++) {
        //         for (int j = 0; j < mat.col_length(); j++) {
        //             if constexpr (std::is_same<U, std::string>::value) {
        //                 row.push_back(std::stoi(mat.data_mat[i][j]));
        //             } else if constexpr (std::is_same<U, char>::value) {
        //                 row.push_back((short int)(mat.data_mat[i][j] - '0'));
        //             } else {
        //                 row.push_back((short int)mat.data_mat[i][j]);
        //             }
        //         }
        //         data_mat.push_back(row);
        //         row.clear();
        //     }
        // } else if constexpr (std::is_same<T, unsigned short int>::value) {
        //     std::vector<unsigned short int> row;

        //     for (int i = 0; i < mat.row_length(); i++) {
        //         for (int j = 0; j < mat.col_length(); j++) {
        //             if constexpr (std::is_same<U, std::string>::value) {
        //                 row.push_back(std::stoul(mat.data_mat[i][j]));
        //             } else if constexpr (std::is_same<U, char>::value) {
        //                 row.push_back((unsigned short int)(mat.data_mat[i][j] - '0'));
        //             } else {
        //                 row.push_back((unsigned short int)mat.data_mat[i][j]);
        //             }
        //         }
        //         data_mat.push_back(row);
        //         row.clear();
        //     }
        // } else if constexpr (std::is_same<T, long int>::value) {
        //     std::vector<long int> row;

        //     for (int i = 0; i < mat.row_length(); i++) {
        //         for (int j = 0; j < mat.col_length(); j++) {
        //             if constexpr (std::is_same<U, std::string>::value) {
        //                 row.push_back(std::stol(mat.data_mat[i][j]));
        //             } else if constexpr (std::is_same<U, char>::value) {
        //                 row.push_back((long int)(mat.data_mat[i][j] - '0'));
        //             } else {
        //                 row.push_back((long int)mat.data_mat[i][j]);
        //             }
        //         }
        //         data_mat.push_back(row);
        //         row.clear();
        //     }
        // } else if constexpr (std::is_same<T, unsigned long int>::value) {
        //     std::vector<unsigned long int> row;

        //     for (int i = 0; i < mat.row_length(); i++) {
        //         for (int j = 0; j < mat.col_length(); j++) {
        //             if constexpr (std::is_same<U, std::string>::value) {
        //                 row.push_back(std::stoul(mat.data_mat[i][j]));
        //             } else if constexpr (std::is_same<U, char>::value) {
        //                 row.push_back((unsigned long int)(mat.data_mat[i][j] - '0'));
        //             } else {
        //                 row.push_back((unsigned long int)mat.data_mat[i][j]);
        //             }
        //         }
        //         data_mat.push_back(row);
        //         row.clear();
        //     }
        // } else if constexpr (std::is_same<T, long long int>::value) {
        //     std::vector<long long int> row;

        //     for (int i = 0; i < mat.row_length(); i++) {
        //         for (int j = 0; j < mat.col_length(); j++) {
        //             if constexpr (std::is_same<U, std::string>::value) {
        //                 row.push_back(std::stoll(mat.data_mat[i][j]));
        //             } else if constexpr (std::is_same<U, char>::value) {
        //                 row.push_back((long long int)(mat.data_mat[i][j] - '0'));
        //             } else {
        //                 row.push_back((long long int)mat.data_mat[i][j]);
        //             }
        //         }
        //         data_mat.push_back(row);
        //         row.clear();
        //     }
        // } else if constexpr (std::is_same<T, unsigned long long int>::value) {
        //     std::vector<unsigned long long int> row;

        //     for (int i = 0; i < mat.row_length(); i++) {
        //         for (int j = 0; j < mat.col_length(); j++) {
        //             if constexpr (std::is_same<U, std::string>::value) {
        //                 row.push_back(std::stoull(mat.data_mat[i][j]));
        //             } else if constexpr (std::is_same<U, char>::value) {
        //                 row.push_back((unsigned long long int)(mat.data_mat[i][j] - '0'));
        //             } else {
        //                 row.push_back((unsigned long long int)mat.data_mat[i][j]);
        //             }
        //         }
        //         data_mat.push_back(row);
        //         row.clear();
        //     }
        // } else if constexpr (std::is_same<T, float>::value) {
        //     std::vector<float> row;

        //     for (int i = 0; i < mat.row_length(); i++) {
        //         for (int j = 0; j < mat.col_length(); j++) {
        //             if constexpr (std::is_same<U, std::string>::value) {
        //                 row.push_back(std::stof(mat.data_mat[i][j]));
        //             } else if constexpr (std::is_same<U, char>::value) {
        //                 row.push_back((float)(mat.data_mat[i][j] - '0'));
        //             } else {
        //                 row.push_back((float)mat.data_mat[i][j]);
        //             }
        //         }
        //         data_mat.push_back(row);
        //         row.clear();
        //     }
        // } else if constexpr (std::is_same<T, double>::value) {
        //     std::vector<double> row;

        //     for (int i = 0; i < mat.row_length(); i++) {
        //         for (int j = 0; j < mat.col_length(); j++) {
        //             if constexpr (std::is_same<U, std::string>::value) {
        //                 row.push_back(std::stod(mat.data_mat[i][j]));
        //             } else if constexpr (std::is_same<U, char>::value) {
        //                 row.push_back((double)(mat.data_mat[i][j] - '0'));
        //             } else {
        //                 row.push_back((double)mat.data_mat[i][j]);
        //             }
        //         }
        //         data_mat.push_back(row);
        //         row.clear();
        //     }
        // } else if constexpr (std::is_same<T, long double>::value) {
    } else {
        // std::vector<long double> row;

        for (int i = 0; i < mat.row_length(); i++) {
            for (int j = 0; j < mat.col_length(); j++) {
                if constexpr (std::is_same<U, std::string>::value) {
                    row.push_back(std::stold(mat.data_mat[i][j]));
                } else if constexpr (std::is_same<U, char>::value) {
                    row.push_back((long double)(mat.data_mat[i][j] - '0'));
                } else {
                    row.push_back((long double)mat.data_mat[i][j]);
                }
            }
            data_mat.push_back(row);
            row.clear();
        }
    }
    // } else
    //     assert(("Undefined data type", false));
}

/// Method to return the matrix in the form of vector
template <typename T>
std::vector<std::vector<T>> Matrix<T>::get() {
    return data_mat;
}

/// Method to return a row of the matrix in the form of a vector
template <typename T>
std::vector<T> Matrix<T>::get_row(int row) {
    bool is_within_range = (data_mat.size() >= row);
    if (!is_within_range) {
        assert(("The row parameter is out of bounds of the matrix size.", is_within_range));
    }

    std::vector<T> row_vec;
    for (int i = 0; i < col_length(); i++)
        row_vec.push_back(data_mat[row][i]);

    return row_vec;
}

/// Method to return a column of the matrix in the form of a vector
template <typename T>
std::vector<T> Matrix<T>::get_col(int col) {
    bool is_within_range = (data_mat[0].size() >= col);
    if (!is_within_range) {
        assert(("The column parameter is out of bounds of the matrix size.", is_within_range));
    }

    std::vector<T> col_vec;
    for (int i = 0; i < row_length(); i++)
        col_vec.push_back(data_mat[i][col]);

    return col_vec;
}

/// Method to return the number of columns
template <typename T>
int Matrix<T>::col_length() const {
    return data_mat[0].size();
}

/// Method to return the number of rows
template <typename T>
int Matrix<T>::row_length() const {
    return data_mat.size();
}

/// Method to print a Matrix object
template <typename T>
void Matrix<T>::print() {
    for (int i = 0; i < data_mat.size(); i++) {
        for (int j = 0; j < data_mat[i].size(); j++)
            std::cout << data_mat[i][j] << "\t";
        std::cout << std::endl;
    }
}

/// Method to print first 5 rows of a Matrix object
template <typename T>
void Matrix<T>::head() {
    int row = row_length() < 5 ? row_length() : 5;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < data_mat[i].size(); j++)
            std::cout << data_mat[i][j] << "\t";
        std::cout << std::endl;
    }
}

/// Method to print last 5 rows of a Matrix object
template <typename T>
void Matrix<T>::tail() {
    int row = row_length() < 5 ? row_length() : 5;
    for (int i = data_mat.size() - row; i < data_mat.size(); i++) {
        for (int j = 0; j < data_mat[i].size(); j++)
            std::cout << data_mat[i][j] << "\t";
        std::cout << std::endl;
    }
}

/// Method to print a single cell (row, col) of a Matrix object
template <typename T>
void Matrix<T>::view(int row, int col) {
    std::cout << data_mat[row][col] << std::endl;
}

/// Method to print a range of rows and columns of a Matrix object
template <typename T>
void Matrix<T>::view(int row_start, int row_end, int col_start, int col_end) {
    bool is_within_range = (data_mat.size() >= row_end) && (data_mat[0].size() >= col_end);
    if (!is_within_range) {
        assert(("The slicing parameters are out of bounds of the matrix size.", is_within_range));
    }

    for (int i = row_start; i < row_end; i++) {
        for (int j = col_start; j < col_end; j++)
            std::cout << data_mat[i][j] << "\t";
        std::cout << std::endl;
    }
}

/** Method to slice a Matrix object
   The method will return a Matrix object whose dimensions will be (row_end-row_start,
   col_end-col_start)
*/
template <typename T>
Matrix<T> Matrix<T>::slice(int row_start, int row_end, int col_start, int col_end) {
    bool is_within_range = (data_mat.size() >= row_end) && (data_mat[0].size() >= col_end);
    if (!is_within_range) {
        assert(("The slicing parameters are out of bounds of the matrix size.", is_within_range));
    }

    Matrix<T> mat;
    std::vector<T> row;
    for (int i = row_start; i < row_end; i++) {
        for (int j = col_start; j < col_end; j++)
            row.push_back(data_mat[i][j]);
        mat.data_mat.push_back(row);
        row.clear();
    }

    return mat;
}

/** Method to return the Tranpose of a Matrix
   The method will return a Matrix object whose dimensions will be (col_length(), row_length())
*/
template <typename T>
Matrix<T> Matrix<T>::transpose() {
    Matrix<T> mat;
    std::vector<T> row;

    for (int i = 0; i < col_length(); i++) {
        for (int j = 0; j < row_length(); j++)
            row.push_back(data_mat[j][i]);
        mat.data_mat.push_back(row);
        row.clear();
    }

    return mat;
}

// Operator overloading functions

template <typename T>
Matrix<T> Matrix<T>::operator+(Matrix<T> mat) {
    if ((row_length() == mat.row_length()) && (col_length() == mat.col_length())) {
        Matrix<T> result;
        std::vector<T> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(data_mat[i][j] + mat.data_mat[i][j]);
            result.data_mat.push_back(row);
            row.clear();
        }

        return result;
    } else if ((row_length() == mat.row_length()) && (mat.col_length() == 1)) {
        Matrix<T> result;
        std::vector<T> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(data_mat[i][j] + mat.data_mat[i][0]);
            result.data_mat.push_back(row);
            row.clear();
        }

        return result;
    } else if ((col_length() == mat.col_length()) && (mat.row_length() == 1)) {
        Matrix<T> result;
        std::vector<T> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(data_mat[i][j] + mat.data_mat[0][j]);
            result.data_mat.push_back(row);
            row.clear();
        }

        return result;
    } else {
        assert(("The Matrix objects should be of compatible dimensions", false));
    }
}

template <typename T>
Matrix<T> Matrix<T>::operator+(T val) {
    Matrix<T> result;
    std::vector<T> row;

    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            row.push_back(data_mat[i][j] + val);
        result.data_mat.push_back(row);
        row.clear();
    }

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-(Matrix<T> mat) {
    if ((row_length() == mat.row_length()) && (col_length() == mat.col_length())) {
        Matrix<T> result;
        std::vector<T> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(data_mat[i][j] - mat.data_mat[i][j]);
            result.data_mat.push_back(row);
            row.clear();
        }

        return result;
    } else if ((row_length() == mat.row_length()) && (mat.col_length() == 1)) {
        Matrix<T> result;
        std::vector<T> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(data_mat[i][j] - mat.data_mat[i][0]);
            result.data_mat.push_back(row);
            row.clear();
        }

        return result;
    } else if ((col_length() == mat.col_length()) && (mat.row_length() == 1)) {
        Matrix<T> result;
        std::vector<T> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(data_mat[i][j] - mat.data_mat[0][j]);
            result.data_mat.push_back(row);
            row.clear();
        }

        return result;
    } else {
        assert(("The Matrix objects should be of compatible dimensions", false));
    }
}

template <typename T>
Matrix<T> Matrix<T>::operator-(T val) {
    Matrix<T> result;
    std::vector<T> row;

    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            row.push_back(data_mat[i][j] - val);
        result.data_mat.push_back(row);
        row.clear();
    }

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator*(Matrix<T> mat) {
    if ((row_length() == mat.row_length()) && (col_length() == mat.col_length())) {
        Matrix<T> result;
        std::vector<T> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(data_mat[i][j] * mat.data_mat[i][j]);
            result.data_mat.push_back(row);
            row.clear();
        }

        return result;
    } else if ((row_length() == mat.row_length()) && (mat.col_length() == 1)) {
        Matrix<T> result;
        std::vector<T> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(data_mat[i][j] * mat.data_mat[i][0]);
            result.data_mat.push_back(row);
            row.clear();
        }

        return result;
    } else if ((col_length() == mat.col_length()) && (mat.row_length() == 1)) {
        Matrix<T> result;
        std::vector<T> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(data_mat[i][j] * mat.data_mat[0][j]);
            result.data_mat.push_back(row);
            row.clear();
        }

        return result;
    } else {
        assert(("The Matrix objects should be of compatible dimensions", false));
    }
}

template <typename T>
Matrix<T> Matrix<T>::operator*(T val) {
    Matrix<T> result;
    std::vector<T> row;

    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            row.push_back(data_mat[i][j] * val);
        result.data_mat.push_back(row);
        row.clear();
    }

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator/(Matrix<T> mat) {
    if ((row_length() == mat.row_length()) && (col_length() == mat.col_length())) {
        Matrix<T> result;
        std::vector<T> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++) {
                T val;
                if (mat.data_mat[i][j] == 0)
                    val = std::numeric_limits<T>::infinity();
                else
                    val = data_mat[i][j] / mat.data_mat[i][j];
                row.push_back(val);
            }
            result.data_mat.push_back(row);
            row.clear();
        }

        return result;
    } else if ((row_length() == mat.row_length()) && (mat.col_length() == 1)) {
        Matrix<T> result;
        std::vector<T> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++) {
                T val;
                if (mat.data_mat[i][0] == 0)
                    val = std::numeric_limits<T>::infinity();
                else
                    val = data_mat[i][j] / mat.data_mat[i][0];
                row.push_back(val);
            }
            result.data_mat.push_back(row);
            row.clear();
        }

        return result;
    } else if ((col_length() == mat.col_length()) && (mat.row_length() == 1)) {
        Matrix<T> result;
        std::vector<T> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++) {
                T val;
                if (mat.data_mat[0][j] == 0)
                    val = std::numeric_limits<T>::infinity();
                else
                    val = data_mat[i][j] / mat.data_mat[0][j];
                row.push_back(val);
            }
            result.data_mat.push_back(row);
            row.clear();
        }

        return result;
    } else {
        assert(("The Matrix objects should be of compatible dimensions", false));
    }
}

template <typename T>
Matrix<T> Matrix<T>::operator/(T val) {
    if (val == 0) {
        Matrix<T> result;
        std::vector<T> row;

        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                row.push_back(std::numeric_limits<T>::infinity());
            result.data_mat.push_back(row);
            row.clear();
        }

        return result;
    }

    Matrix<T> result;
    std::vector<T> row;

    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            row.push_back(data_mat[i][j] / val);
        result.data_mat.push_back(row);
        row.clear();
    }

    return result;
}

template <typename T>
Matrix<T> Matrix<T>::operator-() {
    if constexpr (std::is_same<T, std::string>::value || std::is_same<T, char>::value)
        assert(("The Matrix should be numeric type.", false));

    Matrix<T> result;
    std::vector<T> row;

    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            row.push_back(-data_mat[i][j]);
        result.data_mat.push_back(row);
        row.clear();
    }

    return result;
}

template <typename T>
T &Matrix<T>::operator()(int row, int col) {
    bool error = (((row >= 0) && (row < row_length())) && ((col >= 0) && (col < col_length())));
    if (!error)
        assert(("Index is out of range", false));

    return data_mat[row][col];
}

template <typename T>
Matrix<T> Matrix<T>::operator+=(Matrix<T> mat) {
    if ((row_length() == mat.row_length()) && (col_length() == mat.col_length())) {
        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                data_mat[i][j] = data_mat[i][j] + mat.data_mat[i][j];
        }

        return *this;
    } else if ((row_length() == mat.row_length()) && (mat.col_length() == 1)) {
        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                data_mat[i][j] = data_mat[i][j] + mat.data_mat[i][0];
        }

        return *this;
    } else if ((col_length() == mat.col_length()) && (mat.row_length() == 1)) {
        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                data_mat[i][j] = data_mat[i][j] + mat.data_mat[0][j];
        }

        return *this;
    } else {
        assert(("The Matrix objects should be of compatible dimensions", false));
    }
}

template <typename T>
Matrix<T> Matrix<T>::operator+=(T val) {
    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            data_mat[i][j] = data_mat[i][j] + val;
    }

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator-=(Matrix<T> mat) {
    if ((row_length() == mat.row_length()) && (col_length() == mat.col_length())) {
        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                data_mat[i][j] = data_mat[i][j] - mat.data_mat[i][j];
        }

        return *this;
    } else if ((row_length() == mat.row_length()) && (mat.col_length() == 1)) {
        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                data_mat[i][j] = data_mat[i][j] - mat.data_mat[i][0];
        }

        return *this;
    } else if ((col_length() == mat.col_length()) && (mat.row_length() == 1)) {
        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                data_mat[i][j] = data_mat[i][j] - mat.data_mat[0][j];
        }

        return *this;
    } else {
        assert(("The Matrix objects should be of compatible dimensions", false));
    }
}

template <typename T>
Matrix<T> Matrix<T>::operator-=(T val) {
    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            data_mat[i][j] = data_mat[i][j] - val;
    }

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator*=(Matrix<T> mat) {
    if ((row_length() == mat.row_length()) && (col_length() == mat.col_length())) {
        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                data_mat[i][j] = data_mat[i][j] * mat.data_mat[i][j];
        }

        return *this;
    } else if ((row_length() == mat.row_length()) && (mat.col_length() == 1)) {
        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                data_mat[i][j] = data_mat[i][j] * mat.data_mat[i][0];
        }

        return *this;
    } else if ((col_length() == mat.col_length()) && (mat.row_length() == 1)) {
        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                data_mat[i][j] = data_mat[i][j] * mat.data_mat[0][j];
        }

        return *this;
    } else {
        assert(("The Matrix objects should be of compatible dimensions", false));
    }
}

template <typename T>
Matrix<T> Matrix<T>::operator*=(T val) {
    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            data_mat[i][j] = data_mat[i][j] * val;
    }

    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator/=(Matrix<T> mat) {
    if ((row_length() == mat.row_length()) && (col_length() == mat.col_length())) {
        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++) {
                T val;
                if (mat.data_mat[i][j] == 0)
                    val = std::numeric_limits<T>::infinity();
                else
                    val = data_mat[i][j] / mat.data_mat[i][j];

                data_mat[i][j] = val;
            }
        }

        return *this;
    } else if ((row_length() == mat.row_length()) && (mat.col_length() == 1)) {
        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++) {
                T val;
                if (mat.data_mat[i][0] == 0)
                    val = std::numeric_limits<T>::infinity();
                else
                    val = data_mat[i][j] / mat.data_mat[i][0];

                data_mat[i][j] = val;
            }
        }

        return *this;
    } else if ((col_length() == mat.col_length()) && (mat.row_length() == 1)) {
        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++) {
                T val;
                if (mat.data_mat[0][j] == 0)
                    val = std::numeric_limits<T>::infinity();
                else
                    val = data_mat[i][j] / mat.data_mat[0][j];

                data_mat[i][j] = val;
            }
        }

        return *this;
    } else {
        assert(("The Matrix objects should be of compatible dimensions", false));
    }
}

template <typename T>
Matrix<T> Matrix<T>::operator/=(T val) {
    if (val == 0) {
        for (int i = 0; i < row_length(); i++) {
            for (int j = 0; j < col_length(); j++)
                data_mat[i][j] = std::numeric_limits<T>::infinity();
        }

        return *this;
    }

    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            data_mat[i][j] = data_mat[i][j] / val;
    }

    return *this;
}

template <typename T>
Matrix<T> &Matrix<T>::operator++() {
    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            data_mat[i][j] = data_mat[i][j] + 1;
    }
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator++(int) {
    Matrix tmp(*this);
    operator++();
    return tmp;
}

template <typename T>
Matrix<T> &Matrix<T>::operator--() {
    for (int i = 0; i < row_length(); i++) {
        for (int j = 0; j < col_length(); j++)
            data_mat[i][j] = data_mat[i][j] - 1;
    }
    return *this;
}

template <typename T>
Matrix<T> Matrix<T>::operator--(int) {
    Matrix tmp = *this;
    operator--();
    return tmp;
}

template <typename T>
bool Matrix<T>::operator==(Matrix<T> mat) const {
    if (data_mat == mat.data_mat)
        return true;
    else
        return false;
}

template <typename T>
bool Matrix<T>::operator!=(Matrix<T> mat) const {
    if (data_mat != mat.data_mat)
        return true;
    else
        return false;
}

template <typename T>
bool Matrix<T>::operator<(Matrix<T> mat) const {
    if (data_mat < mat.data_mat)
        return true;
    else
        return false;
}

template <typename T>
bool Matrix<T>::operator<=(Matrix<T> mat) const {
    if (data_mat <= mat.data_mat)
        return true;
    else
        return false;
}

template <typename T>
bool Matrix<T>::operator>(Matrix<T> mat) const {
    if (data_mat > mat.data_mat)
        return true;
    else
        return false;
}

template <typename T>
bool Matrix<T>::operator>=(Matrix<T> mat) const {
    if (data_mat >= mat.data_mat)
        return true;
    else
        return false;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const Matrix<T> &obj) {
    for (int i = 0; i < obj.row_length(); i++) {
        for (int j = 0; j < obj.col_length(); j++)
            os << obj.data_mat[i][j] << "\t";
        os << "\n";
    }
    return os;
}

template <typename T>
std::istream &operator>>(std::istream &is, Matrix<T> &obj) {
    int r, c;
    std::cout << "Enter number of rows = ";
    is >> r;
    std::cout << "Enter number of columns = ";
    is >> c;

    std::cout << "Enter Matrix:\n";

    T temp;
    for (int i = 0; i < r; i++) {
        std::vector<T> t;
        obj.data_mat.push_back(t);
        for (int j = 0; j < c; j++) {
            is >> temp;
            obj.data_mat[i].push_back(temp);
        }
    }

    return is;
}

#endif /* _matrix_basic_cpp_ */