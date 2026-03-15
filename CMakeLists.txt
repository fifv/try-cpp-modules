cmake_minimum_required(VERSION 4.2.3)

### The UUID is from https://github.com/Kitware/CMake/blob/v4.2.3/Help/dev/experimental.rst#c-import-std-support
### Make sure rm the build dir when change this UUID
### Must put his before project()
set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "d0edc3af-4c50-42ea-a356-e2862fe7a444")

project(try-cpp-modules VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26) # 23+ Required
set(CMAKE_CXX_STANDARD_REQUIRED ON) # Optional
set(CMAKE_CXX_MODULE_STD ON) # Required

add_executable(try-cpp-modules src/main.cpp)
target_sources(try-cpp-modules PUBLIC
    FILE_SET CXX_MODULES FILES
    src/mymod.cppm
)
# target_precompile_headers(try-cpp-modules PUBLIC
#     <print>
#     <chrono>
#     <thread>
# )
