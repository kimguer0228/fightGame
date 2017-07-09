#include "stdafx.h"
#include "progressBar.h"


progressBar::progressBar()
{
}


progressBar::~progressBar()
{

}

HRESULT progressBar::init(int x, int y, int width, int height)
{
	_x = x;
	_y = y;
	_widthtop = _widthbottom = width;
	_height = height;

	_rcProgress = RectMake(x, y, width, height);

	_progressBarTop = IMAGEMANAGER->addImage("frontBar", "hpBarTop.bmp", x, y, width, height, true, RGB(255, 0, 255));
	_progressBarBottom = IMAGEMANAGER->addImage("backBar", "hpBarBottom.bmp", x, y, width, height, true, RGB(255, 0, 255));

	return S_OK;
}

void progressBar::release()
{

}

void progressBar::update()
{
	_rcProgress = RectMake(_x, _y, _widthbottom, _height);
}

void progressBar::render()
{
	IMAGEMANAGER->render("backBar", getMemDC(),
		_rcProgress.left,
		_y,
		0, 0,
		_widthbottom, _height);

	IMAGEMANAGER->render("frontBar", getMemDC(),
		_rcProgress.left,
		_y,
		0, 0,
		_widthtop, _height);
}

void progressBar::render2()
{
	IMAGEMANAGER->render("backBar", getMemDC(),
		_rcProgress.left,
		_y,
		0, 0,
		_widthbottom, _height);

	IMAGEMANAGER->render("frontBar", getMemDC(),
		_rcProgress.left + (_widthbottom - _widthtop),
		_y,
		0, 0,
		_widthtop, _height);
}


void progressBar::setGauge(float currentGauge, float maxGauge)
{
	_widthtop = (currentGauge / maxGauge) * _widthbottom;
}
