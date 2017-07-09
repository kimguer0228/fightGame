#pragma once
#include "gameNode.h"
#include "progressBar.h"
#include "playerNode.h"
#include "heavy.h"

class Scene3 : public gameNode
{
private :
	image* _background;
	progressBar* _PlayerHP[2];
	playerNode* Player1;
	playerNode* Player2;

public:
	HRESULT init();
	void release();
	void update();
	void render();


	Scene3();
	~Scene3();
};

