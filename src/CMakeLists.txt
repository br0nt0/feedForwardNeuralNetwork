cmake_minimum_required(VERSION  3.13.0)

add_library(${EXECUTABLE})
target_include_directories(${EXECUTABLE} PRIVATE
                                ${PROJECT_INCLUDE_DIR})
target_sources(${EXECUTABLE} PRIVATE 
                                ${PROJECT_DIR}/activationFunctions.c)