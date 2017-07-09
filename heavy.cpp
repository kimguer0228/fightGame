#include "stdafx.h"
#include "heavy.h"


HRESULT heavy::init(bool isPlayer1, float playerX, float playerY, float playerWidth, float playerHeight, int upKey, int downKey, int leftKey, int rightKey, int punchKey, int kickKey, int Num)
{
	playerNode::init(isPlayer1, playerX, playerY, playerWidth, playerHeight, upKey, downKey, leftKey, rightKey, punchKey, kickKey, Num);

	//이미지와 애니메이션을 플레이어 클래스에서 선언해줬으니 초기화까지 해줍니다.
	_idle = IMAGEMANAGER->addFrameImage("헤비기본", "heavy/heavy_idle.bmp", 7296, 1344, 8, 2, true, RGB(248, 0, 248));
	_walk = IMAGEMANAGER->addFrameImage("헤비걷기", "heavy/heavy_walk.bmp", 10944, 1344, 12, 2, true, RGB(248, 0, 248));
	_punchImage = IMAGEMANAGER->addFrameImage("헤비펀치", "heavy/heavy_punch.bmp", 3648, 1344, 4, 2, true, RGB(248, 0, 248));
	_CpunchImage = IMAGEMANAGER->addFrameImage("헤비앉아펀치", "heavy/heavy_crouchpunch.bmp", 3648, 1344, 4, 2, true, RGB(248, 0, 248));
	_JpunchImage = IMAGEMANAGER->addFrameImage("헤비점프펀치", "heavy/heavy_jumppunch.bmp", 3648, 1344, 4, 2, true, RGB(248, 0, 248));

	_kickImage = IMAGEMANAGER->addFrameImage("헤비킥", "heavy/heavy_kick.bmp", 3648, 1344, 4, 2, true, RGB(248, 0, 248));
	_CkickImage = IMAGEMANAGER->addFrameImage("헤비앉아킥", "heavy/heavy_crouchkick.bmp", 3648, 1344, 4, 2, true, RGB(248, 0, 248));
	_JkickImage = IMAGEMANAGER->addFrameImage("헤비점프킥", "heavy/heavy_jumpkick.bmp", 2736, 1344, 3, 2, true, RGB(248, 0, 248));

	_crouch = IMAGEMANAGER->addFrameImage("헤비앉기", "heavy/heavy_crouch.bmp", 2736, 1344, 3, 2, true, RGB(248, 0, 248));
	_backwalk = IMAGEMANAGER->addFrameImage("헤비뒤로걷기", "heavy/heavy_backwalk.bmp", 10944, 1344, 12, 2, true, RGB(248, 0, 248));
	_jump = IMAGEMANAGER->addFrameImage("헤비점프", "heavy/heavy_jump.bmp", 6384, 1344, 7, 2, true, RGB(248, 0, 248));

	_hit1 = IMAGEMANAGER->addFrameImage("헤비맞기", "heavy/heavy_hit1.bmp", 3648, 1344, 4, 2, true, RGB(248, 0, 248));
	_hit2 = IMAGEMANAGER->addFrameImage("헤비맞기2", "heavy/heavy_hit2.bmp", 7296, 1344, 8, 2, true, RGB(248, 0, 248));
	_standing = IMAGEMANAGER->addFrameImage("헤비서기", "heavy/heavy_standing.bmp", 3648, 1344, 4, 2, true, RGB(248, 0, 248));
	_skill1Image = IMAGEMANAGER->addFrameImage("헤비스킬1", "heavy/heavy_skill1.bmp", 5472, 1344, 6, 2, true, RGB(248, 0, 248));
	_skill1effect = IMAGEMANAGER->addFrameImage("헤비스킬1이펙트", "heavy/heavy_skill1effect.bmp", 5472, 1344, 6, 2, true, RGB(248, 0, 248));
	_skill2Image = IMAGEMANAGER->addFrameImage("헤비스킬2", "heavy/heavy_skill2.bmp", 11856, 1344, 13, 2, true, RGB(248, 0, 248));
	_skill2effect = IMAGEMANAGER->addFrameImage("헤비스킬2이펙트", "heavy/heavy_skill2effect.bmp", 11856, 1344, 13, 2, true, RGB(248, 0, 248));
	_skill3Image = IMAGEMANAGER->addFrameImage("헤비스킬3", "heavy/heavy_skill3.bmp", 11856, 1344, 13, 2, true, RGB(248, 0, 248));
	_skill3effect = IMAGEMANAGER->addFrameImage("헤비스킬3이펙트", "heavy/heavy_skill3effect.bmp", 11856, 1344, 13, 2, true, RGB(248, 0, 248));



	_skill1Ani = new animation;
	_skill1Ani->init(_skill1Image->getWidth(), _skill1Image->getHeight(), _skill1Image->getFrameWidth(), _skill1Image->getFrameHeight());
	_skill1Ani->setPlayFrame(1, 6, false, true);
	_skill1Ani->setFPS(2);

	_skill1effectAni = new animation;
	_skill1effectAni->init(_skill1effect->getWidth(), _skill1effect->getHeight(), _skill1effect->getFrameWidth(), _skill1effect->getFrameHeight());
	_skill1effectAni->setPlayFrame(1, 6, false, true);
	_skill1effectAni->setFPS(2);

	_skill2Ani = new animation;
	_skill2Ani->init(_skill2Image->getWidth(), _skill2Image->getHeight(), _skill2Image->getFrameWidth(), _skill2Image->getFrameHeight());
	_skill2Ani->setPlayFrame(1, 13, false, false);
	_skill2Ani->setFPS(2);

	_skill2effectAni = new animation;
	_skill2effectAni->init(_skill2effect->getWidth(), _skill2effect->getHeight(), _skill2effect->getFrameWidth(), _skill2effect->getFrameHeight());
	_skill2effectAni->setPlayFrame(1, 13, false, false);
	_skill2effectAni->setFPS(2);

	_skill3Ani = new animation;
	_skill3Ani->init(_skill3Image->getWidth(), _skill3Image->getHeight(), _skill3Image->getFrameWidth(), _skill3Image->getFrameHeight());
	_skill3Ani->setPlayFrame(1, 13, false, false);
	_skill3Ani->setFPS(2);

	_skill3effectAni = new animation;
	_skill3effectAni->init(_skill3effect->getWidth(), _skill3effect->getHeight(), _skill3effect->getFrameWidth(), _skill3effect->getFrameHeight());
	_skill3effectAni->setPlayFrame(1, 13, false, false);
	_skill3effectAni->setFPS(2);

	_idleani = new animation;
	_idleani->init(_idle->getWidth(), _idle->getHeight(), _idle->getFrameWidth(), _idle->getFrameHeight());
	_idleani->setPlayFrame(1, 8, false, true);
	_idleani->setFPS(3);
	_idleani->start();

	_hit1ani = new animation;
	_hit1ani->init(_hit1->getWidth(), _hit1->getHeight(), _hit1->getFrameWidth(), _hit1->getFrameHeight());
	_hit1ani->setPlayFrame(1, 4, false, true);
	_hit1ani->setFPS(3);

	_hit2ani = new animation;
	_hit2ani->init(_hit2->getWidth(), _hit2->getHeight(), _hit2->getFrameWidth(), _hit2->getFrameHeight());
	_hit2ani->setPlayFrame(1, 8, false, true);
	_hit2ani->setFPS(3);

	_standingani = new animation;
	_standingani->init(_standing->getWidth(), _standing->getHeight(), _standing->getFrameWidth(), _standing->getFrameHeight());
	_standingani->setPlayFrame(1, 4, false, true);
	_standingani->setFPS(3);


	_walkani = new animation;
	_walkani->init(_walk->getWidth(), _walk->getHeight(), _walk->getFrameWidth(), _walk->getFrameHeight());
	_walkani->setPlayFrame(1, 12, false, true);
	_walkani->setFPS(3);
	_walkani->start();

	_backwalkani = new animation;
	_backwalkani->init(_backwalk->getWidth(), _backwalk->getHeight(), _backwalk->getFrameWidth(), _backwalk->getFrameHeight());
	_backwalkani->setPlayFrame(1, 12, false, true);
	_backwalkani->setFPS(3);
	_backwalkani->start();

	_crouchani = new animation;
	_crouchani->init(_crouch->getWidth(), _crouch->getHeight(), _crouch->getFrameWidth(), _crouch->getFrameHeight());
	_crouchani->setPlayFrame(1, 3, false, true);
	_crouchani->setFPS(1);

	_jumpani = new animation;
	_jumpani->init(_jump->getWidth(), _jump->getHeight(), _jump->getFrameWidth(), _jump->getFrameHeight());
	_jumpani->setPlayFrame(1, 7, false, true);
	_jumpani->setFPS(1);

	_punchAni = new animation;
	_punchAni->init(_punchImage->getWidth(), _punchImage->getHeight(), _punchImage->getFrameWidth(), _punchImage->getFrameHeight());
	_punchAni->setPlayFrame(1, 4, false, false);
	_punchAni->setFPS(1);

	_CpunchAni = new animation;
	_CpunchAni->init(_CpunchImage->getWidth(), _CpunchImage->getHeight(), _CpunchImage->getFrameWidth(), _CpunchImage->getFrameHeight());
	_CpunchAni->setPlayFrame(1, 4, false, false);
	_CpunchAni->setFPS(1);

	_JpunchAni = new animation;
	_JpunchAni->init(_JpunchImage->getWidth(), _JpunchImage->getHeight(), _JpunchImage->getFrameWidth(), _JpunchImage->getFrameHeight());
	_JpunchAni->setPlayFrame(1, 4, false, false);
	_JpunchAni->setFPS(1);

	_kickAni = new animation;
	_kickAni->init(_kickImage->getWidth(), _kickImage->getHeight(), _kickImage->getFrameWidth(), _kickImage->getFrameHeight());
	_kickAni->setPlayFrame(1, 4, false, false);
	_kickAni->setFPS(1);

	_CkickAni = new animation;
	_CkickAni->init(_CkickImage->getWidth(), _CkickImage->getHeight(), _CkickImage->getFrameWidth(), _CkickImage->getFrameHeight());
	_CkickAni->setPlayFrame(1, 4, false, false);
	_CkickAni->setFPS(1);

	_JkickAni = new animation;
	_JkickAni->init(_JkickImage->getWidth(), _JkickImage->getHeight(), _JkickImage->getFrameWidth(), _JkickImage->getFrameHeight());
	_JkickAni->setPlayFrame(1, 4, false, false);
	_JkickAni->setFPS(1);


	

	//공격 초기화
	_punch = new skillPunch;
	_punch->init();
	_Cpunch = new skillCpunch;
	_Cpunch->init();
	_Jpunch = new skillJpunch;
	_Jpunch->init();
	_kick = new skillKick;
	_kick->init();
	_Ckick = new skillCkick;
	_Ckick->init();
	_Jkick = new skillJkick;
	_Jkick->init();
	_skill1 = new skill1st;
	_skill1->init();
	_skill2 = new skill2nd;
	_skill2->init();
	_skill3 = new skill3rd;
	_skill3->init();

	_fCommandClear = 2.5;
	_fCommandTime = 0;

	return S_OK;
};
void heavy::release()
{

};
void heavy::update()
{
	playerNode::update();


	keyControl();
	stateControl();

	//애니메이션을 쓰기 때문에 프레임업데이트를 해줍니다
	_idleani->frameUpdate(TIMEMANAGER->getElapsedTime() * 2);
	_hit1ani->frameUpdate(TIMEMANAGER->getElapsedTime() * 2);
	_hit2ani->frameUpdate(TIMEMANAGER->getElapsedTime() * 2);
	_walkani->frameUpdate(TIMEMANAGER->getElapsedTime() * 2);
	_jumpani->frameUpdate(TIMEMANAGER->getElapsedTime() * 2);
	_backwalkani->frameUpdate(TIMEMANAGER->getElapsedTime() * 2);
	_crouchani->frameUpdate(TIMEMANAGER->getElapsedTime() * 2);
	_punchAni->frameUpdate(TIMEMANAGER->getElapsedTime() * 20);
	_CpunchAni->frameUpdate(TIMEMANAGER->getElapsedTime() * 20);
	_JpunchAni->frameUpdate(TIMEMANAGER->getElapsedTime() * 15);
	_kickAni->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	_CkickAni->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	_JkickAni->frameUpdate(TIMEMANAGER->getElapsedTime() * 10);
	_skill1Ani->frameUpdate(TIMEMANAGER->getElapsedTime() * 5);
	_skill1effectAni->frameUpdate(TIMEMANAGER->getElapsedTime() * 5);
	_skill2Ani->frameUpdate(TIMEMANAGER->getElapsedTime() * 5);
	_skill2effectAni->frameUpdate(TIMEMANAGER->getElapsedTime() * 5);
	_skill3Ani->frameUpdate(TIMEMANAGER->getElapsedTime() * 5);
	_skill3effectAni->frameUpdate(TIMEMANAGER->getElapsedTime() * 5);
};


