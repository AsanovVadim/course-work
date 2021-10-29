cmake_minimum_required(VERSION 3.17)
project(CourseWork)

set(CMAKE_CXX_STANDARD 20)

include_directories(DataMatrix) # там ищем исходники
include_directories(Trainer)
include_directories(Predictor)
include_directories(Model)
add_subdirectory(DataMatrix)    # там создаем подпроект (библиотеку)
add_subdirectory(Trainer)
add_subdirectory(Predictor)
add_subdirectory(Model)

add_executable(CourseWork main.cpp)

target_link_libraries(CourseWork data_matrix model)   # подключаем библиотеку к программе
