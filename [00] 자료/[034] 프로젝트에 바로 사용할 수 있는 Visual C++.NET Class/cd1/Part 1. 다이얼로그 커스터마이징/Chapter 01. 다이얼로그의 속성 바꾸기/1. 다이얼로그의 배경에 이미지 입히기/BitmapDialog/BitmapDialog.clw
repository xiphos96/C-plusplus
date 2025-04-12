; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CImageDialog
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "bitmapdialog.h"
LastPage=0

ClassCount=4
Class1=CBitmapDialogApp
Class2=CAboutDlg
Class3=CBitmapDialogDlg

ResourceCount=2
Resource1=IDD_ABOUTBOX
Class4=CImageDialog
Resource2=IDD_BITMAPDIALOG_DIALOG

[CLS:CBitmapDialogApp]
Type=0
BaseClass=CWinApp
HeaderFile=BitmapDialog.h
ImplementationFile=BitmapDialog.cpp
LastObject=CBitmapDialogApp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=BitmapDialogDlg.cpp
ImplementationFile=BitmapDialogDlg.cpp
LastObject=CAboutDlg

[CLS:CBitmapDialogDlg]
Type=0
BaseClass=CImageDialog
HeaderFile=BitmapDialogDlg.h
ImplementationFile=BitmapDialogDlg.cpp
LastObject=CBitmapDialogDlg
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

[DLG:IDD_BITMAPDIALOG_DIALOG]
Type=1
Class=CBitmapDialogDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_MODE_RADIO1,button,1342308361
Control5=IDC_MODE_RADIO2,button,1342177289
Control6=IDC_MODE_RADIO3,button,1342177289

[CLS:CImageDialog]
Type=0
HeaderFile=ImageDialog.h
ImplementationFile=ImageDialog.cpp
BaseClass=CDialog
Filter=W
LastObject=CImageDialog
VirtualFilter=dWC

