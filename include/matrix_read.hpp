#ifndef _matrix_read_hpp_
#define _matrix_read_hpp_

#include <all.h>
#include <matrix.hpp>

// Method to read a csv file and return a Matrix object
Matrix read_csv(std::string filename) {
    Matrix mat;
    std::ifstream file(filename);
    std::string line, cell;
    std::vector<std::string> cells;
    char delim = ',';

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        while (std::getline(ss, cell, delim)) {
            cells.push_back(cell);
        }
        mat.str_mat.push_back(cells);
        cells.clear();
    }

    return mat;
}

#endif /* _matrix_read_hpp_ */