cmake_minimum_required(VERSION 3.17)
project(CourseWork)

set(CMAKE_CXX_STANDARD 20)

include_directories(DataMatrix) # там ищем исходники
add_subdirectory(DataMatrix)    # там создаем подпроект (библиотеку)

add_executable(CourseWork main.cpp)

target_link_libraries(CourseWork data_matrix)   # подключаем библиотеку к программе