void heavy::render()
{
	
	if (state == idle)_idle->aniRender(getMemDC(), x - 456, y - 336, _idleani);
	else if (state == walk)_walk->aniRender(getMemDC(), x - 456, y - 336, _walkani);
	else if (state == backWalk)_backwalk->aniRender(getMemDC(), x - 456, y - 336, _backwalkani);
	else if (state == jump) _jump->aniRender(getMemDC(), x - 456, y - 336, _jumpani);
	else if (state == crouch) _crouch->aniRender(getMemDC(), x - 456, y - 336, _crouchani);
	else if (state == punch) _punchImage->aniRender(getMemDC(), x - 456, y - 336, _punchAni);
	else if (state == kick) _kickImage->aniRender(getMemDC(), x - 456, y - 336, _kickAni);
	else if (state == crouchPunch) _CpunchImage->aniRender(getMemDC(), x - 456, y - 336, _CpunchAni);
	else if (state == crouchKick) _CkickImage->aniRender(getMemDC(), x - 456, y - 336, _CkickAni);
	else if (state == jumpPunch) _JpunchImage->aniRender(getMemDC(), x - 456, y - 336, _JpunchAni);
	else if (state == jumpKick) _JkickImage->aniRender(getMemDC(), x - 456, y - 336, _JkickAni);
	else if (state == skill1)
	{
		_skill1Image->aniRender(getMemDC(), x - 456, y - 336, _skill1Ani);
		_skill1effect->aniRender(getMemDC(), x - 456, y - 336, _skill1effectAni);
	}
	else if (state == skill2)
	{
		_skill2Image->aniRender(getMemDC(), x - 456, y - 336, _skill2Ani);
		_skill2effect->aniRender(getMemDC(), x - 456, y - 336, _skill2effectAni);
	}
	else if (state == skill3)
	{
		_skill3Image->aniRender(getMemDC(), x - 456, y - 336, _skill3Ani);
		_skill3effect->aniRender(getMemDC(), x - 456, y - 336, _skill3effectAni);
	}

	//공격 히트박스 랜더
	/*
	_punch->render();
	_kick->render();
	_Cpunch->render();
	_Ckick->render();
	_Jpunch->render();
	_Jkick->render();
	_skill1->render();
	_skill2->render();
	_skill3->render();
	*/
};

