# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yuan/XSpace/Study/Interviewers/CodingTest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yuan/XSpace/Study/Interviewers/CodingTest/build

# Include any dependencies generated for this target.
include 8/CMakeFiles/test8.dir/depend.make

# Include the progress variables for this target.
include 8/CMakeFiles/test8.dir/progress.make

# Include the compile flags for this target's objects.
include 8/CMakeFiles/test8.dir/flags.make

8/CMakeFiles/test8.dir/109.cpp.o: 8/CMakeFiles/test8.dir/flags.make
8/CMakeFiles/test8.dir/109.cpp.o: ../8/109.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/yuan/XSpace/Study/Interviewers/CodingTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object 8/CMakeFiles/test8.dir/109.cpp.o"
	cd /home/yuan/XSpace/Study/Interviewers/CodingTest/build/8 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test8.dir/109.cpp.o -c /home/yuan/XSpace/Study/Interviewers/CodingTest/8/109.cpp

8/CMakeFiles/test8.dir/109.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test8.dir/109.cpp.i"
	cd /home/yuan/XSpace/Study/Interviewers/CodingTest/build/8 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/yuan/XSpace/Study/Interviewers/CodingTest/8/109.cpp > CMakeFiles/test8.dir/109.cpp.i

8/CMakeFiles/test8.dir/109.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test8.dir/109.cpp.s"
	cd /home/yuan/XSpace/Study/Interviewers/CodingTest/build/8 && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/yuan/XSpace/Study/Interviewers/CodingTest/8/109.cpp -o CMakeFiles/test8.dir/109.cpp.s

8/CMakeFiles/test8.dir/109.cpp.o.requires:

.PHONY : 8/CMakeFiles/test8.dir/109.cpp.o.requires

8/CMakeFiles/test8.dir/109.cpp.o.provides: 8/CMakeFiles/test8.dir/109.cpp.o.requires
	$(MAKE) -f 8/CMakeFiles/test8.dir/build.make 8/CMakeFiles/test8.dir/109.cpp.o.provides.build
.PHONY : 8/CMakeFiles/test8.dir/109.cpp.o.provides

8/CMakeFiles/test8.dir/109.cpp.o.provides.build: 8/CMakeFiles/test8.dir/109.cpp.o


# Object files for target test8
test8_OBJECTS = \
"CMakeFiles/test8.dir/109.cpp.o"

# External object files for target test8
test8_EXTERNAL_OBJECTS =

8/libtest8.so: 8/CMakeFiles/test8.dir/109.cpp.o
8/libtest8.so: 8/CMakeFiles/test8.dir/build.make
8/libtest8.so: 8/CMakeFiles/test8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/yuan/XSpace/Study/Interviewers/CodingTest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libtest8.so"
	cd /home/yuan/XSpace/Study/Interviewers/CodingTest/build/8 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test8.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
8/CMakeFiles/test8.dir/build: 8/libtest8.so

.PHONY : 8/CMakeFiles/test8.dir/build

8/CMakeFiles/test8.dir/requires: 8/CMakeFiles/test8.dir/109.cpp.o.requires

.PHONY : 8/CMakeFiles/test8.dir/requires

8/CMakeFiles/test8.dir/clean:
	cd /home/yuan/XSpace/Study/Interviewers/CodingTest/build/8 && $(CMAKE_COMMAND) -P CMakeFiles/test8.dir/cmake_clean.cmake
.PHONY : 8/CMakeFiles/test8.dir/clean

8/CMakeFiles/test8.dir/depend:
	cd /home/yuan/XSpace/Study/Interviewers/CodingTest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yuan/XSpace/Study/Interviewers/CodingTest /home/yuan/XSpace/Study/Interviewers/CodingTest/8 /home/yuan/XSpace/Study/Interviewers/CodingTest/build /home/yuan/XSpace/Study/Interviewers/CodingTest/build/8 /home/yuan/XSpace/Study/Interviewers/CodingTest/build/8/CMakeFiles/test8.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : 8/CMakeFiles/test8.dir/depend

