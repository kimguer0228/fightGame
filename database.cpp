#include "stdafx.h"
#include "database.h"

intData::intData(){}
intData::~intData(){}

database::database()
{
}


database::~database()
{

}

HRESULT database::init()
{
	Playerinfo.clear();

	return S_OK;
}

void database::release()
{

}

void database::Makedatapushback(int Num, bool A)
{
	intData* _data = new intData;
	_data->CharacterNumber = Num;
	_data->Player1 = A;
	Playerinfo.push_back(_data);
}