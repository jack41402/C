# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\C++\zerojudge\a015

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\C++\zerojudge\a015\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/a015.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/a015.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/a015.dir/flags.make

CMakeFiles/a015.dir/main.cpp.obj: CMakeFiles/a015.dir/flags.make
CMakeFiles/a015.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\C++\zerojudge\a015\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/a015.dir/main.cpp.obj"
	C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\a015.dir\main.cpp.obj -c D:\C++\zerojudge\a015\main.cpp

CMakeFiles/a015.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a015.dir/main.cpp.i"
	C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\C++\zerojudge\a015\main.cpp > CMakeFiles\a015.dir\main.cpp.i

CMakeFiles/a015.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a015.dir/main.cpp.s"
	C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\C++\zerojudge\a015\main.cpp -o CMakeFiles\a015.dir\main.cpp.s

# Object files for target a015
a015_OBJECTS = \
"CMakeFiles/a015.dir/main.cpp.obj"

# External object files for target a015
a015_EXTERNAL_OBJECTS =

a015.exe: CMakeFiles/a015.dir/main.cpp.obj
a015.exe: CMakeFiles/a015.dir/build.make
a015.exe: CMakeFiles/a015.dir/linklibs.rsp
a015.exe: CMakeFiles/a015.dir/objects1.rsp
a015.exe: CMakeFiles/a015.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\C++\zerojudge\a015\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable a015.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\a015.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/a015.dir/build: a015.exe
.PHONY : CMakeFiles/a015.dir/build

CMakeFiles/a015.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\a015.dir\cmake_clean.cmake
.PHONY : CMakeFiles/a015.dir/clean

CMakeFiles/a015.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\C++\zerojudge\a015 D:\C++\zerojudge\a015 D:\C++\zerojudge\a015\cmake-build-debug D:\C++\zerojudge\a015\cmake-build-debug D:\C++\zerojudge\a015\cmake-build-debug\CMakeFiles\a015.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/a015.dir/depend

