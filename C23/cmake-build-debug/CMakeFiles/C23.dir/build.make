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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.2.4\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\fabri\CLionProjects\DomJudge\ED\C23

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\fabri\CLionProjects\DomJudge\ED\C23\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/C23.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/C23.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/C23.dir/flags.make

CMakeFiles/C23.dir/main.cpp.obj: CMakeFiles/C23.dir/flags.make
CMakeFiles/C23.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\fabri\CLionProjects\DomJudge\ED\C23\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/C23.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\C23.dir\main.cpp.obj -c C:\Users\fabri\CLionProjects\DomJudge\ED\C23\main.cpp

CMakeFiles/C23.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/C23.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\fabri\CLionProjects\DomJudge\ED\C23\main.cpp > CMakeFiles\C23.dir\main.cpp.i

CMakeFiles/C23.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/C23.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\fabri\CLionProjects\DomJudge\ED\C23\main.cpp -o CMakeFiles\C23.dir\main.cpp.s

# Object files for target C23
C23_OBJECTS = \
"CMakeFiles/C23.dir/main.cpp.obj"

# External object files for target C23
C23_EXTERNAL_OBJECTS =

C23.exe: CMakeFiles/C23.dir/main.cpp.obj
C23.exe: CMakeFiles/C23.dir/build.make
C23.exe: CMakeFiles/C23.dir/linklibs.rsp
C23.exe: CMakeFiles/C23.dir/objects1.rsp
C23.exe: CMakeFiles/C23.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\fabri\CLionProjects\DomJudge\ED\C23\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable C23.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\C23.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/C23.dir/build: C23.exe

.PHONY : CMakeFiles/C23.dir/build

CMakeFiles/C23.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\C23.dir\cmake_clean.cmake
.PHONY : CMakeFiles/C23.dir/clean

CMakeFiles/C23.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\fabri\CLionProjects\DomJudge\ED\C23 C:\Users\fabri\CLionProjects\DomJudge\ED\C23 C:\Users\fabri\CLionProjects\DomJudge\ED\C23\cmake-build-debug C:\Users\fabri\CLionProjects\DomJudge\ED\C23\cmake-build-debug C:\Users\fabri\CLionProjects\DomJudge\ED\C23\cmake-build-debug\CMakeFiles\C23.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/C23.dir/depend

