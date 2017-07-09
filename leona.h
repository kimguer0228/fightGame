#pragma once
#include "playerNode.h"
#include <vector>

class leona : public playerNode
{
private:
	animation* _effectAni; //스킬3 이펙트 애니메이션
	animation* _ani;

	float _commandTime;	//커맨드 소요시간
	float _resetTime;	//커맨드 리셋 시간

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

