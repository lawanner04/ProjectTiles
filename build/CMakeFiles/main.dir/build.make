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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lukewanner/Desktop/LukeGames/projectTiles

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lukewanner/Desktop/LukeGames/projectTiles/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/src/GlobalFiles.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/GlobalFiles.cpp.o: /Users/lukewanner/Desktop/LukeGames/projectTiles/src/GlobalFiles.cpp
CMakeFiles/main.dir/src/GlobalFiles.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/lukewanner/Desktop/LukeGames/projectTiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/src/GlobalFiles.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/GlobalFiles.cpp.o -MF CMakeFiles/main.dir/src/GlobalFiles.cpp.o.d -o CMakeFiles/main.dir/src/GlobalFiles.cpp.o -c /Users/lukewanner/Desktop/LukeGames/projectTiles/src/GlobalFiles.cpp

CMakeFiles/main.dir/src/GlobalFiles.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/GlobalFiles.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lukewanner/Desktop/LukeGames/projectTiles/src/GlobalFiles.cpp > CMakeFiles/main.dir/src/GlobalFiles.cpp.i

CMakeFiles/main.dir/src/GlobalFiles.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/GlobalFiles.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lukewanner/Desktop/LukeGames/projectTiles/src/GlobalFiles.cpp -o CMakeFiles/main.dir/src/GlobalFiles.cpp.s

CMakeFiles/main.dir/src/collisionManager.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/collisionManager.cpp.o: /Users/lukewanner/Desktop/LukeGames/projectTiles/src/collisionManager.cpp
CMakeFiles/main.dir/src/collisionManager.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/lukewanner/Desktop/LukeGames/projectTiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/main.dir/src/collisionManager.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/collisionManager.cpp.o -MF CMakeFiles/main.dir/src/collisionManager.cpp.o.d -o CMakeFiles/main.dir/src/collisionManager.cpp.o -c /Users/lukewanner/Desktop/LukeGames/projectTiles/src/collisionManager.cpp

CMakeFiles/main.dir/src/collisionManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/collisionManager.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lukewanner/Desktop/LukeGames/projectTiles/src/collisionManager.cpp > CMakeFiles/main.dir/src/collisionManager.cpp.i

CMakeFiles/main.dir/src/collisionManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/collisionManager.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lukewanner/Desktop/LukeGames/projectTiles/src/collisionManager.cpp -o CMakeFiles/main.dir/src/collisionManager.cpp.s

CMakeFiles/main.dir/src/enemy.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/enemy.cpp.o: /Users/lukewanner/Desktop/LukeGames/projectTiles/src/enemy.cpp
CMakeFiles/main.dir/src/enemy.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/lukewanner/Desktop/LukeGames/projectTiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/main.dir/src/enemy.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/enemy.cpp.o -MF CMakeFiles/main.dir/src/enemy.cpp.o.d -o CMakeFiles/main.dir/src/enemy.cpp.o -c /Users/lukewanner/Desktop/LukeGames/projectTiles/src/enemy.cpp

CMakeFiles/main.dir/src/enemy.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/enemy.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lukewanner/Desktop/LukeGames/projectTiles/src/enemy.cpp > CMakeFiles/main.dir/src/enemy.cpp.i

CMakeFiles/main.dir/src/enemy.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/enemy.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lukewanner/Desktop/LukeGames/projectTiles/src/enemy.cpp -o CMakeFiles/main.dir/src/enemy.cpp.s

CMakeFiles/main.dir/src/entity.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/entity.cpp.o: /Users/lukewanner/Desktop/LukeGames/projectTiles/src/entity.cpp
CMakeFiles/main.dir/src/entity.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/lukewanner/Desktop/LukeGames/projectTiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/main.dir/src/entity.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/entity.cpp.o -MF CMakeFiles/main.dir/src/entity.cpp.o.d -o CMakeFiles/main.dir/src/entity.cpp.o -c /Users/lukewanner/Desktop/LukeGames/projectTiles/src/entity.cpp

CMakeFiles/main.dir/src/entity.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/entity.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lukewanner/Desktop/LukeGames/projectTiles/src/entity.cpp > CMakeFiles/main.dir/src/entity.cpp.i

CMakeFiles/main.dir/src/entity.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/entity.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lukewanner/Desktop/LukeGames/projectTiles/src/entity.cpp -o CMakeFiles/main.dir/src/entity.cpp.s

CMakeFiles/main.dir/src/inventory.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/inventory.cpp.o: /Users/lukewanner/Desktop/LukeGames/projectTiles/src/inventory.cpp
CMakeFiles/main.dir/src/inventory.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/lukewanner/Desktop/LukeGames/projectTiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/main.dir/src/inventory.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/inventory.cpp.o -MF CMakeFiles/main.dir/src/inventory.cpp.o.d -o CMakeFiles/main.dir/src/inventory.cpp.o -c /Users/lukewanner/Desktop/LukeGames/projectTiles/src/inventory.cpp

CMakeFiles/main.dir/src/inventory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/inventory.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lukewanner/Desktop/LukeGames/projectTiles/src/inventory.cpp > CMakeFiles/main.dir/src/inventory.cpp.i

CMakeFiles/main.dir/src/inventory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/inventory.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lukewanner/Desktop/LukeGames/projectTiles/src/inventory.cpp -o CMakeFiles/main.dir/src/inventory.cpp.s

