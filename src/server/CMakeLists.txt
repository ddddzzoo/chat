cmake_minimum_required(VERSION 3.20)

project(chat_server)

set(CMAKE_CXX_STANDARD 20)

aux_source_directory(. SRC_LIST)

add_executable(server ${SRC_LIST})