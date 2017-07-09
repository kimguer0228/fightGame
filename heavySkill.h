#pragma once

#include "playerNode.h"

struct tagSkill
{
	RECT hitbox;
	int damage;
	bool isDown;
	bool isFire;
};

class skillPunch : public playerNode
{
private:
	tagSkill _punch;

public:
	void render();

	HRESULT init();
	skillPunch();
	~skillPunch();


	void punchFire1(float playerX, float playerY);
	void punchFire2(float playerX, float playerY);
	void makeisFireFalse(void);
};
class skillKick : public playerNode
{
private:
	tagSkill _kick;

public:
	void render();

	HRESULT init();
	skillKick();
	~skillKick();


	void kickFire1(float playerX, float playerY);
	void kickFire2(float playerX, float playerY);
	void makeisFireFalse(void);
};

class skillCpunch : public playerNode
{
private:
	tagSkill _skillCpunch;

public:
	void render();

	HRESULT init();
	skillCpunch();
	~skillCpunch();


	void CpunchFire1(float playerX, float playerY);
	void CpunchFire2(float playerX, float playerY);
	void makeisFireFalse(void);
};

class skillCkick : public playerNode
{
private:
	tagSkill _skillCkick;

public:
	void render();

	HRESULT init();
	skillCkick();
	~skillCkick();


	void Fire1(float playerX, float playerY);
	void Fire2(float playerX, float playerY);
	void makeisFireFalse(void);
};

class skillJkick : public playerNode
{
private:
	tagSkill _skillJkick;

public:
	void render();

	HRESULT init();
	skillJkick();
	~skillJkick();


	void Fire1(float playerX, float playerY);
	void Fire2(float playerX, float playerY);
	void makeisFireFalse(void);
};
class skillJpunch : public playerNode
{
private:
	tagSkill _skillJpunch;

public:
	void render();

	HRESULT init();
	skillJpunch();
	~skillJpunch();


	void Fire1(float playerX, float playerY);
	void Fire2(float playerX, float playerY);
	void makeisFireFalse(void);
};

class skill1st : public playerNode
{
private:
	tagSkill _skill1st;

public:
	void render();

	HRESULT init();
	skill1st();
	~skill1st();


	void Fire1(float playerX, float playerY);
	void Fire2(float playerX, float playerY);
	void makeisFireFalse(void);
};

class skill2nd : public playerNode
{
private:
	tagSkill _skill2nd;

public:
	void render();

	HRESULT init();
	skill2nd();
	~skill2nd();


	void Fire1(float playerX, float playerY);
	void Fire2(float playerX, float playerY);
	void makeisFireFalse(void);
};

class skill3rd : public playerNode
{
private:
	tagSkill _skill3rd;

public:
	void render();

	HRESULT init();
	skill3rd();
	~skill3rd();


	void Fire1(float playerX, float playerY);
	void Fire2(float playerX, float playerY);
	void makeisFireFalse(void);
};


