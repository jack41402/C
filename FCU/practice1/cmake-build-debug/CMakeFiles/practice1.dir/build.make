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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2022.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2022.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\GitHub\C\FCU\practice1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\GitHub\C\FCU\practice1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/practice1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/practice1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/practice1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/practice1.dir/flags.make

CMakeFiles/practice1.dir/main.c.obj: CMakeFiles/practice1.dir/flags.make
CMakeFiles/practice1.dir/main.c.obj: ../main.c
CMakeFiles/practice1.dir/main.c.obj: CMakeFiles/practice1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\GitHub\C\FCU\practice1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/practice1.dir/main.c.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/practice1.dir/main.c.obj -MF CMakeFiles\practice1.dir\main.c.obj.d -o CMakeFiles\practice1.dir\main.c.obj -c D:\GitHub\C\FCU\practice1\main.c

CMakeFiles/practice1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/practice1.dir/main.c.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\GitHub\C\FCU\practice1\main.c > CMakeFiles\practice1.dir\main.c.i

CMakeFiles/practice1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/practice1.dir/main.c.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.3\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\GitHub\C\FCU\practice1\main.c -o CMakeFiles\practice1.dir\main.c.s

# Object files for target practice1
practice1_OBJECTS = \
"CMakeFiles/practice1.dir/main.c.obj"

# External object files for target practice1
practice1_EXTERNAL_OBJECTS =

practice1.exe: CMakeFiles/practice1.dir/main.c.obj
practice1.exe: CMakeFiles/practice1.dir/build.make
practice1.exe: CMakeFiles/practice1.dir/linklibs.rsp
practice1.exe: CMakeFiles/practice1.dir/objects1.rsp
practice1.exe: CMakeFiles/practice1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\GitHub\C\FCU\practice1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable practice1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\practice1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/practice1.dir/build: practice1.exe
.PHONY : CMakeFiles/practice1.dir/build

CMakeFiles/practice1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\practice1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/practice1.dir/clean

CMakeFiles/practice1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\GitHub\C\FCU\practice1 D:\GitHub\C\FCU\practice1 D:\GitHub\C\FCU\practice1\cmake-build-debug D:\GitHub\C\FCU\practice1\cmake-build-debug D:\GitHub\C\FCU\practice1\cmake-build-debug\CMakeFiles\practice1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/practice1.dir/depend

