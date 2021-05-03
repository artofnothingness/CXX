project(spdlog_sandbox)

add_executable(spd_log_example simple_example.cpp)
target_link_libraries(spd_log_example PRIVATE CONAN_PKG::spdlog project_warnings)
target_include_directories(spd_log_example INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


add_executable(spd_log_std std.cpp)
target_link_libraries(spd_log_std PRIVATE CONAN_PKG::spdlog project_warnings)
target_include_directories(spd_log_std INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(spd_log_file file.cpp)
target_link_libraries(spd_log_file PRIVATE CONAN_PKG::spdlog project_warnings)
target_include_directories(spd_log_file INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(spd_log_example spd_log_std spd_log_file
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
)
