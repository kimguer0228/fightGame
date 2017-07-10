#pragma once
#include "playerNode.h"

class leonaPunch : public playerNode
{
private:
	tagSkill _punch;

public:
	void render();

	HRESULT init(bool isPlayer1);
	leonaPunch();
	~leonaPunch();


	void punchFire1(float playerX, float playerY);
	void punchFire2(float playerX, float playerY);
	void makeisFireFalse(void);
	tagSkill getStruct() { return _punch; }
};

class leonaKick : public playerNode
{
private:
	tagSkill _kick;

public:
	void render();

	HRESULT init(bool isPlayer1);
	leonaKick();
	~leonaKick();


	void kickFire1(float playerX, float playerY);
	void kickFire2(float playerX, float playerY);
	void makeisFireFalse(void);
	tagSkill getStruct() { return _kick; }
};

class leonaCpunch : public playerNode
{
private:
	tagSkill _skillCpunch;

public:
	void render();

	HRESULT init(bool isPlayer1);
	leonaCpunch();
	~leonaCpunch();


	void CpunchFire1(float playerX, float playerY);
	void CpunchFire2(float playerX, float playerY);
	void makeisFireFalse(void);
	tagSkill getStruct() { return _skillCpunch; }
};

class leonaCkick : public playerNode
{
private:
	tagSkill _skillCkick;

public:
	void render();

	HRESULT init(bool isPlayer1);
	leonaCkick();
	~leonaCkick();


	void Fire1(float playerX, float playerY);
	void Fire2(float playerX, float playerY);
	void makeisFireFalse(void);
	tagSkill getStruct() { return _skillCkick; }
};

class leonaJkick : public playerNode
{
private:
	tagSkill _skillJkick;

public:
	void render();

	HRESULT init(bool isPlayer1);
	leonaJkick();
	~leonaJkick();


	void Fire1(float playerX, float playerY);
	void Fire2(float playerX, float playerY);
	void makeisFireFalse(void);
	tagSkill getStruct() { return _skillJkick; }
};

class leonaJpunch : public playerNode
{
private:
	tagSkill _skillJpunch;

public:
	void render();

	HRESULT init(bool isPlayer1);
	leonaJpunch();
	~leonaJpunch();


	void Fire1(float playerX, float playerY);
	void Fire2(float playerX, float playerY);
	void makeisFireFalse(void);
	tagSkill getStruct() { return _skillJpunch; }
};

class leonaSkill1 : public playerNode
{
private:
	tagSkill _skill1st;

public:
	void render();

	HRESULT init(bool isPlayer1);
	leonaSkill1();
	~leonaSkill1();


	void Fire1(float playerX, float playerY);
	void Fire2(float playerX, float playerY);
	void makeisFireFalse(void);
	tagSkill getStruct() { return _skill1st; }
};

class leonaSkill2 : public playerNode
{
private:
	tagSkill _skill2nd;

public:
	void render();

	HRESULT init(bool isPlayer1);
	leonaSkill2();
	~leonaSkill2();


	void Fire1(float playerX, float playerY);
	void Fire2(float playerX, float playerY);
	void makeisFireFalse(void);
	tagSkill getStruct() { return _skill2nd; }
};

class leonaSkill3 : public playerNode
{
private:
	tagSkill _skill3rd;

public:
	void render();

	HRESULT init(bool isPlayer1);
	leonaSkill3();
	~leonaSkill3();


	void Fire1(float playerX, float playerY);
	void Fire2(float playerX, float playerY);
	void makeisFireFalse(void);
	tagSkill getStruct() { return _skill3rd; }
};
