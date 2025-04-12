; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CRulerSplitterWndDemoView
LastTemplate=CView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "rulersplitterwnddemo.h"
LastPage=0

ClassCount=8
Class1=CMainFrame
Class2=CRulerSplitterWndDemoApp
Class3=CAboutDlg
Class4=CRulerSplitterWndDemoDoc
Class5=CRulerSplitterWndDemoView

ResourceCount=2
Resource1=IDR_MAINFRAME
Class6=CRulerSplitterWnd
Class7=CRulerSquareView
Class8=CRulerView
Resource2=IDD_ABOUTBOX

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
VirtualFilter=fWC
LastObject=CMainFrame

[CLS:CRulerSplitterWndDemoApp]
Type=0
BaseClass=CWinApp
HeaderFile=RulerSplitterWndDemo.h
ImplementationFile=RulerSplitterWndDemo.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=RulerSplitterWndDemo.cpp
ImplementationFile=RulerSplitterWndDemo.cpp
LastObject=CAboutDlg

[CLS:CRulerSplitterWndDemoDoc]
Type=0
BaseClass=CDocument
HeaderFile=RulerSplitterWndDemoDoc.h
ImplementationFile=RulerSplitterWndDemoDoc.cpp
Filter=N
VirtualFilter=DC
LastObject=CRulerSplitterWndDemoDoc

[CLS:CRulerSplitterWndDemoView]
Type=0
BaseClass=CScrollView
HeaderFile=RulerSplitterWndDemoView.h
ImplementationFile=RulerSplitterWndDemoView.cpp
Filter=C
VirtualFilter=VWC
LastObject=CRulerSplitterWndDemoView

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_APP_ABOUT
CommandCount=3

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_MRU_FILE1
Command4=ID_APP_EXIT
Command5=ID_VIEW_TOOLBAR
Command6=ID_VIEW_STATUS_BAR
Command7=ID_APP_ABOUT
CommandCount=7

[ACL:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_NEXT_PANE
Command4=ID_PREV_PANE
CommandCount=4

[CLS:CRulerSplitterWnd]
Type=0
HeaderFile=RulerSplitterWnd.h
ImplementationFile=RulerSplitterWnd.cpp
BaseClass=generic CWnd
Filter=W
LastObject=CRulerSplitterWnd

[CLS:CRulerSquareView]
Type=0
HeaderFile=RulerSquareView.h
ImplementationFile=RulerSquareView.cpp
BaseClass=CView
Filter=C
LastObject=CRulerSquareView
VirtualFilter=VWC

[CLS:CRulerView]
Type=0
HeaderFile=RulerView.h
ImplementationFile=RulerView.cpp
BaseClass=CView
Filter=C
LastObject=CRulerView
VirtualFilter=VWC

