; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CWarpTextDemoDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "warptextdemo.h"
LastPage=0

ClassCount=4
Class1=CWarpText
Class2=CWarpTextDemoApp
Class3=CAboutDlg
Class4=CWarpTextDemoDlg

ResourceCount=2
Resource1=IDD_ABOUTBOX
Resource2=IDD_WARPTEXTDEMO_DIALOG

[CLS:CWarpText]
Type=0
BaseClass=CStatic
HeaderFile=WarpText.h
ImplementationFile=WarpText.cpp
Filter=W
VirtualFilter=WC
LastObject=CWarpText

[CLS:CWarpTextDemoApp]
Type=0
BaseClass=CWinApp
HeaderFile=WarpTextDemo.h
ImplementationFile=WarpTextDemo.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=WarpTextDemoDlg.cpp
ImplementationFile=WarpTextDemoDlg.cpp
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_WARPTEXTDEMO_DIALOG]
Type=1
Class=CWarpTextDemoDlg
ControlCount=6
Control1=IDC_STATIC,static,1342308864
Control2=IDC_TEXT_EDIT,edit,1350631552
Control3=IDC_REFRESH_BUTTON,button,1342242816
Control4=IDC_SHOW_GUIDE_CHECK,button,1342242819
Control5=IDC_WARP_STATIC,static,1342177287
Control6=IDOK,button,1342242817

[CLS:CWarpTextDemoDlg]
Type=0
HeaderFile=warptextdemodlg.h
ImplementationFile=warptextdemodlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_SHOW_GUIDE_CHECK

