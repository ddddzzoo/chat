cmake_minimum_required(VERSION 3.20)

set(CMAKE_CXX_STANDARD 11)

aux_source_directory(. SRC_LIST)

add_executable(server ${SRC_LIST})
target_link_libraries(server muduo_net muduo_base mysqlclient pthread)