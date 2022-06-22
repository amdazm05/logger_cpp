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


# Make this as an install library
