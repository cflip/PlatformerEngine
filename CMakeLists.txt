cmake_minimum_required(VERSION 3.12)
set(PROJECT_NAME "PlatformerEngine")
project(${PROJECT_NAME})

set(CMAKE_EXE_LINKER_FLAGS -static)

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/lib/SFML/lib/cmake/SFML")

file(GLOB SOURCE_FILES "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp" "${CMAKE_CURRENT_LIST_DIR}/src/*.h")
file(GLOB IMGUI_SOURCE "${CMAKE_CURRENT_LIST_DIR}/lib/ImGui/*.cpp" "${CMAKE_CURRENT_LIST_DIR}/lib/ImGui/*.h")

link_libraries(stdc++fs)
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${IMGUI_SOURCE})

set(SFML_STATIC_LIBRARIES TRUE)
find_package(SFML REQUIRED system window graphics)
include_directories(${CMAKE_CURRENT_LIST_DIR}/lib/SFML/include ${CMAKE_CURRENT_LIST_DIR}/lib/ImGui/)
target_link_libraries(${PROJECT_NAME} opengl32 sfml-graphics sfml-window sfml-system)