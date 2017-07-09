#include "stdafx.h"
#include "Scene3.h"


Scene3::Scene3()
{
}


Scene3::~Scene3()
{
}


HRESULT Scene3::init()
{
	_background = new image;
	_background = IMAGEMANAGER->findImage("Scene3_image");

	for (int i = 0; i < DATABASE->getinfo().size(); i++)
	{
		if (DATABASE->getinfo()[i]->Player1)
		{
			Player1 = new heavy;	//플레이어 노드를 캐릭터번호에 맞는거로
			Player1->init(true, WINSIZEX / 4, WINSIZEY - 50, 50, 200, VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT, 'A', 'S', DATABASE->getinfo()[i]->CharacterNumber);
		}
		else
		{
			Player2 = new heavy;	//여기도 마찬가지
			Player2->init(false, WINSIZEX * 3 / 4 - 50, WINSIZEY - 50, 50, 200, VK_NUMPAD8, VK_NUMPAD5, VK_NUMPAD4, VK_NUMPAD6, VK_INSERT, VK_HOME, DATABASE->getinfo()[i]->CharacterNumber);
		}
	}

	_PlayerHP[0] = new progressBar;
	_PlayerHP[0]->init(10, 10, 350, 30);
	_PlayerHP[1] = new progressBar;
	_PlayerHP[1]->init(WINSIZEX - 10 - 350, 10, 350, 30);

	return S_OK;
}
void Scene3::release()	  
{
	Player1->release();
	Player2->release();
}
void Scene3::update()
{
	Player1->update();
	Player2->update();
	_PlayerHP[0]->setGauge(Player1->getcurrentHP(), Player1->getmaxHP());
	_PlayerHP[1]->setGauge(Player2->getcurrentHP(), Player2->getmaxHP());
	if (KEYMANAGER->isOnceKeyDown('L'))
	{
		Player1->getdamage(10);
		Player2->getdamage(10);
	}
}

void Scene3::render()	  
{
	_background->render(getMemDC(), 0, 0, 600, 0, WINSIZEX, WINSIZEY);
	Player1->render();
	Player2->render();
	_PlayerHP[0]->render();
	_PlayerHP[1]->render2();
}