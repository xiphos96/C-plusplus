/** 
	@file	GameOverScene.h
	@date	2013-03-03
	@author ����ȯ(sim436@gmail.com)
	@brief	���ӿ��� Scene Ŭ����.
*/

#pragma once
#include "Common.h"
#include "IScene.h"
class Game;
class GameOverScene : public IScene<Game*>
{
private:
	SDL_Event event;
	SDL_Surface* bg;
public:
	static GameOverScene* Shaerd()
	{
		static GameOverScene* instance = 0;
		if( instance == 0 )
		{
			instance = new GameOverScene();
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
	GameOverScene();
	~GameOverScene() {}
};