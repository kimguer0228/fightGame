#pragma once

#include "playerNode.h"



class skillPunch : public playerNode
{
private:
	tagSkill _punch;

public:
	void render();

	HRESULT init(bool isPlayer1);
	skillPunch();
	~skillPunch();


	void punchFire1(float playerX, float playerY);
	void punchFire2(float playerX, float playerY);
	void makeisFireFalse(void);
	tagSkill getStruct() { return _punch; }
};
class skillKick : public playerNode
{
private:
	tagSkill _kick;

public:
	void render();

	HRESULT init(bool isPlayer1);
	skillKick();
	~skillKick();


	void kickFire1(float playerX, float playerY);
	void kickFire2(float playerX, float playerY);
	void makeisFireFalse(void);
	tagSkill getStruct() { return _kick; }
};

class skillCpunch : public playerNode
{
private:
	tagSkill _skillCpunch;

public:
	void render();

	HRESULT init(bool isPlayer1);
	skillCpunch();
	~skillCpunch();


	void CpunchFire1(float playerX, float playerY);
	void CpunchFire2(float playerX, float playerY);
	void makeisFireFalse(void);
	tagSkill getStruct() { return _skillCpunch; }
};

class skillCkick : public playerNode
{
private:
	tagSkill _skillCkick;

public:
	void render();

	HRESULT init(bool isPlayer1);
	skillCkick();
	~skillCkick();


	void Fire1(float playerX, float playerY);
	void Fire2(float playerX, float playerY);
	void makeisFireFalse(void);
	tagSkill getStruct() { return _skillCkick; }
};

class skillJkick : public playerNode
{
private:
	tagSkill _skillJkick;

public:
	void render();

	HRESULT init(bool isPlayer1);
	skillJkick();
	~skillJkick();


	void Fire1(float playerX, float playerY);
	void Fire2(float playerX, float playerY);
	void makeisFireFalse(void);
	tagSkill getStruct() { return _skillJkick; }
};
class skillJpunch : public playerNode
{
private:
	tagSkill _skillJpunch;

public:
	void render();

	HRESULT init(bool isPlayer1);
	skillJpunch();
	~skillJpunch();


	void Fire1(float playerX, float playerY);
	void Fire2(float playerX, float playerY);
	void makeisFireFalse(void);
	tagSkill getStruct() { return _skillJpunch; }
};

class skill1st : public playerNode
{
private:
	tagSkill _skill1st;

public:
	void render();

	HRESULT init(bool isPlayer1);
	skill1st();
	~skill1st();


	void Fire1(float playerX, float playerY);
	void Fire2(float playerX, float playerY);
	void makeisFireFalse(void);
	tagSkill getStruct() { return _skill1st; }
};

class skill2nd : public playerNode
{
private:
	tagSkill _skill2nd;

public:
	void render();

	HRESULT init(bool isPlayer1);
	skill2nd();
	~skill2nd();


	void Fire1(float playerX, float playerY);
	void Fire2(float playerX, float playerY);
	void makeisFireFalse(void);
	tagSkill getStruct() { return _skill2nd; }
};

class skill3rd : public playerNode
{
private:
	tagSkill _skill3rd;

public:
	void render();

	HRESULT init(bool isPlayer1);
	skill3rd();
	~skill3rd();


	void Fire1(float playerX, float playerY);
	void Fire2(float playerX, float playerY);
	void makeisFireFalse(void);
	tagSkill getStruct() { return _skill3rd; }
};


