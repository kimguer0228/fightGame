#include "stdafx.h"
#include "mainGame.h"

//======================================
// �����ڶ� �Ҹ��ڴ� ���� �ʴ´�
//======================================
mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}


//======================================
// �����ڶ� �Ҹ��ڴ� ���� �ʴ´�
//======================================


//�ʱ�ȭ�� ������ ���⿡�ٰ� �ض�
HRESULT mainGame::init(void)
{
	gameNode::init(true);

	IMAGEMANAGER->addImage("Scene1_image", "Scene1_image.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	
	IMAGEMANAGER->addImage("Scene2_image", "SelectBackground.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Scene2_Select", "����â������.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Scene2_Select2", "����â������2.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Scene2_King", "ŷ��.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Scene2_Reona", "��������.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Scene2_Yuri", "������.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Scene2_HeavyD", "�����.bmp", 100, 100, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("Scene3_image", "Scene3_image.bmp", 1800, 600, false, RGB(255, 0, 255));

	SCENEMANAGER->addScene("Scene1", new Scene1);
	SCENEMANAGER->addScene("Scene2", new Scene2);
	SCENEMANAGER->addScene("Scene3", new Scene3);


	SCENEMANAGER->changeScene("Scene1");

	SCENEMANAGER->changeScene("����Ʈ��");
	
	//���¿ϴٳన
	//�����ִٳన


	return S_OK;
}

//�޸� ������ ������ ���⿡�ٰ� �ض�
void mainGame::release(void)
{
	gameNode::release();

}

//������(��) ������ ���⿡�ٰ� �ض�
void mainGame::update(void)
{
	gameNode::update();

	SCENEMANAGER->update();
	
	if (SCENEMANAGER->getCS() == SCENEMANAGER->findScene("Scene1"))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_F1)) SCENEMANAGER->changeScene("Scene2");
	}
	if (SCENEMANAGER->getCS() == SCENEMANAGER->findScene("Scene2"))
	{
		if (DATABASE->getinfo().size() == 2) SCENEMANAGER->changeScene("Scene3");
	}
}

//������ ���⿡�� �׷��� 
void mainGame::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================ ���� �ǵ������� ================
 
	SCENEMANAGER->render();

	//===============�Ʒ��� �ǵ������� =================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
