cmake_minimum_required(VERSION 3.12)
project(optional C)

set(CMAKE_C_STANDARD 11)

add_library(optional STATIC optional.c)
