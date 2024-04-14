include(${CMAKE_CURRENT_LIST_DIR}/CPM.cmake)

# libcoro C++20 coroutine library
# https://github.com/jbaldwin/libcoro
CPMAddPackage(
        NAME libcoro
        GITHUB_REPOSITORY jbaldwin/libcoro
        VERSION 0.11.1
        OPTIONS "LIBCORO_BUILD_TESTS OFF" "LIBCORO_BUILD_EXAMPLES OFF" "LIBCORO_FEATURE_NETWORKING OFF" "LIBCORO_FEATURE_TLS OFF"
        EXCLUDE_FROM_ALL
)
