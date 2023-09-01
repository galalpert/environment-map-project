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
CMAKE_SOURCE_DIR = /mnt/c/Users/talha/Documents/LennyGraphics

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/talha/Documents/LennyGraphics

# Include any dependencies generated for this target.
include source/gui/external/imguizmo/CMakeFiles/imguizmo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include source/gui/external/imguizmo/CMakeFiles/imguizmo.dir/compiler_depend.make

# Include the progress variables for this target.
include source/gui/external/imguizmo/CMakeFiles/imguizmo.dir/progress.make

# Include the compile flags for this target's objects.
include source/gui/external/imguizmo/CMakeFiles/imguizmo.dir/flags.make

source/gui/external/imguizmo/CMakeFiles/imguizmo.dir/src/ImGuizmo.cpp.o: source/gui/external/imguizmo/CMakeFiles/imguizmo.dir/flags.make
source/gui/external/imguizmo/CMakeFiles/imguizmo.dir/src/ImGuizmo.cpp.o: source/gui/external/imguizmo/src/ImGuizmo.cpp
source/gui/external/imguizmo/CMakeFiles/imguizmo.dir/src/ImGuizmo.cpp.o: source/gui/external/imguizmo/CMakeFiles/imguizmo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/talha/Documents/LennyGraphics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object source/gui/external/imguizmo/CMakeFiles/imguizmo.dir/src/ImGuizmo.cpp.o"
	cd /mnt/c/Users/talha/Documents/LennyGraphics/source/gui/external/imguizmo && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT source/gui/external/imguizmo/CMakeFiles/imguizmo.dir/src/ImGuizmo.cpp.o -MF CMakeFiles/imguizmo.dir/src/ImGuizmo.cpp.o.d -o CMakeFiles/imguizmo.dir/src/ImGuizmo.cpp.o -c /mnt/c/Users/talha/Documents/LennyGraphics/source/gui/external/imguizmo/src/ImGuizmo.cpp

source/gui/external/imguizmo/CMakeFiles/imguizmo.dir/src/ImGuizmo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/imguizmo.dir/src/ImGuizmo.cpp.i"
	cd /mnt/c/Users/talha/Documents/LennyGraphics/source/gui/external/imguizmo && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/talha/Documents/LennyGraphics/source/gui/external/imguizmo/src/ImGuizmo.cpp > CMakeFiles/imguizmo.dir/src/ImGuizmo.cpp.i

source/gui/external/imguizmo/CMakeFiles/imguizmo.dir/src/ImGuizmo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/imguizmo.dir/src/ImGuizmo.cpp.s"
	cd /mnt/c/Users/talha/Documents/LennyGraphics/source/gui/external/imguizmo && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/talha/Documents/LennyGraphics/source/gui/external/imguizmo/src/ImGuizmo.cpp -o CMakeFiles/imguizmo.dir/src/ImGuizmo.cpp.s

# Object files for target imguizmo
imguizmo_OBJECTS = \
"CMakeFiles/imguizmo.dir/src/ImGuizmo.cpp.o"

# External object files for target imguizmo
imguizmo_EXTERNAL_OBJECTS =

source/gui/external/imguizmo/libimguizmo.a: source/gui/external/imguizmo/CMakeFiles/imguizmo.dir/src/ImGuizmo.cpp.o
source/gui/external/imguizmo/libimguizmo.a: source/gui/external/imguizmo/CMakeFiles/imguizmo.dir/build.make
source/gui/external/imguizmo/libimguizmo.a: source/gui/external/imguizmo/CMakeFiles/imguizmo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/talha/Documents/LennyGraphics/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libimguizmo.a"
	cd /mnt/c/Users/talha/Documents/LennyGraphics/source/gui/external/imguizmo && $(CMAKE_COMMAND) -P CMakeFiles/imguizmo.dir/cmake_clean_target.cmake
	cd /mnt/c/Users/talha/Documents/LennyGraphics/source/gui/external/imguizmo && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/imguizmo.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
source/gui/external/imguizmo/CMakeFiles/imguizmo.dir/build: source/gui/external/imguizmo/libimguizmo.a
.PHONY : source/gui/external/imguizmo/CMakeFiles/imguizmo.dir/build

source/gui/external/imguizmo/CMakeFiles/imguizmo.dir/clean:
	cd /mnt/c/Users/talha/Documents/LennyGraphics/source/gui/external/imguizmo && $(CMAKE_COMMAND) -P CMakeFiles/imguizmo.dir/cmake_clean.cmake
.PHONY : source/gui/external/imguizmo/CMakeFiles/imguizmo.dir/clean

source/gui/external/imguizmo/CMakeFiles/imguizmo.dir/depend:
	cd /mnt/c/Users/talha/Documents/LennyGraphics && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/talha/Documents/LennyGraphics /mnt/c/Users/talha/Documents/LennyGraphics/source/gui/external/imguizmo /mnt/c/Users/talha/Documents/LennyGraphics /mnt/c/Users/talha/Documents/LennyGraphics/source/gui/external/imguizmo /mnt/c/Users/talha/Documents/LennyGraphics/source/gui/external/imguizmo/CMakeFiles/imguizmo.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : source/gui/external/imguizmo/CMakeFiles/imguizmo.dir/depend
