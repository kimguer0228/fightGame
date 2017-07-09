#pragma once
#include "gameNode.h"
#include "animation.h"


//�ɸ��� ������Ʈ�� ���õ� �̳ѹ� (�����غ��� ��ũ�� ���ũ�� ���� ������ �վ�ߵǿ�)
enum stateEnum
{
	idle,		// �̶��� �̵� ����
	walk,		// �̶��� �̵� ����
	backWalk,	// �̶��� �̵� ����
	jump,		// �̶��� �̵� �Ұ���, jump�� �����Ҷ� speedX ���� �޾Ƽ� x�� ���ǵ带 �ٰ�
	crouch,		// �̶��� �̵� �Ұ���, �ɾ��ִ� ����
	hit1,		// �������� �´¸�� (�Ѿ����°� x)
	hit2,		// �����鼭 ���󰡴� ��� (�Ѿ����°� o)
	standing,	// ���������� - > idle ���̿� �Ͼ�� �ִϸ��̼��� ����Ǵ� state
	punch,
	kick,
	jumpPunch,
	jumpKick,
	crouchPunch,
	crouchKick,
	skill1,
	skill2,
	skill3
};

struct tagSkill
{
	RECT hitbox;
	int damage;
	bool isDown;
	bool isFire;
	bool isPlayer1;
};

//���ӳ�带 ��ӹ��� �÷��̾��� ���� Ŭ���� �������� �̰��� ��ӹ����ø� �˴ϴ�
class playerNode : public gameNode
{
protected:

	image* _image;			//�ɸ����� �̹���
	animation* _animation;	//�ɸ����� �ִϸ��̼�
	RECT rc;				//�ɸ����� ��Ʈ ��, �ɸ����� �ǰ����� �ڽ�
	RECT pushRc;			//�ɸ��� ����� �Ÿ��� push��Ʈ
	float x, y;				//��ǥ
	float width, height;	//ĳ���� ��Ʈ�� ���ο� ����
	float speedX, speedY;	//�ӵ�
	float pushSpeedX;        //�̴¼ӵ�
	stateEnum state;		//����
	bool isRight;			//�����Ǻ��Ұ� ���� : false , ������ : true
	int maxHP;
	int currentHP;
	bool _isPlayer1;		//�÷��̾�1(true) ���� �÷��̾�2(false) ���� �Ǻ��ϴ� �Լ�
	float gravity;			//�߷°�
	int _upKey, _downKey, _rightKey, _leftKey, _punchKey, _kickKey;    //Ű�Է� ���� ����
	int CharacterNumber;	//ĳ���� ��ȣ
	bool cameraMove;		//ī�޶��̵� ���� �ް��ִ°�

	//��ų����ü
	tagSkill punch_m;
	tagSkill kick_m;
	tagSkill Cpunch_m;
	tagSkill Ckick_m;
	tagSkill Jpunch_m;
	tagSkill Jkick_m;
	tagSkill skill1_m;
	tagSkill skill2_m;
	tagSkill skill3_m;

public:
	virtual HRESULT init(bool isPlayer1, float playerX, float playerY, float playerWidth, float playerHeight, int upKey, int downKey, int leftKey, int rightKey, int punchKey, int kickKey, int Num);
	virtual void release();
	virtual void update();
	virtual void render();

	int getcurrentHP(void) { return currentHP; }
	int getmaxHP(void) { return maxHP; }

	void getdamage(int Num) { currentHP -= Num; }

	void setisRight(bool A) { isRight = A; }
	bool getisRight(void) { return isRight; }

	float getX(void) { return x; }
	void setX(float X) { x = X; }

	void setSpeed0(void) { speedX = 0; }
	int getSpeed(void) { return speedX; }
	void setPushSpeedX(float _pushSpeedX) { pushSpeedX = _pushSpeedX; }
	int getState(void) { return state; }
	void setState(stateEnum enumNum) { state = enumNum; }

	RECT getRect(void) { return rc; }
	RECT getPushRect(void) { return pushRc; }

	tagSkill getTagSkill(int number)
	{
		if (number == 1)
		{
			return punch_m;
		}
		else if (number == 2)
		{
			return kick_m;
		}
		else if (number == 3)
		{
			return Cpunch_m;
		}
		else if (number == 4)
		{
			return Ckick_m;
		}
		else if (number == 5)
		{
			return Jpunch_m;
		}
		else if (number == 6)
		{
			return Jkick_m;
		}
		else if (number == 7)
		{
			return skill1_m;
		}
		else if (number == 8)
		{
			return skill2_m;
		}
		else if (number == 9)
		{
			return skill3_m;
		}
		else return punch_m;
	}


	//�⺻ �̵� �Լ�, �ӵ��� ���� ��ǥ���� ���Ѵ�
	virtual void basicMove();


	/*
	//��3���� ������ �ޱ����� �Լ�
	virtual float getX();
	virtual int getCurrentHP();
	virtual void HPChange(int damage);
	virtual void makeIsRight(bool _isRight);
	virtual RECT getRect();
	virtual RECT getPushRect();
	virtual bool getIsRight();
	virtual void setX(float _x);
	*/

	playerNode();
	~playerNode();
};

