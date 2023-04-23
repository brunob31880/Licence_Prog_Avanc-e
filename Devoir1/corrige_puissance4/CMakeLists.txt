cmake_minimum_required(VERSION 3.0)

project(Puissance4 VERSION 1.0)

set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -Wall --coverage")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall --coverage")

add_executable(${CMAKE_PROJECT_NAME} src/main.c src/p4.c src/utils.c)
