cmake_minimum_required(VERSION 3.18...3.27)

project(myproject_tests LANGUAGES CXX)

cmake_policy(SET CMP0063 NEW)

include(../cmake/benchmark.cmake) # A microbenchmark support library                            https://github.com/google/benchmark
include(../cmake/doctest.cmake)   # The fastest feature-rich single-header testing framework    https://github.com/doctest/doctest

enable_testing()

# Make test executable
add_executable(tests main.cpp example_test.cpp) # More test .cpp files can be added here.
target_link_libraries(tests PRIVATE doctest::doctest example_lib)
target_compile_options(tests PUBLIC -Wall -Wpedantic -Wextra -Werror)
doctest_discover_tests(tests)

# Make benchmark execuable
add_executable(example_benchmark example_bm.cpp)
target_link_libraries(example_benchmark PRIVATE benchmark::benchmark_main)
add_test(NAME example_benchmark COMMAND example_benchmark)
