add_dependencies(tests
	test
)
add_executable(test test.cpp $<TARGET_OBJECTS:MAT>)
target_link_libraries(test PUBLIC gtest gtest_main pthread)