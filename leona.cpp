#include "stdafx.h"
#include "leona.h"

leona::leona() {}
leona::~leona() {}

HRESULT leona::init(bool isPlayer1, float playerX, float playerY, float playerWidth, float playerHeight, int upKey, int downKey, int leftKey, int rightKey, int punchKey, int kickKey, int Num)
{
	playerNode::init(isPlayer1, playerX, playerY, playerWidth, playerHeight, upKey, downKey, leftKey, rightKey, punchKey, kickKey, Num);

	//이미지 추가
	IMAGEMANAGER->addFrameImage("LEONA_IDLE", "Leona/LEONA_IDLE.bmp", 7296, 1344, 8, 2, true, RGB(248, 0, 248));
	IMAGEMANAGER->addFrameImage("LEONA_WALK", "Leona/LEONA_WALK.bmp", 9120, 1344, 10, 2, true, RGB(248, 0, 248));
	IMAGEMANAGER->addFrameImage("LEONA_WALK_BACK", "Leona/LEONA_WALK_BACK.bmp", 7296, 1344, 8, 2, true, RGB(248, 0, 248));
	IMAGEMANAGER->addFrameImage("LEONA_PUNCH", "Leona/LEONA_PUNCH.bmp", 2736, 1344, 3, 2, true, RGB(248, 0, 248));
	IMAGEMANAGER->addFrameImage("LEONA_KICK", "Leona/LEONA_KICK.bmp", 5472, 1344, 6, 2, true, RGB(248, 0, 248));
	IMAGEMANAGER->addFrameImage("LEONA_JUMP", "Leona/LEONA_JUMP.bmp", 13680, 1344, 15, 2, true, RGB(248, 0, 248));
	IMAGEMANAGER->addFrameImage("LEONA_JUMP_PUNCH", "Leona/LEONA_JUMP_PUNCH.bmp", 5472, 1344, 6, 2, true, RGB(248, 0, 248));
	IMAGEMANAGER->addFrameImage("LEONA_JUMP_KICK", "Leona/LEONA_JUMP_KICK.bmp", 4560, 1344, 5, 2, true, RGB(248, 0, 248));
	IMAGEMANAGER->addFrameImage("LEONA_CROUCH", "Leona/LEONA_CROUCH.bmp", 7296, 1344, 8, 2, true, RGB(248, 0, 248));
	IMAGEMANAGER->addFrameImage("LEONA_CROUCH_PUNCH", "Leona/LEONA_CROUCH_PUNCH.bmp", 4560, 1344, 5, 2, true, RGB(248, 0, 248));
	IMAGEMANAGER->addFrameImage("LEONA_CROUCH_KICK", "Leona/LEONA_CROUCH_KICK.bmp", 3648, 1344, 4, 2, true, RGB(248, 0, 248));
	IMAGEMANAGER->addFrameImage("LEONA_HIT_1", "Leona/LEONA_HIT_1.bmp", 2736, 1344, 3, 2, true, RGB(248, 0, 248));
	IMAGEMANAGER->addFrameImage("LEONA_HIT_2", "Leona/LEONA_HIT_2.bmp", 5472, 1344, 6, 2, true, RGB(248, 0, 248));
	IMAGEMANAGER->addFrameImage("LEONA_SKILL_1", "Leona/LEONA_SKILL_1.bmp", 13680, 1344, 15, 2, true, RGB(248, 0, 248));
	IMAGEMANAGER->addFrameImage("LEONA_SKILL_2", "Leona/LEONA_SKILL_2.bmp", 11856, 1344, 13, 2, true, RGB(248, 0, 248));
	IMAGEMANAGER->addFrameImage("LEONA_SKILL_3", "Leona/LEONA_SKILL_3.bmp", 10032, 1344, 11, 2, true, RGB(248, 0, 248));
	IMAGEMANAGER->addFrameImage("LEONA_SKILL_3_EFFECT", "Leona/LEONA_SKILL_3_EFFECT.bmp", 14592, 1344, 16, 2, true, RGB(248, 0, 248));
	IMAGEMANAGER->addFrameImage("LEONA_STANDING", "Leona/LEONA_STANDING.bmp", 6384, 1344, 7, 2, true, RGB(248, 0, 248));

	_ani = new animation;
	_ani->init(IMAGEMANAGER->findImage("LEONA_IDLE")->getWidth(), IMAGEMANAGER->findImage("LEONA_IDLE")->getHeight(), IMAGEMANAGER->findImage("LEONA_IDLE")->getFrameWidth(), IMAGEMANAGER->findImage("LEONA_IDLE")->getFrameHeight());
	_ani->setPlayFrame(1, 7, false, true);
	_ani->start();
	_ani->setFPS(1);


	//애니메이션 추가
	_playerAni[idle] = new animation;
	_playerAni[idle]->init(IMAGEMANAGER->findImage("LEONA_IDLE")->getWidth(), IMAGEMANAGER->findImage("LEONA_IDLE")->getHeight(), IMAGEMANAGER->findImage("LEONA_IDLE")->getFrameWidth(), IMAGEMANAGER->findImage("LEONA_IDLE")->getFrameHeight());
	_playerAni[idle]->setPlayFrame(1, 7, false, true);
	_playerAni[idle]->start();
	_playerAni[idle]->setFPS(1);

	_playerAni[walk] = new animation;
	_playerAni[walk]->init(IMAGEMANAGER->findImage("LEONA_WALK")->getWidth(), IMAGEMANAGER->findImage("LEONA_WALK")->getHeight(), IMAGEMANAGER->findImage("LEONA_WALK")->getFrameWidth(), IMAGEMANAGER->findImage("LEONA_WALK")->getFrameHeight());
	_playerAni[walk]->setPlayFrame(0, 9, false, true);
	_playerAni[walk]->start();
	_playerAni[walk]->setFPS(1);

	_playerAni[backWalk] = new animation;
	_playerAni[backWalk]->init(IMAGEMANAGER->findImage("LEONA_WALK_BACK")->getWidth(), IMAGEMANAGER->findImage("LEONA_WALK_BACK")->getHeight(), IMAGEMANAGER->findImage("LEONA_WALK_BACK")->getFrameWidth(), IMAGEMANAGER->findImage("LEONA_WALK_BACK")->getFrameHeight());
	_playerAni[backWalk]->setPlayFrame(0, 7, false, true);
	_playerAni[backWalk]->start();
	_playerAni[backWalk]->setFPS(1);

	_playerAni[jump] = new animation;
	_playerAni[jump]->init(IMAGEMANAGER->findImage("LEONA_JUMP")->getWidth(), IMAGEMANAGER->findImage("LEONA_JUMP")->getHeight(), IMAGEMANAGER->findImage("LEONA_JUMP")->getFrameWidth(), IMAGEMANAGER->findImage("LEONA_JUMP")->getFrameHeight());
	_playerAni[jump]->setPlayFrame(0, 14);
	_playerAni[jump]->setFPS(1);

	_playerAni[crouch] = new animation;
	_playerAni[crouch]->init(IMAGEMANAGER->findImage("LEONA_CROUCH")->getWidth(), IMAGEMANAGER->findImage("LEONA_CROUCH")->getHeight(), IMAGEMANAGER->findImage("LEONA_CROUCH")->getFrameWidth(), IMAGEMANAGER->findImage("LEONA_CROUCH")->getFrameHeight());
	_playerAni[crouch]->setPlayFrame(0, 7);
	_playerAni[crouch]->setFPS(1);

	_playerAni[hit1] = new animation;
	_playerAni[hit1]->init(IMAGEMANAGER->findImage("LEONA_HIT_1")->getWidth(), IMAGEMANAGER->findImage("LEONA_HIT_1")->getHeight(), IMAGEMANAGER->findImage("LEONA_HIT_1")->getFrameWidth(), IMAGEMANAGER->findImage("LEONA_HIT_1")->getFrameHeight());
	_playerAni[hit1]->setPlayFrame(0, 2);
	_playerAni[hit1]->setFPS(1);

	_playerAni[hit2] = new animation;
	_playerAni[hit2]->init(IMAGEMANAGER->findImage("LEONA_HIT_2")->getWidth(), IMAGEMANAGER->findImage("LEONA_HIT_2")->getHeight(), IMAGEMANAGER->findImage("LEONA_HIT_2")->getFrameWidth(), IMAGEMANAGER->findImage("LEONA_HIT_2")->getFrameHeight());
	_playerAni[hit2]->setPlayFrame(0, 5);
	_playerAni[hit2]->setFPS(1);

	_playerAni[standing] = new animation;
	_playerAni[standing]->init(IMAGEMANAGER->findImage("LEONA_STANDING")->getWidth(), IMAGEMANAGER->findImage("LEONA_STANDING")->getHeight(), IMAGEMANAGER->findImage("LEONA_STANDING")->getFrameWidth(), IMAGEMANAGER->findImage("LEONA_STANDING")->getFrameHeight());
	_playerAni[standing]->setPlayFrame(0, 6);
	_playerAni[standing]->setFPS(1);

	_playerAni[punch] = new animation;
	_playerAni[punch]->init(IMAGEMANAGER->findImage("LEONA_PUNCH")->getWidth(), IMAGEMANAGER->findImage("LEONA_PUNCH")->getHeight(), IMAGEMANAGER->findImage("LEONA_PUNCH")->getFrameWidth(), IMAGEMANAGER->findImage("LEONA_PUNCH")->getFrameHeight());
	_playerAni[punch]->setPlayFrame(0, 2);
	_playerAni[punch]->setFPS(1);

	_playerAni[kick] = new animation;
	_playerAni[kick]->init(IMAGEMANAGER->findImage("LEONA_KICK")->getWidth(), IMAGEMANAGER->findImage("LEONA_KICK")->getHeight(), IMAGEMANAGER->findImage("LEONA_KICK")->getFrameWidth(), IMAGEMANAGER->findImage("LEONA_KICK")->getFrameHeight());
	_playerAni[kick]->setPlayFrame(0, 5);
	_playerAni[kick]->setFPS(1);

	_playerAni[jumpPunch] = new animation;
	_playerAni[jumpPunch]->init(IMAGEMANAGER->findImage("LEONA_JUMP_PUNCH")->getWidth(), IMAGEMANAGER->findImage("LEONA_JUMP_PUNCH")->getHeight(), IMAGEMANAGER->findImage("LEONA_JUMP_PUNCH")->getFrameWidth(), IMAGEMANAGER->findImage("LEONA_JUMP_PUNCH")->getFrameHeight());
	_playerAni[jumpPunch]->setPlayFrame(0, 5);
	_playerAni[jumpPunch]->setFPS(1);

	_playerAni[jumpKick] = new animation;
	_playerAni[jumpKick]->init(IMAGEMANAGER->findImage("LEONA_JUMP_KICK")->getWidth(), IMAGEMANAGER->findImage("LEONA_JUMP_KICK")->getHeight(), IMAGEMANAGER->findImage("LEONA_JUMP_KICK")->getFrameWidth(), IMAGEMANAGER->findImage("LEONA_JUMP_KICK")->getFrameHeight());
	_playerAni[jumpKick]->setPlayFrame(0, 4);
	_playerAni[jumpKick]->setFPS(1);

	_playerAni[crouchPunch] = new animation;
	_playerAni[crouchPunch]->init(IMAGEMANAGER->findImage("LEONA_CROUCH_KICK")->getWidth(), IMAGEMANAGER->findImage("LEONA_CROUCH_PUNCH")->getHeight(), IMAGEMANAGER->findImage("LEONA_CROUCH_PUNCH")->getFrameWidth(), IMAGEMANAGER->findImage("LEONA_CROUCH_PUNCH")->getFrameHeight());
	_playerAni[crouchPunch]->setPlayFrame(0, 4);
	_playerAni[crouchPunch]->setFPS(1);

	_playerAni[crouchKick] = new animation;
	_playerAni[crouchKick]->init(IMAGEMANAGER->findImage("LEONA_CROUCH_KICK")->getWidth(), IMAGEMANAGER->findImage("LEONA_CROUCH_KICK")->getHeight(), IMAGEMANAGER->findImage("LEONA_CROUCH_KICK")->getFrameWidth(), IMAGEMANAGER->findImage("LEONA_CROUCH_KICK")->getFrameHeight());
	_playerAni[crouchKick]->setPlayFrame(0, 3);
	_playerAni[crouchKick]->setFPS(1);

	_playerAni[skill1] = new animation;
	_playerAni[skill1]->init(IMAGEMANAGER->findImage("LEONA_SKILL_1")->getWidth(), IMAGEMANAGER->findImage("LEONA_SKILL_1")->getHeight(), IMAGEMANAGER->findImage("LEONA_SKILL_1")->getFrameWidth(), IMAGEMANAGER->findImage("LEONA_SKILL_1")->getFrameHeight());
	_playerAni[skill1]->setPlayFrame(0, 14);
	_playerAni[skill1]->setFPS(1);

	_playerAni[skill2] = new animation;
	_playerAni[skill2]->init(IMAGEMANAGER->findImage("LEONA_SKILL_2")->getWidth(), IMAGEMANAGER->findImage("LEONA_SKILL_2")->getHeight(), IMAGEMANAGER->findImage("LEONA_SKILL_2")->getFrameWidth(), IMAGEMANAGER->findImage("LEONA_SKILL_2")->getFrameHeight());
	_playerAni[skill2]->setPlayFrame(0, 12);
	_playerAni[skill2]->setFPS(1);

	_playerAni[skill3] = new animation;
	_playerAni[skill3]->init(IMAGEMANAGER->findImage("LEONA_SKILL_3")->getWidth(), IMAGEMANAGER->findImage("LEONA_SKILL_3")->getHeight(), IMAGEMANAGER->findImage("LEONA_SKILL_3")->getFrameWidth(), IMAGEMANAGER->findImage("LEONA_SKILL_3")->getFrameHeight());
	_playerAni[skill3]->setPlayFrame(0, 10);
	_playerAni[skill3]->setFPS(1);

	_effectAni = new animation;
	_effectAni->init(IMAGEMANAGER->findImage("LEONA_SKILL_3_EFFECT")->getWidth(), IMAGEMANAGER->findImage("LEONA_SKILL_3_EFFECT")->getHeight(), IMAGEMANAGER->findImage("LEONA_SKILL_3_EFFECT")->getFrameWidth(), IMAGEMANAGER->findImage("LEONA_SKILL_3_EFFECT")->getFrameHeight());
	_effectAni->setPlayFrame(0, 15);
	_effectAni->setFPS(1);


	//캐릭터 초기화
	_image = IMAGEMANAGER->findImage("LEONA_IDLE");


	_commandTime = 0;
	_resetTime = 2.5f;

	return S_OK;
}
void leona::release()
{

}
void leona::update()
{
	//keyControl();
	setImage();

	_playerAni[state]->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	_effectAni->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
}
void leona::render()
{
	_image->aniRender(getMemDC(), x - 456, y - 595, _ani);

	if (state == skill3)
	{
		IMAGEMANAGER->findImage("LEONA_SKILL_3_EFFECT")->aniRender(getMemDC(), x - 456, y - 595, _effectAni);
	}
}
void leona::keyControl()
{
	if (_vCommand.size() > 0) _commandTime += TIMEMANAGER->getElapsedTime() * 10;
	if (_commandTime > _resetTime)
	{
		_commandTime = 0;
		_vCommand.clear();
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_vCommand.push_back(_leftKey);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_vCommand.push_back(_rightKey);
	}

	//점프
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		if (state == idle || state == walk || state == backWalk)
		{
			state = jump;
			speedY -= 5;

			_playerAni[state]->start();
		}
		_vCommand.push_back(_upKey);
	}
	//앉기
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_vCommand.push_back(_downKey);
	}

	//이동
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		if (state == idle || state == walk || state == backWalk)
		{
			speedX = 1;
			if (isRight) state = walk;
			else if (!isRight) state = backWalk;
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		if (state == idle || state == walk || state == backWalk)
		{
			speedX = -1;
			if (isRight) state = backWalk;
			else if (!isRight) state = walk;
		}
	}
}

