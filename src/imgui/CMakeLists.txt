project(imgui-sfml-sandbox)

add_executable(sfml sfml_simple_example.cpp)

target_link_libraries(sfml PRIVATE CONAN_PKG::imgui-sfml)
target_include_directories(sfml INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


find_package(OpenCV REQUIRED)

add_executable(sfml_cv sfml_opencv.cpp)
target_link_libraries(sfml_cv PRIVATE CONAN_PKG::imgui-sfml ${OpenCV_LIBS})
target_include_directories(sfml_cv 
  PRIVATE ${OpenCV_INCLUDE_DIRS}
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(sfml sfml_cv
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
)
