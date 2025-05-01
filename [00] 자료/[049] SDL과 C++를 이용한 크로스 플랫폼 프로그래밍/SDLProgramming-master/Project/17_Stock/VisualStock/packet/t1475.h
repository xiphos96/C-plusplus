#ifndef _t1475_H_
#define _t1475_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// ü�ᰭ������(t1475) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1475     "t1475"

// �⺻�Է�                       
typedef struct _t1475InBlock
{
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] �����ڵ�                        StartPos 0, Length 6
    char    vptype              [   1];    char    _vptype              ;    // [string,    1] ����϶�                        StartPos 7, Length 1
    char    datacnt             [   4];    char    _datacnt             ;    // [long  ,    4] �����Ͱ���                      StartPos 9, Length 4
    char    date                [   8];    char    _date                ;    // [long  ,    8] ��������                        StartPos 14, Length 8
    char    time                [   6];    char    _time                ;    // [long  ,    6] ���ؽð�                        StartPos 23, Length 6
    char    rankcnt             [   3];    char    _rankcnt             ;    // [long  ,    3] ��ũī����                      StartPos 30, Length 3
    char    gubun               [   1];    char    _gubun               ;    // [string,    1] ��ȸ����                        StartPos 34, Length 1
} t1475InBlock, *LPt1475InBlock;
#define NAME_t1475InBlock     "t1475InBlock"

// ���                           
typedef struct _t1475OutBlock
{
    char    date                [   8];    char    _date                ;    // [long  ,    8] ��������                        StartPos 0, Length 8
    char    time                [   6];    char    _time                ;    // [long  ,    6] ���ؽð�                        StartPos 9, Length 6
    char    rankcnt             [   3];    char    _rankcnt             ;    // [long  ,    3] ��ũī����                      StartPos 16, Length 3
} t1475OutBlock, *LPt1475OutBlock;
#define NAME_t1475OutBlock     "t1475OutBlock"

// ���1                          , occurs
typedef struct _t1475OutBlock1
{
    char    datetime            [  10];    char    _datetime            ;    // [string,   10] ����                            StartPos 0, Length 10
    char    price               [   8];    char    _price               ;    // [long  ,    8] ���簡                          StartPos 11, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] ���ϴ�񱸺�                    StartPos 20, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] ���ϴ��                        StartPos 22, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] �����                          StartPos 31, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] �ŷ���                          StartPos 38, Length 12
    char    todayvp             [   8];    char    _todayvp             ;    // [float ,  8.2] ����VP                          StartPos 51, Length 8
    char    ma5vp               [   8];    char    _ma5vp               ;    // [float ,  8.2] 5��MAVP                         StartPos 60, Length 8
    char    ma20vp              [   8];    char    _ma20vp              ;    // [float ,  8.2] 20��MAVP                        StartPos 69, Length 8
    char    ma60vp              [   8];    char    _ma60vp              ;    // [float ,  8.2] 60��MAVP                        StartPos 78, Length 8
} t1475OutBlock1, *LPt1475OutBlock1;
#define NAME_t1475OutBlock1     "t1475OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1475_H_
