include(${CMAKE_CURRENT_LIST_DIR}/CPM.cmake)

# A microbenchmark support library
# https://github.com/google/benchmark
CPMAddPackage(
        NAME benchmark
        GITHUB_REPOSITORY google/benchmark
        VERSION 1.8.3
        OPTIONS "BENCHMARK_ENABLE_TESTING OFF"
)

if(benchmark_ADDED)
    # enable c++11 to avoid compilation errors
    set_target_properties(benchmark PROPERTIES CXX_STANDARD 11)
endif()
