# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jd/Documents/git_repos/Task_manager_AI

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jd/Documents/git_repos/Task_manager_AI/build

# Include any dependencies generated for this target.
include CMakeFiles/TaskManager.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/TaskManager.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/TaskManager.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TaskManager.dir/flags.make

CMakeFiles/TaskManager.dir/main.cpp.o: CMakeFiles/TaskManager.dir/flags.make
CMakeFiles/TaskManager.dir/main.cpp.o: /Users/jd/Documents/git_repos/Task_manager_AI/main.cpp
CMakeFiles/TaskManager.dir/main.cpp.o: CMakeFiles/TaskManager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jd/Documents/git_repos/Task_manager_AI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TaskManager.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TaskManager.dir/main.cpp.o -MF CMakeFiles/TaskManager.dir/main.cpp.o.d -o CMakeFiles/TaskManager.dir/main.cpp.o -c /Users/jd/Documents/git_repos/Task_manager_AI/main.cpp

CMakeFiles/TaskManager.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TaskManager.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jd/Documents/git_repos/Task_manager_AI/main.cpp > CMakeFiles/TaskManager.dir/main.cpp.i

CMakeFiles/TaskManager.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TaskManager.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jd/Documents/git_repos/Task_manager_AI/main.cpp -o CMakeFiles/TaskManager.dir/main.cpp.s

CMakeFiles/TaskManager.dir/src/TaskManager.cpp.o: CMakeFiles/TaskManager.dir/flags.make
CMakeFiles/TaskManager.dir/src/TaskManager.cpp.o: /Users/jd/Documents/git_repos/Task_manager_AI/src/TaskManager.cpp
CMakeFiles/TaskManager.dir/src/TaskManager.cpp.o: CMakeFiles/TaskManager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jd/Documents/git_repos/Task_manager_AI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TaskManager.dir/src/TaskManager.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TaskManager.dir/src/TaskManager.cpp.o -MF CMakeFiles/TaskManager.dir/src/TaskManager.cpp.o.d -o CMakeFiles/TaskManager.dir/src/TaskManager.cpp.o -c /Users/jd/Documents/git_repos/Task_manager_AI/src/TaskManager.cpp

CMakeFiles/TaskManager.dir/src/TaskManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TaskManager.dir/src/TaskManager.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jd/Documents/git_repos/Task_manager_AI/src/TaskManager.cpp > CMakeFiles/TaskManager.dir/src/TaskManager.cpp.i

CMakeFiles/TaskManager.dir/src/TaskManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TaskManager.dir/src/TaskManager.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jd/Documents/git_repos/Task_manager_AI/src/TaskManager.cpp -o CMakeFiles/TaskManager.dir/src/TaskManager.cpp.s

CMakeFiles/TaskManager.dir/src/AiTask.cpp.o: CMakeFiles/TaskManager.dir/flags.make
CMakeFiles/TaskManager.dir/src/AiTask.cpp.o: /Users/jd/Documents/git_repos/Task_manager_AI/src/AiTask.cpp
CMakeFiles/TaskManager.dir/src/AiTask.cpp.o: CMakeFiles/TaskManager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jd/Documents/git_repos/Task_manager_AI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TaskManager.dir/src/AiTask.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TaskManager.dir/src/AiTask.cpp.o -MF CMakeFiles/TaskManager.dir/src/AiTask.cpp.o.d -o CMakeFiles/TaskManager.dir/src/AiTask.cpp.o -c /Users/jd/Documents/git_repos/Task_manager_AI/src/AiTask.cpp

CMakeFiles/TaskManager.dir/src/AiTask.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TaskManager.dir/src/AiTask.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jd/Documents/git_repos/Task_manager_AI/src/AiTask.cpp > CMakeFiles/TaskManager.dir/src/AiTask.cpp.i

CMakeFiles/TaskManager.dir/src/AiTask.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TaskManager.dir/src/AiTask.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jd/Documents/git_repos/Task_manager_AI/src/AiTask.cpp -o CMakeFiles/TaskManager.dir/src/AiTask.cpp.s

CMakeFiles/TaskManager.dir/src/HpcTask.cpp.o: CMakeFiles/TaskManager.dir/flags.make
CMakeFiles/TaskManager.dir/src/HpcTask.cpp.o: /Users/jd/Documents/git_repos/Task_manager_AI/src/HpcTask.cpp
CMakeFiles/TaskManager.dir/src/HpcTask.cpp.o: CMakeFiles/TaskManager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jd/Documents/git_repos/Task_manager_AI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TaskManager.dir/src/HpcTask.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TaskManager.dir/src/HpcTask.cpp.o -MF CMakeFiles/TaskManager.dir/src/HpcTask.cpp.o.d -o CMakeFiles/TaskManager.dir/src/HpcTask.cpp.o -c /Users/jd/Documents/git_repos/Task_manager_AI/src/HpcTask.cpp

CMakeFiles/TaskManager.dir/src/HpcTask.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TaskManager.dir/src/HpcTask.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jd/Documents/git_repos/Task_manager_AI/src/HpcTask.cpp > CMakeFiles/TaskManager.dir/src/HpcTask.cpp.i

