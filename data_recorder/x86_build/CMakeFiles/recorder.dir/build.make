# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/local/lib/python2.7/dist-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /usr/local/lib/python2.7/dist-packages/cmake/data/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vishal/Github/Software_Design/data_recorder

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vishal/Github/Software_Design/data_recorder/x86_build

# Include any dependencies generated for this target.
include CMakeFiles/recorder.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/recorder.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/recorder.dir/flags.make

CMakeFiles/recorder.dir/main.cpp.o: CMakeFiles/recorder.dir/flags.make
CMakeFiles/recorder.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vishal/Github/Software_Design/data_recorder/x86_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/recorder.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/recorder.dir/main.cpp.o -c /home/vishal/Github/Software_Design/data_recorder/main.cpp

CMakeFiles/recorder.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/recorder.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vishal/Github/Software_Design/data_recorder/main.cpp > CMakeFiles/recorder.dir/main.cpp.i

CMakeFiles/recorder.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/recorder.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vishal/Github/Software_Design/data_recorder/main.cpp -o CMakeFiles/recorder.dir/main.cpp.s

# Object files for target recorder
recorder_OBJECTS = \
"CMakeFiles/recorder.dir/main.cpp.o"

# External object files for target recorder
recorder_EXTERNAL_OBJECTS =

recorder: CMakeFiles/recorder.dir/main.cpp.o
recorder: CMakeFiles/recorder.dir/build.make
recorder: CMakeFiles/recorder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vishal/Github/Software_Design/data_recorder/x86_build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable recorder"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/recorder.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/recorder.dir/build: recorder

.PHONY : CMakeFiles/recorder.dir/build

CMakeFiles/recorder.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/recorder.dir/cmake_clean.cmake
.PHONY : CMakeFiles/recorder.dir/clean

CMakeFiles/recorder.dir/depend:
	cd /home/vishal/Github/Software_Design/data_recorder/x86_build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vishal/Github/Software_Design/data_recorder /home/vishal/Github/Software_Design/data_recorder /home/vishal/Github/Software_Design/data_recorder/x86_build /home/vishal/Github/Software_Design/data_recorder/x86_build /home/vishal/Github/Software_Design/data_recorder/x86_build/CMakeFiles/recorder.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/recorder.dir/depend

