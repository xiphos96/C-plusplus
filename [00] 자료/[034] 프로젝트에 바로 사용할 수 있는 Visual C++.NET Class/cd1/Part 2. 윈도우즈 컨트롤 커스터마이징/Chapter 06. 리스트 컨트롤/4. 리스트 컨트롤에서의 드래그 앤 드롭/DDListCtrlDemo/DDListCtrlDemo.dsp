# Microsoft Developer Studio Project File - Name="DDListCtrlDemo" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=DDListCtrlDemo - Win32 Debug60
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "DDListCtrlDemo.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "DDListCtrlDemo.mak" CFG="DDListCtrlDemo - Win32 Debug60"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "DDListCtrlDemo - Win32 Debug60" (based on "Win32 (x86) Application")
!MESSAGE "DDListCtrlDemo - Win32 Release60" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "DDListCtrlDemo - Win32 Debug60"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug60"
# PROP BASE Intermediate_Dir "Debug60"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug60"
# PROP Intermediate_Dir "Debug60"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_WINDOWS" /D "_DEBUG" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_WINDOWS" /D "_DEBUG" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
# ADD BASE RSC /l 0x409 /i "$(IntDir)" /d "_DEBUG"
# ADD RSC /l 0x409 /i "$(IntDir)" /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:IX86 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:IX86 /pdbtype:sept

!ELSEIF  "$(CFG)" == "DDListCtrlDemo - Win32 Release60"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release60"
# PROP BASE Intermediate_Dir "Release60"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release60"
# PROP Intermediate_Dir "Release60"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /Zi /O2 /D "WIN32" /D "_WINDOWS" /D "NDEBUG" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /GF /c
# ADD CPP /nologo /MD /W3 /GX /Zi /O2 /D "WIN32" /D "_WINDOWS" /D "NDEBUG" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /GF /c
# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
# ADD BASE RSC /l 0x409 /i "$(IntDir)" /d "NDEBUG"
# ADD RSC /l 0x409 /i "$(IntDir)" /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:IX86 /pdbtype:sept /opt:ref /opt:icf
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:IX86 /pdbtype:sept /opt:ref /opt:icf

!ENDIF 

# Begin Target

# Name "DDListCtrlDemo - Win32 Debug60"
# Name "DDListCtrlDemo - Win32 Release60"
# Begin Group "소스 "

# PROP Default_Filter "cpp;c;cxx;def;odl;idl;hpj;bat;asm"
# Begin Source File

SOURCE=.\DDListCtrl.cpp
DEP_CPP_DDLIS=\
	".\DDListCtrl.h"\
	".\DDListCtrlDemo.h"\
	".\stdafx.h"\
	
# End Source File
# Begin Source File

SOURCE=DDListCtrlDemo.cpp
DEP_CPP_DDLIST=\
	".\DDListCtrl.h"\
	".\DDListCtrlDemo.h"\
	".\DDListCtrlDemoDlg.h"\
	".\stdafx.h"\
	
# End Source File
# Begin Source File

SOURCE=DDListCtrlDemoDlg.cpp
DEP_CPP_DDLISTC=\
	".\DDListCtrl.h"\
	".\DDListCtrlDemo.h"\
	".\DDListCtrlDemoDlg.h"\
	".\stdafx.h"\
	
# End Source File
# Begin Source File

SOURCE=stdafx.cpp
DEP_CPP_STDAF=\
	".\stdafx.h"\
	

!IF  "$(CFG)" == "DDListCtrlDemo - Win32 Debug60"

# ADD CPP /nologo /GX /Yc"stdafx.h" /GZ

!ELSEIF  "$(CFG)" == "DDListCtrlDemo - Win32 Release60"

# ADD CPP /nologo /GX /Yc"stdafx.h"

!ENDIF 

# End Source File
# End Group
# Begin Group "헤더 "

# PROP Default_Filter "h;hpp;hxx;hm;inl;inc"
# Begin Source File

SOURCE=.\DDListCtrl.h
# End Source File
# Begin Source File

SOURCE=DDListCtrlDemo.h
# End Source File
# Begin Source File

SOURCE=DDListCtrlDemoDlg.h
# End Source File
# Begin Source File

SOURCE=Resource.h
# End Source File
# Begin Source File

SOURCE=stdafx.h
# End Source File
# End Group
# Begin Group "리소스"

# PROP Default_Filter "rc;ico;cur;bmp;dlg;rc2;rct;bin;rgs;jpg;jpeg;jpe;manifest"
# Begin Source File

SOURCE=res\DDListCtrlDemo.ico
# End Source File
# Begin Source File

SOURCE=res\DDListCtrlDemo.manifest
# End Source File
# Begin Source File

SOURCE=DDListCtrlDemo.rc
# End Source File
# Begin Source File

SOURCE=res\DDListCtrlDemo.rc2
# End Source File
# Begin Source File

SOURCE=.\res\list_big.bmp
# End Source File
# Begin Source File

SOURCE=.\res\list_small.bmp
# End Source File
# End Group
# Begin Source File

SOURCE=ReadMe.txt
# End Source File
# End Target
# End Project
