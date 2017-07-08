#include "stdafx.h"
#include "Scene1.h"


Scene1::Scene1()
{
}


Scene1::~Scene1()
{
}

HRESULT Scene1::init()
{

	return S_OK;
}

void Scene1::release()
{

}

void Scene1::update()
{

}

void Scene1::render()
{
	IMAGEMANAGER->findImage("Scene1_image")->render(getMemDC(), 0, 0);
}