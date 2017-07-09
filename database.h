#pragma once
#include "singletonBase.h"
#include <vector>
#include <map>

class intData
{
public :
	int CharacterNumber;	//ĳ���͹�ȣ
	bool Player1;			//1p ����

	intData();
	~intData();
};

class database : public singletonBase<database>
{
private:
	std::vector<intData*> Playerinfo; //���庤��

	

public:
	HRESULT init();
	void release();

	void Makedatapushback(int Num, bool A);							//Ǫ�ù� �Լ�
	std::vector<intData*> getinfo(void) { return Playerinfo; }		//���� ����

	database();
	~database();
};

