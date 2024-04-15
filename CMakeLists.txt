cmake_minimum_required(VERSION 3.18...3.27)

project(myproject VERSION 0.0.1 LANGUAGES CXX)

# ---- Include guards ----
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there." )
endif()

# Determine whether this is a standalone project or included by other projects
set(MAIN_PROJECT OFF)
if (CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    set(MAIN_PROJECT ON)
endif()
# Establish the project options
option(MYPROJECT_BUILD_TESTS "Set to ON to build tests" ${MAIN_PROJECT})
option(MYPROJECT_PYTHON_BUILD "Set to ON to build python bindings" ${MAIN_PROJECT})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# ---- Add dependencies via CPM ----
# see https://github.com/TheLartians/CPM.cmake for more info
include(cmake/CPM.cmake)
CPMAddPackage("gh:jarro2783/cxxopts@3.2.0") # Lightweight C++ command line option parser                                https://github.com/jarro2783/cxxopts
include(cmake/abseil.cmake)                 # Abseil Common Libraries (C++)                                             https://github.com/abseil/abseil-cpp
include(cmake/nlohmann_json.cmake)          # JSON for Modern C++                                                       https://github.com/nlohmann/json
include(cmake/libcoro.cmake)                # libcoro C++20 coroutine library                                           https://github.com/jbaldwin/libcoro
include(cmake/pegtl.cmake)                  # Parsing Expression Grammar Template Library                               https://github.com/taocpp/PEGTL


# Export only public symbols
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN ON)

add_subdirectory(src)

if (MYPROJECT_PYTHON_BUILD)
    add_subdirectory(python)
endif()

# Enable testing when requested by the user
if (MYPROJECT_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif ()
