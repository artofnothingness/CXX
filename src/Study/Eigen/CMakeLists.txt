project(eigen_sandbox)

add_executable(eigen_simple_ex simple_example.cpp)
target_link_libraries(eigen_simple_ex PRIVATE CONAN_PKG::eigen project_warnings)
target_include_directories(eigen_simple_ex INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


set_target_properties(eigen_simple_ex
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
)
