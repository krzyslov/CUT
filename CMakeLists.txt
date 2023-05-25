cmake_minimum_required(VERSION 3.5)

project(CUT_Project C) 
set(CMAKE_C_STANDARD 11)


# Check if the CC environment variable is set and if not set the compiler to gcc
if (DEFINED ENV{CC})
    set(CMAKE_C_COMPILER $ENV{CC})
    else()
    set(CMAKE_C_COMPILER gcc)
endif()


# Add the source files
set(SOURCE_FILES
    src/queue.c
    src/reader.c
    src/analyzer.c
    src/printer.c
    src/sigterm.c
    src/main.c
)

# Add the executable
add_executable(MyExecutable ${SOURCE_FILES})

# Set compiler flags for clang
if(CMAKE_C_COMPILER_ID MATCHES "Clang")
    target_compile_options(MyExecutable PRIVATE -Weverything -Werror)
endif()

# Set compiler flags for gcc
if(CMAKE_C_COMPILER_ID MATCHES "GNU")
    target_compile_options(MyExecutable PRIVATE -Wall -Wextra -Werror)
endif()

# Add the test sources
set(TEST_SOURCES
    tests/test_queue.c
    src/queue.c
)
# Add the test executable
add_executable(MyTests ${TEST_SOURCES})

# Add a custom target to run the tests
add_custom_target(test
    COMMAND MyTests
    DEPENDS MyTests
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)