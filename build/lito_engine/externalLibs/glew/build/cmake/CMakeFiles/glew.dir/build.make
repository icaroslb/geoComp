# CMAKE generated file: DO NOT EDIT!
# Generated by "NMake Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\icaro\source\repos\geoComp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\icaro\source\repos\geoComp\build

# Include any dependencies generated for this target.
include lito_engine\externalLibs\glew\build\cmake\CMakeFiles\glew.dir\depend.make
# Include any dependencies generated by the compiler for this target.
include lito_engine\externalLibs\glew\build\cmake\CMakeFiles\glew.dir\compiler_depend.make

# Include the progress variables for this target.
include lito_engine\externalLibs\glew\build\cmake\CMakeFiles\glew.dir\progress.make

# Include the compile flags for this target's objects.
include lito_engine\externalLibs\glew\build\cmake\CMakeFiles\glew.dir\flags.make

lito_engine\externalLibs\glew\build\cmake\CMakeFiles\glew.dir\__\__\src\glew.c.obj: lito_engine\externalLibs\glew\build\cmake\CMakeFiles\glew.dir\flags.make
lito_engine\externalLibs\glew\build\cmake\CMakeFiles\glew.dir\__\__\src\glew.c.obj: ..\lito_engine\externalLibs\glew\src\glew.c
lito_engine\externalLibs\glew\build\cmake\CMakeFiles\glew.dir\__\__\src\glew.c.obj: lito_engine\externalLibs\glew\build\cmake\CMakeFiles\glew.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\icaro\source\repos\geoComp\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object lito_engine/externalLibs/glew/build/cmake/CMakeFiles/glew.dir/__/__/src/glew.c.obj"
	cd C:\Users\icaro\source\repos\geoComp\build\lito_engine\externalLibs\glew\build\cmake
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\glew.dir\__\__\src\glew.c.obj.d --working-dir=C:\Users\icaro\source\repos\geoComp\build\lito_engine\externalLibs\glew\build\cmake --filter-prefix="Observação: incluindo arquivo: " -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /showIncludes /FoCMakeFiles\glew.dir\__\__\src\glew.c.obj /FdCMakeFiles\glew.dir\ /FS -c C:\Users\icaro\source\repos\geoComp\lito_engine\externalLibs\glew\src\glew.c
<<
	cd C:\Users\icaro\source\repos\geoComp\build

lito_engine\externalLibs\glew\build\cmake\CMakeFiles\glew.dir\__\__\src\glew.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/glew.dir/__/__/src/glew.c.i"
	cd C:\Users\icaro\source\repos\geoComp\build\lito_engine\externalLibs\glew\build\cmake
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\glew.dir\__\__\src\glew.c.i @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\icaro\source\repos\geoComp\lito_engine\externalLibs\glew\src\glew.c
<<
	cd C:\Users\icaro\source\repos\geoComp\build

lito_engine\externalLibs\glew\build\cmake\CMakeFiles\glew.dir\__\__\src\glew.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/glew.dir/__/__/src/glew.c.s"
	cd C:\Users\icaro\source\repos\geoComp\build\lito_engine\externalLibs\glew\build\cmake
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) /FoNUL /FAs /FaCMakeFiles\glew.dir\__\__\src\glew.c.s /c C:\Users\icaro\source\repos\geoComp\lito_engine\externalLibs\glew\src\glew.c
<<
	cd C:\Users\icaro\source\repos\geoComp\build

lito_engine\externalLibs\glew\build\cmake\CMakeFiles\glew.dir\__\glew.rc.res: lito_engine\externalLibs\glew\build\cmake\CMakeFiles\glew.dir\flags.make
lito_engine\externalLibs\glew\build\cmake\CMakeFiles\glew.dir\__\glew.rc.res: ..\lito_engine\externalLibs\glew\build\glew.rc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\icaro\source\repos\geoComp\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building RC object lito_engine/externalLibs/glew/build/cmake/CMakeFiles/glew.dir/__/glew.rc.res"
	cd C:\Users\icaro\source\repos\geoComp\build\lito_engine\externalLibs\glew\build\cmake
	C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe $(RC_DEFINES) $(RC_INCLUDES) $(RC_FLAGS) /fo CMakeFiles\glew.dir\__\glew.rc.res C:\Users\icaro\source\repos\geoComp\lito_engine\externalLibs\glew\build\glew.rc
	cd C:\Users\icaro\source\repos\geoComp\build

# Object files for target glew
glew_OBJECTS = \
"CMakeFiles\glew.dir\__\__\src\glew.c.obj" \
"CMakeFiles\glew.dir\__\glew.rc.res"

# External object files for target glew
glew_EXTERNAL_OBJECTS =

bin\glew32d.dll: lito_engine\externalLibs\glew\build\cmake\CMakeFiles\glew.dir\__\__\src\glew.c.obj
bin\glew32d.dll: lito_engine\externalLibs\glew\build\cmake\CMakeFiles\glew.dir\__\glew.rc.res
bin\glew32d.dll: lito_engine\externalLibs\glew\build\cmake\CMakeFiles\glew.dir\build.make
bin\glew32d.dll: lito_engine\externalLibs\glew\build\cmake\CMakeFiles\glew.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\icaro\source\repos\geoComp\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C shared library ..\..\..\..\..\bin\glew32d.dll"
	cd C:\Users\icaro\source\repos\geoComp\build\lito_engine\externalLibs\glew\build\cmake
	"C:\Program Files\CMake\bin\cmake.exe" -E vs_link_dll --intdir=CMakeFiles\glew.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\glew.dir\objects1.rsp @<<
 /out:..\..\..\..\..\bin\glew32d.dll /implib:..\..\..\..\..\lib\glew32d.lib /pdb:C:\Users\icaro\source\repos\geoComp\build\bin\glew32d.pdb /dll /version:2.1 /machine:X86 /debug /INCREMENTAL  -BASE:0x62AA0000 -nodefaultlib -noentry opengl32.lib glu32.lib kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib  
<<
	cd C:\Users\icaro\source\repos\geoComp\build

# Rule to build all files generated by this target.
lito_engine\externalLibs\glew\build\cmake\CMakeFiles\glew.dir\build: bin\glew32d.dll
.PHONY : lito_engine\externalLibs\glew\build\cmake\CMakeFiles\glew.dir\build

lito_engine\externalLibs\glew\build\cmake\CMakeFiles\glew.dir\clean:
	cd C:\Users\icaro\source\repos\geoComp\build\lito_engine\externalLibs\glew\build\cmake
	$(CMAKE_COMMAND) -P CMakeFiles\glew.dir\cmake_clean.cmake
	cd C:\Users\icaro\source\repos\geoComp\build
.PHONY : lito_engine\externalLibs\glew\build\cmake\CMakeFiles\glew.dir\clean

lito_engine\externalLibs\glew\build\cmake\CMakeFiles\glew.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\icaro\source\repos\geoComp C:\Users\icaro\source\repos\geoComp\lito_engine\externalLibs\glew\build\cmake C:\Users\icaro\source\repos\geoComp\build C:\Users\icaro\source\repos\geoComp\build\lito_engine\externalLibs\glew\build\cmake C:\Users\icaro\source\repos\geoComp\build\lito_engine\externalLibs\glew\build\cmake\CMakeFiles\glew.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : lito_engine\externalLibs\glew\build\cmake\CMakeFiles\glew.dir\depend

