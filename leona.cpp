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

	state = idle;

	_commandTime = 0;
	_resetTime = 2.5f;

	return S_OK;
}
void leona::release()
{

}
void leona::update()
{
	playerNode::update();

	keyControl();
	stateControl();
	setImage();
	
	_playerAni[state]->frameUpdate(TIMEMANAGER->getElapsedTime() * 8);
	_effectAni->frameUpdate(TIMEMANAGER->getElapsedTime() * 20);

	if (state == skill1 && state == skill2 && state == skill3)
	{
		_playerAni[state]->frameUpdate(TIMEMANAGER->getElapsedTime() * 20);
	}
}
void leona::render()
{
	gameNode::render();

	//Rectangle(getMemDC(), x - 456, y - 336, _image->getFrameWidth(), _image->getFrameHeight());

	_image->aniRender(getMemDC(), x - 456, y - 336, _playerAni[state]);
	
	if (state == skill3)
	{
		IMAGEMANAGER->findImage("LEONA_SKILL_3_EFFECT")->aniRender(getMemDC(), x - 456, y - 336, _effectAni);
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

	if (KEYMANAGER->isOnceKeyDown(_leftKey))
	{
		_vCommand.push_back(_leftKey);
	}
	if (KEYMANAGER->isOnceKeyDown(_rightKey))
	{
		_vCommand.push_back(_rightKey);
	}

	//점프
	if (KEYMANAGER->isOnceKeyDown(_upKey))
	{
		if (state == idle || state == walk || state == backWalk)
		{
			state = jump;
			speedY -= 7;

			_playerAni[state]->start();
		}
		_vCommand.push_back(_upKey);
	}
	//앉기
	if (KEYMANAGER->isOnceKeyDown(_downKey))
	{
		if (state == idle || state == walk || state == backWalk)
		{
			state = crouch;
			speedY -= 10;

			_playerAni[state]->start();
		}

		_vCommand.push_back(_downKey);
	}

	//이동
	if (KEYMANAGER->isStayKeyDown(_leftKey))
	{
		if (state == idle || state == walk || state == backWalk)
		{
			speedX = -1;
			if (isRight) state = backWalk;
			else if (!isRight) state = walk;
		}
	}
	if (KEYMANAGER->isStayKeyDown(_rightKey))
	{
		if (state == idle || state == walk || state == backWalk)
		{
			speedX = 1;
			if (isRight) state = walk;
			else if (!isRight) state = backWalk;
		}
	}
	
	//idle로
	if (KEYMANAGER->isOnceKeyUp(_leftKey))
	{
		speedX = 0;
		if (state == walk || state == idle || state == backWalk) { state = idle; }
	}
	if (KEYMANAGER->isOnceKeyUp(_rightKey))
	{
		speedX = 0;
		if (state == walk || state == idle || state == backWalk) { state = idle; }
	}
	if (KEYMANAGER->isOnceKeyUp(_downKey))
	{
		speedX = 0;
		if (state == crouch) { state = idle; }
	}

	//펀치
	if (KEYMANAGER->isOnceKeyDown(_punchKey))
	{
		if (state == walk || state == idle || state == backWalk)
		{
			_vCommand.push_back(_punchKey);

			if (_vCommand.size() > 2)
			{
				if (isRight)
				{
					if (_vCommand[0] == _downKey && _vCommand[1] == _upKey && _vCommand[2] == _punchKey)
					{
						state = skill2;
						//_skill2->Fire1(x, y);
						_playerAni[state]->start();
					}
					else if (_vCommand[0] == _leftKey && _vCommand[1] == _rightKey && _vCommand[2] == _punchKey)

					{
						state = skill3;
						//_skill3->Fire1(x, y);
						_playerAni[state]->start();
						_effectAni->start();
					}

				}
				if (!isRight)
				{
					if (_vCommand[0] == _downKey && _vCommand[1] == _upKey && _vCommand[2] == _punchKey)
					{
						state = skill2;
						//_skill2->Fire1(x, y);
						_playerAni[state]->start();
					}
					else if (_vCommand[0] == _rightKey && _vCommand[1] == _leftKey && _vCommand[2] == _punchKey)
					{
						state = skill3;
						//_skill3->Fire1(x, y);
						_playerAni[state]->start();
						_effectAni->start();
					}
				}
			}
			else
			{
				state = punch;
				_playerAni[state]->start();
			}
		}
		else if (state == crouch)
		{
			state = crouchPunch;
			_playerAni[state]->start();
		}
		else if (state == jump)
		{
			state = jumpPunch;
			_playerAni[state]->start();
		}
	}

	//킥
	if (KEYMANAGER->isOnceKeyDown(_kickKey))
	{
		if (state == walk || state == idle || state == backWalk)
		{
			_vCommand.push_back(_kickKey);
			if (_vCommand.size() > 1)
			{
				if (isRight)
				{
					if (_vCommand[0] == _rightKey && _vCommand[1] == _kickKey)
					{
						state = skill1;
						_playerAni[state]->start();
					}
				}
				else if (!isRight)
				{
					if (_vCommand[0] == _leftKey && _vCommand[1] == _kickKey)
					{
						state = skill1;
						_playerAni[state]->start();
					}
				}
			}
			else
			{
				state = kick;
				_playerAni[state]->start();
			}
		}
		else if (state == crouch)
		{
			state = crouchKick;
			_playerAni[state]->start();
		}
		else if (state == jump)
		{
			state = jumpKick;
			_playerAni[state]->start();
		}
	}

}

void leona::stateControl()
{
	switch (state)
	{
	case idle:
	{
		speedX = 0;
		speedY = 0;
		y = WINSIZEY / 2;
	}
		break;
	case walk:
	{
		speedY = 0; 
	}
		break;
	case backWalk:
	{
		speedY = 0;
	}
		break;
	case jump:
	{
		if (speedY > 0 && y >= WINSIZEY / 2)
		{
			state = idle;
			speedY = 0;
		}
	}
		break;
	case crouch:
	{
		speedX = 0;
		speedY = 0;
		y = WINSIZEY / 2;
	}
		break;
	case hit1:
	{
		if (hit1int == 0) _playerAni[hit1]->start();
		hit1int++;

		if (!_playerAni[state]->isPlay())
		{
			state = idle;
		}
		speedX = 0;
		speedY = 0;
	}
		break;
	case hit2:
	{

		if (hit2int == 0) _playerAni[hit1]->start();
		hit2int++;

		if (!_playerAni[state]->isPlay())
		{
			state = standing;
			hit2int = 0;
			_playerAni[state]->start();
		}
		speedX = 0;
		speedY = 0;
	}
		break;
	case standing:
	{
		//if (standingint == 0)_standingani->start();
		standingint++;

		if (!_playerAni[state]->isPlay())
		{
			state = idle;
			standingint = 0;
		}
		speedX = 0;
		speedY = 0;
	}
		break;
	case punch:
	{
		if (!_playerAni[state]->isPlay())
		{
			state = idle;
		}
		speedX = 0;
		speedY = 0;
	}
		break;
	case kick:
	{
		if (!_playerAni[state]->isPlay())
		{
			state = idle;
		}
		speedX = 0;
		speedY = 0;
	}
		break;
	case jumpPunch:
	{
		if (speedY > 0 && y >= WINSIZEY / 2)
		{
			state = idle;
			speedY = 0;
		}
		else if (!_playerAni[state]->isPlay())
		{
			state = jump;
		}
	}
		break;
	case jumpKick:
	{
		if (speedY > 0 && y >= WINSIZEY / 2)
		{
			state = idle;
			speedY = 0;
		}
		else if (!_playerAni[state]->isPlay())
		{
			state = jump;
		}
	}
		break;
	case crouchPunch:
	{
		if (!_playerAni[state]->isPlay())
		{
			if (KEYMANAGER->isStayKeyDown(_downKey)) state = crouch;
			else state = idle;
		}
		speedX = 0;
		speedY = 0;
	}
		break;
	case crouchKick:
	{
		if (!_playerAni[state]->isPlay())
		{
			if (KEYMANAGER->isStayKeyDown(_downKey)) state = crouch;
			else state = idle;
		}
		speedX = 0;
		speedY = 0;
	}
		break;
	case skill1:
	{
		if (!_playerAni[state]->isPlay())
		{
			state = idle;
		}
		speedX = 0;
		speedY = 0;
	}
		break;
	case skill2:
	{
		if (!_playerAni[state]->isPlay())
		{
			state = idle;
		}
		speedX = 0;
		speedY = 0;
	}
		break;
	case skill3:
	{
		if (_effectAni->isPlay() == 0)
		{
			state = idle;
		}
		speedX = 0;
		speedY = 0;
	}
		break;
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
		_playerAni[idle]->setPlayFrame(0, 7, false, true);
		_playerAni[walk]->setPlayFrame(0, 9, false, true);
		_playerAni[backWalk]->setPlayFrame(0, 7, false, true);
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
		_playerAni[idle]->setPlayFrame(15, 8, false, true);
		_playerAni[walk]->setPlayFrame(19, 10, false, true);
		_playerAni[backWalk]->setPlayFrame(15, 8, false, true);
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