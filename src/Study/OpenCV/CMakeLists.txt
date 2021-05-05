project(cv_sandbox)

find_package(OpenCV REQUIRED)

add_executable(cv_cap_vid CaptureVideo.cpp)
target_link_libraries(cv_cap_vid PRIVATE ${OpenCV_LIBS})

target_include_directories(cv_cap_vid 
  PRIVATE ${OpenCV_INCLUDE_DIRS}
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(cv_cap_vid
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
)
