add_executable(ct Catch2/simple_test_catch.cpp)
target_link_libraries(ct CONAN_PKG::catch2 project_warnings)

add_test(NAME simple_c_test COMMAND ct)
