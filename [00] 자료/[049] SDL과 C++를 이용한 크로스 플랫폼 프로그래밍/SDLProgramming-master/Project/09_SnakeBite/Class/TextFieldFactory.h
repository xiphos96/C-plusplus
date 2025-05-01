/** 
	@file	TextFieldFactory.h
	@date	2013-03-03
	@author ����ȯ(sim436@gmail.com)
	@brief	SDL ���̺귯������ TextƲ ���� ���� Surface�� ������ִ� Ŭ����.
*/

#pragma once
#include "common.h"

class TextFieldFactory
{
public:
	static TextFieldFactory* Shared();
	SDL_Surface* CreateTextFieldSurface(char* text, int fontsize=15, int r=0, int g =0, int b=0);
	std::string StringAndInt(std::string str, int number);

private:
	TTF_Font *font;

	TextFieldFactory(void) {}
	~TextFieldFactory(void) {}
};

