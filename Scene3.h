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
	playerNode* Player[2];

	float CameraX;
public:
	HRESULT init();
	void release();
	void update();
	void render();

	void setCamera();

	Scene3();
	~Scene3();
};

