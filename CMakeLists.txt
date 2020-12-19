cmake_minimum_required(VERSION 3.13)
project (Matrix CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

# set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

include_directories(${Matrix_SOURCE_DIR}/include)
include_directories(${Matrix_SOURCE_DIR}/lib/benchmark/include)
link_directories(${Matrix_SOURCE_DIR}/lib/benchmark/build/src)


add_custom_target(examples)
add_subdirectory(examples)

add_custom_target(benchmarks)
add_subdirectory(benchmarks)
