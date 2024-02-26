cmake_minimum_required(VERSION 3.18)

project(chat_server)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(src)

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake;${CMAKE_MODULE_PATH}")

include(muduo)