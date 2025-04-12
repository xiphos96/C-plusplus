; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSlideWnd
LastTemplate=generic CWnd
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "slideeditdemo.h"
LastPage=0

ClassCount=5
Class1=CSlideEditDemoApp
Class2=CAboutDlg
Class3=CSlideEditDemoDlg

ResourceCount=2
Resource1=IDD_ABOUTBOX
Class4=CSlideEdit
Class5=CSlideWnd
Resource2=IDD_SLIDEEDITDEMO_DIALOG

[CLS:CSlideEditDemoApp]
Type=0
BaseClass=CWinApp
HeaderFile=SlideEditDemo.h
ImplementationFile=SlideEditDemo.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=SlideEditDemoDlg.cpp
ImplementationFile=SlideEditDemoDlg.cpp

[CLS:CSlideEditDemoDlg]
Type=0
BaseClass=CDialog
HeaderFile=SlideEditDemoDlg.h
ImplementationFile=SlideEditDemoDlg.cpp
LastObject=CSlideEditDemoDlg
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

[DLG:IDD_SLIDEEDITDEMO_DIALOG]
Type=1
Class=CSlideEditDemoDlg
ControlCount=8
Control1=IDC_STATIC,static,1342308864
Control2=IDC_SLIDE_EDIT_R,edit,1350631556
Control3=IDC_STATIC,static,1342308864
Control4=IDC_SLIDE_EDIT_G,edit,1350631556
Control5=IDC_STATIC,static,1342308864
Control6=IDC_SLIDE_EDIT_B,edit,1350631556
Control7=IDC_COLOR_STATIC,static,1342181383
Control8=IDOK,button,1342242817

[CLS:CSlideEdit]
Type=0
HeaderFile=SlideEdit.h
ImplementationFile=SlideEdit.cpp
BaseClass=CEdit
Filter=W
LastObject=CSlideEdit
VirtualFilter=WC

[CLS:CSlideWnd]
Type=0
HeaderFile=SlideWnd.h
ImplementationFile=SlideWnd.cpp
BaseClass=CWnd
Filter=W
LastObject=CSlideWnd
VirtualFilter=WC

