# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /snap/clion/112/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/112/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/felix/CLionProjects/park/algoscpp/3_module

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/felix/CLionProjects/park/algoscpp/3_module/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/4.dir/flags.make

CMakeFiles/4.dir/4.o: CMakeFiles/4.dir/flags.make
CMakeFiles/4.dir/4.o: ../4.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/felix/CLionProjects/park/algoscpp/3_module/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/4.dir/4.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/4.dir/4.o -c /home/felix/CLionProjects/park/algoscpp/3_module/4.cpp

CMakeFiles/4.dir/4.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/4.dir/4.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/felix/CLionProjects/park/algoscpp/3_module/4.cpp > CMakeFiles/4.dir/4.i

CMakeFiles/4.dir/4.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/4.dir/4.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/felix/CLionProjects/park/algoscpp/3_module/4.cpp -o CMakeFiles/4.dir/4.s

# Object files for target 4
4_OBJECTS = \
"CMakeFiles/4.dir/4.o"

# External object files for target 4
4_EXTERNAL_OBJECTS =

4 : CMakeFiles/4.dir/4.o
4 : CMakeFiles/4.dir/build.make
4 : CMakeFiles/4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/felix/CLionProjects/park/algoscpp/3_module/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/4.dir/build: 4

.PHONY : CMakeFiles/4.dir/build

CMakeFiles/4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/4.dir/clean

CMakeFiles/4.dir/depend:
	cd /home/felix/CLionProjects/park/algoscpp/3_module/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/felix/CLionProjects/park/algoscpp/3_module /home/felix/CLionProjects/park/algoscpp/3_module /home/felix/CLionProjects/park/algoscpp/3_module/cmake-build-debug /home/felix/CLionProjects/park/algoscpp/3_module/cmake-build-debug /home/felix/CLionProjects/park/algoscpp/3_module/cmake-build-debug/CMakeFiles/4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/4.dir/depend

