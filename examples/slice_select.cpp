#include <Matrix.hpp>

/* Example program

Read a csv file and get two Matrix objects X and Y.
Slice a selected column of those values of X into a new matrix where values of Y is equal to val.
The select Matrix object is then printed to the console.
*/
int main() {
    Matrix mat = genfromtxt("./datasets/boston/boston.csv",',');
    Matrix X = mat.slice(1, 5, 0, 2);
    Matrix Y = mat.slice(1, 5, 2, 3);
    X.to_double();
    Y.to_double();
    std::cout << "X = {" << std::endl;
    X.print();
    std::cout << "}" << std::endl;
    std::cout << "Y = {" << std::endl;
    Y.print();
    std::cout << "}" << std::endl;
    Matrix select = matrix.slice_select(X, Y, 7.07, 0);
    std::cout << "Select = {" << std::endl;
    select.print();
    std::cout << "}" << std::endl;
    return 0;
}
