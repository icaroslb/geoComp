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
include leitor_obj\CMakeFiles\leitor_obj.dir\depend.make
# Include any dependencies generated by the compiler for this target.
include leitor_obj\CMakeFiles\leitor_obj.dir\compiler_depend.make

# Include the progress variables for this target.
include leitor_obj\CMakeFiles\leitor_obj.dir\progress.make

# Include the compile flags for this target's objects.
include leitor_obj\CMakeFiles\leitor_obj.dir\flags.make

leitor_obj\CMakeFiles\leitor_obj.dir\leitor_obj.cpp.obj: leitor_obj\CMakeFiles\leitor_obj.dir\flags.make
leitor_obj\CMakeFiles\leitor_obj.dir\leitor_obj.cpp.obj: ..\leitor_obj\leitor_obj.cpp
leitor_obj\CMakeFiles\leitor_obj.dir\leitor_obj.cpp.obj: leitor_obj\CMakeFiles\leitor_obj.dir\compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\icaro\source\repos\geoComp\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object leitor_obj/CMakeFiles/leitor_obj.dir/leitor_obj.cpp.obj"
	cd C:\Users\icaro\source\repos\geoComp\build\leitor_obj
	$(CMAKE_COMMAND) -E cmake_cl_compile_depends --dep-file=CMakeFiles\leitor_obj.dir\leitor_obj.cpp.obj.d --working-dir=C:\Users\icaro\source\repos\geoComp\build\leitor_obj --filter-prefix="Observação: incluindo arquivo: " -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /showIncludes /FoCMakeFiles\leitor_obj.dir\leitor_obj.cpp.obj /FdCMakeFiles\leitor_obj.dir\ /FS -c C:\Users\icaro\source\repos\geoComp\leitor_obj\leitor_obj.cpp
<<
	cd C:\Users\icaro\source\repos\geoComp\build

leitor_obj\CMakeFiles\leitor_obj.dir\leitor_obj.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/leitor_obj.dir/leitor_obj.cpp.i"
	cd C:\Users\icaro\source\repos\geoComp\build\leitor_obj
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe > CMakeFiles\leitor_obj.dir\leitor_obj.cpp.i @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\icaro\source\repos\geoComp\leitor_obj\leitor_obj.cpp
<<
	cd C:\Users\icaro\source\repos\geoComp\build

leitor_obj\CMakeFiles\leitor_obj.dir\leitor_obj.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/leitor_obj.dir/leitor_obj.cpp.s"
	cd C:\Users\icaro\source\repos\geoComp\build\leitor_obj
	C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\cl.exe @<<
 /nologo /TP $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) /FoNUL /FAs /FaCMakeFiles\leitor_obj.dir\leitor_obj.cpp.s /c C:\Users\icaro\source\repos\geoComp\leitor_obj\leitor_obj.cpp
<<
	cd C:\Users\icaro\source\repos\geoComp\build

# Object files for target leitor_obj
leitor_obj_OBJECTS = \
"CMakeFiles\leitor_obj.dir\leitor_obj.cpp.obj"

# External object files for target leitor_obj
leitor_obj_EXTERNAL_OBJECTS =

leitor_obj\leitor_obj.dll: leitor_obj\CMakeFiles\leitor_obj.dir\leitor_obj.cpp.obj
leitor_obj\leitor_obj.dll: leitor_obj\CMakeFiles\leitor_obj.dir\build.make
leitor_obj\leitor_obj.dll: leitor_obj\CMakeFiles\leitor_obj.dir\objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\icaro\source\repos\geoComp\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library leitor_obj.dll"
	cd C:\Users\icaro\source\repos\geoComp\build\leitor_obj
	"C:\Program Files\CMake\bin\cmake.exe" -E vs_link_dll --intdir=CMakeFiles\leitor_obj.dir --rc=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\rc.exe --mt=C:\PROGRA~2\WI3CF2~1\10\bin\100190~1.0\x86\mt.exe --manifests -- C:\PROGRA~2\MICROS~2\2019\COMMUN~1\VC\Tools\MSVC\1428~1.299\bin\Hostx86\x86\link.exe /nologo @CMakeFiles\leitor_obj.dir\objects1.rsp @<<
 /out:leitor_obj.dll /implib:leitor_obj.lib /pdb:C:\Users\icaro\source\repos\geoComp\build\leitor_obj\leitor_obj.pdb /dll /version:0.0 /machine:X86 /debug /INCREMENTAL   -LIBPATH:C:\Users\icaro\source\repos\geoComp\lito_engine\algebra  kernel32.lib user32.lib gdi32.lib winspool.lib shell32.lib ole32.lib oleaut32.lib uuid.lib comdlg32.lib advapi32.lib  
<<
	cd C:\Users\icaro\source\repos\geoComp\build

# Rule to build all files generated by this target.
leitor_obj\CMakeFiles\leitor_obj.dir\build: leitor_obj\leitor_obj.dll
.PHONY : leitor_obj\CMakeFiles\leitor_obj.dir\build

leitor_obj\CMakeFiles\leitor_obj.dir\clean:
	cd C:\Users\icaro\source\repos\geoComp\build\leitor_obj
	$(CMAKE_COMMAND) -P CMakeFiles\leitor_obj.dir\cmake_clean.cmake
	cd C:\Users\icaro\source\repos\geoComp\build
.PHONY : leitor_obj\CMakeFiles\leitor_obj.dir\clean

leitor_obj\CMakeFiles\leitor_obj.dir\depend:
	$(CMAKE_COMMAND) -E cmake_depends "NMake Makefiles" C:\Users\icaro\source\repos\geoComp C:\Users\icaro\source\repos\geoComp\leitor_obj C:\Users\icaro\source\repos\geoComp\build C:\Users\icaro\source\repos\geoComp\build\leitor_obj C:\Users\icaro\source\repos\geoComp\build\leitor_obj\CMakeFiles\leitor_obj.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : leitor_obj\CMakeFiles\leitor_obj.dir\depend

