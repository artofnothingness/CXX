project(xtensor-sandbox)

add_executable(xt_simple_ex simple_ex.cpp)
target_link_libraries(xt_simple_ex CONAN_PKG::xtensor)

target_include_directories(xt_simple_ex INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(xt_simple_ex
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
)
