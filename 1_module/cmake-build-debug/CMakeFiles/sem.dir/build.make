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
CMAKE_COMMAND = /snap/clion/111/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/111/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/felix/CLionProjects/park/algoscpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/felix/CLionProjects/park/algoscpp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sem.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sem.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sem.dir/flags.make

CMakeFiles/sem.dir/sem2.cpp.o: CMakeFiles/sem.dir/flags.make
CMakeFiles/sem.dir/sem2.cpp.o: ../sem2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/felix/CLionProjects/park/algoscpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sem.dir/sem2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sem.dir/sem2.cpp.o -c /home/felix/CLionProjects/park/algoscpp/sem2.cpp

CMakeFiles/sem.dir/sem2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sem.dir/sem2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/felix/CLionProjects/park/algoscpp/sem2.cpp > CMakeFiles/sem.dir/sem2.cpp.i

CMakeFiles/sem.dir/sem2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sem.dir/sem2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/felix/CLionProjects/park/algoscpp/sem2.cpp -o CMakeFiles/sem.dir/sem2.cpp.s

# Object files for target sem
sem_OBJECTS = \
"CMakeFiles/sem.dir/sem2.cpp.o"

# External object files for target sem
sem_EXTERNAL_OBJECTS =

sem: CMakeFiles/sem.dir/sem2.cpp.o
sem: CMakeFiles/sem.dir/build.make
sem: CMakeFiles/sem.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/felix/CLionProjects/park/algoscpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable sem"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sem.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sem.dir/build: sem

.PHONY : CMakeFiles/sem.dir/build

CMakeFiles/sem.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sem.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sem.dir/clean

CMakeFiles/sem.dir/depend:
	cd /home/felix/CLionProjects/park/algoscpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/felix/CLionProjects/park/algoscpp /home/felix/CLionProjects/park/algoscpp /home/felix/CLionProjects/park/algoscpp/cmake-build-debug /home/felix/CLionProjects/park/algoscpp/cmake-build-debug /home/felix/CLionProjects/park/algoscpp/cmake-build-debug/CMakeFiles/sem.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sem.dir/depend

