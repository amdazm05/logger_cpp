cmake_minimum_required(VERSION 3.0)
project(main)
add_library(
    LOGGER
        STATIC
    ${PROJECT_SOURCE_DIR}/src/logger.cc   
)

target_include_directories(
    LOGGER
        PUBLIC
    ${PROJECT_SOURCE_DIR}/include/
)

add_executable(main main.cpp)
target_link_libraries(main PUBLIC LOGGER)
add_subdirectory(test)
# Make this as an install library

