cmake_minimum_required(VERSION 3.18)
project(zusi_tcp)

set(CMAKE_CXX_STANDARD 20)

add_executable(zusi_tcp main.cpp src/SysSocket.cpp src/SysSocket.h src/Socket.h src/Node.cpp src/Node.h src/Attribute.cpp src/Attribute.h)