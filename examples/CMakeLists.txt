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
	transpose
	unary_minus
	view_matrix
)
add_executable(abs abs.cpp $<TARGET_OBJECTS:MAT>)
add_executable(addition addition.cpp $<TARGET_OBJECTS:MAT>)
add_executable(argmin_argmax argmin_argmax.cpp $<TARGET_OBJECTS:MAT>)
add_executable(concatenate concatenate.cpp $<TARGET_OBJECTS:MAT>)
add_executable(delete_ delete_.cpp $<TARGET_OBJECTS:MAT>)
add_executable(determinant determinant.cpp $<TARGET_OBJECTS:MAT>)
add_executable(element_wise_multiplication element_wise_multiplication.cpp $<TARGET_OBJECTS:MAT>)
add_executable(exp exp.cpp $<TARGET_OBJECTS:MAT>)
add_executable(genfromtxt genfromtxt.cpp $<TARGET_OBJECTS:MAT>)
add_executable(get_mat get_mat.cpp $<TARGET_OBJECTS:MAT>)
add_executable(indexing indexing.cpp $<TARGET_OBJECTS:MAT>)
add_executable(initialize initialize.cpp $<TARGET_OBJECTS:MAT>)
add_executable(inverse inverse.cpp $<TARGET_OBJECTS:MAT>)
add_executable(log log.cpp $<TARGET_OBJECTS:MAT>)
add_executable(matrix_calc matrix_calc.cpp $<TARGET_OBJECTS:MAT>)
add_executable(matrix_multiplication matrix_multiplication.cpp $<TARGET_OBJECTS:MAT>)
add_executable(min_max min_max.cpp $<TARGET_OBJECTS:MAT>)
add_executable(power power.cpp $<TARGET_OBJECTS:MAT>)
add_executable(reciprocal reciprocal.cpp $<TARGET_OBJECTS:MAT>)
add_executable(slice_matrix slice_matrix.cpp $<TARGET_OBJECTS:MAT>)
add_executable(slice_select slice_select.cpp $<TARGET_OBJECTS:MAT>)
add_executable(sqrt sqrt.cpp $<TARGET_OBJECTS:MAT>)
add_executable(transpose transpose.cpp $<TARGET_OBJECTS:MAT>)
add_executable(unary_minus unary_minus.cpp $<TARGET_OBJECTS:MAT>)
add_executable(view_matrix view_matrix.cpp $<TARGET_OBJECTS:MAT>)