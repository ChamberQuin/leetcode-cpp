cmake_minimum_required(VERSION 3.27)
project(leetcode_cpp C)

set(CMAKE_C_STANDARD 11)

include_directories(.)
include_directories(easy)

add_executable(leetcode_cpp
        easy/forkjoin.h
        easy/lru_cache.h
        easy/single_flight.h
        easy/wait_group.h)
