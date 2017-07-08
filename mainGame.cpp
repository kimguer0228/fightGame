#include "stdafx.h"
#include "mainGame.h"

//======================================
// 생성자랑 소멸자는 쓰지 않는다
//======================================
mainGame::mainGame()
{
}


mainGame::~mainGame()
{
}


//======================================
// 생성자랑 소멸자는 쓰지 않는다
//======================================


//초기화는 앞으로 여기에다가 해라
HRESULT mainGame::init(void)
{
	gameNode::init(true);

	IMAGEMANAGER->addImage("Scene1_image", "Scene1_image.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	
	IMAGEMANAGER->addImage("Scene2_image", "SelectBackground.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Scene2_Select", "선택창프레임.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Scene2_Select2", "선택창프레임2.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Scene2_King", "킹얼굴.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Scene2_Reona", "레오나얼굴.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Scene2_Yuri", "유리얼굴.bmp", 100, 100, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Scene2_HeavyD", "헤비디얼굴.bmp", 100, 100, true, RGB(255, 0, 255));


	SCENEMANAGER->addScene("Scene1", new Scene1);
	SCENEMANAGER->addScene("Scene2", new Scene2);
	SCENEMANAGER->addScene("Scene3", new Scene3);

<<<<<<< HEAD
	SCENEMANAGER->changeScene("Scene1");
=======
	SCENEMANAGER->changeScene("셀렉트씬");
	
	//김태완다녀감
	//석예솔다녀감
>>>>>>> 4619e612b9de549ed5a9150780ba52860183d953

	return S_OK;
}

//메모리 해제는 앞으로 여기에다가 해라
void mainGame::release(void)
{
	gameNode::release();

}

//연산은(는) 앞으로 여기에다가 해라
void mainGame::update(void)
{
	gameNode::update();

	SCENEMANAGER->update();
	
	if (SCENEMANAGER->getCS() == SCENEMANAGER->findScene("Scene1"))
	{
		if (KEYMANAGER->isOnceKeyDown(VK_F1)) SCENEMANAGER->changeScene("Scene2");
	}
}

//앞으로 여기에다 그려라 
void mainGame::render(void)
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//================ 위에 건들지마라 ================
 
	SCENEMANAGER->render();

	//===============아래도 건들지마라 =================
	this->getBackBuffer()->render(getHDC(), 0, 0);
}
