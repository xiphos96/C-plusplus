; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSpeedBmpButton
LastTemplate=CButton
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "bmpbuttondemo.h"
LastPage=0

ClassCount=4
Class1=CBmpButtonDemoApp
Class2=CAboutDlg
Class3=CBmpButtonDemoDlg

ResourceCount=2
Resource1=IDD_ABOUTBOX
Class4=CSpeedBmpButton
Resource2=IDD_BMPBUTTONDEMO_DIALOG

[CLS:CBmpButtonDemoApp]
Type=0
BaseClass=CWinApp
HeaderFile=BmpButtonDemo.h
ImplementationFile=BmpButtonDemo.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=BmpButtonDemoDlg.cpp
ImplementationFile=BmpButtonDemoDlg.cpp

[CLS:CBmpButtonDemoDlg]
Type=0
BaseClass=CDialog
HeaderFile=BmpButtonDemoDlg.h
ImplementationFile=BmpButtonDemoDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=CBmpButtonDemoDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_BMPBUTTONDEMO_DIALOG]
Type=1
Class=CBmpButtonDemoDlg
ControlCount=9
Control1=IDC_STATIC,static,1342308865
Control2=IDC_STATIC,static,1342177296
Control3=IDC_STATIC,static,1342308865
Control4=IDC_ORIGIN_EDIT,edit,1350641794
Control5=IDC_ORIGIN_BITMAP_BUTTON,button,1342242827
Control6=IDC_STATIC,static,1342308865
Control7=IDC_SPEED_EDIT,edit,1350641794
Control8=IDC_SPEED_BITMAP_BUTTON,button,1342242827
Control9=IDOK,button,1342242817

[CLS:CSpeedBmpButton]
Type=0
HeaderFile=SpeedBmpButton.h
ImplementationFile=SpeedBmpButton.cpp
BaseClass=CBitmapButton
Filter=W
LastObject=CSpeedBmpButton
VirtualFilter=BWC

