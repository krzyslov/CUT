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
include CMakeFiles/MyExecutable.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/MyExecutable.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/MyExecutable.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MyExecutable.dir/flags.make

CMakeFiles/MyExecutable.dir/src/queue.c.o: CMakeFiles/MyExecutable.dir/flags.make
CMakeFiles/MyExecutable.dir/src/queue.c.o: ../src/queue.c
CMakeFiles/MyExecutable.dir/src/queue.c.o: CMakeFiles/MyExecutable.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bbekasiak/Desktop/RADIO/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/MyExecutable.dir/src/queue.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MyExecutable.dir/src/queue.c.o -MF CMakeFiles/MyExecutable.dir/src/queue.c.o.d -o CMakeFiles/MyExecutable.dir/src/queue.c.o -c /home/bbekasiak/Desktop/RADIO/src/queue.c

CMakeFiles/MyExecutable.dir/src/queue.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyExecutable.dir/src/queue.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bbekasiak/Desktop/RADIO/src/queue.c > CMakeFiles/MyExecutable.dir/src/queue.c.i

CMakeFiles/MyExecutable.dir/src/queue.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyExecutable.dir/src/queue.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bbekasiak/Desktop/RADIO/src/queue.c -o CMakeFiles/MyExecutable.dir/src/queue.c.s

CMakeFiles/MyExecutable.dir/src/reader.c.o: CMakeFiles/MyExecutable.dir/flags.make
CMakeFiles/MyExecutable.dir/src/reader.c.o: ../src/reader.c
CMakeFiles/MyExecutable.dir/src/reader.c.o: CMakeFiles/MyExecutable.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bbekasiak/Desktop/RADIO/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/MyExecutable.dir/src/reader.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MyExecutable.dir/src/reader.c.o -MF CMakeFiles/MyExecutable.dir/src/reader.c.o.d -o CMakeFiles/MyExecutable.dir/src/reader.c.o -c /home/bbekasiak/Desktop/RADIO/src/reader.c

CMakeFiles/MyExecutable.dir/src/reader.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyExecutable.dir/src/reader.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bbekasiak/Desktop/RADIO/src/reader.c > CMakeFiles/MyExecutable.dir/src/reader.c.i

CMakeFiles/MyExecutable.dir/src/reader.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyExecutable.dir/src/reader.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bbekasiak/Desktop/RADIO/src/reader.c -o CMakeFiles/MyExecutable.dir/src/reader.c.s

CMakeFiles/MyExecutable.dir/src/analyzer.c.o: CMakeFiles/MyExecutable.dir/flags.make
CMakeFiles/MyExecutable.dir/src/analyzer.c.o: ../src/analyzer.c
CMakeFiles/MyExecutable.dir/src/analyzer.c.o: CMakeFiles/MyExecutable.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bbekasiak/Desktop/RADIO/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/MyExecutable.dir/src/analyzer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MyExecutable.dir/src/analyzer.c.o -MF CMakeFiles/MyExecutable.dir/src/analyzer.c.o.d -o CMakeFiles/MyExecutable.dir/src/analyzer.c.o -c /home/bbekasiak/Desktop/RADIO/src/analyzer.c

CMakeFiles/MyExecutable.dir/src/analyzer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyExecutable.dir/src/analyzer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bbekasiak/Desktop/RADIO/src/analyzer.c > CMakeFiles/MyExecutable.dir/src/analyzer.c.i

CMakeFiles/MyExecutable.dir/src/analyzer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyExecutable.dir/src/analyzer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bbekasiak/Desktop/RADIO/src/analyzer.c -o CMakeFiles/MyExecutable.dir/src/analyzer.c.s

CMakeFiles/MyExecutable.dir/src/printer.c.o: CMakeFiles/MyExecutable.dir/flags.make
CMakeFiles/MyExecutable.dir/src/printer.c.o: ../src/printer.c
CMakeFiles/MyExecutable.dir/src/printer.c.o: CMakeFiles/MyExecutable.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bbekasiak/Desktop/RADIO/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/MyExecutable.dir/src/printer.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MyExecutable.dir/src/printer.c.o -MF CMakeFiles/MyExecutable.dir/src/printer.c.o.d -o CMakeFiles/MyExecutable.dir/src/printer.c.o -c /home/bbekasiak/Desktop/RADIO/src/printer.c

CMakeFiles/MyExecutable.dir/src/printer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyExecutable.dir/src/printer.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bbekasiak/Desktop/RADIO/src/printer.c > CMakeFiles/MyExecutable.dir/src/printer.c.i

