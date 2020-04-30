# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.1)

# Name of the project
project(Elevator)

# Prints every warnings and errors
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

# Set sources variable
set(SOURCES src/main.c src/person.h src/person.c src/elevator.h src/elevator.c)

# Add executable target
add_executable(Elevator ${SOURCES})