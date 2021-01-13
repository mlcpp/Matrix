add_dependencies(examples
	abs
	addition
	argmin_argmax
	concatenate
	delete_
	determinant
	element_wise_multiplication
	exp
	genfromtxt
	get_mat
	indexing
	initialize
	inverse
	log
	matrix_calc
	matrix_multiplication
	min_max
	power
	reciprocal
	slice_matrix
	slice_select
	sqrt
	string_to_double
	transpose
	unary_minus
	view_matrix
)
add_executable(abs abs.cpp)
add_executable(addition addition.cpp)
add_executable(argmin_argmax argmin_argmax.cpp)
add_executable(concatenate concatenate.cpp)
add_executable(delete_ delete_.cpp)
add_executable(determinant determinant.cpp)
add_executable(element_wise_multiplication element_wise_multiplication.cpp)
add_executable(exp exp.cpp)
add_executable(genfromtxt genfromtxt.cpp)
add_executable(get_mat get_mat.cpp)
add_executable(indexing indexing.cpp)
add_executable(initialize initialize.cpp)
add_executable(inverse inverse.cpp)
add_executable(log log.cpp)
add_executable(matrix_calc matrix_calc.cpp)
add_executable(matrix_multiplication matrix_multiplication.cpp)
add_executable(min_max min_max.cpp)
add_executable(power power.cpp)
add_executable(reciprocal reciprocal.cpp)
add_executable(slice_matrix slice_matrix.cpp)
add_executable(slice_select slice_select.cpp)
add_executable(sqrt sqrt.cpp)
add_executable(string_to_double string_to_double.cpp)
add_executable(transpose transpose.cpp)
add_executable(unary_minus unary_minus.cpp)
add_executable(view_matrix view_matrix.cpp)
add_executable(matop matrix_operations.cpp $<TARGET_OBJECTS:MAT>)
add_executable(matbasic matrix_basic.cpp $<TARGET_OBJECTS:MAT>)