void heavy::keyControl()
{
	if (_vCOMMAND.size() > 0) _fCommandTime += 0.1f;
	if (_fCommandTime > _fCommandClear)
	{
		_fCommandTime = 0;
		_vCOMMAND.clear();
	}
	if (KEYMANAGER->isOnceKeyDown(_upKey))
	{
		if (isRight) _jumpani->setPlayFrame(3, 7, false, true);
		else if (!isRight)
		{
			_jumpani->setPlayFrame(12, 8, false, true);
		}
		if (state == idle || state == walk || state == backWalk)
		{
			state = jump;
			speedY -= 5;

			_jumpani->start();
		}
		_vCOMMAND.push_back(_upKey);
	}
	if (KEYMANAGER->isOnceKeyDown(_downKey))
	{
		if (isRight) _crouchani->setPlayFrame(1, 3, false, false);
		else if (!isRight) _crouchani->setPlayFrame(5, 4, false, false);
		if (state == idle || state == walk || state == backWalk)
		{
			state = crouch;

			_crouchani->start();
		}
		_vCOMMAND.push_back(_downKey);
	}
	if (KEYMANAGER->isStayKeyDown(_downKey))
	{
		if (isRight) _crouchani->setPlayFrame(2, 3, false, false);
		else if (!isRight) _crouchani->setPlayFrame(5, 4, false, false);
	}
	if (KEYMANAGER->isOnceKeyUp(_downKey))
	{
		if (state == crouch)
		{
			state = idle;
		}
	}

	if (KEYMANAGER->isOnceKeyDown(_rightKey))
	{
		if (isRight) _walkani->setPlayFrame(1, 12, false, true);
		else if (!isRight) _backwalkani->setPlayFrame(23, 13, false, true);

		_vCOMMAND.push_back(_rightKey);
	}
	if (KEYMANAGER->isOnceKeyDown(_leftKey))
	{
		if (isRight) _backwalkani->setPlayFrame(1, 12, false, true);
		else if (!isRight) _walkani->setPlayFrame(23, 13, false, true);

		_vCOMMAND.push_back(_leftKey);
	}
	if (KEYMANAGER->isStayKeyDown(_rightKey))
	{
		if (state == walk || state == idle || state == backWalk)
		{
			speedX = 1;
			if (isRight) state = walk;
			else if (!isRight) state = backWalk;
		}
	}
	if (KEYMANAGER->isOnceKeyUp(_rightKey))
	{
		if (state == walk || state == idle || state == backWalk)
		{
			state = idle;
		}
	}

	if (KEYMANAGER->isStayKeyDown(_leftKey))
	{
		if (state == walk || state == idle || state == backWalk)
		{
			speedX = -1;
			if (isRight) state = backWalk;
			else if (!isRight) state = walk;
		}
	}
	if (KEYMANAGER->isOnceKeyUp(_leftKey))
	{
		if (state == walk || state == idle || state == backWalk)
		{
			state = idle;
		}
	}


	if (KEYMANAGER->isOnceKeyDown(_punchKey))
	{


		if (state == walk || state == idle || state == backWalk)
		{

			_vCOMMAND.push_back(_punchKey);

			if (_vCOMMAND.size() > 2)
			{
				if (isRight)
				{
					if (_vCOMMAND[0] == _downKey && _vCOMMAND[1] == _rightKey && _vCOMMAND[2] == _punchKey)
					{
						state = skill2;
						_skill2->Fire1(x, y);
						_skill2Ani->start();
						_skill2effectAni->start();
					}
					else if (_vCOMMAND[0] == _rightKey && _vCOMMAND[1] == _downKey && _vCOMMAND[2] == _rightKey && _vCOMMAND[3] == _punchKey)
					{
						state = skill3;
						_skill3->Fire1(x, y);
						_skill3Ani->start();
						_skill3effectAni->start();
					}

				}
				if (!isRight)
				{
					if (_vCOMMAND[0] == _downKey && _vCOMMAND[1] == _leftKey && _vCOMMAND[2] == _punchKey)
					{
						state = skill2;
						_skill2->Fire2(x, y);
						_skill2Ani->start();
						_skill2effectAni->start();
					}
					else if (_vCOMMAND[0] == _leftKey && _vCOMMAND[1] == _downKey && _vCOMMAND[2] == _leftKey && _vCOMMAND[3] == _punchKey)
					{
						state = skill3;
						_skill3->Fire2(x, y);
						_skill3Ani->start();
						_skill3effectAni->start();
					}

				}
			}
			else
			{
				state = punch;
				if (isRight) _punch->punchFire1(x, y);
				else if (!isRight) _punch->punchFire2(x, y);
				_punchAni->start();
			}
		}
		else if (state == crouch)
		{
			state = crouchPunch;
			if (isRight) _Cpunch->CpunchFire1(x, y);
			else if (!isRight) _Cpunch->CpunchFire2(x, y);
			_CpunchAni->start();
		}
		else if (state == jump)
		{
			state = jumpPunch;
			if (isRight) _Jpunch->Fire1(x, y);
			else if(!isRight) _Jpunch->Fire2(x, y);
			_JpunchAni->start();
		}
	}
	if (KEYMANAGER->isOnceKeyDown(_kickKey))
	{
		if (state == walk || state == idle || state == backWalk)
		{
			_vCOMMAND.push_back(_kickKey);
			if (_vCOMMAND.size() > 2)
			{
				if (isRight)
				{
						if (_vCOMMAND[0] == _downKey && _vCOMMAND[1] == _rightKey && _vCOMMAND[2] == _kickKey)
						{
							state = skill1;
							_skill1->Fire1(x, y);
							_skill1Ani->start();
							_skill1effectAni->start();
						}
				}
				else if (!isRight)
				{
					if (_vCOMMAND[0] == _downKey && _vCOMMAND[1] == _leftKey && _vCOMMAND[2] == _kickKey)
					{
						state = skill1;
						_skill1->Fire2(x, y);
						_skill1Ani->start();
						_skill1effectAni->start();
					}
				}
			}
			else
			{
				state = kick;
				if (isRight) _kick->kickFire1(x, y);
				else if (!isRight) _kick->kickFire2(x, y);
				_kickAni->start();
			}
		}
		else if (state == crouch)
		{
			state = crouchKick;
			if (isRight) _Ckick->Fire1(x, y);
			else if (!isRight) _Ckick->Fire2(x, y);
			_CkickAni->start();
		}
		else if (state == jump)
		{
			state = jumpKick;
			if (isRight) _Jkick->Fire1(x, y);
			else if (!isRight) _Jkick->Fire2(x, y);
			_JkickAni->start();
		}
	}
}

