/**
 *  file    ApplicationPanelTask.h
 *  date    2009/11/03
 *  author  kkamagui 
 *          Copyright(c)2008 All rights reserved by kkamagui 
 *  brief   애플리케이션 패널에 관련된 헤더 파일
 */

#ifndef __APPLICATIONPANELTASK_H__
#define __APPLICATIONPANELTASK_H__

#include "windef.h"
#include <skyoswindow.h>

#define FONT_ENGLISHWIDTH   8
#define FONT_ENGLISHHEIGHT  16

 // 한글 폰트의 너비와 길이
#define FONT_HANGULWIDTH   16
#define FONT_HANGULHEIGHT  16

// 애플리케이션 패널 윈도우의 높이
#define APPLICATIONPANEL_HEIGHT             31
// 애플리케이션 패널 윈도우의 제목
#define APPLICATIONPANEL_TITLE              "SYS_APPLICATIONPANNEL"
// 애플리케이션 패널 윈도우에 표시할 시계의 너비
// 09:00 AM 형태로 표시하므로 8 * 폰트의 너비로 계산
#define APPLICATIONPANEL_CLOCKWIDTH         ( 8 * FONT_ENGLISHWIDTH )

// 애플리케이션 리스트 윈도우에 나타낼 아이템의 높이
#define APPLICATIONPANEL_LISTITEMHEIGHT     ( FONT_ENGLISHHEIGHT + 4 )
// 애플리케이션 리스트 윈도우의 제목
#define APPLICATIONPANEL_LISTTITLE          "SYS_APPLICATIONLIST"

// 애플리케이션 패널에서 사용하는 색깔
#define APPLICATIONPANEL_COLOR_OUTERLINE     RGB( 109, 218, 22 )
#define APPLICATIONPANEL_COLOR_MIDDLELINE    RGB( 183, 249, 171 )
#define APPLICATIONPANEL_COLOR_INNERLINE     RGB( 150, 210, 140 )
#define APPLICATIONPANEL_COLOR_BACKGROUND    RGB( 55, 135, 11 )
#define APPLICATIONPANEL_COLOR_ACTIVE        RGB( 79, 204, 11 )

////////////////////////////////////////////////////////////////////////////////
//
// 구조체
//
////////////////////////////////////////////////////////////////////////////////
// 애플리케이션 패널이 사용하는 정보를 저장하는 자료구조
typedef struct kApplicationPanelDataStruct
{
    // 애플리케이션 패널 윈도우의 ID
    QWORD qwApplicationPanelID;
    
    // 애플리케이션 리스트 윈도우의 ID
    QWORD qwApplicationListID;
    
    // 애플리케이션 패널의 버튼 위치
    RECT stButtonArea;
    
    // 애플리케이션 리스트 윈도우의 너비
    int iApplicationListWidth;
    
    // 애플리케이션 리스트 윈도우에서 이전에 마우스가 위치한 아이템의 인덱스
    int iPreviousMouseOverIndex;

    // 애플리케이션 리스트 윈도우가 화면에 표시되었는지 여부
	bool bApplicationWindowVisible;
} APPLICATIONPANELDATA;

// GUI 태스크의 정보를 저장하는 자료구조
typedef struct kApplicationEntryStruct
{   
    char appName[MAX_PATH];
    char appDesc[MAX_PATH];
	char exePath[MAX_PATH];
} APPLICATIONENTRY;

bool CreateApplicationPanelWindow( void );
bool CreateApplicationListWindow( void );
bool ProcessApplicationPanelWindowEvent(void);
bool ProcessApplicationListWindowEvent(void);

#endif /*__APPLICATIONPANELTASK_H__*/
