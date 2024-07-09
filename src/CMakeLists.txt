
add_library(example_lib INTERFACE)
target_include_directories(example_lib INTERFACE .)
target_link_libraries(example_lib INTERFACE absl::hash nlohmann_json::nlohmann_json libcoro)

add_executable(example example.cpp)
target_link_libraries(example PRIVATE example_lib pegtl cxxopts::cxxopts)
if (MSVC)
    target_compile_options(example PRIVATE /W4)
else()
    target_compile_options(example PRIVATE -Wall -Wextra -Wpedantic)
endif()
