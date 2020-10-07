cmake_minimum_required(VERSION 3.16.3 FATAL_ERROR)

project(engine)
set(CMAKE_CXX_STANDARD 11)

include(FetchContent)

FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw
)

FetchContent_GetProperties(glfw)
if(NOT glfw_POPULATED)
    FetchContent_Populate(glfw)

    set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
    set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
    set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
    set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

    add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})
endif()

FetchContent_Declare(
        linmath
        GIT_REPOSITORY https://github.com/datenwolf/linmath.h.git
)

FetchContent_GetProperties(linmath)
if(NOT linmath_POPULATED)
    FetchContent_Populate(linmath)
    add_library(linmath INTERFACE)
    target_include_directories(linmath INTERFACE ${linmath_SOURCE_DIR})
endif()

FetchContent_Declare(
        glad
        GIT_REPOSITORY https://github.com/Dav1dde/glad.git
)

FetchContent_GetProperties(glad)
if(NOT glad_POPULATED)
    FetchContent_Populate(glad)
    set(GLAD_PROFILE "core" CACHE STRING "OpenGL profile")
    set(GLAD_API "gl=" CACHE STRING "API type/version pairs, like \"gl=3.2,gles=\", no version means latest")
    set(GLAD_GENERATOR "c" CACHE STRING "Language to generate the binding for")
    add_subdirectory(${glad_SOURCE_DIR} ${glad_BINARY_DIR})
endif()

# FetchContent_Declare(
#         SDL2
#         GIT_REPOSITORY "https://github.com/SDL-mirror/SDL.git"
#         GIT_TAG release-2.0.10
# )

# FetchContent_GetProperties(SDL2)
# if (NOT sdl2_POPULATED)
#     FetchContent_Populate(SDL2)
#     add_subdirectory(${sdl2_SOURCE_DIR} ${sdl2_BINARY_DIR})
# endif ()

# FetchContent_Declare(
#     GLEW
#     GIT_REPOSITORY "https://github.com/davidnr/glew.git"
# )

# FetchContent_GetProperties(glew)
# if(NOT glew_POPULATED)
#     FetchContent_Populate(glew)
#     add_subdirectory(${glew_SOURCE_DIR} ${glew_BINARY_DIR})
# endif()

INCLUDE_DIRECTORIES(${CMAKE_CURRENT_LIST_DIR}/vendor/spdlog/include)
INCLUDE_DIRECTORIES(${CMAKE_CURRENT_LIST_DIR}/include)




set(ENGINE_SOURCE
    ${CMAKE_CURRENT_LIST_DIR}/include/engine.h
    ${CMAKE_CURRENT_LIST_DIR}/src/engine.cpp
)

set(LOG_SOURCE
    ${CMAKE_CURRENT_LIST_DIR}/include/Log.h
    ${CMAKE_CURRENT_LIST_DIR}/src/Log.cpp
)

set(MATH_SOURCE
    ${CMAKE_CURRENT_LIST_DIR}/include/Math.h
    ${CMAKE_CURRENT_LIST_DIR}/src/Math.cpp
)

# set(DISPLAY_SOURCE
#     ${CMAKE_CURRENT_LIST_DIR}/include/display.h
#     ${CMAKE_CURRENT_LIST_DIR}/src/display.cpp
# )

add_library(engine STATIC ${ENGINE_SOURCE})
add_library(log STATIC ${LOG_SOURCE})
add_library(Math STATIC ${MATH_SOURCE})
# add_library(display STATIC ${DISPLAY_SOURCE})


set(TESTING_SOURCE    ${CMAKE_CURRENT_LIST_DIR}/src/testing.cpp)
add_executable(program ${TESTING_SOURCE})
target_link_libraries(engine   glfw linmath glad Math)
# target_link_libraries(display   glfw linmath glad)
target_link_libraries(program   glfw linmath glad)
target_link_libraries(program   engine)
target_link_libraries(program   ${OPENGL_LIBRARIES})
target_link_libraries(program   log)
target_link_libraries(program   log Math)
# target_link_libraries(program   display)
