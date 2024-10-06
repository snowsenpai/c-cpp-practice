cmake_minimum_required(VERSION 3.5.0)

# Define the project name and the language
project(c_cpp_practice VERSION 0.1 LANGUAGES C CXX)

# Set the C++ standard (optional)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executables for each source file
add_executable(GuessGame GuessGame.cpp)
add_executable(rand rand.cpp)
add_executable(student student.cpp)
add_executable(test test.cpp)