void heavy::stateControl()
{
	if (state == jump)
	{
		if (isRight)
		{
			_jumpani->setPlayFrame(1, 7, false, false);
		}
		else if (!isRight)
		{
			_jumpani->setPlayFrame(12, 8, false, false);
		}
		if (speedY > 0 && y >= WINSIZEY / 2)
		{
			state = idle;
			speedY = 0;
		}
	}
	else if (state == skill1)
	{
		if (isRight)
		{
			_skill1Ani->setPlayFrame(1, 6, false, false);
			_skill1effectAni->setPlayFrame(1, 6, false, false);
		}
		else if (!isRight)
		{
			_skill1Ani->setPlayFrame(11, 7, false, false);
			_skill1effectAni->setPlayFrame(11, 7, false, false);
		}
		if (_skill1Ani->isPlay() == 0)
		{
			state = idle;
			_skill1->makeisFireFalse();
		}
		speedX = 0;
		speedY = 0;

	}
	else if (state == skill2)
	{
		if (isRight)
		{
			_skill2Ani->setPlayFrame(1, 13, false, false);
			_skill2effectAni->setPlayFrame(1, 13, false, false);
		}
		else if (!isRight)
		{
			_skill2Ani->setPlayFrame(25, 14, false, false);
			_skill2effectAni->setPlayFrame(25, 14, false, false);
		}
		if (_skill2Ani->isPlay() == 0)
		{
			state = idle;
			_skill2->makeisFireFalse();
		}
		speedX = 0;
		speedY = 0;

	}
	else if (state == skill3)
	{
		if (isRight)
		{
			_skill3Ani->setPlayFrame(1, 13, false, false);
			_skill3effectAni->setPlayFrame(1, 13, false, false);
		}
		else if (!isRight)
		{
			_skill3Ani->setPlayFrame(25, 14, false, false);
			_skill3effectAni->setPlayFrame(25, 14, false, false);
		}
		if (_skill3Ani->isPlay() == 0)
		{
			state = idle;
			_skill3->makeisFireFalse();
		}
		speedX = 0;
		speedY = 0;
	}
	else if (state == idle)
	{
		if (isRight)
		{
			_idleani->setPlayFrame(1, 8, false, true);
		}
		else if (!isRight)
		{
			_idleani->setPlayFrame(15, 9, false, true);
		}
		speedX = 0;
		speedY = 0;
		y = WINSIZEY / 2;
	}
	else if (state == hit1)
	{
		if (isRight) _hit1ani->setPlayFrame(1, 4, false, false);
		else if (!isRight) _hit1ani->setPlayFrame(7, 5, false, false);
		if (_hit1ani->isPlay() == 0)
		{
			state = idle;
		}
		speedX = 0;
		speedY = 0;
	}
	else if (state == hit2)
	{
		if (isRight) _hit2ani->setPlayFrame(1, 8, false, false);
		else if (!isRight) _hit2ani->setPlayFrame(15, 9, false, false);
		if (_hit2ani->isPlay() == 0)
		{
			state = standing;
		}
		speedX = 0;
		speedY = 0;
	}
	else if (state == standing)
	{
		if (isRight) _standingani->setPlayFrame(1, 4, false, false);
		else if (!isRight) _standingani->setPlayFrame(7, 5, false, false);
		if (_standingani->isPlay() == 0)
		{
			state = idle;
		}
		speedX = 0;
		speedY = 0;
	}
	else if (state == crouch)
	{
		speedX = 0;
		speedY = 0;
		y = WINSIZEY / 2;
	}
	else if (state == walk)
	{
		speedY = 0;
	}
	else if (state == backWalk)
	{
		speedY = 0;
	}
	else if (state == punch)
	{
		if (isRight) _punchAni->setPlayFrame(1, 4, false, false);
		else if (!isRight) _punchAni->setPlayFrame(7, 5, false, false);
		if (_punchAni->isPlay() == 0)
		{
			state = idle;
			_punch->makeisFireFalse();
		}
		speedX = 0;
		speedY = 0;
	}
	else if (state == crouchPunch)
	{
		if (isRight) _CpunchAni->setPlayFrame(1, 4, false, false);
		else if (!isRight) _CpunchAni->setPlayFrame(7, 5, false, false);
		if (_CpunchAni->isPlay() == 0)
		{
			if (KEYMANAGER->isStayKeyDown(_downKey)) state = crouch;
			else state = idle;

			_Cpunch->makeisFireFalse();
		}
		speedX = 0;
		speedY = 0;
	}
	else if (state == jumpPunch)
	{
		if (isRight) _JpunchAni->setPlayFrame(1, 4, false, false);
		else if (!isRight) _JpunchAni->setPlayFrame(7, 5, false, false);
		if (speedY > 0 && y >= WINSIZEY / 2)
		{
			state = idle;
			speedY = 0;
			_Jpunch->makeisFireFalse();
		}
		else if (_JpunchAni->isPlay() == 0)
		{
			state = jump;
			_Jpunch->makeisFireFalse();
		}
	}
	else if (state == kick)
	{
		if (isRight) _kickAni->setPlayFrame(1, 4, false, false);
		else if (!isRight) _kickAni->setPlayFrame(7, 5, false, false);
		if (_kickAni->isPlay() == 0)
		{
			state = idle;
			_kick->makeisFireFalse();
		}
		speedX = 0;
		speedY = 0;
	}
	else if (state == crouchKick)
	{
		if (isRight) _CkickAni->setPlayFrame(1, 4, false, false);
		else if (!isRight) _CkickAni->setPlayFrame(7, 5, false, false);
		if (_CkickAni->isPlay() == 0)
		{
			if (KEYMANAGER->isStayKeyDown(_downKey)) state = crouch;
			else state = idle;
			_Ckick->makeisFireFalse();
		}
		speedX = 0;
		speedY = 0;
	}
	else if (state == jumpKick)
	{
		if (isRight) _JkickAni->setPlayFrame(1, 3, false, false);
		else if (!isRight) _JkickAni->setPlayFrame(5, 4, false, false);
		if (speedY > 0 && y >= WINSIZEY / 2)
		{
			state = idle;
			speedY = 0;
			_Jkick->makeisFireFalse();
		}
		else if (_JkickAni->isPlay() == 0)
		{
			state = jump;
			_Jkick->makeisFireFalse();
		}
	}
}

heavy::heavy()
{
}


heavy::~heavy()
{
}
