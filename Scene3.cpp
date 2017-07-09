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

	CameraX = 600;

	for (int i = 0; i < DATABASE->getinfo().size(); i++)
	{
		if (DATABASE->getinfo()[i]->Player1)
		{
			if (DATABASE->getinfo()[i]->CharacterNumber == 3)
			{
				Player[0] = new heavy;	//플레이어 노드를 캐릭터번호에 맞는거로
				Player[0]->init(true, WINSIZEX / 4, WINSIZEY - 50, 50, 200, VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT, 'A', 'S', DATABASE->getinfo()[i]->CharacterNumber);
			}
			else if (DATABASE->getinfo()[i]->CharacterNumber == 1)
			{
				Player[0] = new leona;
				Player[0]->init(true, WINSIZEX / 4, WINSIZEY - 50, 50, 200, VK_UP, VK_DOWN, VK_LEFT, VK_RIGHT, 'A', 'S', DATABASE->getinfo()[i]->CharacterNumber);
			}
		}
		else
		{
			Player[1] = new heavy;	//여기도 마찬가지
			Player[1]->init(false, WINSIZEX * 3 / 4 - 50, WINSIZEY - 50, 50, 200, VK_NUMPAD8, VK_NUMPAD5, VK_NUMPAD4, VK_NUMPAD6, VK_INSERT, VK_HOME, DATABASE->getinfo()[i]->CharacterNumber);
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
	Player[0]->release();
	Player[1]->release();
}
void Scene3::update()
{
	Player[0]->update();
	Player[1]->update();
	_PlayerHP[0]->setGauge(Player[0]->getcurrentHP(), Player[0]->getmaxHP());
	_PlayerHP[1]->setGauge(Player[1]->getcurrentHP(), Player[1]->getmaxHP());
	if (KEYMANAGER->isOnceKeyDown('L'))
	{
		Player[0]->getdamage(10);
		Player[1]->getdamage(10);
	}

	if (Player[0]->getX() <Player[1]->getX())
	{
		Player[0]->setisRight(true);
		Player[1]->setisRight(false);
	}
	else
	{
		Player[0]->setisRight(false);
		Player[1]->setisRight(true);
	}

	setCamera();
	if (CameraX < 4) CameraX = 0;
	else if (CameraX > 1800 - WINSIZEX - 4) CameraX = 1800 - WINSIZEX;

}

void Scene3::render()	  
{
	_background->render(getMemDC(), 0, 0, CameraX, 0, WINSIZEX, WINSIZEY);
	Player[0]->render();
	Player[1]->render();
	_PlayerHP[0]->render();
	_PlayerHP[1]->render2();
}

void Scene3::setCamera()
{
	int width;

	int speedincamera = 1;
	if (CameraX == 0 || CameraX == 1800 - WINSIZEX)
	{
		speedincamera = 0;
		return;
	}

	for (int i = 0; i < 2; i++)
	{
		width = Player[i]->getRect().right - Player[i]->getRect().left;
		if (Player[i]->getisRight() && Player[i]->getX() < width)
		{
			Player[i]->setX(width);
			CameraX += Player[i]->getSpeed();
			if (i == 0 && Player[1]->getX() < WINSIZEX - width) Player[1]->setX(Player[1]->getX() + speedincamera);
			if (i == 1 && Player[0]->getX() < WINSIZEX - width) Player[0]->setX(Player[0]->getX() + speedincamera);
			Player[0]->setSpeed0();
			Player[1]->setSpeed0();
		}		
		if (!Player[i]->getisRight() && Player[i]->getX() > WINSIZEX - width)
		{
			Player[i]->setX(WINSIZEX - width);
			CameraX += Player[i]->getSpeed();
			if (i == 0 && Player[1]->getX() > width) Player[1]->setX(Player[1]->getX() - speedincamera);
			if (i == 1 && Player[1]->getX() > width) Player[0]->setX(Player[0]->getX() - speedincamera);
			Player[0]->setSpeed0();
			Player[1]->setSpeed0();
		}
	}
}