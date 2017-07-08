#pragma once
#include "gameNode.h"

struct tagSkill
{
	RECT hitbox;
	int damage;
	bool isDown;
	bool isFire;
};

class skillPunch : public gameNode
{
private:
	tagSkill _punch;

public:
	void render();

	HRESULT init();
	skillPunch();
	~skillPunch();


	void punchFire(float playerX, float playerY);
	void makeisFireFalse(void);
};
class skillKick : public gameNode
{
private:
	tagSkill _kick;

public:
	void render();

	HRESULT init();
	skillKick();
	~skillKick();


	void kickFire(float playerX, float playerY);
	void makeisFireFalse(void);
};

class skillCpunch : public gameNode
{
private:
	tagSkill _skillCpunch;

public:
	void render();

	HRESULT init();
	skillCpunch();
	~skillCpunch();


	void CpunchFire(float playerX, float playerY);
	void makeisFireFalse(void);
};

class skillCkick : public gameNode
{
private:
	tagSkill _skillCkick;

public:
	void render();

	HRESULT init();
	skillCkick();
	~skillCkick();


	void Fire(float playerX, float playerY);
	void makeisFireFalse(void);
};

class skillJkick : public gameNode
{
private:
	tagSkill _skillJkick;

public:
	void render();

	HRESULT init();
	skillJkick();
	~skillJkick();


	void Fire(float playerX, float playerY);
	void makeisFireFalse(void);
};
class skillJpunch : public gameNode
{
private:
	tagSkill _skillJpunch;

public:
	void render();

	HRESULT init();
	skillJpunch();
	~skillJpunch();


	void Fire(float playerX, float playerY);
	void makeisFireFalse(void);
};

class skill1st : public gameNode
{
private:
	tagSkill _skill1st;

public:
	void render();

	HRESULT init();
	skill1st();
	~skill1st();


	void Fire(float playerX, float playerY);
	void makeisFireFalse(void);
};

class skill2nd : public gameNode
{
private:
	tagSkill _skill2nd;

public:
	void render();

	HRESULT init();
	skill2nd();
	~skill2nd();


	void Fire(float playerX, float playerY);
	void makeisFireFalse(void);
};

class skill3rd : public gameNode
{
private:
	tagSkill _skill3rd;

public:
	void render();

	HRESULT init();
	skill3rd();
	~skill3rd();


	void Fire(float playerX, float playerY);
	void makeisFireFalse(void);
};


