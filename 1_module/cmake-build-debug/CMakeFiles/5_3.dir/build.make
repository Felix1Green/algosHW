# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /snap/clion/107/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/107/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/felix/CLionProjects/park/algoscpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/felix/CLionProjects/park/algoscpp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/5_3.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/5_3.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/5_3.dir/flags.make

CMakeFiles/5_3.dir/5_3.cpp.o: CMakeFiles/5_3.dir/flags.make
CMakeFiles/5_3.dir/5_3.cpp.o: ../5_3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/felix/CLionProjects/park/algoscpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/5_3.dir/5_3.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/5_3.dir/5_3.cpp.o -c /home/felix/CLionProjects/park/algoscpp/5_3.cpp

CMakeFiles/5_3.dir/5_3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/5_3.dir/5_3.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/felix/CLionProjects/park/algoscpp/5_3.cpp > CMakeFiles/5_3.dir/5_3.cpp.i

CMakeFiles/5_3.dir/5_3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/5_3.dir/5_3.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/felix/CLionProjects/park/algoscpp/5_3.cpp -o CMakeFiles/5_3.dir/5_3.cpp.s

# Object files for target 5_3
5_3_OBJECTS = \
"CMakeFiles/5_3.dir/5_3.cpp.o"

# External object files for target 5_3
5_3_EXTERNAL_OBJECTS =

5_3: CMakeFiles/5_3.dir/5_3.cpp.o
5_3: CMakeFiles/5_3.dir/build.make
5_3: CMakeFiles/5_3.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/felix/CLionProjects/park/algoscpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 5_3"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/5_3.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/5_3.dir/build: 5_3

.PHONY : CMakeFiles/5_3.dir/build

CMakeFiles/5_3.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/5_3.dir/cmake_clean.cmake
.PHONY : CMakeFiles/5_3.dir/clean

CMakeFiles/5_3.dir/depend:
	cd /home/felix/CLionProjects/park/algoscpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/felix/CLionProjects/park/algoscpp /home/felix/CLionProjects/park/algoscpp /home/felix/CLionProjects/park/algoscpp/cmake-build-debug /home/felix/CLionProjects/park/algoscpp/cmake-build-debug /home/felix/CLionProjects/park/algoscpp/cmake-build-debug/CMakeFiles/5_3.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/5_3.dir/depend

