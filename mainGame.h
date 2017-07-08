#pragma once
#include "gameNode.h"
#include "Scene1.h"
#include "Scene2.h"
#include "Scene3.h"

class mainGame : public gameNode
{
private:

public:
	virtual HRESULT init(void);		
	virtual void release(void);		
	virtual void update(void);		
	virtual void render(void);

	

	mainGame();
	~mainGame();
};

