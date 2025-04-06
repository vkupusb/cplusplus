cmake_minimum_required(VERSION 3.16)
project(SmartPointers)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_BUILD_TYPE Debug)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(SmartPointers 
src/main.cpp
src/UniquePtr.cpp)

#add_subdirectory(googletest)

#target_link_directories(SmartPointers)



