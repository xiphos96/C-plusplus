; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLeftView
LastTemplate=CView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "flatsplitterwnddemo.h"
LastPage=0

ClassCount=8
Class1=CFlatSplitterWndDemoApp
Class2=CAboutDlg
Class3=CFlatSplitterWndDemoDoc
Class4=CFlatSplitterWndDemoView
Class5=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Class6=CFlatSplitterWnd
Resource2=IDR_MAINFRAME
Class7=CLeftView
Class8=CBottomView
Resource3=IDD_FORM_VIEW

[CLS:CFlatSplitterWndDemoApp]
Type=0
BaseClass=CWinApp
HeaderFile=FlatSplitterWndDemo.h
ImplementationFile=FlatSplitterWndDemo.cpp
LastObject=CFlatSplitterWndDemoApp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=FlatSplitterWndDemo.cpp
ImplementationFile=FlatSplitterWndDemo.cpp
LastObject=CAboutDlg

[CLS:CFlatSplitterWndDemoDoc]
Type=0
BaseClass=CDocument
HeaderFile=FlatSplitterWndDemoDoc.h
ImplementationFile=FlatSplitterWndDemoDoc.cpp

[CLS:CFlatSplitterWndDemoView]
Type=0
BaseClass=CView
HeaderFile=FlatSplitterWndDemoView.h
ImplementationFile=FlatSplitterWndDemoView.cpp

[CLS:CMainFrame]
Type=0
BaseClass=CFrameWnd
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
VirtualFilter=fWC
LastObject=CMainFrame

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
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[MNU:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
CommandCount=16

[ACL:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[CLS:CFlatSplitterWnd]
Type=0
HeaderFile=FlatSplitterWnd.h
ImplementationFile=FlatSplitterWnd.cpp
BaseClass=CSplitterWnd
Filter=W
LastObject=CFlatSplitterWnd
VirtualFilter=pWC

[DLG:IDD_FORM_VIEW]
Type=1
Class=CLeftView
ControlCount=7
Control1=IDC_STATIC,static,1342308864
Control2=IDC_STATIC,static,1342308864
Control3=IDC_STATIC,static,1342308864
Control4=IDC_CX_EDIT,edit,1350639746
Control5=IDC_CY_EDIT,edit,1350639746
Control6=IDC_CHANGE_BUTTON,button,1342242816
Control7=IDC_STATIC,static,1342177296

[CLS:CLeftView]
Type=0
HeaderFile=LeftView.h
ImplementationFile=LeftView.cpp
BaseClass=CFormView
Filter=D
LastObject=IDC_CHANGE_BUTTON
VirtualFilter=VWC

[CLS:CBottomView]
Type=0
HeaderFile=BottomView.h
ImplementationFile=BottomView.cpp
BaseClass=CView
Filter=C
LastObject=CBottomView

