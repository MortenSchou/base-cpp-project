This project is a sample CMake project that includes and tests out some libraries I find useful.

- [CPM](https://github.com/cpm-cmake/CPM.cmake) is used to include dependencies, and there are .cmake files or one-liners for each dependency.
- Unit testing with [doctest](https://github.com/doctest/doctest) and micro-benchmarking with [benchmark](https://github.com/google/benchmark). 
- Python bindings with [pybind11](https://github.com/pybind/pybind11) and python build using [scikit_build_core](https://github.com/scikit-build/scikit-build-core).
- CL option parsing with [cxxopts](https://github.com/jarro2783/cxxopts), JSON support with [nlohmann_json](https://github.com/nlohmann/json).
- Other: [abseil](https://github.com/abseil/abseil-cpp) (I use absl::hash for hashing custom types), [libcoro](https://github.com/jbaldwin/libcoro) coroutine library, and [pegtl](https://github.com/taocpp/PEGTL) for making parsers.
