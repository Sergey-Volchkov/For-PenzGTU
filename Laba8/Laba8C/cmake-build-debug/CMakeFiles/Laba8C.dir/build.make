# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/argo/Desktop/clion-2016.2.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/argo/Desktop/clion-2016.2.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/argo/Desktop/For-PenzGTU/Laba8/Laba8C

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/argo/Desktop/For-PenzGTU/Laba8/Laba8C/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Laba8C.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Laba8C.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Laba8C.dir/flags.make

CMakeFiles/Laba8C.dir/main.c.o: CMakeFiles/Laba8C.dir/flags.make
CMakeFiles/Laba8C.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/argo/Desktop/For-PenzGTU/Laba8/Laba8C/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Laba8C.dir/main.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Laba8C.dir/main.c.o   -c /home/argo/Desktop/For-PenzGTU/Laba8/Laba8C/main.c

CMakeFiles/Laba8C.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Laba8C.dir/main.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/argo/Desktop/For-PenzGTU/Laba8/Laba8C/main.c > CMakeFiles/Laba8C.dir/main.c.i

CMakeFiles/Laba8C.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Laba8C.dir/main.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/argo/Desktop/For-PenzGTU/Laba8/Laba8C/main.c -o CMakeFiles/Laba8C.dir/main.c.s

CMakeFiles/Laba8C.dir/main.c.o.requires:

.PHONY : CMakeFiles/Laba8C.dir/main.c.o.requires

CMakeFiles/Laba8C.dir/main.c.o.provides: CMakeFiles/Laba8C.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Laba8C.dir/build.make CMakeFiles/Laba8C.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Laba8C.dir/main.c.o.provides

CMakeFiles/Laba8C.dir/main.c.o.provides.build: CMakeFiles/Laba8C.dir/main.c.o


# Object files for target Laba8C
Laba8C_OBJECTS = \
"CMakeFiles/Laba8C.dir/main.c.o"

# External object files for target Laba8C
Laba8C_EXTERNAL_OBJECTS =

Laba8C: CMakeFiles/Laba8C.dir/main.c.o
Laba8C: CMakeFiles/Laba8C.dir/build.make
Laba8C: CMakeFiles/Laba8C.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/argo/Desktop/For-PenzGTU/Laba8/Laba8C/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Laba8C"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Laba8C.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Laba8C.dir/build: Laba8C

.PHONY : CMakeFiles/Laba8C.dir/build

CMakeFiles/Laba8C.dir/requires: CMakeFiles/Laba8C.dir/main.c.o.requires

.PHONY : CMakeFiles/Laba8C.dir/requires

CMakeFiles/Laba8C.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Laba8C.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Laba8C.dir/clean

CMakeFiles/Laba8C.dir/depend:
	cd /home/argo/Desktop/For-PenzGTU/Laba8/Laba8C/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/argo/Desktop/For-PenzGTU/Laba8/Laba8C /home/argo/Desktop/For-PenzGTU/Laba8/Laba8C /home/argo/Desktop/For-PenzGTU/Laba8/Laba8C/cmake-build-debug /home/argo/Desktop/For-PenzGTU/Laba8/Laba8C/cmake-build-debug /home/argo/Desktop/For-PenzGTU/Laba8/Laba8C/cmake-build-debug/CMakeFiles/Laba8C.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Laba8C.dir/depend
