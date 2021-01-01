# Matrix

##  TABLE OF CONTENTS
1. [Installation](#Installation)

2. [Development](##Development)

      [Linux](###Linux)
      [Windows](###Windows)

3. [Benchmarking](##Benchmarking)

4. [Quick Start Guide](##Quick-Start-Guide)

      [Initializers](###Initializers)

      [Slicing](###Slicing)

      [Printing/Viewing](###Printing/Viewing)

      [Minimum/Maximum](###Minimum/Maximum)

      [Broadcasting](###Broadcasting)

      [Indexing](###Indexing)

      [Mathematical-Operations](###Mathematical-Operations)

      [Statistical-Operations](###Statistical-Operations)

      [Matrix-Algebra](###Matrix-Algebra)

      [Miscellaneous](###Miscellaneous)


## Installation

This describes the installation process using cmake. As pre-requisites, you'll
need git and cmake installed.

```bash
# Check out the library.
$ git clone https://github.com/mlcpp/Matrix.git

# Make a build directory to place the build output.
$ cmake -E make_directory "build"

# Generate build system files with cmake.
$ cmake -E chdir "build" cmake -DCMAKE_BUILD_TYPE=Release ../

# Build the library.
$ cmake -DCMAKE_BUILD_TYPE=Release -S . -B "build"

```
On a unix system, the build directory should now look something like this:

```
/Matrix
  /build
    /examples
      /abs
      /addition
      ...
```

## Development

### Linux

#### Prerequisites

1. C++ compiler (gcc or clang)
2. git
3. clang-format
5. make (for Makefiles)
4. cmake (version 3.13 or higher)

```bash
# Check out the library.
$ git clone https://github.com/mlcpp/Matrix.git && cd Matrix

# Create build directory.
$ mkdir build

# Enter into build directory.
$ cd build

# Run CMake. This step will generate a Makefile in the build/ folder.
$ cmake ../

# Compile all files and place the binaries inside build/examples/ folder.
$ make

# Compile single file and place the binary inside build/examples/ folder.
$ make <file_name_without_extension>
```

### Windows

#### Prerequisites

1. C++ compiler (mingw-gcc)
2. git (msysgit)
3. clang-format
5. mingw-make or mingw32-make (for Makefiles)
4. cmake (version 3.13 or higher)

Add these tools to PATH. 

__Note__: Run the following commands in msysgit terminal. 

```bash
# Check out the library.
$ git clone https://github.com/mlcpp/Matrix.git && cd Matrix

# Create build directory.
$ mkdir build

# Enter into build directory.
$ cd build

# Run CMake. This step will generate a Makefile in the build/ folder.
$ cmake ../

# Compile all files and place the binaries inside build/examples/ folder.
$ mingw-make                                          # use mingw32-make if using 32-bit Windows

# Compile single file and place the binary inside build/examples/ folder.
$ mingw-make <file_name_without_extension>            # use mingw32-make if using 32-bit Windows
```


## Benchmarking

To compile benchmarking binaries:

Linux:

`g++ <file_name>.cpp -std=c++11 -I../include/ -isystem ../lib/benchmark/include -L../lib/benchmark/build/src -lbenchmark -lpthread -o ./linux_binaries/<file_name>`

## Quick Start Guide

This guide contains detailed explaination of all the methods and functions available and how to use them.

More detailed information about how to use these methods and functions is available in `/examples`.

### Initializers

Many initializer functions are provided that return `Matrix` object.

|   **Function**   |                                                  **Parameters**                                                  | **Return value** |                                  **Description**                                   |
| :--------------: | :--------------------------------------------------------------------------------------------------------------: | :--------------: | :--------------------------------------------------------------------------------: |
| `matrix.init()`  | <p>_1 Parameter:_<br>Type: `std::vector<std::vector<double>>`<br>Job: vector of vector of type string/double</p> | `Matrix` object  | Creates a `Matrix` object of same dimensions and values as the 2D vector provided. |
|  `matrix.eye()`  |                     <p>_1 Parameter:_<br>Type: `int`<br>Job: Size of the identity matrix</p>                     | `Matrix` object  |        Creates an identity `Matrix` object of the size given as parameters.        |
| `matrix.zeros()` |              <p>_2 Parameters:_<br>Type: `int`; `int`<br>Job: Number of rows; Number of columns</p>              | `Matrix` object  |   Creates a `Matrix` object of all elements `0` of the size given as parameters.   |
| `matrix.ones()`  |              <p>_2 Parameters:_<br>Type: `int`; `int`<br>Job: Number of rows; Number of columns</p>              | `Matrix` object  |   Creates a `Matrix` object of all elements `1` of the size given as parameters.   |
|   `matrix.genfromtxt()`   |                <p>_2 Parameters:_<br>Type: `std::string`;`char`<br>Job: Path of the `.csv` file</p>                 | `Matrix` object  |        Creates a `Matrix` object with data elements of type `std::string`.         |

### Slicing

`Matrix` objects can be sliced like `Numpy` arrays.

**Note:** First convert the `Matrix` elements' data type to double using `Matrix.to_double()`.

|      **Function**       |                                                                                      **Parameters**                                                                                       | **Return value** |                                                          **Description**                                                           |
| :---------------------: | :---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------: | :--------------: | :--------------------------------------------------------------------------------------------------------------------------------: |
|    `Matrix.slice()`     |                    <p>_4 Parameter:_<br>Type: `int`; `int`; `int`; `int`<br>Job: Starting row index; Ending row index; Starting column index; Ending column index</p>                     | `Matrix` object  |                                   Slices the `Matrix` object according to the indices provided.                                    |
| `matrix.slice_select()` | <p>_4 Parameter:_<br>Type: `Matrix`; `Matrix`; `double`; `int`<br>Job: `Matrix` to select values on; `Matrix` to select values from; value to select; column index on which to select</p> | `Matrix` object  | Slices the `Matrix` object to get all rows which have value(3rd parameter) in second `Matrix` object and one column(4th parameter) |

### Printing/Viewing

A number of methods are provided to print/view a `Matrix` object in different ways.

|   **Function**   |                                                                   **Parameters**                                                                   | **Return value** |                        **Description**                        |
| :--------------: | :------------------------------------------------------------------------------------------------------------------------------------------------: | :--------------: | :-----------------------------------------------------------: |
| `matrix.print()` |                                                                 <p>_0 Parameters_                                                                  |      `void`      |      Prints the whole `Matrix` object onto the console.       |
| `matrix.head()`  |                                                                 <p>_0 Parameters_                                                                  |      `void`      | Prints first 5 rows of the `Matrix` object onto the console.  |
| `matrix.tail()`  |                                                                 <p>_0 Parameters_                                                                  |      `void`      | Prints first 5 rows of the `Matrix` object onto the console.  |
| `matrix.view()`  |                                    <p>_2 Parameters:_<br>Type: `int`; `int`<br>Job: row index; column index</p>                                    |      `void`      |            Prints the value on the provided index.            |
| `matrix.view()`  | <p>_4 Parameters:_<br>Type: `int`; `int`; `int`; `int`<br>ob: Starting row index; Ending row index; Starting column index; Ending column index</p> |      `void`      | Prints the `Matrix` object according to the indices provided. |

### Minimum, Maximum

|   **Function**    |                                                                   **Parameters**                                                                   | **Return value** |                    **Description**                     |
| :---------------: | :------------------------------------------------------------------------------------------------------------------------------------------------: | :--------------: | :----------------------------------------------------: |
|  `matrix.min()`   |          <p>_2 Parameters:_<br>Type: `Matrix`; `std::string`<br>Job: `Matrix` to find minimum; dimension across which to find minimum</p>          | `Matrix` object  |     Method to get the minimum value along an axis      |
|  `matrix.max()`   |          <p>_2 Parameters:_<br>Type: `Matrix`; `std::string`<br>Job: `Matrix` to find maximum; dimension across which to find maximum</p>          | `Matrix` object  |     Method to get the maximum value along an axis      |
| `matrix.argmin()` | <p>_2 Parameters:_<br>Type: `Matrix`; `std::string`<br>Job: `Matrix` to find index of minimum; dimension across which to find index of minimum</p> | `Matrix` object  | Method to get the index of minimum value along an axis |
| `matrix.argmax()` | <p>_2 Parameters:_<br>Type: `Matrix`; `std::string`<br>Job: `Matrix` to find index of maximum; dimension across which to find index of maximum</p> | `Matrix` object  | Method to get the index of maximum value along an axis |

### Broadcasting

Broadcasting is in-built in the Basic Mathematical operations i.e., addition, subtraction, multiplication and division.

Following binary operations are possible:

<ul>
<li>Matrix = Matrix @ Matrix
<li>Matrix = Matrix @ Vector
<li>Matrix = Matrix @ Scalar
</ul>

where, @ is any operator from (+, -, \*, /)

**Note:** Vector is a `Matrix` object where row length **or** column length is equal to 1.

Following unary operations are possible:

<ul>
<li>Matrix = @Matrix
</ul>

where, @ is any operator from (-)

### Indexing

Indexing can be used to get or assign value to a particular element.

For example, let there is a `Matrix` object named mat. If we want to get the value at index (5,3) we can do this as follows:

    double val = mat(5,3);

Similarly, if we want to assign the value to index (5,3) we can do this by:

    mat(5,3) = 10.54;

### Mathematical Operations

|   **Function**   |                                                      **Parameters**                                                       | **Return value** |                                   **Description**                                   |
| :--------------: | :-----------------------------------------------------------------------------------------------------------------------: | :--------------: | :---------------------------------------------------------------------------------: |
| `matrix.sqrt()`  |                    <p>_1 Parameter:_<br>Type: `Matrix`<br>Job: `Matrix` object to apply method on</p>                     | `Matrix` object  |             Method to get the sqrt of each element of a`Matrix` object              |
| `matrix.power()` | <p>_2 Parameters:_<br>Type: `Matrix`; `double`<br>Job: `Matrix` object to apply method on; power of `Matrix` elements</p> | `Matrix` object  |           Method to calculate power of each element of a `Matrix` object            |
| `matrix.power()` | <p>_2 Parameters:_<br>Type: `Matrix`; `Matrix`<br>Job: `Matrix` object to apply method on; power of `Matrix` elements</p> | `Matrix` object  |           Method to calculate power of each element of a `Matrix` object            |
|  `matrix.exp()`  |                    <p>_1 Parameter:_<br>Type: `Matrix`<br>Job: `Matrix` object to apply method on</p>                     | `Matrix` object  |       Method to calculate exponential of all elements in the `Matrix` object        |
|  `matrix.log()`  |                    <p>_1 Parameter:_<br>Type: `Matrix`<br>Job: `Matrix` object to apply method on</p>                     | `Matrix` object  | Method to calculate natural logarithm of all elements in the in the `Matrix` object |
|  `matrix.abs()`  |                    <p>_1 Parameter:_<br>Type: `Matrix`<br>Job: `Matrix` object to apply method on</p>                     | `Matrix` object  |     Method to get absolute value of all elements in the in the `Matrix` object      |

**Note:** Broadcasting in power() methods works in the same way as in Basic Mathematical operations.

### Statistical Operations

|  **Function**   |                                                                     **Parameters**                                                                     | **Return value** |                               **Description**                                |
| :-------------: | :----------------------------------------------------------------------------------------------------------------------------------------------------: | :--------------: | :--------------------------------------------------------------------------: |
| `matrix.sum()`  |        <p>_2 Parameters:_<br>Type: `Matrix`; `std::string`<br>Job: `Matrix` object to apply method on; Dimension on which to calculate sum</p>         | `Matrix` object  |         Method to calculate the sum over an axis of a`Matrix` object         |
| `matrix.mean()` |        <p>_2 Parameters:_<br>Type: `Matrix`; `std::string`<br>Job: `Matrix` object to apply method on; Dimension on which to calculate mean</p>        | `Matrix` object  |        Method to calculate the mean over an axis of a `Matrix` object        |
| `matrix.std()`  | <p>_2 Parameters:_<br>Type: `Matrix`; `std::string`<br>Job: `Matrix` object to apply method on; Dimension on which to calculate standard deviation</p> | `Matrix` object  | Method to calculate the standard deviation over an axis of a `Matrix` object |

### Matrix Algebra

|      **Function**      |                                                                 **Parameters**                                                                 | **Return value** |                     **Description**                      |
| :--------------------: | :--------------------------------------------------------------------------------------------------------------------------------------------: | :--------------: | :------------------------------------------------------: |
|      `Matrix.T()`      |                                                               <p>_0 Parameters_                                                                | `Matrix` object  |    Method to return the Tranpose of a`Matrix` object     |
|   `matrix.matmul()`    | <p>_2 Parameters:_<br>Type: `Matrix`; `Matrix`<br>Job: First `Matrix` for matrix multiplication; Second `Matrix` for matrix multiplication</p> | `Matrix` object  |        Method to calculate matrix multiplication         |
| `matrix.determinant()` |        <p>_2 Parameters:_<br>Type: `Matrix`; `int`<br>Job: `Matrix` object to calculate determinant of; Size of the `Matrix` object</p>        |     `double`     | Method to calculate the Determinant of a `Matrix` object |
|   `matrix.inverse()`   |                            <p>_1 Parameter:_<br>Type: `Matrix`<br>Job: `Matrix` object to calculate inverse of</p>                             | `Matrix` object  |   Method to calculate the Inverse of a `Matrix` object   |

### Miscellaneous

|     **Function**      |                                                                                **Parameters**                                                                                 |          **Return value**          |                               **Description**                               |
| :-------------------: | :---------------------------------------------------------------------------------------------------------------------------------------------------------------------------: | :--------------------------------: | :-------------------------------------------------------------------------: |
|   `matrix.concatenate()`   | <p>_3 Parameters:_<br>Type: `Matrix`; `Matrix`; `std::string`<br>Job: `Matrix` to concatenate on; `Matrix` which is to be concatenated; Dimension on which to concatenate</p> |          `Matrix` object           |               Method to concatenate/join two `Matrix` objects               |
|    `Matrix.get()`     |                                                                               <p>_0 Parameters_                                                                               | `std::vector<std::vector<double>>` |              Method to get the `Matrix` object as a 2D vector               |
|  `Matrix.get_row()`   |                                                            <p>_1 Parameter:_<br>Type: `int`<br>Job: row index</p>                                                             |       `std::vector<double>`        |      Method to get a row of a `Matrix` object in the form of a vector       |
|  `Matrix.get_col()`   |                                                           <p>_1 Parameter:_<br>Type: `int`<br>Job: column index</p>                                                           |       `std::vector<double>`        |     Method to get a column of a `Matrix` object in the form of a vector     |
|    `matrix.delete_()`     |          <p>_3 Parameters:_<br>Type: `Matrix`; `int`; `std::string`<br>Job: `Matrix` to delete row/column of; index to be deleted; Dimension on which to delete</p>           |          `Matrix` object           |            Method to delete a row or column of a `Matrix` object            |
| `matrix.reciprocal()` |                                              <p>_1 Parameter:_<br>Type: `Matrix`<br>Job: `Matrix` object to apply method on</p>                                               |          `Matrix` object           |    Method to calculate reciprocal of all elements in the `Matrix` object    |
| `Matrix.row_length()` |                                                                               <p>_0 Parameters_                                                                               |               `int`                |            Method to get the number of rows in a `Matrix` object            |
| `Matrix.col_length()` |                                                                               <p>_0 Parameters_                                                                               |               `int`                |          Method to get the number of columns in a `Matrix` object           |
| `Matrix.to_double()`  |                                                                               <p>_0 Parameters_                                                                               |               `void`               | Method convert the elements of a `Matrix` object from std::string to double |
| `Matrix.to_string()`  |                                                                               <p>_0 Parameters_                                                                               |               `void`               | Method convert the elements of a `Matrix` object from double to std::string |
