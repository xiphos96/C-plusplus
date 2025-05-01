#ifndef _t1403_H_
#define _t1403_H_

///////////////////////////////////////////////////////////////////////////////////////////////////
// �űԻ���������ȸ(t1403) ( attr,block,headtype=A )
#pragma pack( push, 1 )

#define NAME_t1403     "t1403"

// �⺻�Է�                       
typedef struct _t1403InBlock
{
    char    gubun               [   1];    char    _gubun               ;    // [string,    1] ����                            StartPos 0, Length 1
    char    styymm              [   6];    char    _styymm              ;    // [string,    6] ���ۻ����                      StartPos 2, Length 6
    char    enyymm              [   6];    char    _enyymm              ;    // [string,    6] ��������                      StartPos 9, Length 6
    char    idx                 [   4];    char    _idx                 ;    // [long  ,    4] IDX                             StartPos 16, Length 4
} t1403InBlock, *LPt1403InBlock;
#define NAME_t1403InBlock     "t1403InBlock"

// ���                           
typedef struct _t1403OutBlock
{
    char    idx                 [   4];    char    _idx                 ;    // [long  ,    4] IDX                             StartPos 0, Length 4
} t1403OutBlock, *LPt1403OutBlock;
#define NAME_t1403OutBlock     "t1403OutBlock"

// ���1                          , occurs
typedef struct _t1403OutBlock1
{
    char    hname               [  20];    char    _hname               ;    // [string,   20] �ѱ۸�                          StartPos 0, Length 20
    char    price               [   8];    char    _price               ;    // [long  ,    8] ���簡                          StartPos 21, Length 8
    char    sign                [   1];    char    _sign                ;    // [string,    1] ���ϴ�񱸺�                    StartPos 30, Length 1
    char    change              [   8];    char    _change              ;    // [long  ,    8] ���ϴ��                        StartPos 32, Length 8
    char    diff                [   6];    char    _diff                ;    // [float ,  6.2] �����                          StartPos 41, Length 6
    char    volume              [  12];    char    _volume              ;    // [long  ,   12] �����ŷ���                      StartPos 48, Length 12
    char    kmprice             [   8];    char    _kmprice             ;    // [long  ,    8] ����                          StartPos 61, Length 8
    char    date                [   8];    char    _date                ;    // [string,    8] �����                          StartPos 70, Length 8
    char    recprice            [   8];    char    _recprice            ;    // [long  ,    8] ����ϱ��ذ�                    StartPos 79, Length 8
    char    kmdiff              [   6];    char    _kmdiff              ;    // [float ,  6.2] ���ذ������                    StartPos 88, Length 6
    char    close               [   8];    char    _close               ;    // [long  ,    8] ���������                      StartPos 95, Length 8
    char    recdiff             [   6];    char    _recdiff             ;    // [float ,  6.2] ����ϵ����                    StartPos 104, Length 6
    char    shcode              [   6];    char    _shcode              ;    // [string,    6] �����ڵ�                        StartPos 111, Length 6
} t1403OutBlock1, *LPt1403OutBlock1;
#define NAME_t1403OutBlock1     "t1403OutBlock1"

#pragma pack( pop )
///////////////////////////////////////////////////////////////////////////////////////////////////

#endif // _t1403_H_
