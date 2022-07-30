cmake_minimum_required(VERSION 3.0)
project(logger)
option(TESTS "TESTING IS DISABLED" OFF)
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

if(TESTS)
add_subdirectory(test)
endif(TESTS)

# Make this as an install library

