# Microsoft Developer Studio Project File - Name="Use Syslog Static EXE" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=Use Syslog Static EXE - Win32 Static Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE run the tool that generated this project file and specify the
!MESSAGE nmake output type.  You can then use the following command:
!MESSAGE
!MESSAGE NMAKE /f "Use_Syslog_Static.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "Use_Syslog_Static.mak" CFG="Use Syslog Static EXE - Win32 Static Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "Use Syslog Static EXE - Win32 Static Release" (based on "Win32 (x86) Console Application")
!MESSAGE "Use Syslog Static EXE - Win32 Static Debug" (based on "Win32 (x86) Console Application")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Use Syslog Static EXE - Win32 Static Release"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Static_Release"
# PROP Intermediate_Dir "Static_Release"
# PROP Target_Dir ""
# ADD CPP /nologo /W3 /GX /O2 /MD /GR /I "..\..\.." /D NDEBUG=1 /D WIN32=1 /D _CONSOLE=1 /D ACE_AS_STATIC_LIBS=1 /FD /c
# SUBTRACT CPP /YX
# ADD RSC /l 0x409 /d NDEBUG=1 /i "..\..\.."
BSC32=bscmake.exe
# ADD BSC32 /nologo 
LINK32=link.exe
# ADD LINK32 advapi32.lib user32.lib /INCREMENTAL:NO ACEs.lib /libpath:"..\..\..\ace" /nologo /version:5.3 /subsystem:console  /machine:I386 /out:"Use_Syslog.exe"

!ELSEIF  "$(CFG)" == "Use Syslog Static EXE - Win32 Static Debug"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Static_Debug"
# PROP Intermediate_Dir "Static_Debug"
# PROP Target_Dir ""
# ADD CPP /nologo /W3 /Gm /GX /Zi /Od /MDd /GR /Gy /I "..\..\.." /D _DEBUG=1 /D WIN32=1 /D _CONSOLE=1 /D ACE_AS_STATIC_LIBS=1 /FD /c
# SUBTRACT CPP /YX
# ADD RSC /l 0x409 /d _DEBUG=1 /i "..\..\.."
BSC32=bscmake.exe
# ADD BSC32 /nologo 
LINK32=link.exe
# ADD LINK32 advapi32.lib user32.lib /INCREMENTAL:NO ACEsd.lib /libpath:"..\..\..\ace" /nologo /version:5.3 /subsystem:console /debug /machine:I386 /out:"Use_Syslog.exe"

!ENDIF

# Begin Target

# Name "Use Syslog Static EXE - Win32 Static Release"
# Name "Use Syslog Static EXE - Win32 Static Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;cxx;c"
# Begin Source File

SOURCE=.\Use_Syslog.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hh"
# Begin Source File

SOURCE=.\Callback-2.h
# End Source File
# Begin Source File

SOURCE=.\Callback-3.h
# End Source File
# Begin Source File

SOURCE=.\Callback.h
# End Source File
# Begin Source File

SOURCE=.\Log_Msg_Alt.h
# End Source File
# Begin Source File

SOURCE=.\LogManager.h
# End Source File
# Begin Source File

SOURCE=.\Trace.h
# End Source File
# End Group
# End Target
# End Project