void leona::setImage()
{
	//상태에 따라 이미지 넣어줌
	switch (state)
	{
	case idle:
		_image = IMAGEMANAGER->findImage("LEONA_IDLE");
		break;
	case walk:
		_image = IMAGEMANAGER->findImage("LEONA_WALK");
		break;
	case backWalk:
		_image = IMAGEMANAGER->findImage("LEONA_WALK_BACK");
		break;
	case jump:
		_image = IMAGEMANAGER->findImage("LEONA_JUMP");
		break;
	case crouch:
		_image = IMAGEMANAGER->findImage("LEONA_CROUCH");
		break;
	case hit1:
		_image = IMAGEMANAGER->findImage("LEONA_HIT_1");
		break;
	case hit2:
		_image = IMAGEMANAGER->findImage("LEONA_HIT_2");
		break;
	case standing:
		_image = IMAGEMANAGER->findImage("LEONA_STANDING");
		break;
	case punch:
		_image = IMAGEMANAGER->findImage("LEONA_PUNCH");
		break;
	case kick:
		_image = IMAGEMANAGER->findImage("LEONA_KICK");
		break;
	case jumpPunch:
		_image = IMAGEMANAGER->findImage("LEONA_JUMP_PUNCH");
		break;
	case jumpKick:
		_image = IMAGEMANAGER->findImage("LEONA_JUMP_KICK");
		break;
	case crouchPunch:
		_image = IMAGEMANAGER->findImage("LEONA_CROUCH_PUNCH");
		break;
	case crouchKick:
		_image = IMAGEMANAGER->findImage("LEONA_CROUCH_KICK");
		break;
	case skill1:
		_image = IMAGEMANAGER->findImage("LEONA_SKILL_1");
		break;
	case skill2:
		_image = IMAGEMANAGER->findImage("LEONA_SKILL_2");
		break;
	case skill3:
		_image = IMAGEMANAGER->findImage("LEONA_SKILL_3");
		break;
	}
	
	//오른쪽 왼쪽 playFrame 변경
	if (isRight)
	{
		_playerAni[idle]->setPlayFrame(0, 7, true);
		_playerAni[walk]->setPlayFrame(0, 9, true);
		_playerAni[backWalk]->setPlayFrame(0, 7, true);
		_playerAni[jump]->setPlayFrame(0, 14);
		_playerAni[crouch]->setPlayFrame(0, 7);
		_playerAni[hit1]->setPlayFrame(0, 2);
		_playerAni[hit2]->setPlayFrame(0, 5);
		_playerAni[standing]->setPlayFrame(0, 6);
		_playerAni[punch]->setPlayFrame(0, 2);
		_playerAni[kick]->setPlayFrame(0, 5);
		_playerAni[jumpPunch]->setPlayFrame(0, 5);
		_playerAni[jumpKick]->setPlayFrame(0, 4);
		_playerAni[crouchPunch]->setPlayFrame(0, 4);
		_playerAni[crouchKick]->setPlayFrame(0, 3);
		_playerAni[skill1]->setPlayFrame(0, 14);
		_playerAni[skill2]->setPlayFrame(0, 12);
		_playerAni[skill3]->setPlayFrame(0, 10);
		_effectAni->setPlayFrame(0, 15);

	}
	else
	{
		_playerAni[idle]->setPlayFrame(15, 8, true);
		_playerAni[walk]->setPlayFrame(19, 10, true);
		_playerAni[backWalk]->setPlayFrame(15, 8, true);
		_playerAni[jump]->setPlayFrame(29, 15);
		_playerAni[crouch]->setPlayFrame(15, 8);
		_playerAni[hit1]->setPlayFrame(5, 3);
		_playerAni[hit2]->setPlayFrame(11, 6);
		_playerAni[standing]->setPlayFrame(13, 7);
		_playerAni[punch]->setPlayFrame(5, 3);
		_playerAni[kick]->setPlayFrame(11, 6);
		_playerAni[jumpPunch]->setPlayFrame(11, 6);
		_playerAni[jumpKick]->setPlayFrame(9, 5);
		_playerAni[crouchPunch]->setPlayFrame(9, 5);
		_playerAni[crouchKick]->setPlayFrame(7, 4);
		_playerAni[skill1]->setPlayFrame(29, 15);
		_playerAni[skill2]->setPlayFrame(25, 13);
		_playerAni[skill3]->setPlayFrame(21, 11);
		_effectAni->setPlayFrame(31, 16);
	}

}