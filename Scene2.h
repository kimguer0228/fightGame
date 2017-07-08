#pragma once
#include "gameNode.h"
#define CHARNUM 4

struct tagSlot
{
	image* Slotimage;
	RECT rcSlot;
	int CharacterNumber;
};

struct tagSelect
{
	int SlotNum;
	RECT rcSelect;
	int CharacterNumber2;
};

class Scene2 : public gameNode
{
private:
	tagSlot _Slot[CHARNUM];
	tagSelect _Select[2];

public:
	HRESULT init();
	void release();
	void update();
	void render();

	void SelectChar();

	Scene2();
	~Scene2();
};

