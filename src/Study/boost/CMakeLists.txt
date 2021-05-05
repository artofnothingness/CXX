project(boost_sandbox)

add_executable(boost_options options.cpp)
target_link_libraries(boost_options CONAN_PKG::boost)
target_include_directories(boost_options INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


set_target_properties(boost_options
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
)
