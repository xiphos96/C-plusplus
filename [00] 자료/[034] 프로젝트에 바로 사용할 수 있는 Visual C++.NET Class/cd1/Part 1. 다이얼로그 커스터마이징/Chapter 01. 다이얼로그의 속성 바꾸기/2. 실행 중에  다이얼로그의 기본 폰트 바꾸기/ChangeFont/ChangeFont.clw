; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CChangeFontDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "changefont.h"
LastPage=0

ClassCount=5
Class1=CChangeFontApp
Class2=CAboutDlg
Class3=CChangeFontDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Class4=CDefFontDialog
Resource2=IDD_CHANGEFONT_DIALOG
Class5=CNewDlg
Resource3=IDD_NEW_DIALOG

[CLS:CChangeFontApp]
Type=0
BaseClass=CWinApp
HeaderFile=ChangeFont.h
ImplementationFile=ChangeFont.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=ChangeFontDlg.cpp
ImplementationFile=ChangeFontDlg.cpp
LastObject=CAboutDlg

[CLS:CChangeFontDlg]
Type=0
BaseClass=CDialog
HeaderFile=ChangeFontDlg.h
ImplementationFile=ChangeFontDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=IDC_DOMODAL_BUTTON

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CHANGEFONT_DIALOG]
Type=1
Class=CChangeFontDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDC_FONT_BUTTON,button,1342242816
Control3=IDC_DOMODAL_BUTTON,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352

[CLS:CDefFontDialog]
Type=0
HeaderFile=DefFontDialog.h
ImplementationFile=DefFontDialog.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDefFontDialog

[DLG:IDD_NEW_DIALOG]
Type=1
Class=CNewDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308865

[CLS:CNewDlg]
Type=0
HeaderFile=NewDlg.h
ImplementationFile=NewDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CNewDlg

