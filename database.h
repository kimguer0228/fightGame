#pragma once
#include "singletonBase.h"
#include <vector>
#include <map>

class intData
{
public :
	int CharacterNumber;	//캐릭터번호
	bool Player1;			//1p 여부

	intData();
	~intData();
};

class database : public singletonBase<database>
{
private:
	std::vector<intData*> Playerinfo; //저장벡터

	

public:
	HRESULT init();
	void release();

	void Makedatapushback(int Num, bool A);							//푸시백 함수
	std::vector<intData*> getinfo(void) { return Playerinfo; }		//벡터 접근

	database();
	~database();
};

