
# Make test executable
add_executable(tests main.cpp example_test.cpp) # More test .cpp files can be added here.
target_link_libraries(tests PRIVATE doctest::doctest)
target_compile_options(tests PUBLIC -Wall -Wpedantic -Wextra -Werror)
doctest_discover_tests(tests)

# Make benchmark execuable
add_executable(example_benchmark example_bm.cpp)
target_link_libraries(example_benchmark PRIVATE benchmark::benchmark_main)
add_test(NAME example_benchmark COMMAND example_benchmark)
