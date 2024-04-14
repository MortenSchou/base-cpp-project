
add_executable(example example.cpp)
target_link_libraries(example PRIVATE absl::hash pegtl nlohmann_json::nlohmann_json libcoro cxxopts::cxxopts)
target_compile_options(example PRIVATE -Wall -Wextra -Wpedantic)
