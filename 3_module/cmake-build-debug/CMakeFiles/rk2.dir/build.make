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
include CMakeFiles/rk2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rk2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rk2.dir/flags.make

CMakeFiles/rk2.dir/rk2.o: CMakeFiles/rk2.dir/flags.make
CMakeFiles/rk2.dir/rk2.o: ../rk2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/felix/CLionProjects/park/algoscpp/3_module/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rk2.dir/rk2.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rk2.dir/rk2.o -c /home/felix/CLionProjects/park/algoscpp/3_module/rk2.cpp

CMakeFiles/rk2.dir/rk2.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rk2.dir/rk2.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/felix/CLionProjects/park/algoscpp/3_module/rk2.cpp > CMakeFiles/rk2.dir/rk2.i

CMakeFiles/rk2.dir/rk2.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rk2.dir/rk2.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/felix/CLionProjects/park/algoscpp/3_module/rk2.cpp -o CMakeFiles/rk2.dir/rk2.s

# Object files for target rk2
rk2_OBJECTS = \
"CMakeFiles/rk2.dir/rk2.o"

# External object files for target rk2
rk2_EXTERNAL_OBJECTS =

rk2: CMakeFiles/rk2.dir/rk2.o
rk2: CMakeFiles/rk2.dir/build.make
rk2: CMakeFiles/rk2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/felix/CLionProjects/park/algoscpp/3_module/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable rk2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rk2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rk2.dir/build: rk2

.PHONY : CMakeFiles/rk2.dir/build

CMakeFiles/rk2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rk2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rk2.dir/clean

CMakeFiles/rk2.dir/depend:
	cd /home/felix/CLionProjects/park/algoscpp/3_module/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/felix/CLionProjects/park/algoscpp/3_module /home/felix/CLionProjects/park/algoscpp/3_module /home/felix/CLionProjects/park/algoscpp/3_module/cmake-build-debug /home/felix/CLionProjects/park/algoscpp/3_module/cmake-build-debug /home/felix/CLionProjects/park/algoscpp/3_module/cmake-build-debug/CMakeFiles/rk2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rk2.dir/depend
