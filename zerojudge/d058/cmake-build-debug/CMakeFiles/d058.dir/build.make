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
CMAKE_SOURCE_DIR = D:\C++\zerojudge\d058

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\C++\zerojudge\d058\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/d058.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/d058.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/d058.dir/flags.make

CMakeFiles/d058.dir/main.cpp.obj: CMakeFiles/d058.dir/flags.make
CMakeFiles/d058.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\C++\zerojudge\d058\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/d058.dir/main.cpp.obj"
	C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\d058.dir\main.cpp.obj -c D:\C++\zerojudge\d058\main.cpp

CMakeFiles/d058.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/d058.dir/main.cpp.i"
	C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\C++\zerojudge\d058\main.cpp > CMakeFiles\d058.dir\main.cpp.i

CMakeFiles/d058.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/d058.dir/main.cpp.s"
	C:\PROGRA~1\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\C++\zerojudge\d058\main.cpp -o CMakeFiles\d058.dir\main.cpp.s

# Object files for target d058
d058_OBJECTS = \
"CMakeFiles/d058.dir/main.cpp.obj"

# External object files for target d058
d058_EXTERNAL_OBJECTS =

d058.exe: CMakeFiles/d058.dir/main.cpp.obj
d058.exe: CMakeFiles/d058.dir/build.make
d058.exe: CMakeFiles/d058.dir/linklibs.rsp
d058.exe: CMakeFiles/d058.dir/objects1.rsp
d058.exe: CMakeFiles/d058.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\C++\zerojudge\d058\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable d058.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\d058.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/d058.dir/build: d058.exe
.PHONY : CMakeFiles/d058.dir/build

CMakeFiles/d058.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\d058.dir\cmake_clean.cmake
.PHONY : CMakeFiles/d058.dir/clean

CMakeFiles/d058.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\C++\zerojudge\d058 D:\C++\zerojudge\d058 D:\C++\zerojudge\d058\cmake-build-debug D:\C++\zerojudge\d058\cmake-build-debug D:\C++\zerojudge\d058\cmake-build-debug\CMakeFiles\d058.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/d058.dir/depend

