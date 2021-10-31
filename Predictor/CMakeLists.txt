cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)

add_library(predictor Predictor.cpp LinearRegressionPredictor.cpp LogRegressionPredictor.cpp)

target_include_directories(predictor PUBLIC ${PROJECT_SOURCE_DIR}/VectorLib)
