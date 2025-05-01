/** 
	@file	ISnakeSingleScene.h
	@date	2013-03-03
	@author ����ȯ(sim436@gmail.com)
	@brief	Sanke ���ӿ��� �̱۸���� Stage �� ���� �߻�Ŭ����
*/

#pragma once
#include "Common.h"
#include "IScene.h"
class Game;
class SnakeMap;
class Wall;
class ItemManager;
class Snake;
class TextFieldFactory;

class ISnakeSingleScene : public IScene<Game*>
{
protected:
	SnakeMap	*snakeMap;
	Wall		*wall;
	ItemManager	*itemMgr;
	Snake		*snake;

	SDL_Event	event;
	SDL_Surface *lifeLabel;
	SDL_Surface *tailCountLabel;

	int clear_tailCount;

public:
	virtual void Init(Game* owner) = 0;
	virtual void Execute(Game* owner) = 0;
	virtual void Exit(Game* owner) = 0;

protected:
	virtual void Input(Game* owner);
	virtual void Update(Game* owner);
	virtual void Rendder(Game* owner);
	void DrawTextFiledLabelWithValue(SDL_Surface* screen, std::string label, int value, int posx, int posy);
};
