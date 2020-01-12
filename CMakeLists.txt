cmake_minimum_required(VERSION 3.15)
project(ex4)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread")

add_executable(ex4 main.cpp ClientHandler.h Server.h Solver.h CacheManager.h FileCacheManager.h MyTestClientHandler.h MySerialServer.cpp MySerialServer.h MyClientHandler.cpp MyClientHandler.h MyParallelServer.cpp MyParallelServer.h StringReverser.h SearchSolver.h Searcher.h Searchable.h MySearcher.h StringReverser.cpp BestFirstSearch.h State.h MySearchable.h Matrix.cpp Matrix.h Point.cpp Point.h)