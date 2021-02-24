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
	BM_transpose
	BM_unary_minus
	BM_zeros
)
add_executable(BM_abs BM_abs.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_abs PUBLIC benchmark benchmark_main pthread MAT)

add_executable(BM_add_n_assign BM_add_n_assign.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_add_n_assign PUBLIC benchmark benchmark_main pthread)

add_executable(BM_addition BM_addition.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_addition PUBLIC benchmark benchmark_main pthread)

add_executable(BM_all BM_all.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_all PUBLIC benchmark benchmark_main pthread)

add_executable(BM_argmax BM_argmax.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_argmax PUBLIC benchmark benchmark_main pthread)

add_executable(BM_argmin BM_argmin.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_argmin PUBLIC benchmark benchmark_main pthread)

add_executable(BM_concatenate BM_concatenate.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_concatenate PUBLIC benchmark benchmark_main pthread)

add_executable(BM_decrement BM_decrement.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_decrement PUBLIC benchmark benchmark_main pthread)

add_executable(BM_delete_ BM_delete_.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_delete_ PUBLIC benchmark benchmark_main pthread)

add_executable(BM_determinant BM_determinant.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_determinant PUBLIC benchmark benchmark_main pthread)

add_executable(BM_element_wise_mult_n_assign BM_element_wise_mult_n_assign.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_element_wise_mult_n_assign PUBLIC benchmark benchmark_main pthread)

add_executable(BM_element_wise_multiplication BM_element_wise_multiplication.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_element_wise_multiplication PUBLIC benchmark benchmark_main pthread)

add_executable(BM_exp BM_exp.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_exp PUBLIC benchmark benchmark_main pthread)

add_executable(BM_eye BM_eye.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_eye PUBLIC benchmark benchmark_main pthread)

add_executable(BM_genfromtxt BM_genfromtxt.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_genfromtxt PUBLIC benchmark benchmark_main pthread)

add_executable(BM_get BM_get.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_get PUBLIC benchmark benchmark_main pthread)

add_executable(BM_increment BM_increment.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_increment PUBLIC benchmark benchmark_main pthread)

add_executable(BM_indexing BM_indexing.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_indexing PUBLIC benchmark benchmark_main pthread)

add_executable(BM_init BM_init.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_init PUBLIC benchmark benchmark_main pthread)

add_executable(BM_inverse BM_inverse.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_inverse PUBLIC benchmark benchmark_main pthread)

add_executable(BM_log BM_log.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_log PUBLIC benchmark benchmark_main pthread)

add_executable(BM_matmul BM_matmul.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_matmul PUBLIC benchmark benchmark_main pthread)

add_executable(BM_max BM_max.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_max PUBLIC benchmark benchmark_main pthread)

add_executable(BM_mean BM_mean.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_mean PUBLIC benchmark benchmark_main pthread)

add_executable(BM_min BM_min.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_min PUBLIC benchmark benchmark_main pthread)

add_executable(BM_ones BM_ones.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_ones PUBLIC benchmark benchmark_main pthread)

add_executable(BM_power BM_power.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_power PUBLIC benchmark benchmark_main pthread)

add_executable(BM_reciprocal BM_reciprocal.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_reciprocal PUBLIC benchmark benchmark_main pthread)

add_executable(BM_slice BM_slice.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_slice PUBLIC benchmark benchmark_main pthread)

add_executable(BM_slice_select BM_slice_select.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_slice_select PUBLIC benchmark benchmark_main pthread)

add_executable(BM_sqrt BM_sqrt.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_sqrt PUBLIC benchmark benchmark_main pthread)

add_executable(BM_std BM_std.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_std PUBLIC benchmark benchmark_main pthread)

add_executable(BM_sum BM_sum.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_sum PUBLIC benchmark benchmark_main pthread)

add_executable(BM_transpose BM_transpose.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_transpose PUBLIC benchmark benchmark_main pthread)

add_executable(BM_unary_minus BM_unary_minus.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_unary_minus PUBLIC benchmark benchmark_main pthread)

add_executable(BM_zeros BM_zeros.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(BM_zeros PUBLIC benchmark benchmark_main pthread)