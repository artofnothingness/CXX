project(boost_sandbox)

add_executable(options options.cpp)
target_link_libraries(options CONAN_PKG::boost)
target_include_directories(options INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


set_target_properties(options
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
)
