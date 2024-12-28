cmake_minimum_required(VERSION 3.16)

# Set the project name and version
project(MyProject VERSION 1.0 LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the compiler to Clang
# set(CMAKE_CXX_COMPILER clang++-18)

set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

# Add the src and tests directories
# add_subdirectory(src)
add_subdirectory(tests)

# Enable warnings
if (CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Define the executable
add_executable(FastPegSolitaire main.cpp)

target_include_directories(FastPegSolitaire PRIVATE src)

# Link libraries if any
# target_link_libraries(FastPegSolitaire PRIVATE fast_peg_solitaire)
# ```

