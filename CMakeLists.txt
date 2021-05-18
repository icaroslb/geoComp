cmake_minimum_required(VERSION 3.10)

project(geoComp VERSION 1.0 LANGUAGES C CXX)
configure_file(config.h.in config.h)
include_directories(${PROJECT_BINARY_DIR})

add_subdirectory(lito_engine)
add_subdirectory(leitor_obj)

add_executable(geoComp "geoComp.cpp")

target_link_libraries(geoComp PUBLIC lito_opengl_sdl ${leitor_obj})