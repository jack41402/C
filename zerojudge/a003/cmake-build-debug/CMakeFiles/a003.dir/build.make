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
CMAKE_SOURCE_DIR = D:\C++\zerojudge\a003

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\C++\zerojudge\a003\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/a003.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/a003.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/a003.dir/flags.make

CMakeFiles/a003.dir/main.cpp.obj: CMakeFiles/a003.dir/flags.make
CMakeFiles/a003.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\C++\zerojudge\a003\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/a003.dir/main.cpp.obj"
	C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\a003.dir\main.cpp.obj -c D:\C++\zerojudge\a003\main.cpp

CMakeFiles/a003.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/a003.dir/main.cpp.i"
	C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\C++\zerojudge\a003\main.cpp > CMakeFiles\a003.dir\main.cpp.i

CMakeFiles/a003.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/a003.dir/main.cpp.s"
	C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\C++\zerojudge\a003\main.cpp -o CMakeFiles\a003.dir\main.cpp.s

# Object files for target a003
a003_OBJECTS = \
"CMakeFiles/a003.dir/main.cpp.obj"

# External object files for target a003
a003_EXTERNAL_OBJECTS =

a003.exe: CMakeFiles/a003.dir/main.cpp.obj
a003.exe: CMakeFiles/a003.dir/build.make
a003.exe: CMakeFiles/a003.dir/linklibs.rsp
a003.exe: CMakeFiles/a003.dir/objects1.rsp
a003.exe: CMakeFiles/a003.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\C++\zerojudge\a003\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable a003.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\a003.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/a003.dir/build: a003.exe
.PHONY : CMakeFiles/a003.dir/build

CMakeFiles/a003.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\a003.dir\cmake_clean.cmake
.PHONY : CMakeFiles/a003.dir/clean

CMakeFiles/a003.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\C++\zerojudge\a003 D:\C++\zerojudge\a003 D:\C++\zerojudge\a003\cmake-build-debug D:\C++\zerojudge\a003\cmake-build-debug D:\C++\zerojudge\a003\cmake-build-debug\CMakeFiles\a003.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/a003.dir/depend

