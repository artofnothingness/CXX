cmake_minimum_required(VERSION 2.8.12)
project(Starter LANGUAGES CXX)

SET(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(example src/OpenCV/AddingImages.cpp)
target_link_libraries(example ${CONAN_LIBS})
