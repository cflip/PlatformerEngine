cmake_minimum_required(VERSION 3.17)
set(PROJECT_NAME "PlatformerEngine")
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)

set(SFML_DIR "${CMAKE_CURRENT_LIST_DIR}/lib/SFML/lib/cmake/SFML")

file(GLOB SOURCE_FILES "${CMAKE_CURRENT_LIST_DIR}/src/*.cpp" "${CMAKE_CURRENT_LIST_DIR}/src/*.h")
file(GLOB IMGUI_SOURCE "${CMAKE_CURRENT_LIST_DIR}/lib/ImGui/*.cpp" "${CMAKE_CURRENT_LIST_DIR}/lib/ImGui/*.h")
file(GLOB REQUIRED_DLLS "${CMAKE_CURRENT_LIST_DIR}/lib/SFML/bin/*.dll")
file(COPY ${REQUIRED_DLLS} DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

link_libraries(stdc++fs)
add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${IMGUI_SOURCE})

find_package(SFML REQUIRED system window graphics)
include_directories(${CMAKE_CURRENT_LIST_DIR}/lib/SFML/include ${CMAKE_CURRENT_LIST_DIR}/lib/ImGui/)
target_link_libraries(${PROJECT_NAME} opengl32 sfml-graphics sfml-window sfml-system)