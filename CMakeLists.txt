cmake_minimum_required(VERSION 3.13.0)
project(ffwnn VERSION 0.1.0 LANGUAGES C CXX)

set(PROJECT_DIR             ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(PROJECT_ROOT_DIR        ${CMAKE_CURRENT_SOURCE_DIR})
set(PROJECT_INCLUDE_DIR     ${PROJECT_DIR})

set(EXECUTABLE              ${CMAKE_PROJECT_NAME}) 

add_subdirectory(src)
add_subdirectory(tests)


