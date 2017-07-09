#pragma once

#include "playerNode.h"
#include "animation.h"
#include "timer.h"
#include "heavySkill.h"
#include <vector>


class heavy : public playerNode
{
private:

	//이미지와 애니메이션은 플레이어 클래스에서 선언합니다
	image* _idle;
	animation* _idleani;
	image* _hit1;
	animation* _hit1ani;
	image* _hit2;
	animation* _hit2ani;
	image* _standing;
	animation* _standingani;

	image* _walk;
	animation* _walkani;

	image* _backwalk;
	animation* _backwalkani;
	image* _crouch;
	animation* _crouchani;
	image* _jump;
	animation* _jumpani;

	image* _punchImage;
	animation* _punchAni;
	image* _CpunchImage;
	animation* _CpunchAni;
	image* _JpunchImage;
	animation* _JpunchAni;
	image* _kickImage;
	animation* _kickAni;
	image* _CkickImage;
	animation* _CkickAni;
	image* _JkickImage;
	animation* _JkickAni;
	image* _skill1Image;
	animation* _skill1Ani;
	image* _skill1effect;
	animation* _skill1effectAni;
	image* _skill2Image;
	animation* _skill2Ani;
	image* _skill2effect;
	animation* _skill2effectAni;
	image* _skill3Image;
	animation* _skill3Ani;
	image* _skill3effect;
	animation* _skill3effectAni;

	//펀치선언 (마치 총알처럼)
	skillPunch* _punch;
	skillKick* _kick;
	skillCpunch* _Cpunch;
	skillCkick* _Ckick;
	skillJpunch* _Jpunch;
	skillJkick* _Jkick;
	skill1st* _skill1;
	skill2nd* _skill2;
	skill3rd* _skill3;


	vector<BYTE> _vCOMMAND;

	float _fCommandTime;
	float _fCommandClear;

	//애니메이션 중복 x 함수들
	int hit1int;
	int hit2int;
	int standingint;


public:
	virtual HRESULT init(bool isPlayer1, float playerX, float playerY, float playerWidth, float playerHeight, int upKey, int downKey, int leftKey, int rightKey, int punchKey, int kickKey, int Num);
	virtual void release();
	virtual void update();
	virtual void render();

	//키 컨트롤 함수 (업데이트에 들어감)
	virtual void keyControl();

	//스테이트 컨트롤 함수 (업데이트에 들어감)
	virtual void stateControl();


	
	heavy();
	~heavy();
};