CMakeFiles/MyExecutable.dir/src/printer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyExecutable.dir/src/printer.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bbekasiak/Desktop/RADIO/src/printer.c -o CMakeFiles/MyExecutable.dir/src/printer.c.s

CMakeFiles/MyExecutable.dir/src/sigterm.c.o: CMakeFiles/MyExecutable.dir/flags.make
CMakeFiles/MyExecutable.dir/src/sigterm.c.o: ../src/sigterm.c
CMakeFiles/MyExecutable.dir/src/sigterm.c.o: CMakeFiles/MyExecutable.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bbekasiak/Desktop/RADIO/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/MyExecutable.dir/src/sigterm.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MyExecutable.dir/src/sigterm.c.o -MF CMakeFiles/MyExecutable.dir/src/sigterm.c.o.d -o CMakeFiles/MyExecutable.dir/src/sigterm.c.o -c /home/bbekasiak/Desktop/RADIO/src/sigterm.c

CMakeFiles/MyExecutable.dir/src/sigterm.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyExecutable.dir/src/sigterm.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bbekasiak/Desktop/RADIO/src/sigterm.c > CMakeFiles/MyExecutable.dir/src/sigterm.c.i

CMakeFiles/MyExecutable.dir/src/sigterm.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyExecutable.dir/src/sigterm.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bbekasiak/Desktop/RADIO/src/sigterm.c -o CMakeFiles/MyExecutable.dir/src/sigterm.c.s

CMakeFiles/MyExecutable.dir/src/main.c.o: CMakeFiles/MyExecutable.dir/flags.make
CMakeFiles/MyExecutable.dir/src/main.c.o: ../src/main.c
CMakeFiles/MyExecutable.dir/src/main.c.o: CMakeFiles/MyExecutable.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bbekasiak/Desktop/RADIO/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/MyExecutable.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/MyExecutable.dir/src/main.c.o -MF CMakeFiles/MyExecutable.dir/src/main.c.o.d -o CMakeFiles/MyExecutable.dir/src/main.c.o -c /home/bbekasiak/Desktop/RADIO/src/main.c

CMakeFiles/MyExecutable.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/MyExecutable.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/bbekasiak/Desktop/RADIO/src/main.c > CMakeFiles/MyExecutable.dir/src/main.c.i

CMakeFiles/MyExecutable.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/MyExecutable.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/bbekasiak/Desktop/RADIO/src/main.c -o CMakeFiles/MyExecutable.dir/src/main.c.s

# Object files for target MyExecutable
MyExecutable_OBJECTS = \
"CMakeFiles/MyExecutable.dir/src/queue.c.o" \
"CMakeFiles/MyExecutable.dir/src/reader.c.o" \
"CMakeFiles/MyExecutable.dir/src/analyzer.c.o" \
"CMakeFiles/MyExecutable.dir/src/printer.c.o" \
"CMakeFiles/MyExecutable.dir/src/sigterm.c.o" \
"CMakeFiles/MyExecutable.dir/src/main.c.o"

# External object files for target MyExecutable
MyExecutable_EXTERNAL_OBJECTS =

MyExecutable: CMakeFiles/MyExecutable.dir/src/queue.c.o
MyExecutable: CMakeFiles/MyExecutable.dir/src/reader.c.o
MyExecutable: CMakeFiles/MyExecutable.dir/src/analyzer.c.o
MyExecutable: CMakeFiles/MyExecutable.dir/src/printer.c.o
MyExecutable: CMakeFiles/MyExecutable.dir/src/sigterm.c.o
MyExecutable: CMakeFiles/MyExecutable.dir/src/main.c.o
MyExecutable: CMakeFiles/MyExecutable.dir/build.make
MyExecutable: CMakeFiles/MyExecutable.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bbekasiak/Desktop/RADIO/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking C executable MyExecutable"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MyExecutable.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MyExecutable.dir/build: MyExecutable
.PHONY : CMakeFiles/MyExecutable.dir/build

CMakeFiles/MyExecutable.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MyExecutable.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MyExecutable.dir/clean

CMakeFiles/MyExecutable.dir/depend:
	cd /home/bbekasiak/Desktop/RADIO/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bbekasiak/Desktop/RADIO /home/bbekasiak/Desktop/RADIO /home/bbekasiak/Desktop/RADIO/build /home/bbekasiak/Desktop/RADIO/build /home/bbekasiak/Desktop/RADIO/build/CMakeFiles/MyExecutable.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MyExecutable.dir/depend

