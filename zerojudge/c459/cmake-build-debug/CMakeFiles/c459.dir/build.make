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
CMAKE_SOURCE_DIR = D:\C++\zerojudge\c459

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\C++\zerojudge\c459\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/c459.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/c459.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/c459.dir/flags.make

CMakeFiles/c459.dir/main.cpp.obj: CMakeFiles/c459.dir/flags.make
CMakeFiles/c459.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\C++\zerojudge\c459\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/c459.dir/main.cpp.obj"
	C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\c459.dir\main.cpp.obj -c D:\C++\zerojudge\c459\main.cpp

CMakeFiles/c459.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c459.dir/main.cpp.i"
	C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\C++\zerojudge\c459\main.cpp > CMakeFiles\c459.dir\main.cpp.i

CMakeFiles/c459.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c459.dir/main.cpp.s"
	C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\C++\zerojudge\c459\main.cpp -o CMakeFiles\c459.dir\main.cpp.s

# Object files for target c459
c459_OBJECTS = \
"CMakeFiles/c459.dir/main.cpp.obj"

# External object files for target c459
c459_EXTERNAL_OBJECTS =

c459.exe: CMakeFiles/c459.dir/main.cpp.obj
c459.exe: CMakeFiles/c459.dir/build.make
c459.exe: CMakeFiles/c459.dir/linklibs.rsp
c459.exe: CMakeFiles/c459.dir/objects1.rsp
c459.exe: CMakeFiles/c459.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\C++\zerojudge\c459\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable c459.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\c459.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/c459.dir/build: c459.exe
.PHONY : CMakeFiles/c459.dir/build

CMakeFiles/c459.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\c459.dir\cmake_clean.cmake
.PHONY : CMakeFiles/c459.dir/clean

CMakeFiles/c459.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\C++\zerojudge\c459 D:\C++\zerojudge\c459 D:\C++\zerojudge\c459\cmake-build-debug D:\C++\zerojudge\c459\cmake-build-debug D:\C++\zerojudge\c459\cmake-build-debug\CMakeFiles\c459.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/c459.dir/depend

