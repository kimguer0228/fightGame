#pragma once
#include "playerNode.h"
#include <vector>
#include "leonaSkill.h"

class leona : public playerNode
{
private:
	animation* _effectAni; //스킬3 이펙트 애니메이션

	float _commandTime;	//커맨드 소요시간
	float _resetTime;	//커맨드 리셋 시간

	vector<BYTE> _vCommand;

	leonaPunch* _punch;
	leonaKick* _kick;
	leonaCpunch* _Cpunch;
	leonaCkick* _Ckick;
	leonaJpunch* _Jpunch;
	leonaJkick* _Jkick;
	leonaSkill1* _skill1;
	leonaSkill2* _skill2;
	leonaSkill3* _skill3;


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

