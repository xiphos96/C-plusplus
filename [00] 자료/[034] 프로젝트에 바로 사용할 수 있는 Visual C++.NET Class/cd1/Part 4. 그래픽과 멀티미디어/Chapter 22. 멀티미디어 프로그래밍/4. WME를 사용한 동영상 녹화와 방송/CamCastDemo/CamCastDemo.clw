; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CEncoderConfigDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "camcastdemo.h"
LastPage=0

ClassCount=5
Class1=CCamCast
Class2=CCamCastDemoApp
Class3=CAboutDlg
Class4=CCamCastDemoDlg
Class5=CEncoderConfigDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDD_CAMCASTDEMO_DIALOG
Resource3=IDD_ENCODER_CONFIG_DLG

[CLS:CCamCast]
Type=0
BaseClass=CStatic
HeaderFile=CamCast.h
ImplementationFile=CamCast.cpp
Filter=W
VirtualFilter=WC
LastObject=CCamCast

[CLS:CCamCastDemoApp]
Type=0
BaseClass=CWinApp
HeaderFile=CamCastDemo.h
ImplementationFile=CamCastDemo.cpp
Filter=N
VirtualFilter=AC
LastObject=CCamCastDemoApp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=CamCastDemoDlg.cpp
ImplementationFile=CamCastDemoDlg.cpp
LastObject=CAboutDlg

[CLS:CCamCastDemoDlg]
Type=0
BaseClass=CDialog
HeaderFile=CamCastDemoDlg.h
ImplementationFile=CamCastDemoDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=IDC_CONFIG_BUTTON

[CLS:CEncoderConfigDlg]
Type=0
BaseClass=CDialog
HeaderFile=EncoderConfigDlg.h
ImplementationFile=EncoderConfigDlg.cpp
LastObject=IDC_PROPSHELLCTRL_CONFIG

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CAMCASTDEMO_DIALOG]
Type=1
Class=CCamCastDemoDlg
ControlCount=6
Control1=IDC_CAMCAST_STATIC,static,1342177287
Control2=IDC_REC_BUTTON,button,1342242816
Control3=IDC_CAST_BUTTON,button,1342242816
Control4=IDC_STOP_BUTTON,button,1342242816
Control5=IDC_CONFIG_BUTTON,button,1342242816
Control6=IDOK,button,1342242817

[DLG:IDD_ENCODER_CONFIG_DLG]
Type=1
Class=CEncoderConfigDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_PROPSHELLCTRL_CONFIG,{E297AB5E-40B0-41BD-9E06-E4144084EE5F},1342242816

