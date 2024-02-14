cmake_minimum_required(VERSION 3.12...3.14 FATAL_ERROR)
set(MAJOR_VERSION 1)
set(MINOR_VERSION 0)
set(PATCH_VERSION 0)
project(timberline VERSION ${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION})
file(GLOB TEST_PATHS ${CMAKE_SOURCE_DIR}/test/*.cc ${CMAKE_SOURCE_DIR}/test/*.cpp)
configure_file(
  ${CMAKE_SOURCE_DIR}/include/version/version.h.in
  ${CMAKE_BINARY_DIR}/include/version/version.h
)

foreach(TEST_SOURCE ${TEST_PATHS})
    cmake_path(GET TEST_SOURCE STEM TEST_NAME)
    set_source_files_properties(${TEST_SOURCE} PROPERTIES LANGUAGES CXX)
    add_executable(${TEST_NAME} ${TEST_SOURCE})
    target_compile_features(${TEST_NAME} PUBLIC cxx_std_20)
endforeach()