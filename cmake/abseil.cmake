include(${CMAKE_CURRENT_LIST_DIR}/CPM.cmake)

# Abseil is a collection of fundamental libraries originally developed by Google.
# https://github.com/abseil/abseil-cpp
CPMAddPackage(
        NAME abseil
        GIT_REPOSITORY https://github.com/abseil/abseil-cpp.git
        GIT_TAG master
#        URL https://github.com/abseil/abseil-cpp/archive/refs/tags/20240116.2.tar.gz
#        URL_HASH SHA512=5062e731ee8c9a757e6d75fc1c558652deb4dd1daab4d6143f7ad52a139501c61365f89acbf82480be0f9a4911a58286560068d8b1a8b6774e6afad51739766e
        OPTIONS "ABSL_ENABLE_INSTALL ON" "ABSL_PROPAGATE_CXX_STD ON"
        EXCLUDE_FROM_ALL
)
