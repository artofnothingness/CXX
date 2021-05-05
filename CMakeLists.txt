cmake_minimum_required(VERSION 3.15)
project(Starter LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(CompilerWarnings)
include(FetchContent)


include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

# set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=*")
add_subdirectory(extern/pybind11)

add_subdirectory(src/Study/Eigen)
add_subdirectory(src/Study/boost)
add_subdirectory(src/Study/OpenCV)
add_subdirectory(src/Study/xtensor)
add_subdirectory(src/Study/spdlog)
add_subdirectory(src/Study/pybind11)

enable_testing()
add_subdirectory(tests)
