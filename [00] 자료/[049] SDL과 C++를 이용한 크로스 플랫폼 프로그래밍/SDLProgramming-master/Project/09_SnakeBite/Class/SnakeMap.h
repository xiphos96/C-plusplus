/** 
	@file	SnakeMap.h
	@date	2013-03-03
	@author ����ȯ(sim436@gmail.com)
	@brief	������ ��� ������Ʈ�� ������ Ÿ���� ������ ������ �ִ� Ŭ����
*/

#pragma once
#include "common.h"
class SnakeMap
{
private:
	int width_;  ///< Ÿ���� ���� ����
	int height_; ///< Ÿ���� ���α���
	std::vector<std::vector<char>> tilesInfo_; ///< tilesInfo_[height][widht] 2�����迭

public:
	SnakeMap(int width, int height);
	~SnakeMap();

	char TilesInfoOfIndex(int x, int y) const;
	void SetTilesInfoOfIndex(int x, int y, char ch);
	int Width() const;
	int Height() const;
};

