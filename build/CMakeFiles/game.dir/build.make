# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/locc/git/makoh

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/locc/git/makoh/build

# Include any dependencies generated for this target.
include CMakeFiles/game.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/game.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/game.dir/flags.make

CMakeFiles/game.dir/codegen:
.PHONY : CMakeFiles/game.dir/codegen

CMakeFiles/game.dir/src/core/game_controller.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/core/game_controller.cpp.o: /Users/locc/git/makoh/src/core/game_controller.cpp
CMakeFiles/game.dir/src/core/game_controller.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/locc/git/makoh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/game.dir/src/core/game_controller.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/src/core/game_controller.cpp.o -MF CMakeFiles/game.dir/src/core/game_controller.cpp.o.d -o CMakeFiles/game.dir/src/core/game_controller.cpp.o -c /Users/locc/git/makoh/src/core/game_controller.cpp

CMakeFiles/game.dir/src/core/game_controller.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/src/core/game_controller.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/locc/git/makoh/src/core/game_controller.cpp > CMakeFiles/game.dir/src/core/game_controller.cpp.i

CMakeFiles/game.dir/src/core/game_controller.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/core/game_controller.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/locc/git/makoh/src/core/game_controller.cpp -o CMakeFiles/game.dir/src/core/game_controller.cpp.s

CMakeFiles/game.dir/src/main.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/main.cpp.o: /Users/locc/git/makoh/src/main.cpp
CMakeFiles/game.dir/src/main.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/locc/git/makoh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/game.dir/src/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/src/main.cpp.o -MF CMakeFiles/game.dir/src/main.cpp.o.d -o CMakeFiles/game.dir/src/main.cpp.o -c /Users/locc/git/makoh/src/main.cpp

CMakeFiles/game.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/src/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/locc/git/makoh/src/main.cpp > CMakeFiles/game.dir/src/main.cpp.i

CMakeFiles/game.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/locc/git/makoh/src/main.cpp -o CMakeFiles/game.dir/src/main.cpp.s

CMakeFiles/game.dir/src/ui/button.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/ui/button.cpp.o: /Users/locc/git/makoh/src/ui/button.cpp
CMakeFiles/game.dir/src/ui/button.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/locc/git/makoh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/game.dir/src/ui/button.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/src/ui/button.cpp.o -MF CMakeFiles/game.dir/src/ui/button.cpp.o.d -o CMakeFiles/game.dir/src/ui/button.cpp.o -c /Users/locc/git/makoh/src/ui/button.cpp

CMakeFiles/game.dir/src/ui/button.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/src/ui/button.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/locc/git/makoh/src/ui/button.cpp > CMakeFiles/game.dir/src/ui/button.cpp.i

CMakeFiles/game.dir/src/ui/button.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/ui/button.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/locc/git/makoh/src/ui/button.cpp -o CMakeFiles/game.dir/src/ui/button.cpp.s

CMakeFiles/game.dir/src/ui/fonts.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/ui/fonts.cpp.o: /Users/locc/git/makoh/src/ui/fonts.cpp
CMakeFiles/game.dir/src/ui/fonts.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/locc/git/makoh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/game.dir/src/ui/fonts.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/src/ui/fonts.cpp.o -MF CMakeFiles/game.dir/src/ui/fonts.cpp.o.d -o CMakeFiles/game.dir/src/ui/fonts.cpp.o -c /Users/locc/git/makoh/src/ui/fonts.cpp

CMakeFiles/game.dir/src/ui/fonts.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/src/ui/fonts.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/locc/git/makoh/src/ui/fonts.cpp > CMakeFiles/game.dir/src/ui/fonts.cpp.i

CMakeFiles/game.dir/src/ui/fonts.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/ui/fonts.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/locc/git/makoh/src/ui/fonts.cpp -o CMakeFiles/game.dir/src/ui/fonts.cpp.s

CMakeFiles/game.dir/src/ui/textures.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/ui/textures.cpp.o: /Users/locc/git/makoh/src/ui/textures.cpp
CMakeFiles/game.dir/src/ui/textures.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/locc/git/makoh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/game.dir/src/ui/textures.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/src/ui/textures.cpp.o -MF CMakeFiles/game.dir/src/ui/textures.cpp.o.d -o CMakeFiles/game.dir/src/ui/textures.cpp.o -c /Users/locc/git/makoh/src/ui/textures.cpp

CMakeFiles/game.dir/src/ui/textures.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/src/ui/textures.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/locc/git/makoh/src/ui/textures.cpp > CMakeFiles/game.dir/src/ui/textures.cpp.i

CMakeFiles/game.dir/src/ui/textures.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/ui/textures.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/locc/git/makoh/src/ui/textures.cpp -o CMakeFiles/game.dir/src/ui/textures.cpp.s

CMakeFiles/game.dir/src/ui/tile.cpp.o: CMakeFiles/game.dir/flags.make
CMakeFiles/game.dir/src/ui/tile.cpp.o: /Users/locc/git/makoh/src/ui/tile.cpp
CMakeFiles/game.dir/src/ui/tile.cpp.o: CMakeFiles/game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/locc/git/makoh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/game.dir/src/ui/tile.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/game.dir/src/ui/tile.cpp.o -MF CMakeFiles/game.dir/src/ui/tile.cpp.o.d -o CMakeFiles/game.dir/src/ui/tile.cpp.o -c /Users/locc/git/makoh/src/ui/tile.cpp

CMakeFiles/game.dir/src/ui/tile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/game.dir/src/ui/tile.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/locc/git/makoh/src/ui/tile.cpp > CMakeFiles/game.dir/src/ui/tile.cpp.i

CMakeFiles/game.dir/src/ui/tile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/game.dir/src/ui/tile.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/locc/git/makoh/src/ui/tile.cpp -o CMakeFiles/game.dir/src/ui/tile.cpp.s

# Object files for target game
game_OBJECTS = \
"CMakeFiles/game.dir/src/core/game_controller.cpp.o" \
"CMakeFiles/game.dir/src/main.cpp.o" \
"CMakeFiles/game.dir/src/ui/button.cpp.o" \
"CMakeFiles/game.dir/src/ui/fonts.cpp.o" \
"CMakeFiles/game.dir/src/ui/textures.cpp.o" \
"CMakeFiles/game.dir/src/ui/tile.cpp.o"

# External object files for target game
game_EXTERNAL_OBJECTS =

game: CMakeFiles/game.dir/src/core/game_controller.cpp.o
game: CMakeFiles/game.dir/src/main.cpp.o
game: CMakeFiles/game.dir/src/ui/button.cpp.o
game: CMakeFiles/game.dir/src/ui/fonts.cpp.o
game: CMakeFiles/game.dir/src/ui/textures.cpp.o
game: CMakeFiles/game.dir/src/ui/tile.cpp.o
game: CMakeFiles/game.dir/build.make
game: /opt/homebrew/lib/libsfml-graphics.3.0.0.dylib
game: /opt/homebrew/lib/libsfml-window.3.0.0.dylib
game: /opt/homebrew/lib/libsfml-system.3.0.0.dylib
game: CMakeFiles/game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/locc/git/makoh/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/game.dir/build: game
.PHONY : CMakeFiles/game.dir/build

CMakeFiles/game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/game.dir/clean

CMakeFiles/game.dir/depend:
	cd /Users/locc/git/makoh/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/locc/git/makoh /Users/locc/git/makoh /Users/locc/git/makoh/build /Users/locc/git/makoh/build /Users/locc/git/makoh/build/CMakeFiles/game.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/game.dir/depend

