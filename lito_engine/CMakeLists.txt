add_subdirectory(externalLibs/glew/build/cmake)
add_subdirectory(externalLibs/SDL2)

add_library(
    lito_opengl_sdl STATIC
    engines/Engine_OpenGl.h engines/Engine_OpenGl.cpp
    engines/Engine_SDL.h    engines/Engine_SDL.cpp
    shaders/Shader.h        shaders/Shader.cpp
)
target_include_directories(
    lito_opengl_sdl PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/engines"
    "${CMAKE_CURRENT_SOURCE_DIR}/shaders"
    "${CMAKE_CURRENT_SOURCE_DIR}/externalLibs/include"
)
target_link_libraries(
    lito_opengl_sdl PUBLIC
    glew
    SDL2
)

add_library(
    lito_algebra INTERFACE
)
target_link_directories(lito_algebra INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/algebra")
target_include_directories(
    lito_algebra INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/algebra"
)

add_library(
    lito_fisica INTERFACE
)
target_link_directories(lito_fisica INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/fisica")
target_include_directories(
    lito_fisica INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/fisica"
)