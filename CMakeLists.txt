# Set the minimum required version of CMake
cmake_minimum_required(VERSION 3.1)

# Name of the project
project(Elevator)

# Prints every warnings and errors
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall")

# Set sources variable
set(SOURCES src/main.c)

# Add libraries
add_library(person STATIC src/person.c)
add_library(elevator STATIC src/elevator.c)

# Set libraries variable
set(LIBRARIES person elevator)

# Add executable target
add_executable(Elevator ${SOURCES})

# Link libraries to target
target_link_libraries(Elevator ${LIBRARIES})