/**
 *  file    ApplicationPanelTask.h
 *  date    2009/11/03
 *  author  kkamagui 
 *          Copyright(c)2008 All rights reserved by kkamagui 
 *  brief   ���ø����̼� �гο� ���õ� ��� ����
 */

#ifndef __APPLICATIONPANELTASK_H__
#define __APPLICATIONPANELTASK_H__

#include "windef.h"
#include <skyoswindow.h>

#define FONT_ENGLISHWIDTH   8
#define FONT_ENGLISHHEIGHT  16

 // �ѱ� ��Ʈ�� �ʺ�� ����
#define FONT_HANGULWIDTH   16
#define FONT_HANGULHEIGHT  16

// ���ø����̼� �г� �������� ����
#define APPLICATIONPANEL_HEIGHT             31
// ���ø����̼� �г� �������� ����
#define APPLICATIONPANEL_TITLE              "SYS_APPLICATIONPANNEL"
// ���ø����̼� �г� �����쿡 ǥ���� �ð��� �ʺ�
// 09:00 AM ���·� ǥ���ϹǷ� 8 * ��Ʈ�� �ʺ�� ���
#define APPLICATIONPANEL_CLOCKWIDTH         ( 8 * FONT_ENGLISHWIDTH )

// ���ø����̼� ����Ʈ �����쿡 ��Ÿ�� �������� ����
#define APPLICATIONPANEL_LISTITEMHEIGHT     ( FONT_ENGLISHHEIGHT + 4 )
// ���ø����̼� ����Ʈ �������� ����
#define APPLICATIONPANEL_LISTTITLE          "SYS_APPLICATIONLIST"

// ���ø����̼� �гο��� ����ϴ� ����
#define APPLICATIONPANEL_COLOR_OUTERLINE     RGB( 109, 218, 22 )
#define APPLICATIONPANEL_COLOR_MIDDLELINE    RGB( 183, 249, 171 )
#define APPLICATIONPANEL_COLOR_INNERLINE     RGB( 150, 210, 140 )
#define APPLICATIONPANEL_COLOR_BACKGROUND    RGB( 55, 135, 11 )
#define APPLICATIONPANEL_COLOR_ACTIVE        RGB( 79, 204, 11 )

////////////////////////////////////////////////////////////////////////////////
//
// ����ü
//
////////////////////////////////////////////////////////////////////////////////
// ���ø����̼� �г��� ����ϴ� ������ �����ϴ� �ڷᱸ��
typedef struct kApplicationPanelDataStruct
{
    // ���ø����̼� �г� �������� ID
    QWORD qwApplicationPanelID;
    
    // ���ø����̼� ����Ʈ �������� ID
    QWORD qwApplicationListID;
    
    // ���ø����̼� �г��� ��ư ��ġ
    RECT stButtonArea;
    
    // ���ø����̼� ����Ʈ �������� �ʺ�
    int iApplicationListWidth;
    
    // ���ø����̼� ����Ʈ �����쿡�� ������ ���콺�� ��ġ�� �������� �ε���
    int iPreviousMouseOverIndex;

    // ���ø����̼� ����Ʈ �����찡 ȭ�鿡 ǥ�õǾ����� ����
	bool bApplicationWindowVisible;
} APPLICATIONPANELDATA;

// GUI �½�ũ�� ������ �����ϴ� �ڷᱸ��
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
