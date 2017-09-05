cmake_minimum_required(VERSION 3.8)
project(ordered_table)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp include/OrderedTable.h include/Table.h)
add_executable(ordered_table ${SOURCE_FILES})