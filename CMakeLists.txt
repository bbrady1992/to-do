cmake_minimum_required(VERSION 2.8)
project(to-do)

set(CMAKE_CXX_FLAGS "-std=c++1y")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)

include_directories(include)

add_executable(to-do 
  src/main.cpp
  src/SQLiteInterface.cpp)

target_link_libraries(to-do sqlite3)
