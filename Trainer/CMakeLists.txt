cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(Regularizers)

add_library(trainer CommonGradient.cpp StochasticGradient.cpp Trainer.cpp LogLossGradient.cpp LogLossStochastic.cpp)

target_include_directories(trainer PUBLIC ${PROJECT_SOURCE_DIR}/VectorLib)

