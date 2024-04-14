include(${CMAKE_CURRENT_LIST_DIR}/CPM.cmake)

# JSON for Modern C++
# https://github.com/nlohmann/json
CPMAddPackage(
        NAME nlohmann_json
        VERSION 3.11.3
        # the git repo is incredibly large, so we download the archived include directory
        URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
        URL_HASH SHA512=1aa94cdc3378a1fe0e3048ee73293e34bfa5ed9b46c6db0993e58e289ef818f7b7a472c0dc9c920114312e2e3ae1ff346ca797407ff48143744592adfd0a41ad
)
