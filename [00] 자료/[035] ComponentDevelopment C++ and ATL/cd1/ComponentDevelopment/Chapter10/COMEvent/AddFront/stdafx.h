// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이 
// 들어 있는 포함 파일입니다.
//

#pragma once


#include <iostream>
#include <tchar.h>
#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// 일부 CString 생성자는 명시적으로 선언됩니다.

#define _ATL_ATTRIBUTES 1
#define _WIN32_DCOM	

#include <atlbase.h>
#include <atlcom.h>

// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#import "progid:AddBack.AddBack.1" embedded_idl, no_namespace


