#pragma once
#include "playerNode.h"
#include <vector>

class leona : public playerNode
{
private:
	animation* _effectAni; //��ų3 ����Ʈ �ִϸ��̼�
	animation* _ani;

	float _commandTime;	//Ŀ�ǵ� �ҿ�ð�
	float _resetTime;	//Ŀ�ǵ� ���� �ð�

	vector<BYTE> _vCommand;

public:
	virtual HRESULT init(bool isPlayer1, float playerX, float playerY, float playerWidth, float playerHeight, int upKey, int downKey, int leftKey, int rightKey, int punchKey, int kickKey, int Num);
	virtual void release();
	virtual void update();
	virtual void render();

	void keyControl();
	void setImage();

	~leona();
	leona();
};

