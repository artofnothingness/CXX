project(boost_sandbox)

add_executable(options options.cpp)
target_link_libraries(options CONAN_PKG::boost)
target_include_directories(options INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


add_executable(options2 options_2.cpp)
target_link_libraries(options2 CONAN_PKG::boost)
target_include_directories(options2 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(options options2
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
)
