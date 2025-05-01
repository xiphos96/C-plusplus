/** 
	@file	Stage01Scene.h
	@date	2013-03-03
	@author ����ȯ(sim436@gmail.com)
	@brief	Sanke ���ӿ��� Stage 1 �� Scene Ŭ����
*/

#pragma once
#include "ISnakeSingleScene.h"
class Stage01Scene : public ISnakeSingleScene
{
public:
	static Stage01Scene* Shaerd()
	{
		static Stage01Scene* instance = NULL;
		if( instance == NULL )
		{
			instance = new Stage01Scene();
		}
		return instance;
	}

	virtual void Init(Game* owner);
	virtual void Execute(Game* owner);
	virtual void Exit(Game* owner);

private:
	Stage01Scene() {}
	~Stage01Scene() {}
};
