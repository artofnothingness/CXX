cmake_minimum_required(VERSION 3.15)
project(Starter LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")
include(CompilerWarnings)
include(FetchContent)


include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

# set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=*")

add_subdirectory(src/Eigen)
add_subdirectory(src/boost)
add_subdirectory(src/OpenCV)
add_subdirectory(src/xtensor)
add_subdirectory(src/spdlog)

enable_testing()
add_subdirectory(tests)
