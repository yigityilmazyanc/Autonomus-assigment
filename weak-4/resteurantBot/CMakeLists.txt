cmake_minimum_required(VERSION 3.10)  
project(Cafe)  

set(CMAKE_CXX_STANDARD 17)  

find_package(jsoncpp REQUIRED)

add_executable(cafe_executable main.cpp Menu.cpp)

target_link_libraries(cafe_executabale jsoncpp)
