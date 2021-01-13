add_dependencies(benchmarks
	BM_abs
	BM_add_n_assign
	BM_addition
	BM_all
	BM_argmax
	BM_argmin
	BM_concatenate
	BM_decrement
	BM_delete_
	BM_determinant
	BM_element_wise_mult_n_assign
	BM_element_wise_multiplication
	BM_exp
	BM_eye
	BM_genfromtxt
	BM_get
	BM_increment
	BM_indexing
	BM_init
	BM_inverse
	BM_log
	BM_matmul
	BM_max
	BM_mean
	BM_min
	BM_ones
	BM_power
	BM_reciprocal
	BM_slice
	BM_slice_select
	BM_sqrt
	BM_std
	BM_sum
	BM_T
	BM_to_double
	BM_unary_minus
	BM_zeros
)
add_executable(BM_abs BM_abs.cpp)
target_link_libraries(BM_abs PUBLIC benchmark benchmark_main pthread)

add_executable(BM_add_n_assign BM_add_n_assign.cpp)
target_link_libraries(BM_add_n_assign PUBLIC benchmark benchmark_main pthread)

add_executable(BM_addition BM_addition.cpp)
target_link_libraries(BM_addition PUBLIC benchmark benchmark_main pthread)

add_executable(BM_all BM_all.cpp)
target_link_libraries(BM_all PUBLIC benchmark benchmark_main pthread)

add_executable(BM_argmax BM_argmax.cpp)
target_link_libraries(BM_argmax PUBLIC benchmark benchmark_main pthread)

add_executable(BM_argmin BM_argmin.cpp)
target_link_libraries(BM_argmin PUBLIC benchmark benchmark_main pthread)

add_executable(BM_concatenate BM_concatenate.cpp)
target_link_libraries(BM_concatenate PUBLIC benchmark benchmark_main pthread)

add_executable(BM_decrement BM_decrement.cpp)
target_link_libraries(BM_decrement PUBLIC benchmark benchmark_main pthread)

add_executable(BM_delete_ BM_delete_.cpp)
target_link_libraries(BM_delete_ PUBLIC benchmark benchmark_main pthread)

add_executable(BM_determinant BM_determinant.cpp)
target_link_libraries(BM_determinant PUBLIC benchmark benchmark_main pthread)

add_executable(BM_element_wise_mult_n_assign BM_element_wise_mult_n_assign.cpp)
target_link_libraries(BM_element_wise_mult_n_assign PUBLIC benchmark benchmark_main pthread)

add_executable(BM_element_wise_multiplication BM_element_wise_multiplication.cpp)
target_link_libraries(BM_element_wise_multiplication PUBLIC benchmark benchmark_main pthread)

add_executable(BM_exp BM_exp.cpp)
target_link_libraries(BM_exp PUBLIC benchmark benchmark_main pthread)

add_executable(BM_eye BM_eye.cpp)
target_link_libraries(BM_eye PUBLIC benchmark benchmark_main pthread)

add_executable(BM_genfromtxt BM_genfromtxt.cpp)
target_link_libraries(BM_genfromtxt PUBLIC benchmark benchmark_main pthread)

add_executable(BM_get BM_get.cpp)
target_link_libraries(BM_get PUBLIC benchmark benchmark_main pthread)

add_executable(BM_increment BM_increment.cpp)
target_link_libraries(BM_increment PUBLIC benchmark benchmark_main pthread)

add_executable(BM_indexing BM_indexing.cpp)
target_link_libraries(BM_indexing PUBLIC benchmark benchmark_main pthread)

add_executable(BM_init BM_init.cpp)
target_link_libraries(BM_init PUBLIC benchmark benchmark_main pthread)

add_executable(BM_inverse BM_inverse.cpp)
target_link_libraries(BM_inverse PUBLIC benchmark benchmark_main pthread)

add_executable(BM_log BM_log.cpp)
target_link_libraries(BM_log PUBLIC benchmark benchmark_main pthread)

add_executable(BM_matmul BM_matmul.cpp)
target_link_libraries(BM_matmul PUBLIC benchmark benchmark_main pthread)

add_executable(BM_max BM_max.cpp)
target_link_libraries(BM_max PUBLIC benchmark benchmark_main pthread)

add_executable(BM_mean BM_mean.cpp)
target_link_libraries(BM_mean PUBLIC benchmark benchmark_main pthread)

add_executable(BM_min BM_min.cpp)
target_link_libraries(BM_min PUBLIC benchmark benchmark_main pthread)

add_executable(BM_ones BM_ones.cpp)
target_link_libraries(BM_ones PUBLIC benchmark benchmark_main pthread)

add_executable(BM_power BM_power.cpp)
target_link_libraries(BM_power PUBLIC benchmark benchmark_main pthread)

add_executable(BM_reciprocal BM_reciprocal.cpp)
target_link_libraries(BM_reciprocal PUBLIC benchmark benchmark_main pthread)

add_executable(BM_slice BM_slice.cpp)
target_link_libraries(BM_slice PUBLIC benchmark benchmark_main pthread)

add_executable(BM_slice_select BM_slice_select.cpp)
target_link_libraries(BM_slice_select PUBLIC benchmark benchmark_main pthread)

add_executable(BM_sqrt BM_sqrt.cpp)
target_link_libraries(BM_sqrt PUBLIC benchmark benchmark_main pthread)

add_executable(BM_std BM_std.cpp)
target_link_libraries(BM_std PUBLIC benchmark benchmark_main pthread)

add_executable(BM_sum BM_sum.cpp)
target_link_libraries(BM_sum PUBLIC benchmark benchmark_main pthread)

add_executable(BM_T BM_T.cpp)
target_link_libraries(BM_T PUBLIC benchmark benchmark_main pthread)

add_executable(BM_to_double BM_to_double.cpp)
target_link_libraries(BM_to_double PUBLIC benchmark benchmark_main pthread)

add_executable(BM_unary_minus BM_unary_minus.cpp)
target_link_libraries(BM_unary_minus PUBLIC benchmark benchmark_main pthread)

add_executable(BM_zeros BM_zeros.cpp)
target_link_libraries(BM_zeros PUBLIC benchmark benchmark_main pthread)

add_executable(matop matrix_operations.cpp $<TARGET_OBJECTS:MAT>)
add_executable(matbasic matrix_basic.cpp $<TARGET_OBJECTS:MAT>)