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
CMAKE_SOURCE_DIR = /home/vadim/projects/progbase2/labs/lab8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vadim/projects/progbase2/labs/lab8/build

# Include any dependencies generated for this target.
include CMakeFiles/json.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/json.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/json.dir/flags.make

CMakeFiles/json.dir/main.cpp.o: CMakeFiles/json.dir/flags.make
CMakeFiles/json.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vadim/projects/progbase2/labs/lab8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/json.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/json.dir/main.cpp.o -c /home/vadim/projects/progbase2/labs/lab8/main.cpp

CMakeFiles/json.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/json.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vadim/projects/progbase2/labs/lab8/main.cpp > CMakeFiles/json.dir/main.cpp.i

CMakeFiles/json.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/json.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vadim/projects/progbase2/labs/lab8/main.cpp -o CMakeFiles/json.dir/main.cpp.s

CMakeFiles/json.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/json.dir/main.cpp.o.requires

CMakeFiles/json.dir/main.cpp.o.provides: CMakeFiles/json.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/json.dir/build.make CMakeFiles/json.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/json.dir/main.cpp.o.provides

CMakeFiles/json.dir/main.cpp.o.provides.build: CMakeFiles/json.dir/main.cpp.o


CMakeFiles/json.dir/src/jsonconverter.cpp.o: CMakeFiles/json.dir/flags.make
CMakeFiles/json.dir/src/jsonconverter.cpp.o: ../src/jsonconverter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vadim/projects/progbase2/labs/lab8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/json.dir/src/jsonconverter.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/json.dir/src/jsonconverter.cpp.o -c /home/vadim/projects/progbase2/labs/lab8/src/jsonconverter.cpp

CMakeFiles/json.dir/src/jsonconverter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/json.dir/src/jsonconverter.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vadim/projects/progbase2/labs/lab8/src/jsonconverter.cpp > CMakeFiles/json.dir/src/jsonconverter.cpp.i

CMakeFiles/json.dir/src/jsonconverter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/json.dir/src/jsonconverter.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vadim/projects/progbase2/labs/lab8/src/jsonconverter.cpp -o CMakeFiles/json.dir/src/jsonconverter.cpp.s

CMakeFiles/json.dir/src/jsonconverter.cpp.o.requires:

.PHONY : CMakeFiles/json.dir/src/jsonconverter.cpp.o.requires

CMakeFiles/json.dir/src/jsonconverter.cpp.o.provides: CMakeFiles/json.dir/src/jsonconverter.cpp.o.requires
	$(MAKE) -f CMakeFiles/json.dir/build.make CMakeFiles/json.dir/src/jsonconverter.cpp.o.provides.build
.PHONY : CMakeFiles/json.dir/src/jsonconverter.cpp.o.provides

CMakeFiles/json.dir/src/jsonconverter.cpp.o.provides.build: CMakeFiles/json.dir/src/jsonconverter.cpp.o


CMakeFiles/json.dir/src/places.cpp.o: CMakeFiles/json.dir/flags.make
CMakeFiles/json.dir/src/places.cpp.o: ../src/places.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vadim/projects/progbase2/labs/lab8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/json.dir/src/places.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/json.dir/src/places.cpp.o -c /home/vadim/projects/progbase2/labs/lab8/src/places.cpp

CMakeFiles/json.dir/src/places.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/json.dir/src/places.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vadim/projects/progbase2/labs/lab8/src/places.cpp > CMakeFiles/json.dir/src/places.cpp.i

CMakeFiles/json.dir/src/places.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/json.dir/src/places.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vadim/projects/progbase2/labs/lab8/src/places.cpp -o CMakeFiles/json.dir/src/places.cpp.s

CMakeFiles/json.dir/src/places.cpp.o.requires:

.PHONY : CMakeFiles/json.dir/src/places.cpp.o.requires

CMakeFiles/json.dir/src/places.cpp.o.provides: CMakeFiles/json.dir/src/places.cpp.o.requires
	$(MAKE) -f CMakeFiles/json.dir/build.make CMakeFiles/json.dir/src/places.cpp.o.provides.build
.PHONY : CMakeFiles/json.dir/src/places.cpp.o.provides

CMakeFiles/json.dir/src/places.cpp.o.provides.build: CMakeFiles/json.dir/src/places.cpp.o


CMakeFiles/json.dir/src/request.cpp.o: CMakeFiles/json.dir/flags.make
CMakeFiles/json.dir/src/request.cpp.o: ../src/request.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vadim/projects/progbase2/labs/lab8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/json.dir/src/request.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/json.dir/src/request.cpp.o -c /home/vadim/projects/progbase2/labs/lab8/src/request.cpp

