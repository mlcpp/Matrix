# Matrix

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
|   `read_csv()`   |                <p>_1 Parameter:_<br>Type: `std::string`<br>Job: File Name of the `.csv` file</p>                 | `Matrix` object  |        Creates a `Matrix` object with data elements of type `std::string`.         |

### Slicing

`Matrix` objects can be sliced like `Numpy` arrays.
**Note:**First convert the `Matrix` elements' data type to double using `Matrix.to_double()`.

|   **Function**   |                                                                   **Parameters**                                                                   | **Return value** |                        **Description**                        |
| :--------------: | :------------------------------------------------------------------------------------------------------------------------------------------------: | :--------------: | :-----------------------------------------------------------: |
| `Matrix.slice()` | <p>_4 Parameter:_<br>Type: `int`; `int`; `int`; `int`<br>Job: Starting row index; Ending row index; Starting column index; Ending column index</p> | `Matrix` object  | Slices the `Matrix` object according to the indices provided. |

### Printing/Viewing

A number of methods are provided to print/view a `Matrix` object in different ways.

|   **Function**   |                                                                   **Parameters**                                                                   | **Return value** |                        **Description**                        |
| :--------------: | :------------------------------------------------------------------------------------------------------------------------------------------------: | :--------------: | :-----------------------------------------------------------: |
| `matrix.print()` |                                                                  <p>_0 Parameter_                                                                  |      `void`      |      Prints the whole `Matrix` object onto the console.       |
| `matrix.head()`  |                                                                  <p>_0 Parameter_                                                                  |      `void`      | Prints first 5 rows of the `Matrix` object onto the console.  |
| `matrix.tail()`  |                                                                  <p>_0 Parameter_                                                                  |      `void`      | Prints first 5 rows of the `Matrix` object onto the console.  |
| `matrix.view()`  |                                    <p>_2 Parameters:_<br>Type: `int`; `int`<br>Job: row index; column index</p>                                    |      `void`      |            Prints the value on the provided index.            |
| `matrix.view()`  | <p>_4 Parameters:_<br>Type: `int`; `int`; `int`; `int`<br>ob: Starting row index; Ending row index; Starting column index; Ending column index</p> |      `void`      | Prints the `Matrix` object according to the indices provided. |

### Minimum, Maximum

|   **Function**    |                                                                   **Parameters**                                                                   | **Return value** |                    **Description**                     |
| :---------------: | :------------------------------------------------------------------------------------------------------------------------------------------------: | :--------------: | :----------------------------------------------------: |
|  `matrix.min()`   |          <p>_2 Parameters:_<br>Type: `Matrix`; `std::string`<br>Job: `Matrix` to find minimum; dimension across which to find minimum</p>          | `Matrix` object  |     Method to get the minimum value along an axis      |
|  `matrix.max()`   |          <p>_2 Parameters:_<br>Type: `Matrix`; `std::string`<br>Job: `Matrix` to find maximum; dimension across which to find maximum</p>          | `Matrix` object  |     Method to get the maximum value along an axis      |
| `matrix.argmin()` | <p>_2 Parameters:_<br>Type: `Matrix`; `std::string`<br>Job: `Matrix` to find index of minimum; dimension across which to find index of minimum</p> | `Matrix` object  | Method to get the index of minimum value along an axis |
| `matrix.argmax()` | <p>_2 Parameters:_<br>Type: `Matrix`; `std::string`<br>Job: `Matrix` to find index of maximum; dimension across which to find index of maximum</p> | `Matrix` object  | Method to get the index of maximum value along an axis |
