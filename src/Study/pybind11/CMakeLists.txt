project(pybind_sandbox)

pybind11_add_module(pybind_func pybind_function.cpp)
target_link_libraries(pybind_func PRIVATE project_warnings)
target_include_directories(pybind_func INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(pybind_func
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
)