CMakeFiles/json.dir/src/request.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/json.dir/src/request.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vadim/projects/progbase2/labs/lab8/src/request.cpp > CMakeFiles/json.dir/src/request.cpp.i

CMakeFiles/json.dir/src/request.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/json.dir/src/request.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vadim/projects/progbase2/labs/lab8/src/request.cpp -o CMakeFiles/json.dir/src/request.cpp.s

CMakeFiles/json.dir/src/request.cpp.o.requires:

.PHONY : CMakeFiles/json.dir/src/request.cpp.o.requires

CMakeFiles/json.dir/src/request.cpp.o.provides: CMakeFiles/json.dir/src/request.cpp.o.requires
	$(MAKE) -f CMakeFiles/json.dir/build.make CMakeFiles/json.dir/src/request.cpp.o.provides.build
.PHONY : CMakeFiles/json.dir/src/request.cpp.o.provides

CMakeFiles/json.dir/src/request.cpp.o.provides.build: CMakeFiles/json.dir/src/request.cpp.o


CMakeFiles/json.dir/src/tcp_server.cpp.o: CMakeFiles/json.dir/flags.make
CMakeFiles/json.dir/src/tcp_server.cpp.o: ../src/tcp_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/vadim/projects/progbase2/labs/lab8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/json.dir/src/tcp_server.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/json.dir/src/tcp_server.cpp.o -c /home/vadim/projects/progbase2/labs/lab8/src/tcp_server.cpp

CMakeFiles/json.dir/src/tcp_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/json.dir/src/tcp_server.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/vadim/projects/progbase2/labs/lab8/src/tcp_server.cpp > CMakeFiles/json.dir/src/tcp_server.cpp.i

CMakeFiles/json.dir/src/tcp_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/json.dir/src/tcp_server.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/vadim/projects/progbase2/labs/lab8/src/tcp_server.cpp -o CMakeFiles/json.dir/src/tcp_server.cpp.s

CMakeFiles/json.dir/src/tcp_server.cpp.o.requires:

.PHONY : CMakeFiles/json.dir/src/tcp_server.cpp.o.requires

CMakeFiles/json.dir/src/tcp_server.cpp.o.provides: CMakeFiles/json.dir/src/tcp_server.cpp.o.requires
	$(MAKE) -f CMakeFiles/json.dir/build.make CMakeFiles/json.dir/src/tcp_server.cpp.o.provides.build
.PHONY : CMakeFiles/json.dir/src/tcp_server.cpp.o.provides

CMakeFiles/json.dir/src/tcp_server.cpp.o.provides.build: CMakeFiles/json.dir/src/tcp_server.cpp.o


# Object files for target json
json_OBJECTS = \
"CMakeFiles/json.dir/main.cpp.o" \
"CMakeFiles/json.dir/src/jsonconverter.cpp.o" \
"CMakeFiles/json.dir/src/places.cpp.o" \
"CMakeFiles/json.dir/src/request.cpp.o" \
"CMakeFiles/json.dir/src/tcp_server.cpp.o"

# External object files for target json
json_EXTERNAL_OBJECTS =

json: CMakeFiles/json.dir/main.cpp.o
json: CMakeFiles/json.dir/src/jsonconverter.cpp.o
json: CMakeFiles/json.dir/src/places.cpp.o
json: CMakeFiles/json.dir/src/request.cpp.o
json: CMakeFiles/json.dir/src/tcp_server.cpp.o
json: CMakeFiles/json.dir/build.make
json: CMakeFiles/json.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/vadim/projects/progbase2/labs/lab8/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable json"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/json.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/json.dir/build: json

.PHONY : CMakeFiles/json.dir/build

CMakeFiles/json.dir/requires: CMakeFiles/json.dir/main.cpp.o.requires
CMakeFiles/json.dir/requires: CMakeFiles/json.dir/src/jsonconverter.cpp.o.requires
CMakeFiles/json.dir/requires: CMakeFiles/json.dir/src/places.cpp.o.requires
CMakeFiles/json.dir/requires: CMakeFiles/json.dir/src/request.cpp.o.requires
CMakeFiles/json.dir/requires: CMakeFiles/json.dir/src/tcp_server.cpp.o.requires

.PHONY : CMakeFiles/json.dir/requires

CMakeFiles/json.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/json.dir/cmake_clean.cmake
.PHONY : CMakeFiles/json.dir/clean

CMakeFiles/json.dir/depend:
	cd /home/vadim/projects/progbase2/labs/lab8/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vadim/projects/progbase2/labs/lab8 /home/vadim/projects/progbase2/labs/lab8 /home/vadim/projects/progbase2/labs/lab8/build /home/vadim/projects/progbase2/labs/lab8/build /home/vadim/projects/progbase2/labs/lab8/build/CMakeFiles/json.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/json.dir/depend

