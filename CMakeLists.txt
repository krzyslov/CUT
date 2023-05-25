cmake_minimum_required(VERSION 3.5)

project(CUT_Project C) 
set(CMAKE_C_STANDARD 11)

set(MAIN_EXECUTABLE_SOURCES
    src/main.c
)

# Add the main executable
add_executable(MyExecutable ${MAIN_EXECUTABLE_SOURCES})


# Add the example source files
set(SOURCES
    src/queue.c
    src/queue.h
    src/reader.h
    src/reader.c
    src/analyzer.h
    src/analyzer.c
    src/printer.h
    src/printer.c
)

# Add the example library
add_library(QueueLib ${SOURCES})


# Include the header files for the main executable
target_link_libraries(MyExecutable QueueLib)

# Set the source files for the test executable
set(TEST_EXECUTABLE_SOURCES
    tests/test_file1.c
    src/queue.c
)

# Add the test executable
add_executable(TestExecutable ${TEST_EXECUTABLE_SOURCES})


# Include the header files for the test executable
target_include_directories(TestExecutable PUBLIC src)