CMakeFiles/main.dir/src/item.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/item.cpp.o: /Users/lukewanner/Desktop/LukeGames/projectTiles/src/item.cpp
CMakeFiles/main.dir/src/item.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/lukewanner/Desktop/LukeGames/projectTiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/main.dir/src/item.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/item.cpp.o -MF CMakeFiles/main.dir/src/item.cpp.o.d -o CMakeFiles/main.dir/src/item.cpp.o -c /Users/lukewanner/Desktop/LukeGames/projectTiles/src/item.cpp

CMakeFiles/main.dir/src/item.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/item.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lukewanner/Desktop/LukeGames/projectTiles/src/item.cpp > CMakeFiles/main.dir/src/item.cpp.i

CMakeFiles/main.dir/src/item.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/item.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lukewanner/Desktop/LukeGames/projectTiles/src/item.cpp -o CMakeFiles/main.dir/src/item.cpp.s

CMakeFiles/main.dir/src/main.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/main.cpp.o: /Users/lukewanner/Desktop/LukeGames/projectTiles/src/main.cpp
CMakeFiles/main.dir/src/main.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/lukewanner/Desktop/LukeGames/projectTiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/main.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/main.cpp.o -MF CMakeFiles/main.dir/src/main.cpp.o.d -o CMakeFiles/main.dir/src/main.cpp.o -c /Users/lukewanner/Desktop/LukeGames/projectTiles/src/main.cpp

CMakeFiles/main.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lukewanner/Desktop/LukeGames/projectTiles/src/main.cpp > CMakeFiles/main.dir/src/main.cpp.i

CMakeFiles/main.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lukewanner/Desktop/LukeGames/projectTiles/src/main.cpp -o CMakeFiles/main.dir/src/main.cpp.s

CMakeFiles/main.dir/src/player.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/player.cpp.o: /Users/lukewanner/Desktop/LukeGames/projectTiles/src/player.cpp
CMakeFiles/main.dir/src/player.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/lukewanner/Desktop/LukeGames/projectTiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/main.dir/src/player.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/player.cpp.o -MF CMakeFiles/main.dir/src/player.cpp.o.d -o CMakeFiles/main.dir/src/player.cpp.o -c /Users/lukewanner/Desktop/LukeGames/projectTiles/src/player.cpp

CMakeFiles/main.dir/src/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/player.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lukewanner/Desktop/LukeGames/projectTiles/src/player.cpp > CMakeFiles/main.dir/src/player.cpp.i

CMakeFiles/main.dir/src/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/player.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lukewanner/Desktop/LukeGames/projectTiles/src/player.cpp -o CMakeFiles/main.dir/src/player.cpp.s

CMakeFiles/main.dir/src/worldMap.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/src/worldMap.cpp.o: /Users/lukewanner/Desktop/LukeGames/projectTiles/src/worldMap.cpp
CMakeFiles/main.dir/src/worldMap.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/lukewanner/Desktop/LukeGames/projectTiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/main.dir/src/worldMap.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/src/worldMap.cpp.o -MF CMakeFiles/main.dir/src/worldMap.cpp.o.d -o CMakeFiles/main.dir/src/worldMap.cpp.o -c /Users/lukewanner/Desktop/LukeGames/projectTiles/src/worldMap.cpp

CMakeFiles/main.dir/src/worldMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/main.dir/src/worldMap.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lukewanner/Desktop/LukeGames/projectTiles/src/worldMap.cpp > CMakeFiles/main.dir/src/worldMap.cpp.i

CMakeFiles/main.dir/src/worldMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/main.dir/src/worldMap.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lukewanner/Desktop/LukeGames/projectTiles/src/worldMap.cpp -o CMakeFiles/main.dir/src/worldMap.cpp.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/src/GlobalFiles.cpp.o" \
"CMakeFiles/main.dir/src/collisionManager.cpp.o" \
"CMakeFiles/main.dir/src/enemy.cpp.o" \
"CMakeFiles/main.dir/src/entity.cpp.o" \
"CMakeFiles/main.dir/src/inventory.cpp.o" \
"CMakeFiles/main.dir/src/item.cpp.o" \
"CMakeFiles/main.dir/src/main.cpp.o" \
"CMakeFiles/main.dir/src/player.cpp.o" \
"CMakeFiles/main.dir/src/worldMap.cpp.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/src/GlobalFiles.cpp.o
main: CMakeFiles/main.dir/src/collisionManager.cpp.o
main: CMakeFiles/main.dir/src/enemy.cpp.o
main: CMakeFiles/main.dir/src/entity.cpp.o
main: CMakeFiles/main.dir/src/inventory.cpp.o
main: CMakeFiles/main.dir/src/item.cpp.o
main: CMakeFiles/main.dir/src/main.cpp.o
main: CMakeFiles/main.dir/src/player.cpp.o
main: CMakeFiles/main.dir/src/worldMap.cpp.o
main: CMakeFiles/main.dir/build.make
main: /opt/homebrew/lib/libsfml-graphics.2.6.1.dylib
main: /opt/homebrew/lib/libsfml-window.2.6.1.dylib
main: /opt/homebrew/lib/libsfml-system.2.6.1.dylib
main: /Users/lukewanner/Desktop/LukeGames/projectTiles/tmxlite/build/libtmxlite.dylib
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/lukewanner/Desktop/LukeGames/projectTiles/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /Users/lukewanner/Desktop/LukeGames/projectTiles/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lukewanner/Desktop/LukeGames/projectTiles /Users/lukewanner/Desktop/LukeGames/projectTiles /Users/lukewanner/Desktop/LukeGames/projectTiles/build /Users/lukewanner/Desktop/LukeGames/projectTiles/build /Users/lukewanner/Desktop/LukeGames/projectTiles/build/CMakeFiles/main.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/main.dir/depend
