cmake_minimum_required(VERSION 2.8.12)
project(Starter LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=*")
SET(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

add_library(project_warnings INTERFACE)
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

# Projects

add_subdirectory(src/Eigen)
add_subdirectory(src/boost)

# TESTS
enable_testing()

add_executable(ct tests/Catch2/simple_test_catch.cpp)
target_link_libraries(ct CONAN_PKG::catch2 project_warnings)

add_test(NAME simple_g_test COMMAND gt)
add_test(NAME simple_c_test COMMAND ct)
