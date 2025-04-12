; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDriveComboBoxDemoDlg
LastTemplate=CComboBox
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "drivecomboboxdemo.h"
LastPage=0

ClassCount=4
Class1=CDriveComboBoxDemoApp
Class2=CAboutDlg
Class3=CDriveComboBoxDemoDlg

ResourceCount=2
Resource1=IDD_ABOUTBOX
Class4=CDriveComboBox
Resource2=IDD_DRIVECOMBOBOXDEMO_DIALOG

[CLS:CDriveComboBoxDemoApp]
Type=0
BaseClass=CWinApp
HeaderFile=DriveComboBoxDemo.h
ImplementationFile=DriveComboBoxDemo.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=DriveComboBoxDemoDlg.cpp
ImplementationFile=DriveComboBoxDemoDlg.cpp

[CLS:CDriveComboBoxDemoDlg]
Type=0
BaseClass=CDialog
HeaderFile=DriveComboBoxDemoDlg.h
ImplementationFile=DriveComboBoxDemoDlg.cpp
LastObject=CDriveComboBoxDemoDlg
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

[DLG:IDD_DRIVECOMBOBOXDEMO_DIALOG]
Type=1
Class=CDriveComboBoxDemoDlg
ControlCount=10
Control1=IDC_STATIC,static,1342308866
Control2=IDC_COUNT_EDIT,edit,1350633600
Control3=IDC_STATIC,static,1342308866
Control4=IDC_CUR_DRIVE_EDIT,edit,1350633600
Control5=IDC_STATIC,static,1342308866
Control6=IDC_BIG_RADIO,button,1342308361
Control7=IDC_SMALL_RADIO,button,1342177289
Control8=IDC_STATIC,static,1342308866
Control9=IDC_DRIVE_COMBO,combobox,1344340771
Control10=IDOK,button,1342242817

[CLS:CDriveComboBox]
Type=0
HeaderFile=DriveComboBox.h
ImplementationFile=DriveComboBox.cpp
BaseClass=CComboBox
Filter=W
VirtualFilter=cWC
LastObject=CDriveComboBox

