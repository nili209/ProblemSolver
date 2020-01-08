cmake_minimum_required(VERSION 3.15)
project(ex4)

set(CMAKE_CXX_STANDARD 11)

add_executable(ex4 main.cpp ClientHandler.h Server.h Solver.h CacheManager.h FileCacheManager.h MyTestClientHandler.h MySerialServer.cpp MySerialServer.h MyClientHandler.cpp MyClientHandler.h MyParallelServer.cpp MyParallelServer.h StringReverser.h)