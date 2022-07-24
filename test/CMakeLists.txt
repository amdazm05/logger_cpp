cmake_minimum_required(VERSION 3.0)
set(BENCHMARK_ENABLE_TESTING NO)

include(FetchContent)

FetchContent_Declare(
    googlebenchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG origin/master
)

FetchContent_MakeAvailable(googlebenchmark)

add_executable(test ${PROJECT_SOURCE_DIR}/test/test.cpp)
target_link_libraries(test PUBLIC LOGGER benchmark::benchmark)
