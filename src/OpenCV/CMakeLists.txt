project(cv_sandbox)

find_package(OpenCV REQUIRED)

add_executable(cap_vid CaptureVideo.cpp)
target_link_libraries(cap_vid PRIVATE ${OpenCV_LIBS})
target_include_directories(cap_vid 
  PRIVATE ${OpenCV_INCLUDE_DIRS}
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(cap_vid
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
)
