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
CMAKE_BINARY_DIR = /home/bbekasiak/Desktop/RADIO

# Include any dependencies generated for this target.
include CMakeFiles/myprogram.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/myprogram.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/myprogram.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/myprogram.dir/flags.make

CMakeFiles/myprogram.dir/main.c.o: CMakeFiles/myprogram.dir/flags.make
CMakeFiles/myprogram.dir/main.c.o: main.c
CMakeFiles/myprogram.dir/main.c.o: CMakeFiles/myprogram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bbekasiak/Desktop/RADIO/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/myprogram.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/myprogram.dir/main.c.o -MF CMakeFiles/myprogram.dir/main.c.o.d -o CMakeFiles/myprogram.dir/main.c.o -c /home/bbekasiak/Desktop/RADIO/main.c

CMakeFiles/myprogram.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/myprogram.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bbekasiak/Desktop/RADIO/main.c > CMakeFiles/myprogram.dir/main.c.i

CMakeFiles/myprogram.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/myprogram.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bbekasiak/Desktop/RADIO/main.c -o CMakeFiles/myprogram.dir/main.c.s

# Object files for target myprogram
myprogram_OBJECTS = \
"CMakeFiles/myprogram.dir/main.c.o"

# External object files for target myprogram
myprogram_EXTERNAL_OBJECTS =

myprogram: CMakeFiles/myprogram.dir/main.c.o
myprogram: CMakeFiles/myprogram.dir/build.make
myprogram: CMakeFiles/myprogram.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bbekasiak/Desktop/RADIO/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable myprogram"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myprogram.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/myprogram.dir/build: myprogram
.PHONY : CMakeFiles/myprogram.dir/build

CMakeFiles/myprogram.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/myprogram.dir/cmake_clean.cmake
.PHONY : CMakeFiles/myprogram.dir/clean

CMakeFiles/myprogram.dir/depend:
	cd /home/bbekasiak/Desktop/RADIO && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bbekasiak/Desktop/RADIO /home/bbekasiak/Desktop/RADIO /home/bbekasiak/Desktop/RADIO /home/bbekasiak/Desktop/RADIO /home/bbekasiak/Desktop/RADIO/CMakeFiles/myprogram.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/myprogram.dir/depend

