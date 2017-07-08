#pragma once
#include "gameNode.h"

class Scene1 : public gameNode
{
private :


public:
	HRESULT init();
	void release();
	void update();
	void render();

	

	Scene1();
	~Scene1();
};

