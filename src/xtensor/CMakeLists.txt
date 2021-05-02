project(xtensor-sandbox)

add_executable(xtensor xtensor.cpp)
target_link_libraries(xtensor CONAN_PKG::xtensor)

target_include_directories(xtensor INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(xtensor
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
)
