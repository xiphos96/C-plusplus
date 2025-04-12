; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFontEffectDemoDlg
LastTemplate=CStatic
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "fonteffectdemo.h"
LastPage=0

ClassCount=4
Class1=CFontEffectDemoApp
Class2=CAboutDlg
Class3=CFontEffectDemoDlg

ResourceCount=2
Resource1=IDD_ABOUTBOX
Class4=CFontEffect
Resource2=IDD_FONTEFFECTDEMO_DIALOG

[CLS:CFontEffectDemoApp]
Type=0
BaseClass=CWinApp
HeaderFile=FontEffectDemo.h
ImplementationFile=FontEffectDemo.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=FontEffectDemoDlg.cpp
ImplementationFile=FontEffectDemoDlg.cpp

[CLS:CFontEffectDemoDlg]
Type=0
BaseClass=CDialog
HeaderFile=FontEffectDemoDlg.h
ImplementationFile=FontEffectDemoDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=IDC_EFFECT_STATIC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FONTEFFECTDEMO_DIALOG]
Type=1
Class=CFontEffectDemoDlg
ControlCount=9
Control1=IDC_STATIC,static,1342308864
Control2=IDC_TEXT_EDIT,edit,1350631552
Control3=IDC_REFRESH_BUTTON,button,1342242816
Control4=IDC_OUTLINE_CHECK,button,1342242819
Control5=IDC_EFFECT_STATIC,static,1342177287
Control6=IDOK,button,1342242817
Control7=IDC_SHAPE_BUTTON1,button,1342312585
Control8=IDC_SHAPE_BUTTON2,button,1342181513
Control9=IDC_SHAPE_BUTTON3,button,1342181513

[CLS:CFontEffect]
Type=0
HeaderFile=FontEffect.h
ImplementationFile=FontEffect.cpp
BaseClass=CStatic
Filter=W
VirtualFilter=WC
LastObject=CFontEffect

