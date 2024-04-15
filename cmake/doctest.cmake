include(${CMAKE_CURRENT_LIST_DIR}/CPM.cmake)

# The fastest feature-rich single-header testing framework
# https://github.com/doctest/doctest
CPMAddPackage(
        NAME doctest
        VERSION 2.4.11
        GITHUB_REPOSITORY doctest/doctest
        OPTIONS "DOCTEST_WITH_MAIN_IN_STATIC_LIB OFF"
)

# This includes the `doctest_discover_tests(...)` macro.
include(${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake)
