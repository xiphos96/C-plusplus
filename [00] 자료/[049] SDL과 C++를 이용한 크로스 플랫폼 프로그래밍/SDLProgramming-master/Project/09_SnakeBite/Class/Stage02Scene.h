/** 
	@file	Stage02Scene.h
	@date	2013-03-03
	@author ����ȯ(sim436@gmail.com)
	@brief	Sanke ���ӿ��� Stage 2 �� Scene Ŭ����
*/

#pragma once
#include "ISnakeSingleScene.h"
class Stage02Scene : public ISnakeSingleScene
{
public:
	static Stage02Scene* Shaerd()
	{
		static Stage02Scene* instance = NULL;
		if( instance == NULL )
		{
			instance = new Stage02Scene();
		}
		return instance;
	}

	virtual void Init(Game* owner);
	virtual void Execute(Game* owner);
	virtual void Exit(Game* owner);

private:
	Stage02Scene() {}
	~Stage02Scene() {}
};
