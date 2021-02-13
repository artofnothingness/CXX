cmake_minimum_required(VERSION 2.8.12)
project(Starter LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()

set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=*")
SET(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

# Link this 'library' to use the warnings specified in CompilerWarnings.cmake
add_library(project_warnings INTERFACE)

# standard compiler warnings
include(cmake/CompilerWarnings.cmake)
set_project_warnings(project_warnings)

# # # APPS # # #

# OpenCV 
add_executable(cv_img src/OpenCV/AddingImages.cpp)
target_link_libraries(cv_img CONAN_PKG::opencv project_warnings)

# Eigen
add_executable(eig src/Eigen/eig.cpp)
target_link_libraries(eig CONAN_PKG::eigen project_warnings)

# SpdLog
add_executable(spdlog src/SpdLog/spdlog.cpp)
target_link_libraries(spdlog CONAN_PKG::spdlog project_warnings)

add_executable(spdlog_obj src/SpdLog/spdlog_std_obj.cpp)
target_link_libraries(spdlog_obj CONAN_PKG::spdlog project_warnings)

add_executable(spdlog_file src/SpdLog/spd_log_file.cpp)
target_link_libraries(spdlog_file CONAN_PKG::spdlog project_warnings)


# nlohmann
add_executable(nlohm src/nlohmann/nlohm.cpp)
target_link_libraries(nlohm CONAN_PKG::nlohmann_json project_warnings)

# yaml-cpp
add_executable(yml src/yaml-cpp/yaml.cpp)
target_link_libraries(yml CONAN_PKG::yaml-cpp project_warnings)

# TESTS
add_executable(ct tests/Catch2/simple_test_catch.cpp)
target_link_libraries(ct CONAN_PKG::catch2 project_warnings)

add_test(NAME simple_g_test COMMAND gt)
add_test(NAME simple_c_test COMMAND ct)
