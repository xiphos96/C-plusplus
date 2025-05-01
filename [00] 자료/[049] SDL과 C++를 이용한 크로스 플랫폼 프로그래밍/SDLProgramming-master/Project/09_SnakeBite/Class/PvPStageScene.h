/** 
	@file	PvPStageScene.h
	@date	2013-03-03
	@author ����ȯ(sim436@gmail.com)
	@brief	Sanke ���ӿ��� ��������� Scene Ŭ����
*/

#pragma once
#include "common.h"
#include "IScene.h"
class Game;
class SnakeMap;
class Wall;
class ItemManager;
class Snake;
class TextFieldFactory;

class PvPStageScene : public IScene<Game*>
{
private:
	SnakeMap	*snakeMap;
	Wall		*wall;
	ItemManager	*itemMgr;
	Snake		*snake_1p;
	Snake		*snake_2p;

	SDL_Event	event;

	SDL_Surface *tailCountLabel_1p;
	SDL_Surface *tailCountLabel_2p;

public:
	static PvPStageScene* Shaerd()
	{
		static PvPStageScene* instance = NULL;
		if( instance == NULL )
		{
			instance = new PvPStageScene();
		}
		return instance;
	}

	virtual void Init(Game* owner);
	virtual void Execute(Game* owner);
	virtual void Exit(Game* owner);

	virtual void Input(Game* owner);
	virtual void Update(Game* owner);
	virtual void Rendder(Game* owner);

private:
	PvPStageScene() {}
	~PvPStageScene() {}
};
