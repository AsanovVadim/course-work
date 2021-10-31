cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)

add_library(model Model.cpp LinRegFactory.cpp LogRegFactory.cpp)

target_link_libraries(model trainer predictor regulazer)

target_include_directories(model PUBLIC ${PROJECT_SOURCE_DIR}/Trainer/Regularizers)
