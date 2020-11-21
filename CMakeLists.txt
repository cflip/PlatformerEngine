cmake_minimum_required(VERSION 3.1)
set(PROJECT_NAME "PlatformerEngine")
project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

set(IMGUI_DIR "${CMAKE_CURRENT_LIST_DIR}/ImGui")
set(BUILD_SHARED_LIBS ON)
add_subdirectory(ImGui-SFML)

file(GLOB SOURCE_FILES "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp" "${CMAKE_CURRENT_LIST_DIR}/src/*.h")

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${IMGUI_SOURCE})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics)
find_package(OpenGL REQUIRED)

include_directories(${SFML_INCLUDE_DIR})
target_link_libraries(${PROJECT_NAME} ${SFML_DEPENDENCIES} ${SFML_LIBRARIES} ${OPENGL_LIBRARIES} ImGui-SFML)