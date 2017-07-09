#pragma once
#include "gameNode.h"

#define CHARNUM 4	//캐릭터수

struct tagSlot		//선택창
{
	image* Slotimage;
	RECT rcSlot;
	int CharacterNumber;
};

struct tagSelect	//플레이어가 고른 캐릭터
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

