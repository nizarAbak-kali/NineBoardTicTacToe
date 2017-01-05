cmake_minimum_required(VERSION 3.6)
project(9BoardTicTacToe)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp includes/structs.h Board.cpp includes/Board.h ia.cpp Player.cpp includes/Player.h Coup.cpp includes/Coup.h includes/Cell.h includes/IA_MINIMAX.h)
add_executable(9BoardTicTacToe ${SOURCE_FILES})