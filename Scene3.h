#pragma once
#include "gameNode.h"

class Scene3 : public gameNode
{
private :
	

public:
	HRESULT init();
	void release();
	void update();
	void render();


	Scene3();
	~Scene3();
};

