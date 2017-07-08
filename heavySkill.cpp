#include "stdafx.h"
#include "heavySkill.h"


skillPunch::skillPunch()
{
}
skillPunch::~skillPunch()
{
}
void skillPunch::punchFire(float playerX, float playerY)
{
	_punch.hitbox = RectMakeCenter(playerX + 155, playerY, 130, 30);
	_punch.isFire = true;
}

void skillPunch::render()
{
	if (_punch.isFire)Rectangle(getMemDC(), _punch.hitbox.left, _punch.hitbox.top, _punch.hitbox.right, _punch.hitbox.bottom);
}

HRESULT skillPunch::init()
{
	_punch.hitbox = RectMakeCenter(0, 0, 60, 15);
	_punch.damage = 7;
	_punch.isDown = false;
	_punch.isFire = false;

	return S_OK;
}

void skillPunch::makeisFireFalse()
{
	_punch.isFire = false;
}


skillKick::skillKick()
{
}
skillKick::~skillKick()
{
}

void skillKick::kickFire(float playerX, float playerY)
{
	_kick.hitbox = RectMakeCenter(playerX + 100, playerY + 20, 90, 50);
	_kick.isFire = true;
}

void skillKick::render()
{
	if (_kick.isFire)Rectangle(getMemDC(), _kick.hitbox.left, _kick.hitbox.top, _kick.hitbox.right, _kick.hitbox.bottom);
}

HRESULT skillKick::init()
{
	_kick.hitbox = RectMakeCenter(0, 0, 60, 15);
	_kick.damage = 10;
	_kick.isDown = false;
	_kick.isFire = false;

	return S_OK;
}

void skillKick::makeisFireFalse()
{
	_kick.isFire = false;
}



skillCpunch::skillCpunch()
{
}
skillCpunch::~skillCpunch()
{
}
void skillCpunch::CpunchFire(float playerX, float playerY)
{
	_skillCpunch.hitbox = RectMakeCenter(playerX + 165, playerY + 70, 130, 30);
	_skillCpunch.isFire = true;
}

void skillCpunch::render()
{
	if (_skillCpunch.isFire)Rectangle(getMemDC(), _skillCpunch.hitbox.left, _skillCpunch.hitbox.top, _skillCpunch.hitbox.right, _skillCpunch.hitbox.bottom);
}

HRESULT skillCpunch::init()
{
	_skillCpunch.hitbox = RectMakeCenter(0, 0, 60, 15);
	_skillCpunch.damage = 7;
	_skillCpunch.isDown = false;
	_skillCpunch.isFire = false;

	return S_OK;
}

void skillCpunch::makeisFireFalse()
{
	_skillCpunch.isFire = false;
}


skillCkick::skillCkick()
{
}
skillCkick::~skillCkick()
{
}
void skillCkick::Fire(float playerX, float playerY)
{
	_skillCkick.hitbox = RectMakeCenter(playerX + 165, playerY + 150, 70, 40);
	_skillCkick.isFire = true;
}

void skillCkick::render()
{
	if (_skillCkick.isFire)Rectangle(getMemDC(), _skillCkick.hitbox.left, _skillCkick.hitbox.top, _skillCkick.hitbox.right, _skillCkick.hitbox.bottom);
}

HRESULT skillCkick::init()
{
	_skillCkick.hitbox = RectMakeCenter(0, 0, 60, 15);
	_skillCkick.damage = 10;
	_skillCkick.isDown = true;
	_skillCkick.isFire = false;

	return S_OK;
}

void skillCkick::makeisFireFalse()
{
	_skillCkick.isFire = false;
}


skillJkick::skillJkick()
{
}
skillJkick::~skillJkick()
{
}
void skillJkick::Fire(float playerX, float playerY)
{
	_skillJkick.hitbox = RectMakeCenter(playerX + 140, playerY + 40, 70, 40);
	_skillJkick.isFire = true;
}

void skillJkick::render()
{
	if (_skillJkick.isFire)Rectangle(getMemDC(), _skillJkick.hitbox.left, _skillJkick.hitbox.top, _skillJkick.hitbox.right, _skillJkick.hitbox.bottom);
}

