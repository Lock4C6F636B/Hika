# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 4.0

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
CMAKE_SOURCE_DIR = /home/kasumi/programming/c++/HiKa_linux

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kasumi/programming/c++/HiKa_linux/build/Desktop-Debug

# Utility rule file for HiKa_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/HiKa_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/HiKa_autogen.dir/progress.make

CMakeFiles/HiKa_autogen: HiKa_autogen/timestamp

HiKa_autogen/timestamp: /usr/lib/qt6/moc
HiKa_autogen/timestamp: /usr/lib/qt6/uic
HiKa_autogen/timestamp: CMakeFiles/HiKa_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/kasumi/programming/c++/HiKa_linux/build/Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target HiKa"
	/usr/bin/cmake -E cmake_autogen /home/kasumi/programming/c++/HiKa_linux/build/Desktop-Debug/CMakeFiles/HiKa_autogen.dir/AutogenInfo.json Debug
	/usr/bin/cmake -E touch /home/kasumi/programming/c++/HiKa_linux/build/Desktop-Debug/HiKa_autogen/timestamp

CMakeFiles/HiKa_autogen.dir/codegen:
.PHONY : CMakeFiles/HiKa_autogen.dir/codegen

HiKa_autogen: CMakeFiles/HiKa_autogen
HiKa_autogen: HiKa_autogen/timestamp
HiKa_autogen: CMakeFiles/HiKa_autogen.dir/build.make
.PHONY : HiKa_autogen

# Rule to build all files generated by this target.
CMakeFiles/HiKa_autogen.dir/build: HiKa_autogen
.PHONY : CMakeFiles/HiKa_autogen.dir/build

CMakeFiles/HiKa_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HiKa_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HiKa_autogen.dir/clean

CMakeFiles/HiKa_autogen.dir/depend:
	cd /home/kasumi/programming/c++/HiKa_linux/build/Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kasumi/programming/c++/HiKa_linux /home/kasumi/programming/c++/HiKa_linux /home/kasumi/programming/c++/HiKa_linux/build/Desktop-Debug /home/kasumi/programming/c++/HiKa_linux/build/Desktop-Debug /home/kasumi/programming/c++/HiKa_linux/build/Desktop-Debug/CMakeFiles/HiKa_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/HiKa_autogen.dir/depend

