cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_COMPILER "/usr/bin/g++")
# set the project name

project(laberinto
VERSION 1.0
LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#add_subdirectory(src)
#add_subdirectory(tests)

add_executable(test test/test.cpp src/tt.cpp src/ttNode.cpp src/abb.cpp src/abbNode.cpp src/avl.cpp src/avlNode.cpp src/utils.cpp)
target_include_directories(test PUBLIC ${PROJECT_SOURCE_DIR}/include)


# add the executable