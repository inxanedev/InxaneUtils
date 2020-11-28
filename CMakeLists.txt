cmake_minimum_required(VERSION 3.16.3)
project(InxaneUtils)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17");
file(GLOB_RECURSE source_list "src/*.cpp" "src/*.hpp");

add_library(InxaneUtils STATIC ${source_list})

add_executable(InxaneUtilsTest "src/test/main.cpp")
target_link_libraries(InxaneUtilsTest InxaneUtils)
