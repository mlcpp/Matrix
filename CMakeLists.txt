cmake_minimum_required(VERSION 3.13)
project (Matrix CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(FetchContent)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-w")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Externally provided libraries
set(BENCHMARK_ENABLE_TESTING NO)

FetchContent_Declare(
	googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG origin/master)

<<<<<<< HEAD
include_directories(${Matrix_SOURCE_DIR}/lib/googletest/googletest/include)
link_directories(${Matrix_SOURCE_DIR}/lib/googletest/googletest/build/src)
=======
FetchContent_Declare(
    googlebenchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG origin/master
)

FetchContent_MakeAvailable(
	googletest
	googlebenchmark	
)

include_directories(${Matrix_SOURCE_DIR}/include)
>>>>>>> eb7f8b4 (Fixes #62)

add_custom_target(examples)
add_subdirectory(examples)

add_custom_target(benchmarks)
add_subdirectory(benchmarks)

add_custom_target(tests)
add_subdirectory(tests)
