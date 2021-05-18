add_library(
    leitor_obj SHARED
    leitor_obj.hpp leitor_obj.cpp
)
target_link_libraries(
    leitor_obj PUBLIC
    lito_algebra
)