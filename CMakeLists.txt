cmake_minimum_required(VERSION 3.5)

project(CUT_Project C) 
set(CMAKE_C_STANDARD 11)

# Set the path to the GCC compiler
set(CMAKE_C_COMPILER gcc)

set(MAIN_EXECUTABLE_SOURCES
    src/main.c
)

# Add the main executable
add_executable(MyExecutable ${MAIN_EXECUTABLE_SOURCES})

# Set compiler flags for clang
if(CMAKE_C_COMPILER_ID MATCHES "Clang")
    target_compile_options(MyExecutable PRIVATE -Weverything -Werror)
endif()

# Set compiler flags for gcc
if(CMAKE_C_COMPILER_ID MATCHES "GNU")
    target_compile_options(MyExecutable PRIVATE -Wall -Wextra -Werror)
endif()

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
    src/sigterm.c
    src/sigterm.h
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


