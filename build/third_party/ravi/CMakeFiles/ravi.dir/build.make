# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/xash/luamod

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/xash/luamod/build

# Include any dependencies generated for this target.
include third_party/ravi/CMakeFiles/ravi.dir/depend.make

# Include the progress variables for this target.
include third_party/ravi/CMakeFiles/ravi.dir/progress.make

# Include the compile flags for this target's objects.
include third_party/ravi/CMakeFiles/ravi.dir/flags.make

third_party/ravi/CMakeFiles/ravi.dir/src/lua.c.o: third_party/ravi/CMakeFiles/ravi.dir/flags.make
third_party/ravi/CMakeFiles/ravi.dir/src/lua.c.o: ../third_party/ravi/src/lua.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/xash/luamod/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object third_party/ravi/CMakeFiles/ravi.dir/src/lua.c.o"
	cd /home/xash/luamod/build/third_party/ravi && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ravi.dir/src/lua.c.o   -c /home/xash/luamod/third_party/ravi/src/lua.c

third_party/ravi/CMakeFiles/ravi.dir/src/lua.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ravi.dir/src/lua.c.i"
	cd /home/xash/luamod/build/third_party/ravi && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/xash/luamod/third_party/ravi/src/lua.c > CMakeFiles/ravi.dir/src/lua.c.i

third_party/ravi/CMakeFiles/ravi.dir/src/lua.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ravi.dir/src/lua.c.s"
	cd /home/xash/luamod/build/third_party/ravi && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/xash/luamod/third_party/ravi/src/lua.c -o CMakeFiles/ravi.dir/src/lua.c.s

third_party/ravi/CMakeFiles/ravi.dir/src/lua.c.o.requires:

.PHONY : third_party/ravi/CMakeFiles/ravi.dir/src/lua.c.o.requires

third_party/ravi/CMakeFiles/ravi.dir/src/lua.c.o.provides: third_party/ravi/CMakeFiles/ravi.dir/src/lua.c.o.requires
	$(MAKE) -f third_party/ravi/CMakeFiles/ravi.dir/build.make third_party/ravi/CMakeFiles/ravi.dir/src/lua.c.o.provides.build
.PHONY : third_party/ravi/CMakeFiles/ravi.dir/src/lua.c.o.provides

third_party/ravi/CMakeFiles/ravi.dir/src/lua.c.o.provides.build: third_party/ravi/CMakeFiles/ravi.dir/src/lua.c.o


# Object files for target ravi
ravi_OBJECTS = \
"CMakeFiles/ravi.dir/src/lua.c.o"

# External object files for target ravi
ravi_EXTERNAL_OBJECTS =

third_party/ravi/ravi: third_party/ravi/CMakeFiles/ravi.dir/src/lua.c.o
third_party/ravi/ravi: third_party/ravi/CMakeFiles/ravi.dir/build.make
third_party/ravi/ravi: third_party/ravi/libravinojit.so
third_party/ravi/ravi: third_party/ravi/CMakeFiles/ravi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/xash/luamod/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ravi"
	cd /home/xash/luamod/build/third_party/ravi && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ravi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
third_party/ravi/CMakeFiles/ravi.dir/build: third_party/ravi/ravi

.PHONY : third_party/ravi/CMakeFiles/ravi.dir/build

third_party/ravi/CMakeFiles/ravi.dir/requires: third_party/ravi/CMakeFiles/ravi.dir/src/lua.c.o.requires

.PHONY : third_party/ravi/CMakeFiles/ravi.dir/requires

third_party/ravi/CMakeFiles/ravi.dir/clean:
	cd /home/xash/luamod/build/third_party/ravi && $(CMAKE_COMMAND) -P CMakeFiles/ravi.dir/cmake_clean.cmake
.PHONY : third_party/ravi/CMakeFiles/ravi.dir/clean

third_party/ravi/CMakeFiles/ravi.dir/depend:
	cd /home/xash/luamod/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/xash/luamod /home/xash/luamod/third_party/ravi /home/xash/luamod/build /home/xash/luamod/build/third_party/ravi /home/xash/luamod/build/third_party/ravi/CMakeFiles/ravi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : third_party/ravi/CMakeFiles/ravi.dir/depend
