cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)

add_library(regulazer Lasso.cpp Ridge.cpp)

target_include_directories(regulazer PUBLIC ${PROJECT_SOURCE_DIR}/VectorLib)
