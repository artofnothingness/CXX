cmake_minimum_required(VERSION 2.8.12)
project(Starter LANGUAGES CXX)

SET(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_executable(example src/OpenCV/CaptureVideo.cpp)
