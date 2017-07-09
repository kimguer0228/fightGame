#pragma once
#include "playerNode.h"
#include <vector>

class leona : public playerNode
{
private:
	//animation* _idleAni;
	//animation* _hit1Ani;
	//animation* _hit2Ani;
	//animation* _standingAni;

	//animation* _walkAni;

	//animation* _backwalkAni;
	//animation* _crouchAni;
	//animation* _jumpAni;

	//animation* _punchAni;
	//animation* _CpunchAni;
	//animation* _JpunchAni;
	//animation* _kickAni;
	//animation* _CkickAni;
	//animation* _JkickAni;
	//animation* _skill1Ani;
	//animation* _skill2Ani;
	//animation* _skill3Ani;


	animation* _effectAni; //��ų3 ����Ʈ �ִϸ��̼�

	float _commandTime;	//Ŀ�ǵ� �ҿ�ð�
	float _resetTime;	//Ŀ�ǵ� ���� �ð�

	vector<BYTE> _vCommand;

	//�ִϸ��̼� �ߺ� x �Լ���
	int hit1int;
	int hit2int;
	int standingint;

public:
	virtual HRESULT init(bool isPlayer1, float playerX, float playerY, float playerWidth, float playerHeight, int upKey, int downKey, int leftKey, int rightKey, int punchKey, int kickKey, int Num);
	virtual void release();
	virtual void update();
	virtual void render();

	void keyControl();
	void stateControl();
	void setImage();

	~leona();
	leona();
};

