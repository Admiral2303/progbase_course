# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_SOURCE_DIR = /home/vadim/Atomproject/atomproject/lab4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vadim/Atomproject/atomproject/lab4/build

# Include any dependencies generated for this target.
include CMakeFiles/profecionals.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/profecionals.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/profecionals.dir/flags.make

CMakeFiles/profecionals.dir/src/list.c.o: CMakeFiles/profecionals.dir/flags.make
CMakeFiles/profecionals.dir/src/list.c.o: ../src/list.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vadim/Atomproject/atomproject/lab4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/profecionals.dir/src/list.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/profecionals.dir/src/list.c.o   -c /home/vadim/Atomproject/atomproject/lab4/src/list.c

CMakeFiles/profecionals.dir/src/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/profecionals.dir/src/list.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vadim/Atomproject/atomproject/lab4/src/list.c > CMakeFiles/profecionals.dir/src/list.c.i

CMakeFiles/profecionals.dir/src/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/profecionals.dir/src/list.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vadim/Atomproject/atomproject/lab4/src/list.c -o CMakeFiles/profecionals.dir/src/list.c.s

CMakeFiles/profecionals.dir/src/list.c.o.requires:

.PHONY : CMakeFiles/profecionals.dir/src/list.c.o.requires

CMakeFiles/profecionals.dir/src/list.c.o.provides: CMakeFiles/profecionals.dir/src/list.c.o.requires
	$(MAKE) -f CMakeFiles/profecionals.dir/build.make CMakeFiles/profecionals.dir/src/list.c.o.provides.build
.PHONY : CMakeFiles/profecionals.dir/src/list.c.o.provides

CMakeFiles/profecionals.dir/src/list.c.o.provides.build: CMakeFiles/profecionals.dir/src/list.c.o


CMakeFiles/profecionals.dir/src/convert.c.o: CMakeFiles/profecionals.dir/flags.make
CMakeFiles/profecionals.dir/src/convert.c.o: ../src/convert.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vadim/Atomproject/atomproject/lab4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/profecionals.dir/src/convert.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/profecionals.dir/src/convert.c.o   -c /home/vadim/Atomproject/atomproject/lab4/src/convert.c

CMakeFiles/profecionals.dir/src/convert.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/profecionals.dir/src/convert.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vadim/Atomproject/atomproject/lab4/src/convert.c > CMakeFiles/profecionals.dir/src/convert.c.i

CMakeFiles/profecionals.dir/src/convert.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/profecionals.dir/src/convert.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vadim/Atomproject/atomproject/lab4/src/convert.c -o CMakeFiles/profecionals.dir/src/convert.c.s

CMakeFiles/profecionals.dir/src/convert.c.o.requires:

.PHONY : CMakeFiles/profecionals.dir/src/convert.c.o.requires

CMakeFiles/profecionals.dir/src/convert.c.o.provides: CMakeFiles/profecionals.dir/src/convert.c.o.requires
	$(MAKE) -f CMakeFiles/profecionals.dir/build.make CMakeFiles/profecionals.dir/src/convert.c.o.provides.build
.PHONY : CMakeFiles/profecionals.dir/src/convert.c.o.provides

CMakeFiles/profecionals.dir/src/convert.c.o.provides.build: CMakeFiles/profecionals.dir/src/convert.c.o


CMakeFiles/profecionals.dir/src/function.c.o: CMakeFiles/profecionals.dir/flags.make
CMakeFiles/profecionals.dir/src/function.c.o: ../src/function.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vadim/Atomproject/atomproject/lab4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/profecionals.dir/src/function.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/profecionals.dir/src/function.c.o   -c /home/vadim/Atomproject/atomproject/lab4/src/function.c

CMakeFiles/profecionals.dir/src/function.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/profecionals.dir/src/function.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vadim/Atomproject/atomproject/lab4/src/function.c > CMakeFiles/profecionals.dir/src/function.c.i

CMakeFiles/profecionals.dir/src/function.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/profecionals.dir/src/function.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vadim/Atomproject/atomproject/lab4/src/function.c -o CMakeFiles/profecionals.dir/src/function.c.s

CMakeFiles/profecionals.dir/src/function.c.o.requires:

.PHONY : CMakeFiles/profecionals.dir/src/function.c.o.requires

