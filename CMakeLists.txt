cmake_minimum_required(VERSION 2.8.12)
project(Starter LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()

SET(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

# APPS
add_executable(cv_example src/OpenCV/AddingImages.cpp)
target_link_libraries(cv_example CONAN_PKG::opencv)


# TESTS
add_executable(simple_g_test tests/GoogleTest/simple.cpp)
target_link_libraries(simple_g_test CONAN_PKG::gtest)

add_executable(simple_c_test tests/Catch2/simple_test_catch.cpp)
target_link_libraries(simple_c_test CONAN_PKG::catch2)

add_test(NAME simple_g_test COMMAND simple_g_test)
add_test(NAME simple_c_test COMMAND simple_c_test)
