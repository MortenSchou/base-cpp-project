include(${CMAKE_CURRENT_LIST_DIR}/CPM.cmake)

# The fastest feature-rich single-header testing framework
# https://github.com/doctest/doctest
CPMAddPackage("gh:doctest/doctest@2.4.11")

# This includes the `doctest_discover_tests(...)` macro.
include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)
