cmake_minimum_required(VERSION 3.10)
project(InxaneUtils)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall -Wextra")
set(GLOB_RECURSE SOURCES "src/*.hpp")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
add_executable(InxaneUtilsTest "src/test/main.cpp" ${SOURCES})
target_include_directories(InxaneUtilsTest PRIVATE "./src/")
