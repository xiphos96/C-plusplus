# Microsoft Developer Studio Project File - Name="HA Status LIB" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=HA Status LIB - Win32 Static Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE run the tool that generated this project file and specify the
!MESSAGE nmake output type.  You can then use the following command:
!MESSAGE
!MESSAGE NMAKE /f "HA_Status_Static.mak".
!MESSAGE
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE
!MESSAGE NMAKE /f "HA_Status_Static.mak" CFG="HA Status LIB - Win32 Static Debug"
!MESSAGE
!MESSAGE Possible choices for configuration are:
!MESSAGE
!MESSAGE "HA Status LIB - Win32 Static Release" (based on "Win32 (x86) Static Library")
!MESSAGE "HA Status LIB - Win32 Static Debug" (based on "Win32 (x86) Static Library")
!MESSAGE

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "HA Status LIB - Win32 Static Release"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Static_Release"
# PROP Intermediate_Dir "Static_Release"
# PROP Target_Dir ""
LINK32=link.exe -lib
# ADD CPP /nologo /G5 /W3 /GX /O2 /MD /Zi /GR /I "..\..\.." /D NDEBUG=1 /D WIN32=1 /D _WINDOWS=1 /D ACE_AS_STATIC_LIBS=1 /FD /c
# SUBTRACT CPP /YX
# ADD RSC /l 0x409 /d NDEBUG=1 /i "..\..\.."
BSC32=bscmake.exe
# ADD BSC32 /nologo /o".\HA_Status.bsc"
LIB32=link.exe -lib
# ADD LIB32 /nologo /out:".\HA_Statuss.lib"

!ELSEIF  "$(CFG)" == "HA Status LIB - Win32 Static Debug"

# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Static_Debug"
# PROP Intermediate_Dir "Static_Debug"
# PROP Target_Dir ""
LINK32=link.exe -lib
# ADD CPP /nologo /G5 /W3 /Gm /GX /Zi /Od /GR /Gy /MDd /I "..\..\.." /D _DEBUG=1 /D WIN32=1 /D _WINDOWS=1 /D ACE_AS_STATIC_LIBS=1 /FD /c
# SUBTRACT CPP /Fr /YX
# ADD RSC /l 0x409 /d _DEBUG=1 /i "..\..\.."
BSC32=bscmake.exe
# ADD BSC32 /nologo /o".\HA_Status.bsc"
LIB32=link.exe -lib
# ADD LIB32 /nologo /out:".\HA_Statussd.lib"

!ENDIF

# Begin Target

# Name "HA Status LIB - Win32 Static Release"
# Name "HA Status LIB - Win32 Static Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;cxx;c"
# Begin Source File

SOURCE=.\HA_Status_Dynamic.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hh"
# Begin Source File

SOURCE=.\HA_Status_Dynamic.h
# End Source File
# End Group
# End Target
# End Project
