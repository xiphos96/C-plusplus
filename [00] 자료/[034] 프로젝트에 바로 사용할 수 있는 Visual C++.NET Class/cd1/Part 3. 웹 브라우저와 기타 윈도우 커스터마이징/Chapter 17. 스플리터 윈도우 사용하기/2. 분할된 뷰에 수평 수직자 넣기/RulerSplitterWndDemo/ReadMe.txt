================================================================================
              MFC 라이브러리 : RulerSplitterWndDemo 프로젝트 개요
================================================================================

응용 프로그램 마법사를 사용하여 RulerSplitterWndDemo 응용 프로그램을 만듭니다. 이 응용 
프로그램에서는 기본적인 MFC 사용 밥법과 응용 프로그램 작성 방법을 설명합니다.

이 파일에는 RulerSplitterWndDemo 응용 프로그램을 구성하는 각 파일에 대한 개요가 포함되어
있습니다.

RulerSplitterWndDemo.vcproj
    응용 프로그램 마법사를 사용하여 생성된 VC++ 프로젝트의 주 프로젝트 파일입니다.
    이 파일에는 파일을 생성한 Visual C++ 버전 정보 및 응용 프로그램 마법사에서 선택한 플랫폼,
    구성, 프로젝트 기능 등의 정보가 포함됩니다.

RulerSplitterWndDemo.h
    응용 프로그램의 주 헤더 파일입니다. 이 파일에는 다른 프로젝트에 관련된 Resource.h와 같은
    특정 헤더가 포함되며 CRulerSplitterWndDemoApp 응용 프로그램 클래스가 선언됩니다.

RulerSplitterWndDemo.cpp
    CRulerSplitterWndDemoApp 응용 프로그램 클래스를 포함하는 주 응용 프로그램의 소스 파일입니다.

RulerSplitterWndDemo.rc
    프로그램에서 사용하는 모든 Microsoft Windows 리소스가 나열된 파일입니다.
    이 파일에는 RES 하위 디렉터리에 저장된 아이콘, 비트맵 및 커서가 포함되며
    Microsoft Visual C++에서 직접 이 파일을 편집할 수도 있습니다. 사용자의 프로젝트
    리소스는 1042에 들어 있습니다.

res\RulerSplitterWndDemo.ico
    응용 프로그램의 아이콘으로 사용되는 아이콘 파일입니다.
    이 아이콘은 주 리소스 파일인 RulerSplitterWndDemo.rc에 포함됩니다.

res\RulerSplitterWndDemo.rc2
    Microsoft Visual C++에서 편집할 수 없는 리소스가 포함된 파일입니다.
    리소스 편집기에서 편집할 수 없는 모든 리소스는 이 파일에 포함되어 있습니다.
/////////////////////////////////////////////////////////////////////////////

주 프레임 창에 해당되는 내용입니다.
    프로젝트에 표준 MFC 인터페이스가 포함됩니다.
MainFrm.h, MainFrm.cpp
    CMainFrame 프레임 클래스를 포함하는 파일입니다.
    프레임 클래스는 CFrameWnd에서 파생되며 모든 SDI 프레임 기능을 제어합니다.
res\Toolbar.bmp
    도구 모음에 바둑판식 이미지를 만들 때 사용되는 비트맵 파일입니다.
    초기 도구 모음 및 상태 표시줄은 CMainFrame 클래스에 구성됩니다.
    리소스 편집기를 사용하여 도구 모음 비트맵을 편집하고 RulerSplitterWndDemo.rc의
    IDR_MAINFRAME TOOLBAR 배열을 업데이트하여 도구 모음 단추에 추가합니다.
/////////////////////////////////////////////////////////////////////////////

응용 프로그램 마법사에서 단일 문서 종류 및 단일 뷰를 만듭니다.

RulerSplitterWndDemoDoc.h, RulerSplitterWndDemoDoc.cpp - 문서
    CRulerSplitterWndDemoDoc 클래스를 포함하는 파일입니다. 이 파일을 편집하여
    특정 문서 데이터를 추가하고 파일을 저장 및 로드합니다
    (CRulerSplitterWndDemoDoc::Serialize 사용).
RulerSplitterWndDemoView.h, RulerSplitterWndDemoView.cpp - 문서 뷰
    CRulerSplitterWndDemoView 클래스를 포함하는 파일입니다.
    CRulerSplitterWndDemoView 개체를 사용하여 CRulerSplitterWndDemoDoc 개체를 볼 수 있습니다.
/////////////////////////////////////////////////////////////////////////////

기타 기능

ActiveX 컨트롤
    응용 프로그램에서 ActiveX 컨트롤을 사용할 수 있습니다.

인쇄 및 인쇄 미리보기 지원
    응용 프로그램 마법사에서 MFC 라이브러리의 CView 클래스에 있는 멤버 함수를 호출하여
    인쇄, 인쇄 설정, 인쇄 미리보기 명령을 처리할 수 있는 코드를 생성합니다.
/////////////////////////////////////////////////////////////////////////////

기타 표준 파일

StdAfx.h, StdAfx.cpp
    미리 컴파일된 헤더 파일(PCH) RulerSplitterWndDemo.pch 및 미리 컴파일된
    형식 파일 StdAfx.obj를 빌드할 때 사용되는 파일입니다.

Resource.h
    새로운 리소스 ID를 정의하는 표준 헤더 파일입니다.
    Microsoft Visual C++에서 이 파일을 읽고 업데이트합니다.

/////////////////////////////////////////////////////////////////////////////

기타 정보

응용 프로그램 마법사에서는 "TODO:"를 사용하여 추가하거나 사용자 지정해야 하는
소스 코드를 나타냅니다.

응용 프로그램에서 공유 DLL에 MFC를 사용하고 응용 프로그램의 언어가 운영 체제의
언어와 다른 경우 Microsoft Visual C++ CD-ROM의 Win\System 디렉터리에 있는 
해당 지역의 리소스인 MFC70XXX.DLL을 컴퓨터의 system 또는 system32 디렉터리에 
복사한 다음 MFCLOC.DLL로 이름을 바꾸어야 합니다. "XXX"는 해당 언어를 나타내는
약어입니다. 예를 들어 MFC70DEU.DLL에는 독일어로 변환된 리소스가 포함됩니다.
이런 작업을 하지 않으면 응용 프로그램의 일부 UI 요소가 운영 체제의 언어로
남아 있게 됩니다.

/////////////////////////////////////////////////////////////////////////////
