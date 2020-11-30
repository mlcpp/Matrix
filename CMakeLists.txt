cmake_minimum_required(VERSION 3.13)
project (Matrix CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(${Matrix_SOURCE_DIR}/include)

add_subdirectory(examples)

