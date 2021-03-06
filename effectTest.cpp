#include "stdafx.h"
#include "effectTest.h"


effectTest::effectTest()
{
}


effectTest::~effectTest()
{
}

HRESULT effectTest::init()
{
	IMAGEMANAGER->addImage("폭발", "explosion.bmp", 832, 62, true, RGB(255, 0, 255));


	_effect = new effect;
	_effect->init(IMAGEMANAGER->findImage("폭발"), 32, 62, 1, 1.0f);

	//이펙트 이름, 이펙트이미지 이름,이미지 가로, 세로크기, 이펙트 가로 세로
	EFFECTMANAGER->addEffect("explosion", "explosion.bmp", 832, 62, 32, 62, 1, 1.0f, 100);

	_count = 0;



	return S_OK;
}

void effectTest::release()
{

}

void effectTest::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		_effect->startEffect(_ptMouse.x, _ptMouse.y);
	}

	if (KEYMANAGER->isStayKeyDown(VK_RBUTTON))
	{
		EFFECTMANAGER->play("explosion", _ptMouse.x, _ptMouse.y);
	}

	_count++;

	if (_count % 5 == 0)
	{
		EFFECTMANAGER->play("explosion", RND->getFromIntTo(100, 200), RND->getFromIntTo(100, 200));

		_count = 0;
	}


	_effect->update();
	EFFECTMANAGER->update();
}

void effectTest::render()
{

	_effect->render();
	EFFECTMANAGER->render();
}
