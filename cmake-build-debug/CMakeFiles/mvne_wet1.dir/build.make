﻿# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

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

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE
NULL=nul
!ENDIF
SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\shayr\Documents\GitHub\mvne_wet1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\shayr\Documents\GitHub\mvne_wet1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles\mvne_wet1.dir\depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles\mvne_wet1.dir\compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles\mvne_wet1.dir\progress.make

# Include the compile flags for this target's objects.
include CMakeFiles\mvne_wet1.dir\flags.make

CMakeFiles\mvne_wet1.dir\main.cpp.obj: CMakeFiles\mvne_wet1.dir\flags.make
CMakeFiles\mvne_wet1.dir\main.cpp.obj: ..\main.cpp
CMakeFiles\mvne_wet1.dir\main.cpp.obj: CMakeFiles\mvne_wet1.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\shayr\Documents\GitHub\mvne_wet1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/mvne_wet1.dir/main.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\mvne_wet1.dir\main.cpp.obj.d --working-dir=C:\Users\shayr\Documents\GitHub\mvne_wet1\cmake-build-debug --filter-prefix="Note: including file: " -- C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\mvne_wet1.dir\main.cpp.obj /FdCMakeFiles\mvne_wet1.dir\ /FS -c C:\Users\shayr\Documents\GitHub\mvne_wet1\main.cpp
<<

CMakeFiles\mvne_wet1.dir\main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mvne_wet1.dir/main.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe > CMakeFiles\mvne_wet1.dir\main.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\shayr\Documents\GitHub\mvne_wet1\main.cpp
<<

CMakeFiles\mvne_wet1.dir\main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mvne_wet1.dir/main.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\mvne_wet1.dir\main.cpp.s /c C:\Users\shayr\Documents\GitHub\mvne_wet1\main.cpp
<<

CMakeFiles\mvne_wet1.dir\Team.cpp.obj: CMakeFiles\mvne_wet1.dir\flags.make
CMakeFiles\mvne_wet1.dir\Team.cpp.obj: ..\Team.cpp
CMakeFiles\mvne_wet1.dir\Team.cpp.obj: CMakeFiles\mvne_wet1.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\shayr\Documents\GitHub\mvne_wet1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/mvne_wet1.dir/Team.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\mvne_wet1.dir\Team.cpp.obj.d --working-dir=C:\Users\shayr\Documents\GitHub\mvne_wet1\cmake-build-debug --filter-prefix="Note: including file: " -- C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\mvne_wet1.dir\Team.cpp.obj /FdCMakeFiles\mvne_wet1.dir\ /FS -c C:\Users\shayr\Documents\GitHub\mvne_wet1\Team.cpp
<<

CMakeFiles\mvne_wet1.dir\Team.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mvne_wet1.dir/Team.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe > CMakeFiles\mvne_wet1.dir\Team.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\shayr\Documents\GitHub\mvne_wet1\Team.cpp
<<

CMakeFiles\mvne_wet1.dir\Team.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mvne_wet1.dir/Team.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\mvne_wet1.dir\Team.cpp.s /c C:\Users\shayr\Documents\GitHub\mvne_wet1\Team.cpp
<<

CMakeFiles\mvne_wet1.dir\worldcup23a1.cpp.obj: CMakeFiles\mvne_wet1.dir\flags.make
CMakeFiles\mvne_wet1.dir\worldcup23a1.cpp.obj: ..\worldcup23a1.cpp
CMakeFiles\mvne_wet1.dir\worldcup23a1.cpp.obj: CMakeFiles\mvne_wet1.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\shayr\Documents\GitHub\mvne_wet1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/mvne_wet1.dir/worldcup23a1.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\mvne_wet1.dir\worldcup23a1.cpp.obj.d --working-dir=C:\Users\shayr\Documents\GitHub\mvne_wet1\cmake-build-debug --filter-prefix="Note: including file: " -- C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\mvne_wet1.dir\worldcup23a1.cpp.obj /FdCMakeFiles\mvne_wet1.dir\ /FS -c C:\Users\shayr\Documents\GitHub\mvne_wet1\worldcup23a1.cpp
<<

CMakeFiles\mvne_wet1.dir\worldcup23a1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mvne_wet1.dir/worldcup23a1.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe > CMakeFiles\mvne_wet1.dir\worldcup23a1.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\shayr\Documents\GitHub\mvne_wet1\worldcup23a1.cpp
<<

CMakeFiles\mvne_wet1.dir\worldcup23a1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mvne_wet1.dir/worldcup23a1.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\mvne_wet1.dir\worldcup23a1.cpp.s /c C:\Users\shayr\Documents\GitHub\mvne_wet1\worldcup23a1.cpp
<<

CMakeFiles\mvne_wet1.dir\Player.cpp.obj: CMakeFiles\mvne_wet1.dir\flags.make
CMakeFiles\mvne_wet1.dir\Player.cpp.obj: ..\Player.cpp
CMakeFiles\mvne_wet1.dir\Player.cpp.obj: CMakeFiles\mvne_wet1.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\shayr\Documents\GitHub\mvne_wet1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/mvne_wet1.dir/Player.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\mvne_wet1.dir\Player.cpp.obj.d --working-dir=C:\Users\shayr\Documents\GitHub\mvne_wet1\cmake-build-debug --filter-prefix="Note: including file: " -- C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\mvne_wet1.dir\Player.cpp.obj /FdCMakeFiles\mvne_wet1.dir\ /FS -c C:\Users\shayr\Documents\GitHub\mvne_wet1\Player.cpp
<<

