#pragma once
#include "gameNode.h"
#include "ship.h"
#include "playerNode.h"

class battle;
class dummy;

class starcraftScene : public gameNode
{
private:
	ship* _battle;
	playerNode* player1;

public:
	HRESULT init();
	void release();
	void update();
	void render();


	starcraftScene();
	~starcraftScene();
};

