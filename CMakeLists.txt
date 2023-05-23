cmake_minimum_required(VERSION 2.6.0)

# here we specify that the project is C language only, so the default
# C compiler on the system will be used

set(CMAKE_C_STANDARD 11)
project(myprogram C)

add_executable(myprogram main.c)