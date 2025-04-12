; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCoolButtonDemoDlg
LastTemplate=CButton
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "coolbuttondemo.h"
LastPage=0

ClassCount=4
Class1=CCoolButtonDemoApp
Class2=CAboutDlg
Class3=CCoolButtonDemoDlg

ResourceCount=2
Resource1=IDD_ABOUTBOX
Class4=CCoolButton
Resource2=IDD_COOLBUTTONDEMO_DIALOG

[CLS:CCoolButtonDemoApp]
Type=0
BaseClass=CWinApp
HeaderFile=CoolButtonDemo.h
ImplementationFile=CoolButtonDemo.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=CoolButtonDemoDlg.cpp
ImplementationFile=CoolButtonDemoDlg.cpp
LastObject=CAboutDlg

[CLS:CCoolButtonDemoDlg]
Type=0
BaseClass=CDialog
HeaderFile=CoolButtonDemoDlg.h
ImplementationFile=CoolButtonDemoDlg.cpp
LastObject=IDC_ENABLE_CHECK
Filter=D
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_COOLBUTTONDEMO_DIALOG]
Type=1
Class=CCoolButtonDemoDlg
ControlCount=16
Control1=IDC_STATIC,static,1342308864
Control2=IDC_BMP_BUTTON,button,1342242827
Control3=IDC_STATIC,static,1342308864
Control4=IDC_ICON_BUTTON,button,1342242827
Control5=IDC_STATIC,static,1342308864
Control6=IDC_TRASPARENT_BUTTON,button,1342242827
Control7=IDC_STATIC,static,1342308864
Control8=IDC_LEFT_RADIO,button,1342308361
Control9=IDC_RIGHT_RADIO,button,1342177289
Control10=IDC_TOP_RADIO,button,1342177289
Control11=IDC_BOTTOM_RADIO,button,1342177289
Control12=IDC_OVER_RADIO,button,1342177289
Control13=IDC_STATIC,static,1342308864
Control14=IDC_ENABLE_CHECK,button,1342242819
Control15=IDC_POSITION_BUTTON,button,1342242827
Control16=IDOK,button,1342242817

[CLS:CCoolButton]
Type=0
HeaderFile=CoolButton.h
ImplementationFile=CoolButton.cpp
BaseClass=CButton
Filter=W
LastObject=CCoolButton
VirtualFilter=BWC

