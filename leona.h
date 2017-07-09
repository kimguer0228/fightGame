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


	animation* _effectAni; //스킬3 이펙트 애니메이션

	float _commandTime;	//커맨드 소요시간
	float _resetTime;	//커맨드 리셋 시간

	vector<BYTE> _vCommand;

	//애니메이션 중복 x 함수들
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

