cmake_minimum_required(VERSION 3.5)

project(TestProject C)
set(CMAKE_C_STANDARD 11)

# Set the source files for the test executable
set(TEST_EXECUTABLE_SOURCES
    test_file1.c
    ../src/queue.c
)

# Add the test executable
add_executable(TestExecutable ${TEST_EXECUTABLE_SOURCES})

# Include the header files for the test executable
target_include_directories(TestExecutable PUBLIC ../src)