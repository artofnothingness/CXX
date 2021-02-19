project(boost_sandbox)

add_executable(options options.cpp)
add_executable(options2 options_2.cpp)
add_executable(type_name type_name.cpp)
target_link_libraries(options CONAN_PKG::boost)
target_link_libraries(options2 CONAN_PKG::boost)
target_link_libraries(type_name CONAN_PKG::boost)

target_include_directories(options INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(options2 INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(type_name INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
