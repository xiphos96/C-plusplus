; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDialogTabCtrl
LastTemplate=CTabCtrl
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "dialogtabctrldemo.h"
LastPage=0

ClassCount=7
Class1=CDialogTabCtrlDemoApp
Class2=CAboutDlg
Class3=CDialogTabCtrlDemoDlg

ResourceCount=5
Resource1=IDD_INCOME_DIALOG
Resource2=IDD_OUTGO_DIALOG
Resource3=IDD_ABOUTBOX
Resource4=IDD_DIALOGTABCTRLDEMO_DIALOG
Class4=CIncomeDlg
Class5=COutgoDlg
Class6=CReportDlg
Class7=CDialogTabCtrl
Resource5=IDD_REPORT_DIALOG

[CLS:CDialogTabCtrlDemoApp]
Type=0
BaseClass=CWinApp
HeaderFile=DialogTabCtrlDemo.h
ImplementationFile=DialogTabCtrlDemo.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=DialogTabCtrlDemoDlg.cpp
ImplementationFile=DialogTabCtrlDemoDlg.cpp

[CLS:CDialogTabCtrlDemoDlg]
Type=0
BaseClass=CDialog
HeaderFile=DialogTabCtrlDemoDlg.h
ImplementationFile=DialogTabCtrlDemoDlg.cpp
LastObject=IDC_DIALOG_TAB
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

[DLG:IDD_DIALOGTABCTRLDEMO_DIALOG]
Type=1
Class=CDialogTabCtrlDemoDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_DIALOG_TAB,SysTabControl32,1342177280

[DLG:IDD_INCOME_DIALOG]
Type=1
Class=CIncomeDlg
ControlCount=6
Control1=IDC_NAME_STATIC,static,1342308866
Control2=IDC_NAME_EDIT,edit,1350631552
Control3=IDC_MONEY_STATIC,static,1342308866
Control4=IDC_MONEY_EDIT,edit,1350639744
Control5=IDC_ADD_BUTTON,button,1342242817
Control6=IDC_INCOME_LIST,SysListView32,1350664205

[DLG:IDD_OUTGO_DIALOG]
Type=1
Class=COutgoDlg
ControlCount=6
Control1=IDC_NAME_STATIC,static,1342308866
Control2=IDC_NAME_EDIT,edit,1350631552
Control3=IDC_MONEY_STATIC,static,1342308866
Control4=IDC_MONEY_EDIT,edit,1350639744
Control5=IDC_ADD_BUTTON,button,1342242817
Control6=IDC_OUTGO_LIST,SysListView32,1350664205

[DLG:IDD_REPORT_DIALOG]
Type=1
Class=CReportDlg
ControlCount=1
Control1=IDC_REPORT_STATIC,static,1342312449

[CLS:CIncomeDlg]
Type=0
HeaderFile=IncomeDlg.h
ImplementationFile=IncomeDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_INCOME_LIST
VirtualFilter=dWC

[CLS:COutgoDlg]
Type=0
HeaderFile=OutgoDlg.h
ImplementationFile=OutgoDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=COutgoDlg
VirtualFilter=dWC

[CLS:CReportDlg]
Type=0
HeaderFile=ReportDlg.h
ImplementationFile=ReportDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CReportDlg
VirtualFilter=dWC

[CLS:CDialogTabCtrl]
Type=0
HeaderFile=DialogTabCtrl.h
ImplementationFile=DialogTabCtrl.cpp
BaseClass=CTabCtrl
Filter=W
VirtualFilter=UWC
LastObject=CDialogTabCtrl

