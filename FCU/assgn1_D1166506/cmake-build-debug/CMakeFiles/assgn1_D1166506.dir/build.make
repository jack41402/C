# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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
CMAKE_SOURCE_DIR = D:\GitHub\C\FCU\assgn1_D1166506

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\GitHub\C\FCU\assgn1_D1166506\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/assgn1_D1166506.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/assgn1_D1166506.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/assgn1_D1166506.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/assgn1_D1166506.dir/flags.make

CMakeFiles/assgn1_D1166506.dir/assgn1_D1166506.c.obj: CMakeFiles/assgn1_D1166506.dir/flags.make
CMakeFiles/assgn1_D1166506.dir/assgn1_D1166506.c.obj: ../assgn1_D1166506.c
CMakeFiles/assgn1_D1166506.dir/assgn1_D1166506.c.obj: CMakeFiles/assgn1_D1166506.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\GitHub\C\FCU\assgn1_D1166506\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/assgn1_D1166506.dir/assgn1_D1166506.c.obj"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/assgn1_D1166506.dir/assgn1_D1166506.c.obj -MF CMakeFiles\assgn1_D1166506.dir\assgn1_D1166506.c.obj.d -o CMakeFiles\assgn1_D1166506.dir\assgn1_D1166506.c.obj -c D:\GitHub\C\FCU\assgn1_D1166506\assgn1_D1166506.c

CMakeFiles/assgn1_D1166506.dir/assgn1_D1166506.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/assgn1_D1166506.dir/assgn1_D1166506.c.i"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\GitHub\C\FCU\assgn1_D1166506\assgn1_D1166506.c > CMakeFiles\assgn1_D1166506.dir\assgn1_D1166506.c.i

CMakeFiles/assgn1_D1166506.dir/assgn1_D1166506.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/assgn1_D1166506.dir/assgn1_D1166506.c.s"
	C:\PROGRA~1\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\GitHub\C\FCU\assgn1_D1166506\assgn1_D1166506.c -o CMakeFiles\assgn1_D1166506.dir\assgn1_D1166506.c.s

# Object files for target assgn1_D1166506
assgn1_D1166506_OBJECTS = \
"CMakeFiles/assgn1_D1166506.dir/assgn1_D1166506.c.obj"

# External object files for target assgn1_D1166506
assgn1_D1166506_EXTERNAL_OBJECTS =

assgn1_D1166506.exe: CMakeFiles/assgn1_D1166506.dir/assgn1_D1166506.c.obj
assgn1_D1166506.exe: CMakeFiles/assgn1_D1166506.dir/build.make
assgn1_D1166506.exe: CMakeFiles/assgn1_D1166506.dir/linklibs.rsp
assgn1_D1166506.exe: CMakeFiles/assgn1_D1166506.dir/objects1.rsp
assgn1_D1166506.exe: CMakeFiles/assgn1_D1166506.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\GitHub\C\FCU\assgn1_D1166506\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable assgn1_D1166506.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\assgn1_D1166506.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/assgn1_D1166506.dir/build: assgn1_D1166506.exe
.PHONY : CMakeFiles/assgn1_D1166506.dir/build

CMakeFiles/assgn1_D1166506.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\assgn1_D1166506.dir\cmake_clean.cmake
.PHONY : CMakeFiles/assgn1_D1166506.dir/clean

CMakeFiles/assgn1_D1166506.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\GitHub\C\FCU\assgn1_D1166506 D:\GitHub\C\FCU\assgn1_D1166506 D:\GitHub\C\FCU\assgn1_D1166506\cmake-build-debug D:\GitHub\C\FCU\assgn1_D1166506\cmake-build-debug D:\GitHub\C\FCU\assgn1_D1166506\cmake-build-debug\CMakeFiles\assgn1_D1166506.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/assgn1_D1166506.dir/depend

