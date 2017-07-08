#include "stdafx.h"
#include "Scene2.h"



Scene2::Scene2()
{
}


Scene2::~Scene2()
{
}


HRESULT Scene2::init()
{
	for (int i = 0; i < CHARNUM; i++)
	{
		_Slot[i].CharacterNumber = i;
		_Slot[i].rcSlot.left = 100 + (WINSIZEX-200) * i / CHARNUM + 5;
		_Slot[i].rcSlot.right = _Slot[i].rcSlot.left + 100;
		_Slot[i].rcSlot.top = WINSIZEY * 3 / 4;
		_Slot[i].rcSlot.bottom = WINSIZEY * 3 / 4 + 100;
		_Slot[i].Slotimage = new image;
	}

	_Slot[0].Slotimage = IMAGEMANAGER->findImage("Scene2_King");
	_Slot[1].Slotimage = IMAGEMANAGER->findImage("Scene2_Reona");
	_Slot[2].Slotimage = IMAGEMANAGER->findImage("Scene2_Yuri");
	_Slot[3].Slotimage = IMAGEMANAGER->findImage("Scene2_HeavyD");

	_Select[0].rcSelect = _Slot[0].rcSlot;
	_Select[0].SlotNum = 0;
	_Select[0].CharacterNumber2 = CHARNUM;
	_Select[1].rcSelect = _Slot[CHARNUM - 1].rcSlot;
	_Select[1].SlotNum = CHARNUM - 1;
	_Select[1].CharacterNumber2 = CHARNUM;

	return S_OK;
}

void Scene2::release()
{


}

void Scene2::update()
{
	SelectChar();
}

void Scene2::render()
{
	IMAGEMANAGER->findImage("Scene2_image")->alphaRender(getMemDC(), 0, 0, 200);
	for (int i = 0; i < 2; i++)
	{
		IMAGEMANAGER->findImage("Scene2_Select")->render(getMemDC(), _Select[i].rcSelect.left, _Select[i].rcSelect.top);
	}

	for (int i = 0; i < CHARNUM; i++)
	{
		_Slot[i].Slotimage->render(getMemDC(), _Slot[i].rcSlot.left, _Slot[i].rcSlot.top);
		IMAGEMANAGER->findImage("Scene2_Select2")->render(getMemDC(), _Slot[i].rcSlot.left, _Slot[i].rcSlot.top);
	}

}

void Scene2::SelectChar()
{
	if (_Select[0].CharacterNumber2 == CHARNUM)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT)) (_Select[0].SlotNum != 0) ?
			(_Select[0].rcSelect = _Slot[_Select[0].SlotNum - 1].rcSlot, _Select[0].SlotNum -= 1) :
			(_Select[0].rcSelect = _Slot[CHARNUM - 1].rcSlot, _Select[0].SlotNum = CHARNUM - 1);
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) (_Select[0].SlotNum != CHARNUM - 1) ?
			(_Select[0].rcSelect = _Slot[_Select[0].SlotNum + 1].rcSlot, _Select[0].SlotNum += 1) :
			(_Select[0].rcSelect = _Slot[0].rcSlot, _Select[0].SlotNum = 0);
		if (KEYMANAGER->isOnceKeyDown('A')) _Select[0].CharacterNumber2 = _Slot[_Select[0].SlotNum].CharacterNumber;
	}
	if (_Select[1].CharacterNumber2 == CHARNUM)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD4)) (_Select[1].SlotNum != 0) ?
			(_Select[1].rcSelect = _Slot[_Select[1].SlotNum - 1].rcSlot, _Select[1].SlotNum -= 1) :
			(_Select[1].rcSelect = _Slot[CHARNUM - 1].rcSlot, _Select[1].SlotNum = CHARNUM - 1);
		if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD6)) (_Select[1].SlotNum != CHARNUM - 1) ?
			(_Select[1].rcSelect = _Slot[_Select[1].SlotNum + 1].rcSlot, _Select[1].SlotNum += 1) :
			(_Select[1].rcSelect = _Slot[0].rcSlot, _Select[1].SlotNum = 0);
		if (KEYMANAGER->isOnceKeyDown(VK_INSERT)) _Select[1].CharacterNumber2 = _Slot[_Select[1].SlotNum].CharacterNumber;
	}
	
}