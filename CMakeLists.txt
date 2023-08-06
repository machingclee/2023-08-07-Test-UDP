cmake_minimum_required(VERSION 3.22)
set(This UDP_SERVER)
project(
  ${This}
  VERSION 1.0.0
  LANGUAGES C CXX
)

add_executable(${This} main.c)