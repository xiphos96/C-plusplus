; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CFlatHeaderCtrlDemoDlg
LastTemplate=CHeaderCtrl
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "flatheaderctrldemo.h"
LastPage=0

ClassCount=5
Class1=CFlatHeaderCtrlDemoApp
Class2=CAboutDlg
Class3=CFlatHeaderCtrlDemoDlg

ResourceCount=2
Resource1=IDD_ABOUTBOX
Class4=CFlatListCtrl
Class5=CFlatHeaderCtrl
Resource2=IDD_FLATHEADERCTRLDEMO_DIALOG

[CLS:CFlatHeaderCtrlDemoApp]
Type=0
BaseClass=CWinApp
HeaderFile=FlatHeaderCtrlDemo.h
ImplementationFile=FlatHeaderCtrlDemo.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=FlatHeaderCtrlDemoDlg.cpp
ImplementationFile=FlatHeaderCtrlDemoDlg.cpp

[CLS:CFlatHeaderCtrlDemoDlg]
Type=0
BaseClass=CDialog
HeaderFile=FlatHeaderCtrlDemoDlg.h
ImplementationFile=FlatHeaderCtrlDemoDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=IDC_ADD_BUTTON

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_FLATHEADERCTRLDEMO_DIALOG]
Type=1
Class=CFlatHeaderCtrlDemoDlg
ControlCount=9
Control1=IDC_STATIC,static,1342308864
Control2=IDC_NAME_EDIT,edit,1350631552
Control3=IDC_STATIC,static,1342308864
Control4=IDC_AGE_EDIT,edit,1350631552
Control5=IDC_STATIC,static,1342308864
Control6=IDC_ADDR_EDIT,edit,1350631552
Control7=IDC_FLAT_LIST,SysListView32,1350631437
Control8=IDC_ADD_BUTTON,button,1342242817
Control9=IDOK,button,1342242816

[CLS:CFlatListCtrl]
Type=0
HeaderFile=FlatListCtrl.h
ImplementationFile=FlatListCtrl.cpp
BaseClass=CListCtrl
Filter=W
LastObject=CFlatListCtrl
VirtualFilter=FWC

[CLS:CFlatHeaderCtrl]
Type=0
HeaderFile=FlatHeaderCtrl.h
ImplementationFile=FlatHeaderCtrl.cpp
BaseClass=CHeaderCtrl
Filter=W
LastObject=CFlatHeaderCtrl
VirtualFilter=JWC

