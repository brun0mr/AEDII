# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\bruno\Desktop\prog\abb

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\bruno\Desktop\prog\abb\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/abb.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/abb.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/abb.dir/flags.make

CMakeFiles/abb.dir/main.c.obj: CMakeFiles/abb.dir/flags.make
CMakeFiles/abb.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\bruno\Desktop\prog\abb\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/abb.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\abb.dir\main.c.obj   -c C:\Users\bruno\Desktop\prog\abb\main.c

CMakeFiles/abb.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/abb.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\bruno\Desktop\prog\abb\main.c > CMakeFiles\abb.dir\main.c.i

CMakeFiles/abb.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/abb.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\bruno\Desktop\prog\abb\main.c -o CMakeFiles\abb.dir\main.c.s

# Object files for target abb
abb_OBJECTS = \
"CMakeFiles/abb.dir/main.c.obj"

# External object files for target abb
abb_EXTERNAL_OBJECTS =

abb.exe: CMakeFiles/abb.dir/main.c.obj
abb.exe: CMakeFiles/abb.dir/build.make
abb.exe: CMakeFiles/abb.dir/linklibs.rsp
abb.exe: CMakeFiles/abb.dir/objects1.rsp
abb.exe: CMakeFiles/abb.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\bruno\Desktop\prog\abb\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable abb.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\abb.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/abb.dir/build: abb.exe

.PHONY : CMakeFiles/abb.dir/build

CMakeFiles/abb.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\abb.dir\cmake_clean.cmake
.PHONY : CMakeFiles/abb.dir/clean

CMakeFiles/abb.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\bruno\Desktop\prog\abb C:\Users\bruno\Desktop\prog\abb C:\Users\bruno\Desktop\prog\abb\cmake-build-debug C:\Users\bruno\Desktop\prog\abb\cmake-build-debug C:\Users\bruno\Desktop\prog\abb\cmake-build-debug\CMakeFiles\abb.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/abb.dir/depend

