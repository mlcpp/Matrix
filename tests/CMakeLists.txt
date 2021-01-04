add_dependencies(tests
	Tests
)
add_executable(Tests tests.cpp)
target_link_libraries(Tests PUBLIC gtest gtest_main pthread)