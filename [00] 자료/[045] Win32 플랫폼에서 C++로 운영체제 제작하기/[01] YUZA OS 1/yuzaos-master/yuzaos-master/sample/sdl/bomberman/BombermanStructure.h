#pragma once
#include "GameConstant.h"

typedef struct tag_EdgeInfo
{
	int from;
	int to;
}EdgeInfo;

typedef struct tag_NodeInfo
{
	float x;
	float y;
	int id;
}NodeInfo;

typedef struct tag_PlayerStatInfo
{
	int maxBombCount;
	int currentBombCount;
	int bombPower;
	int bombType;

	tag_PlayerStatInfo()
	{
		maxBombCount = 1; //�÷��̾ ��ġ�� �� �ִ� ��ź�� �ִ� ��
		currentBombCount = 0; //�÷��̾ �ʵ忡 ��ġ�� ��ź ��
		bombPower = 1; //��ź�� �Ŀ�. 
		bombType = 0;//��ź�� Ÿ�� 0 : �Ϲ�, 1 TNT
	}

}PlayerStatInfo;