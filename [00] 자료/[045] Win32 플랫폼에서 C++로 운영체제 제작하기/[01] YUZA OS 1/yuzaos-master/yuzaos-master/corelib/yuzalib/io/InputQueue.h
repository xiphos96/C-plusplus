#pragma once

#pragma pack( push, 1 )

// 큐에 대한 구조체
typedef struct kQueueManagerStruct
{
    // 큐를 구성하는 데이터 하나의 크기와 최대 개수
    int iDataSize;
    int iMaxDataCount;

    // 큐 버퍼의 포인터와 삽입/제거 인덱스
    void* pvQueueArray;
    int iPutIndex;
    int iGetIndex;
    
    // 큐에 수행된 마지막 명령이 삽입인지를 저장
    bool bLastOperationPut;
} QUEUE;

#pragma pack( pop )

void kInitializeQueue( QUEUE* pstQueue, void* pvQueueBuffer, int iMaxDataCount, 
		int iDataSize );
bool kIsQueueFull( const QUEUE* pstQueue );
bool kIsQueueEmpty( const QUEUE* pstQueue );
bool kPutQueue( QUEUE* pstQueue, const void* pvData );
bool kGetQueue( QUEUE* pstQueue, void* pvData );