CMakeFiles/TaskManager.dir/src/HpcTask.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TaskManager.dir/src/HpcTask.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jd/Documents/git_repos/Task_manager_AI/src/HpcTask.cpp -o CMakeFiles/TaskManager.dir/src/HpcTask.cpp.s

CMakeFiles/TaskManager.dir/src/ProgrammingTask.cpp.o: CMakeFiles/TaskManager.dir/flags.make
CMakeFiles/TaskManager.dir/src/ProgrammingTask.cpp.o: /Users/jd/Documents/git_repos/Task_manager_AI/src/ProgrammingTask.cpp
CMakeFiles/TaskManager.dir/src/ProgrammingTask.cpp.o: CMakeFiles/TaskManager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jd/Documents/git_repos/Task_manager_AI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/TaskManager.dir/src/ProgrammingTask.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TaskManager.dir/src/ProgrammingTask.cpp.o -MF CMakeFiles/TaskManager.dir/src/ProgrammingTask.cpp.o.d -o CMakeFiles/TaskManager.dir/src/ProgrammingTask.cpp.o -c /Users/jd/Documents/git_repos/Task_manager_AI/src/ProgrammingTask.cpp

CMakeFiles/TaskManager.dir/src/ProgrammingTask.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TaskManager.dir/src/ProgrammingTask.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jd/Documents/git_repos/Task_manager_AI/src/ProgrammingTask.cpp > CMakeFiles/TaskManager.dir/src/ProgrammingTask.cpp.i

CMakeFiles/TaskManager.dir/src/ProgrammingTask.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TaskManager.dir/src/ProgrammingTask.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jd/Documents/git_repos/Task_manager_AI/src/ProgrammingTask.cpp -o CMakeFiles/TaskManager.dir/src/ProgrammingTask.cpp.s

CMakeFiles/TaskManager.dir/src/DevopsTask.cpp.o: CMakeFiles/TaskManager.dir/flags.make
CMakeFiles/TaskManager.dir/src/DevopsTask.cpp.o: /Users/jd/Documents/git_repos/Task_manager_AI/src/DevopsTask.cpp
CMakeFiles/TaskManager.dir/src/DevopsTask.cpp.o: CMakeFiles/TaskManager.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/jd/Documents/git_repos/Task_manager_AI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/TaskManager.dir/src/DevopsTask.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/TaskManager.dir/src/DevopsTask.cpp.o -MF CMakeFiles/TaskManager.dir/src/DevopsTask.cpp.o.d -o CMakeFiles/TaskManager.dir/src/DevopsTask.cpp.o -c /Users/jd/Documents/git_repos/Task_manager_AI/src/DevopsTask.cpp

CMakeFiles/TaskManager.dir/src/DevopsTask.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/TaskManager.dir/src/DevopsTask.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jd/Documents/git_repos/Task_manager_AI/src/DevopsTask.cpp > CMakeFiles/TaskManager.dir/src/DevopsTask.cpp.i

CMakeFiles/TaskManager.dir/src/DevopsTask.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/TaskManager.dir/src/DevopsTask.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jd/Documents/git_repos/Task_manager_AI/src/DevopsTask.cpp -o CMakeFiles/TaskManager.dir/src/DevopsTask.cpp.s

# Object files for target TaskManager
TaskManager_OBJECTS = \
"CMakeFiles/TaskManager.dir/main.cpp.o" \
"CMakeFiles/TaskManager.dir/src/TaskManager.cpp.o" \
"CMakeFiles/TaskManager.dir/src/AiTask.cpp.o" \
"CMakeFiles/TaskManager.dir/src/HpcTask.cpp.o" \
"CMakeFiles/TaskManager.dir/src/ProgrammingTask.cpp.o" \
"CMakeFiles/TaskManager.dir/src/DevopsTask.cpp.o"

# External object files for target TaskManager
TaskManager_EXTERNAL_OBJECTS =

TaskManager: CMakeFiles/TaskManager.dir/main.cpp.o
TaskManager: CMakeFiles/TaskManager.dir/src/TaskManager.cpp.o
TaskManager: CMakeFiles/TaskManager.dir/src/AiTask.cpp.o
TaskManager: CMakeFiles/TaskManager.dir/src/HpcTask.cpp.o
TaskManager: CMakeFiles/TaskManager.dir/src/ProgrammingTask.cpp.o
TaskManager: CMakeFiles/TaskManager.dir/src/DevopsTask.cpp.o
TaskManager: CMakeFiles/TaskManager.dir/build.make
TaskManager: CMakeFiles/TaskManager.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/jd/Documents/git_repos/Task_manager_AI/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable TaskManager"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TaskManager.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TaskManager.dir/build: TaskManager
.PHONY : CMakeFiles/TaskManager.dir/build

CMakeFiles/TaskManager.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TaskManager.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TaskManager.dir/clean

CMakeFiles/TaskManager.dir/depend:
	cd /Users/jd/Documents/git_repos/Task_manager_AI/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jd/Documents/git_repos/Task_manager_AI /Users/jd/Documents/git_repos/Task_manager_AI /Users/jd/Documents/git_repos/Task_manager_AI/build /Users/jd/Documents/git_repos/Task_manager_AI/build /Users/jd/Documents/git_repos/Task_manager_AI/build/CMakeFiles/TaskManager.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/TaskManager.dir/depend
