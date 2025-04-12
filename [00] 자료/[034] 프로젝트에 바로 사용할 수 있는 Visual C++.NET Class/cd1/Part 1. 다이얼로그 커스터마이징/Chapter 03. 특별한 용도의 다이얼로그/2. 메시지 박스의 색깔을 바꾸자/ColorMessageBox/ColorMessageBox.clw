; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CColorMessageBoxDlg
LastTemplate=CStatic
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "colormessagebox.h"
LastPage=0

ClassCount=4
Class1=CColorMessageBoxApp
Class2=CAboutDlg
Class3=CColorMessageBoxDlg

ResourceCount=2
Resource1=IDD_ABOUTBOX
Class4=CColorStatic
Resource2=IDD_COLORMESSAGEBOX_DIALOG

[CLS:CColorMessageBoxApp]
Type=0
BaseClass=CWinApp
HeaderFile=ColorMessageBox.h
ImplementationFile=ColorMessageBox.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=ColorMessageBoxDlg.cpp
ImplementationFile=ColorMessageBoxDlg.cpp

[CLS:CColorMessageBoxDlg]
Type=0
BaseClass=CDialog
HeaderFile=ColorMessageBoxDlg.h
ImplementationFile=ColorMessageBoxDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=CColorMessageBoxDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_COLORMESSAGEBOX_DIALOG]
Type=1
Class=CColorMessageBoxDlg
ControlCount=12
Control1=IDC_STATIC,static,1342308864
Control2=IDC_COLOR_TEXT_STATIC,static,1342181639
Control3=IDC_STATIC,static,1342308864
Control4=IDC_COLOR_BKGND_STATIC,static,1342181639
Control5=IDC_STATIC,static,1342308864
Control6=IDC_USE_RADIO,button,1342308361
Control7=IDC_UNUSE_RADIO,button,1342177289
Control8=IDC_STATIC,static,1342177296
Control9=IDC_MESSAGEBOX_BUTTON,button,1342242816
Control10=IDC_AFXMESSAGEBOX_BUTTON,button,1342242816
Control11=IDOK,button,1342242817
Control12=IDC_STATIC,static,1342308865

[CLS:CColorStatic]
Type=0
HeaderFile=ColorStatic.h
ImplementationFile=ColorStatic.cpp
BaseClass=CStatic
Filter=W
VirtualFilter=WC
LastObject=CColorStatic

