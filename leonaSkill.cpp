#include "stdafx.h"
#include "leonaSkill.h"

leonaPunch::leonaPunch(){}
leonaPunch::~leonaPunch(){}

void leonaPunch::punchFire1(float playerX, float playerY)
{
	_punch.hitbox = RectMakeCenter(playerX + 150, playerY + 45, 120, 30);
	_punch.isFire = true;
}
void leonaPunch::punchFire2(float playerX, float playerY)
{
	_punch.hitbox = RectMakeCenter(playerX - 150, playerY + 45, 120, 30);
	_punch.isFire = true;
}

void leonaPunch::render()
{
	if (_punch.isFire)Rectangle(getMemDC(), _punch.hitbox.left, _punch.hitbox.top, _punch.hitbox.right, _punch.hitbox.bottom);
}

HRESULT leonaPunch::init(bool isPlayer1)
{
	_punch.hitbox = RectMakeCenter(0, 0, 60, 15);
	_punch.damage = 7;
	_punch.isDown = false;
	_punch.isFire = false;
	_punch.isPlayer1 = isPlayer1;

	return S_OK;
}

void leonaPunch::makeisFireFalse()
{
	_punch.isFire = false;
}


leonaKick::leonaKick(){}
leonaKick::~leonaKick(){}

void leonaKick::kickFire1(float playerX, float playerY)
{
	_kick.hitbox = RectMakeCenter(playerX + 150, playerY + 10, 90, 50);
	_kick.isFire = true;
}
void leonaKick::kickFire2(float playerX, float playerY)
{
	_kick.hitbox = RectMakeCenter(playerX - 150, playerY + 10, 90, 50);
	_kick.isFire = true;
}

void leonaKick::render()
{
	if (_kick.isFire) Rectangle(getMemDC(), _kick.hitbox.left, _kick.hitbox.top, _kick.hitbox.right, _kick.hitbox.bottom);
}

HRESULT leonaKick::init(bool isPlayer1)
{
	_kick.hitbox = RectMakeCenter(0, 0, 60, 15);
	_kick.damage = 10;
	_kick.isDown = false;
	_kick.isFire = false;
	_kick.isPlayer1 = isPlayer1;

	return S_OK;
}

void leonaKick::makeisFireFalse()
{
	_kick.isFire = false;
}



leonaCpunch::leonaCpunch(){}
leonaCpunch::~leonaCpunch(){}

void leonaCpunch::CpunchFire1(float playerX, float playerY)
{
	_skillCpunch.hitbox = RectMakeCenter(playerX + 160, playerY + 70, 130, 30);
	_skillCpunch.isFire = true;
}
void leonaCpunch::CpunchFire2(float playerX, float playerY)
{
	_skillCpunch.hitbox = RectMakeCenter(playerX - 160, playerY + 70, 130, 30);
	_skillCpunch.isFire = true;
}

void leonaCpunch::render()
{
	if (_skillCpunch.isFire)Rectangle(getMemDC(), _skillCpunch.hitbox.left, _skillCpunch.hitbox.top, _skillCpunch.hitbox.right, _skillCpunch.hitbox.bottom);
}

HRESULT leonaCpunch::init(bool isPlayer1)
{
	_skillCpunch.hitbox = RectMakeCenter(0, 0, 60, 15);
	_skillCpunch.damage = 7;
	_skillCpunch.isDown = false;
	_skillCpunch.isFire = false;
	_skillCpunch.isPlayer1 = isPlayer1;

	return S_OK;
}

void leonaCpunch::makeisFireFalse()
{
	_skillCpunch.isFire = false;
}


leonaCkick::leonaCkick(){}
leonaCkick::~leonaCkick(){}

void leonaCkick::Fire1(float playerX, float playerY)
{
	_skillCkick.hitbox = RectMakeCenter(playerX + 225, playerY + 195, 70, 40);
	_skillCkick.isFire = true;
}
void leonaCkick::Fire2(float playerX, float playerY)
{
	_skillCkick.hitbox = RectMakeCenter(playerX - 225, playerY + 195, 70, 40);
	_skillCkick.isFire = true;
}

void leonaCkick::render()
{
	if (_skillCkick.isFire)Rectangle(getMemDC(), _skillCkick.hitbox.left, _skillCkick.hitbox.top, _skillCkick.hitbox.right, _skillCkick.hitbox.bottom);
}

HRESULT leonaCkick::init(bool isPlayer1)
{
	_skillCkick.hitbox = RectMakeCenter(0, 0, 60, 15);
	_skillCkick.damage = 10;
	_skillCkick.isDown = true;
	_skillCkick.isFire = false;
	_skillCkick.isPlayer1 = isPlayer1;

	return S_OK;
}

void leonaCkick::makeisFireFalse()
{
	_skillCkick.isFire = false;
}


leonaJkick::leonaJkick(){}
leonaJkick::~leonaJkick(){}

void leonaJkick::Fire1(float playerX, float playerY)
{
	_skillJkick.hitbox = RectMakeCenter(playerX + 140, playerY + 40, 70, 40);
	_skillJkick.isFire = true;
}
void leonaJkick::Fire2(float playerX, float playerY)
{
	_skillJkick.hitbox = RectMakeCenter(playerX - 140, playerY + 40, 70, 40);
	_skillJkick.isFire = true;
}

void leonaJkick::render()
{
	if (_skillJkick.isFire)Rectangle(getMemDC(), _skillJkick.hitbox.left, _skillJkick.hitbox.top, _skillJkick.hitbox.right, _skillJkick.hitbox.bottom);
}

