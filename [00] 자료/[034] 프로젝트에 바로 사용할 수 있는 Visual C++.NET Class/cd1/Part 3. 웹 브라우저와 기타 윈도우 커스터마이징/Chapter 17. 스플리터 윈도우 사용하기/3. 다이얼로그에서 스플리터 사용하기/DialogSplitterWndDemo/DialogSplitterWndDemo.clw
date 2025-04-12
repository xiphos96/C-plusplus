; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDialogSplitterWnd
LastTemplate=CStatic
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "dialogsplitterwnddemo.h"
LastPage=0

ClassCount=4
Class1=CDialogSplitterWndDemoApp
Class2=CAboutDlg
Class3=CDialogSplitterWndDemoDlg

ResourceCount=2
Resource1=IDD_ABOUTBOX
Class4=CDialogSplitterWnd
Resource2=IDD_DIALOGSPLITTERWNDDEMO_DIALOG

[CLS:CDialogSplitterWndDemoApp]
Type=0
BaseClass=CWinApp
HeaderFile=DialogSplitterWndDemo.h
ImplementationFile=DialogSplitterWndDemo.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=DialogSplitterWndDemoDlg.cpp
ImplementationFile=DialogSplitterWndDemoDlg.cpp
LastObject=CAboutDlg

[CLS:CDialogSplitterWndDemoDlg]
Type=0
BaseClass=CDialog
HeaderFile=DialogSplitterWndDemoDlg.h
ImplementationFile=DialogSplitterWndDemoDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=IDC_SPLITTER_STATIC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_DIALOGSPLITTERWNDDEMO_DIALOG]
Type=1
Class=CDialogSplitterWndDemoDlg
ControlCount=9
Control1=IDC_TEST_STATIC,static,1342308864
Control2=IDC_TEST_EDIT,edit,1350631552
Control3=IDC_TEST_BUTTON,button,1342242816
Control4=IDC_TEST_CALENDAR,SysMonthCal32,1342242832
Control5=IDC_SPLITTER_STATIC,static,1342177287
Control6=IDC_TEST_TREE,SysTreeView32,1350631424
Control7=IDC_SPLITTER2_STATIC,static,1342177287
Control8=IDC_TEST_LIST,SysListView32,1350631425
Control9=IDOK,button,1342242817

[CLS:CDialogSplitterWnd]
Type=0
HeaderFile=dialogsplitterwnd.h
ImplementationFile=dialogsplitterwnd.cpp
BaseClass=CStatic
Filter=W
VirtualFilter=WC
LastObject=CDialogSplitterWnd