CMakeFiles/profecionals.dir/src/function.c.o.provides: CMakeFiles/profecionals.dir/src/function.c.o.requires
	$(MAKE) -f CMakeFiles/profecionals.dir/build.make CMakeFiles/profecionals.dir/src/function.c.o.provides.build
.PHONY : CMakeFiles/profecionals.dir/src/function.c.o.provides

CMakeFiles/profecionals.dir/src/function.c.o.provides.build: CMakeFiles/profecionals.dir/src/function.c.o


CMakeFiles/profecionals.dir/src/menu.c.o: CMakeFiles/profecionals.dir/flags.make
CMakeFiles/profecionals.dir/src/menu.c.o: ../src/menu.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vadim/Atomproject/atomproject/lab4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/profecionals.dir/src/menu.c.o"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/profecionals.dir/src/menu.c.o   -c /home/vadim/Atomproject/atomproject/lab4/src/menu.c

CMakeFiles/profecionals.dir/src/menu.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/profecionals.dir/src/menu.c.i"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/vadim/Atomproject/atomproject/lab4/src/menu.c > CMakeFiles/profecionals.dir/src/menu.c.i

CMakeFiles/profecionals.dir/src/menu.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/profecionals.dir/src/menu.c.s"
	/usr/bin/cc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/vadim/Atomproject/atomproject/lab4/src/menu.c -o CMakeFiles/profecionals.dir/src/menu.c.s

CMakeFiles/profecionals.dir/src/menu.c.o.requires:

.PHONY : CMakeFiles/profecionals.dir/src/menu.c.o.requires

CMakeFiles/profecionals.dir/src/menu.c.o.provides: CMakeFiles/profecionals.dir/src/menu.c.o.requires
	$(MAKE) -f CMakeFiles/profecionals.dir/build.make CMakeFiles/profecionals.dir/src/menu.c.o.provides.build
.PHONY : CMakeFiles/profecionals.dir/src/menu.c.o.provides

CMakeFiles/profecionals.dir/src/menu.c.o.provides.build: CMakeFiles/profecionals.dir/src/menu.c.o


# Object files for target profecionals
profecionals_OBJECTS = \
"CMakeFiles/profecionals.dir/src/list.c.o" \
"CMakeFiles/profecionals.dir/src/convert.c.o" \
"CMakeFiles/profecionals.dir/src/function.c.o" \
"CMakeFiles/profecionals.dir/src/menu.c.o"

# External object files for target profecionals
profecionals_EXTERNAL_OBJECTS =

libprofecionals.a: CMakeFiles/profecionals.dir/src/list.c.o
libprofecionals.a: CMakeFiles/profecionals.dir/src/convert.c.o
libprofecionals.a: CMakeFiles/profecionals.dir/src/function.c.o
libprofecionals.a: CMakeFiles/profecionals.dir/src/menu.c.o
libprofecionals.a: CMakeFiles/profecionals.dir/build.make
libprofecionals.a: CMakeFiles/profecionals.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vadim/Atomproject/atomproject/lab4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C static library libprofecionals.a"
	$(CMAKE_COMMAND) -P CMakeFiles/profecionals.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/profecionals.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/profecionals.dir/build: libprofecionals.a

.PHONY : CMakeFiles/profecionals.dir/build

CMakeFiles/profecionals.dir/requires: CMakeFiles/profecionals.dir/src/list.c.o.requires
CMakeFiles/profecionals.dir/requires: CMakeFiles/profecionals.dir/src/convert.c.o.requires
CMakeFiles/profecionals.dir/requires: CMakeFiles/profecionals.dir/src/function.c.o.requires
CMakeFiles/profecionals.dir/requires: CMakeFiles/profecionals.dir/src/menu.c.o.requires

.PHONY : CMakeFiles/profecionals.dir/requires

CMakeFiles/profecionals.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/profecionals.dir/cmake_clean.cmake
.PHONY : CMakeFiles/profecionals.dir/clean

CMakeFiles/profecionals.dir/depend:
	cd /home/vadim/Atomproject/atomproject/lab4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vadim/Atomproject/atomproject/lab4 /home/vadim/Atomproject/atomproject/lab4 /home/vadim/Atomproject/atomproject/lab4/build /home/vadim/Atomproject/atomproject/lab4/build /home/vadim/Atomproject/atomproject/lab4/build/CMakeFiles/profecionals.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/profecionals.dir/depend