HRESULT leonaJkick::init(bool isPlayer1)
{
	_skillJkick.hitbox = RectMakeCenter(0, 0, 60, 15);
	_skillJkick.damage = 10;
	_skillJkick.isDown = true;
	_skillJkick.isFire = false;
	_skillJkick.isPlayer1 = isPlayer1;
	return S_OK;
}

void leonaJkick::makeisFireFalse()
{
	_skillJkick.isFire = false;
}



leonaJpunch::leonaJpunch(){}
leonaJpunch::~leonaJpunch(){}
void leonaJpunch::Fire1(float playerX, float playerY)
{
	_skillJpunch.hitbox = RectMakeCenter(playerX + 110, playerY + 45, 70, 40);
	_skillJpunch.isFire = true;
}
void leonaJpunch::Fire2(float playerX, float playerY)
{
	_skillJpunch.hitbox = RectMakeCenter(playerX - 110, playerY + 45, 70, 40);
	_skillJpunch.isFire = true;
}

void leonaJpunch::render()
{
	if (_skillJpunch.isFire)Rectangle(getMemDC(), _skillJpunch.hitbox.left, _skillJpunch.hitbox.top, _skillJpunch.hitbox.right, _skillJpunch.hitbox.bottom);
}

HRESULT leonaJpunch::init(bool isPlayer1)
{
	_skillJpunch.hitbox = RectMakeCenter(0, 0, 60, 15);
	_skillJpunch.damage = 7;
	_skillJpunch.isDown = false;
	_skillJpunch.isFire = false;
	_skillJpunch.isPlayer1 = isPlayer1;

	return S_OK;
}

void leonaJpunch::makeisFireFalse()
{
	_skillJpunch.isFire = false;
}


leonaSkill1::leonaSkill1(){}
leonaSkill1::~leonaSkill1(){}

void leonaSkill1::Fire1(float playerX, float playerY)
{
	_skill1st.hitbox = RectMakeCenter(playerX + 50, playerY + 50, 250, 400);
	_skill1st.isFire = true;
}
void leonaSkill1::Fire2(float playerX, float playerY)
{
	_skill1st.hitbox = RectMakeCenter(playerX - 50, playerY + 50, 250, 400);
	_skill1st.isFire = true;
}


void leonaSkill1::render()
{
	if (_skill1st.isFire)Rectangle(getMemDC(), _skill1st.hitbox.left, _skill1st.hitbox.top, _skill1st.hitbox.right, _skill1st.hitbox.bottom);
}

HRESULT leonaSkill1::init(bool isPlayer1)
{
	_skill1st.hitbox = RectMakeCenter(0, 0, 60, 15);
	_skill1st.damage = 15;
	_skill1st.isDown = true;
	_skill1st.isFire = false;
	_skill1st.isPlayer1 = isPlayer1;

	return S_OK;
}

void leonaSkill1::makeisFireFalse()
{
	_skill1st.isFire = false;
}




leonaSkill2::leonaSkill2(){}
leonaSkill2::~leonaSkill2(){}

void leonaSkill2::Fire1(float playerX, float playerY)
{
	_skill2nd.hitbox = RectMakeCenter(playerX + 80, playerY + 100, 200, 300);
	_skill2nd.isFire = true;
}
void leonaSkill2::Fire2(float playerX, float playerY)
{
	_skill2nd.hitbox = RectMakeCenter(playerX - 80, playerY + 100, 200, 300);
	_skill2nd.isFire = true;
}

void leonaSkill2::render()
{
	if (_skill2nd.isFire)Rectangle(getMemDC(), _skill2nd.hitbox.left, _skill2nd.hitbox.top, _skill2nd.hitbox.right, _skill2nd.hitbox.bottom);
}

HRESULT leonaSkill2::init(bool isPlayer1)
{
	_skill2nd.hitbox = RectMakeCenter(0, 0, 60, 15);
	_skill2nd.damage = 3;
	_skill2nd.isDown = false;
	_skill2nd.isFire = false;
	_skill2nd.isPlayer1 = isPlayer1;

	return S_OK;
}

void leonaSkill2::makeisFireFalse()
{
	_skill2nd.isFire = false;
}


leonaSkill3::leonaSkill3(){}
leonaSkill3::~leonaSkill3(){}

void leonaSkill3::Fire1(float playerX, float playerY)
{
	_skill3rd.hitbox = RectMakeCenter(playerX + 145, playerY - 30, 150, 150);
	_skill3rd.isFire = true;
}
void leonaSkill3::Fire2(float playerX, float playerY)
{
	_skill3rd.hitbox = RectMakeCenter(playerX - 145, playerY - 30, 150, 150);
	_skill3rd.isFire = true;
}

void leonaSkill3::render()
{
	if (_skill3rd.isFire)Rectangle(getMemDC(), _skill3rd.hitbox.left, _skill3rd.hitbox.top, _skill3rd.hitbox.right, _skill3rd.hitbox.bottom);
}

HRESULT leonaSkill3::init(bool isPlayer1)
{
	_skill3rd.hitbox = RectMakeCenter(0, 0, 60, 15);
	_skill3rd.damage = 25;
	_skill3rd.isDown = true;
	_skill3rd.isFire = false;
	_skill3rd.isPlayer1 = isPlayer1;
	return S_OK;
}

void leonaSkill3::makeisFireFalse()
{
	_skill3rd.isFire = false;
}
