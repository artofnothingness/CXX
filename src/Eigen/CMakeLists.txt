project(eigen_sandbox)

add_executable(simple_example simple_example.cpp)
target_link_libraries(simple_example PRIVATE CONAN_PKG::eigen project_warnings)
target_include_directories(simple_example INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

