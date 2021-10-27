cmake_minimum_required(VERSION 3.17)

set(CMAKE_CXX_STANDARD 20)

add_library(trainer MSEGradientTrainer.cpp Trainer.cpp)

target_include_directories(trainer PUBLIC ${PROJECT_SOURCE_DIR}/VectorLib)
