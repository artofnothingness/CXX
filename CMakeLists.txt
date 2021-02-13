cmake_minimum_required(VERSION 2.8.12)
project(Starter LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

enable_testing()

SET(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)

# # # APPS # # #

# OpenCV 
add_executable(cv_img src/OpenCV/AddingImages.cpp)
target_link_libraries(cv_img CONAN_PKG::opencv)

# Eigen
add_executable(eig src/Eigen/eig.cpp)
target_link_libraries(eig CONAN_PKG::eigen)

# SpdLog
add_executable(spdlog src/SpdLog/spdlog.cpp)
target_link_libraries(spdlog CONAN_PKG::spdlog)

add_executable(spdlog_obj src/SpdLog/spdlog_std_obj.cpp)
target_link_libraries(spdlog_obj CONAN_PKG::spdlog)

add_executable(spdlog_file src/SpdLog/spd_log_file.cpp)
target_link_libraries(spdlog_file CONAN_PKG::spdlog)


# imgui
add_executable(nlohm src/nlohmann/nlohm.cpp)
target_link_libraries(nlohm CONAN_PKG::nlohmann_json)


# TESTS
add_executable(ct tests/Catch2/simple_test_catch.cpp)
target_link_libraries(ct CONAN_PKG::catch2)

add_test(NAME simple_g_test COMMAND gt)
add_test(NAME simple_c_test COMMAND ct)
