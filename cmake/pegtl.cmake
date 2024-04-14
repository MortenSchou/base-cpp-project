include(${CMAKE_CURRENT_LIST_DIR}/CPM.cmake)

# Parsing Expression Grammar Template Library
# https://github.com/taocpp/PEGTL
CPMAddPackage(
        NAME pegtl
        VERSION 3.2.7
        URL https://github.com/taocpp/PEGTL/archive/refs/tags/3.2.7.tar.gz
        URL_HASH SHA512=e996be569e1c25377b13870c4f3e59f1935bbf24bb7c6edca0edc85b304fbe3d05db52a303839b0bd50c78769b773fc2237814787a703c58de8a79398210ee34
)
