# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bbekasiak/Desktop/RADIO

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bbekasiak/Desktop/RADIO/build

# Include any dependencies generated for this target.
include CMakeFiles/MyTests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MyTests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MyTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyTests.dir/flags.make

CMakeFiles/MyTests.dir/tests/test_queue.c.o: CMakeFiles/MyTests.dir/flags.make
CMakeFiles/MyTests.dir/tests/test_queue.c.o: ../tests/test_queue.c
CMakeFiles/MyTests.dir/tests/test_queue.c.o: CMakeFiles/MyTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bbekasiak/Desktop/RADIO/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/MyTests.dir/tests/test_queue.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MyTests.dir/tests/test_queue.c.o -MF CMakeFiles/MyTests.dir/tests/test_queue.c.o.d -o CMakeFiles/MyTests.dir/tests/test_queue.c.o -c /home/bbekasiak/Desktop/RADIO/tests/test_queue.c

CMakeFiles/MyTests.dir/tests/test_queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyTests.dir/tests/test_queue.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bbekasiak/Desktop/RADIO/tests/test_queue.c > CMakeFiles/MyTests.dir/tests/test_queue.c.i

CMakeFiles/MyTests.dir/tests/test_queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyTests.dir/tests/test_queue.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bbekasiak/Desktop/RADIO/tests/test_queue.c -o CMakeFiles/MyTests.dir/tests/test_queue.c.s

CMakeFiles/MyTests.dir/src/queue.c.o: CMakeFiles/MyTests.dir/flags.make
CMakeFiles/MyTests.dir/src/queue.c.o: ../src/queue.c
CMakeFiles/MyTests.dir/src/queue.c.o: CMakeFiles/MyTests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bbekasiak/Desktop/RADIO/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/MyTests.dir/src/queue.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MyTests.dir/src/queue.c.o -MF CMakeFiles/MyTests.dir/src/queue.c.o.d -o CMakeFiles/MyTests.dir/src/queue.c.o -c /home/bbekasiak/Desktop/RADIO/src/queue.c

CMakeFiles/MyTests.dir/src/queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyTests.dir/src/queue.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bbekasiak/Desktop/RADIO/src/queue.c > CMakeFiles/MyTests.dir/src/queue.c.i

CMakeFiles/MyTests.dir/src/queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyTests.dir/src/queue.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bbekasiak/Desktop/RADIO/src/queue.c -o CMakeFiles/MyTests.dir/src/queue.c.s

# Object files for target MyTests
MyTests_OBJECTS = \
"CMakeFiles/MyTests.dir/tests/test_queue.c.o" \
"CMakeFiles/MyTests.dir/src/queue.c.o"

# External object files for target MyTests
MyTests_EXTERNAL_OBJECTS =

MyTests: CMakeFiles/MyTests.dir/tests/test_queue.c.o
MyTests: CMakeFiles/MyTests.dir/src/queue.c.o
MyTests: CMakeFiles/MyTests.dir/build.make
MyTests: CMakeFiles/MyTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bbekasiak/Desktop/RADIO/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable MyTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyTests.dir/build: MyTests
.PHONY : CMakeFiles/MyTests.dir/build

CMakeFiles/MyTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MyTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MyTests.dir/clean

CMakeFiles/MyTests.dir/depend:
	cd /home/bbekasiak/Desktop/RADIO/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bbekasiak/Desktop/RADIO /home/bbekasiak/Desktop/RADIO /home/bbekasiak/Desktop/RADIO/build /home/bbekasiak/Desktop/RADIO/build /home/bbekasiak/Desktop/RADIO/build/CMakeFiles/MyTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyTests.dir/depend

