; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CTestPage2
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "custompropertysheetdemo.h"
LastPage=0

ClassCount=7
Class1=CCustomPropertySheet
Class2=CCustomPropertySheetDemoApp
Class3=CAboutDlg
Class4=CCustomPropertySheetDemoDlg
Class5=CTestPage1
Class6=CTestPage2
Class7=CTestSheet

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDD_CUSTOMPROPERTYSHEETDEMO_DIALOG
Resource3=IDD_TEST_PAGE1
Resource4=IDD_TEST_PAGE2

[CLS:CCustomPropertySheet]
Type=0
BaseClass=CPropertySheet
HeaderFile=CustomPropertySheet.h
ImplementationFile=CustomPropertySheet.cpp

[CLS:CCustomPropertySheetDemoApp]
Type=0
BaseClass=CWinApp
HeaderFile=CustomPropertySheetDemo.h
ImplementationFile=CustomPropertySheetDemo.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=CustomPropertySheetDemoDlg.cpp
ImplementationFile=CustomPropertySheetDemoDlg.cpp

[CLS:CCustomPropertySheetDemoDlg]
Type=0
BaseClass=CDialog
HeaderFile=CustomPropertySheetDemoDlg.h
ImplementationFile=CustomPropertySheetDemoDlg.cpp
Filter=D
VirtualFilter=dWC

[CLS:CTestPage1]
Type=0
BaseClass=CPropertyPage
HeaderFile=TestPage1.h
ImplementationFile=TestPage1.cpp

[CLS:CTestPage2]
Type=0
BaseClass=CPropertyPage
HeaderFile=TestPage2.h
ImplementationFile=TestPage2.cpp
LastObject=IDC_EDIT1
Filter=D
VirtualFilter=idWC

[CLS:CTestSheet]
Type=0
BaseClass=CCustomPropertySheet
HeaderFile=TestSheet.h
ImplementationFile=TestSheet.cpp

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CUSTOMPROPERTYSHEETDEMO_DIALOG]
Type=1
Class=CCustomPropertySheetDemoDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308353
Control3=IDC_OPEN_BUTTON,button,1342242816

[DLG:IDD_TEST_PAGE1]
Type=1
Class=CTestPage1
ControlCount=5
Control1=IDC_STATIC,static,1342308864
Control2=IDC_LIST1,SysListView32,1350631424
Control3=IDC_SLIDER1,msctls_trackbar32,1342242840
Control4=IDC_PROGRESS1,msctls_progress32,1350565888
Control5=IDC_DATETIMEPICKER1,SysDateTimePick32,1342242853

[DLG:IDD_TEST_PAGE2]
Type=1
Class=CTestPage2
ControlCount=3
Control1=IDC_STATIC,static,1342308864
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_ERASE_BUTTON,button,1342242816