HRESULT skillJkick::init()
{
	_skillJkick.hitbox = RectMakeCenter(0, 0, 60, 15);
	_skillJkick.damage = 10;
	_skillJkick.isDown = true;
	_skillJkick.isFire = false;

	return S_OK;
}

void skillJkick::makeisFireFalse()
{
	_skillJkick.isFire = false;
}



skillJpunch::skillJpunch()
{
}
skillJpunch::~skillJpunch()
{
}
void skillJpunch::Fire(float playerX, float playerY)
{
	_skillJpunch.hitbox = RectMakeCenter(playerX + 140, playerY + 100, 70, 40);
	_skillJpunch.isFire = true;
}

void skillJpunch::render()
{
	if (_skillJpunch.isFire)Rectangle(getMemDC(), _skillJpunch.hitbox.left, _skillJpunch.hitbox.top, _skillJpunch.hitbox.right, _skillJpunch.hitbox.bottom);
}

HRESULT skillJpunch::init()
{
	_skillJpunch.hitbox = RectMakeCenter(0, 0, 60, 15);
	_skillJpunch.damage = 7;
	_skillJpunch.isDown = false;
	_skillJpunch.isFire = false;

	return S_OK;
}

void skillJpunch::makeisFireFalse()
{
	_skillJpunch.isFire = false;
}


skill1st::skill1st()
{
}
skill1st::~skill1st()
{
}
void skill1st::Fire(float playerX, float playerY)
{
	_skill1st.hitbox = RectMakeCenter(playerX + 200, playerY, 300, 400);
	_skill1st.isFire = true;
}

void skill1st::render()
{
	if (_skill1st.isFire)Rectangle(getMemDC(), _skill1st.hitbox.left, _skill1st.hitbox.top, _skill1st.hitbox.right, _skill1st.hitbox.bottom);
}

HRESULT skill1st::init()
{
	_skill1st.hitbox = RectMakeCenter(0, 0, 60, 15);
	_skill1st.damage = 150;
	_skill1st.isDown = true;
	_skill1st.isFire = false;

	return S_OK;
}

void skill1st::makeisFireFalse()
{
	_skill1st.isFire = false;
}




skill2nd::skill2nd()
{
}
skill2nd::~skill2nd()
{
}
void skill2nd::Fire(float playerX, float playerY)
{
	_skill2nd.hitbox = RectMakeCenter(playerX + 155, playerY + 40, 170, 90);
	_skill2nd.isFire = true;
}

void skill2nd::render()
{
	if (_skill2nd.isFire)Rectangle(getMemDC(), _skill2nd.hitbox.left, _skill2nd.hitbox.top, _skill2nd.hitbox.right, _skill2nd.hitbox.bottom);
}

HRESULT skill2nd::init()
{
	_skill2nd.hitbox = RectMakeCenter(0, 0, 60, 15);
	_skill2nd.damage = 20;
	_skill2nd.isDown = true;
	_skill2nd.isFire = false;

	return S_OK;
}

void skill2nd::makeisFireFalse()
{
	_skill2nd.isFire = false;
}


skill3rd::skill3rd()
{
}
skill3rd::~skill3rd()
{
}
void skill3rd::Fire(float playerX, float playerY)
{
	_skill3rd.hitbox = RectMakeCenter(playerX - 30, playerY + 40, 350, 450);
	_skill3rd.isFire = true;
}

void skill3rd::render()
{
	if (_skill3rd.isFire)Rectangle(getMemDC(), _skill3rd.hitbox.left, _skill3rd.hitbox.top, _skill3rd.hitbox.right, _skill3rd.hitbox.bottom);
}

HRESULT skill3rd::init()
{
	_skill3rd.hitbox = RectMakeCenter(0, 0, 60, 15);
	_skill3rd.damage = 25;
	_skill3rd.isDown = true;
	_skill3rd.isFire = false;

	return S_OK;
}

void skill3rd::makeisFireFalse()
{
	_skill3rd.isFire = false;
}