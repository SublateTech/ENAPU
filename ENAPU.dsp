# Microsoft Developer Studio Project File - Name="ENAPU" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=ENAPU - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ENAPU.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ENAPU.mak" CFG="ENAPU - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ENAPU - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "ENAPU - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ENAPU - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 2
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /Ox /D "WIN32" /D "_CONSOLE" /D "_MBCS" /D "NDEBUG" /D "_AFXDLL" /YX /FD
# ADD BASE RSC /l 0xc0a /d "NDEBUG"
# ADD RSC /l 0xc0a /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib ntwdblib.lib /nologo /subsystem:console /machine:I386
# SUBTRACT LINK32 /incremental:yes

!ELSEIF  "$(CFG)" == "ENAPU - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 1
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /Zi /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MTd /W3 /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0xc0a /d "_DEBUG"
# ADD RSC /l 0xc0a /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 ntwdblib.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "ENAPU - Win32 Release"
# Name "ENAPU - Win32 Debug"
# Begin Source File

SOURCE=.\ALMACENA.CPP
# End Source File
# Begin Source File

SOURCE=.\ALMACENA.H
# End Source File
# Begin Source File

SOURCE=.\Carga.cpp
# End Source File
# Begin Source File

SOURCE=.\Carga.h
# End Source File
# Begin Source File

SOURCE=.\CHOFER.CPP
# End Source File
# Begin Source File

SOURCE=.\CHOFER.H
# End Source File
# Begin Source File

SOURCE=.\Condicion_Contenedores.CPP
# End Source File
# Begin Source File

SOURCE=.\Condicion_contenedores.H
# End Source File
# Begin Source File

SOURCE=.\Console.cpp
# End Source File
# Begin Source File

SOURCE=.\Console.h
# End Source File
# Begin Source File

SOURCE=.\DESCARGA.CPP
# End Source File
# Begin Source File

SOURCE=.\DESCARGA.H
# End Source File
# Begin Source File

SOURCE=.\EMBARQUE.CPP
# End Source File
# Begin Source File

SOURCE=.\EMBARQUE.H
# End Source File
# Begin Source File

SOURCE=.\ENAPU.cpp
# End Source File
# Begin Source File

SOURCE=.\Equipos_Accesorios.CPP
# End Source File
# Begin Source File

SOURCE=.\Equipos_Accesorios.H
# End Source File
# Begin Source File

SOURCE=.\Estado_Contenedores.CPP
# End Source File
# Begin Source File

SOURCE=.\Estado_contenedores.H
# End Source File
# Begin Source File

SOURCE=.\Keyboard.cpp
# End Source File
# Begin Source File

SOURCE=.\Keyboard.h
# End Source File
# Begin Source File

SOURCE=.\MENSAJES.CPP
# End Source File
# Begin Source File

SOURCE=.\MENSAJES.H
# End Source File
# Begin Source File

SOURCE=.\Menu.cpp
# End Source File
# Begin Source File

SOURCE=.\Menu.h
# End Source File
# Begin Source File

SOURCE=.\Muelles_Amarradores.CPP
# End Source File
# Begin Source File

SOURCE=.\Muelles_Amarradores.H
# End Source File
# Begin Source File

SOURCE=.\PLACAS.CPP
# End Source File
# Begin Source File

SOURCE=.\PLACAS.H
# End Source File
# Begin Source File

SOURCE=.\Portuario.cpp
# End Source File
# Begin Source File

SOURCE=.\Portuario.h
# End Source File
# Begin Source File

SOURCE=.\RODANTE.CPP
# End Source File
# Begin Source File

SOURCE=.\RODANTE.H
# End Source File
# Begin Source File

SOURCE=.\Scroller.cpp
# End Source File
# Begin Source File

SOURCE=.\Scroller.h
# End Source File
# Begin Source File

SOURCE=.\ScrollerH.h
# End Source File
# Begin Source File

SOURCE=.\scrollerV.cpp
# End Source File
# Begin Source File

SOURCE=.\ScrollerV.h
# End Source File
# Begin Source File

SOURCE=.\scrollh.cpp
# End Source File
# Begin Source File

SOURCE=.\SqlServer.cpp
# End Source File
# Begin Source File

SOURCE=.\SqlServer.h
# End Source File
# Begin Source File

SOURCE=.\STR.CPP
# End Source File
# Begin Source File

SOURCE=.\STR.H
# End Source File
# Begin Source File

SOURCE=.\Stristr.cpp
# End Source File
# Begin Source File

SOURCE=".\Tipo Contenedores.CPP"
# End Source File
# Begin Source File

SOURCE=.\Tipo_Contenedores.H
# End Source File
# Begin Source File

SOURCE=.\Vanes.cpp
# End Source File
# Begin Source File

SOURCE=.\Vanes.h
# End Source File
# Begin Source File

SOURCE=.\Window.cpp
# End Source File
# Begin Source File

SOURCE=.\Window.h
# End Source File
# End Target
# End Project