CMakeFiles\mvne_wet1.dir\Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mvne_wet1.dir/Player.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe > CMakeFiles\mvne_wet1.dir\Player.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\shayr\Documents\GitHub\mvne_wet1\Player.cpp
<<

CMakeFiles\mvne_wet1.dir\Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mvne_wet1.dir/Player.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\mvne_wet1.dir\Player.cpp.s /c C:\Users\shayr\Documents\GitHub\mvne_wet1\Player.cpp
<<

CMakeFiles\mvne_wet1.dir\PlayerId.cpp.obj: CMakeFiles\mvne_wet1.dir\flags.make
CMakeFiles\mvne_wet1.dir\PlayerId.cpp.obj: ..\PlayerId.cpp
CMakeFiles\mvne_wet1.dir\PlayerId.cpp.obj: CMakeFiles\mvne_wet1.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\shayr\Documents\GitHub\mvne_wet1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/mvne_wet1.dir/PlayerId.cpp.obj"
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\mvne_wet1.dir\PlayerId.cpp.obj.d --working-dir=C:\Users\shayr\Documents\GitHub\mvne_wet1\cmake-build-debug --filter-prefix="Note: including file: " -- C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\mvne_wet1.dir\PlayerId.cpp.obj /FdCMakeFiles\mvne_wet1.dir\ /FS -c C:\Users\shayr\Documents\GitHub\mvne_wet1\PlayerId.cpp
<<

CMakeFiles\mvne_wet1.dir\PlayerId.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/mvne_wet1.dir/PlayerId.cpp.i"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe > CMakeFiles\mvne_wet1.dir\PlayerId.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\shayr\Documents\GitHub\mvne_wet1\PlayerId.cpp
<<

CMakeFiles\mvne_wet1.dir\PlayerId.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/mvne_wet1.dir/PlayerId.cpp.s"
	C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\mvne_wet1.dir\PlayerId.cpp.s /c C:\Users\shayr\Documents\GitHub\mvne_wet1\PlayerId.cpp
<<

# Object files for target mvne_wet1
mvne_wet1_OBJECTS = \
"CMakeFiles\mvne_wet1.dir\main.cpp.obj" \
"CMakeFiles\mvne_wet1.dir\Team.cpp.obj" \
"CMakeFiles\mvne_wet1.dir\worldcup23a1.cpp.obj" \
"CMakeFiles\mvne_wet1.dir\Player.cpp.obj" \
"CMakeFiles\mvne_wet1.dir\PlayerId.cpp.obj"

# External object files for target mvne_wet1
mvne_wet1_EXTERNAL_OBJECTS =

mvne_wet1.exe: CMakeFiles\mvne_wet1.dir\main.cpp.obj
mvne_wet1.exe: CMakeFiles\mvne_wet1.dir\Team.cpp.obj
mvne_wet1.exe: CMakeFiles\mvne_wet1.dir\worldcup23a1.cpp.obj
mvne_wet1.exe: CMakeFiles\mvne_wet1.dir\Player.cpp.obj
mvne_wet1.exe: CMakeFiles\mvne_wet1.dir\PlayerId.cpp.obj
mvne_wet1.exe: CMakeFiles\mvne_wet1.dir\build.make
mvne_wet1.exe: CMakeFiles\mvne_wet1.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\shayr\Documents\GitHub\mvne_wet1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable mvne_wet1.exe"
	"C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E vs_link_exe --intdir=CMakeFiles\mvne_wet1.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~3\2019\COMMUN~1\VC\Tools\MSVC\1429~1.300\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\mvne_wet1.dir\objects1.rsp @<<
 /out:mvne_wet1.exe /implib:mvne_wet1.lib /pdb:C:\Users\shayr\Documents\GitHub\mvne_wet1\cmake-build-debug\mvne_wet1.pdb /version:0.0 /machine:X86 /debug /INCREMENTAL /subsystem:console  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib 
<<

# Rule to build all files generated by this target.
CMakeFiles\mvne_wet1.dir\build: mvne_wet1.exe
.PHONY : CMakeFiles\mvne_wet1.dir\build

CMakeFiles\mvne_wet1.dir\clean:
	$(CMAKE_COMMAND) -P CMakeFiles\mvne_wet1.dir\cmake_clean.cmake
.PHONY : CMakeFiles\mvne_wet1.dir\clean

CMakeFiles\mvne_wet1.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\shayr\Documents\GitHub\mvne_wet1 C:\Users\shayr\Documents\GitHub\mvne_wet1 C:\Users\shayr\Documents\GitHub\mvne_wet1\cmake-build-debug C:\Users\shayr\Documents\GitHub\mvne_wet1\cmake-build-debug C:\Users\shayr\Documents\GitHub\mvne_wet1\cmake-build-debug\CMakeFiles\mvne_wet1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles\mvne_wet1.dir\depend

