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
	skill3,
	stateEnumEnd
};

//���ӳ�带 ��ӹ��� �÷��̾��� ���� Ŭ���� �������� �̰��� ��ӹ����ø� �˴ϴ�
class playerNode : public gameNode
{
protected:

	image* _image;			//�ɸ����� �̹���
	animation* _animation;	//�ɸ����� �ִϸ��̼�
	animation* _playerAni[stateEnumEnd];	//�ɸ��� �ִϸ��̼� �迭����!
	RECT rc;				//�ɸ����� ��Ʈ ��, �ɸ����� �ǰ����� �ڽ�
	float x, y;				//��ǥ
	float width, height;	//ĳ���� ��Ʈ�� ���ο� ����
	float speedX, speedY;	//�ӵ�
	stateEnum state;		//����
	bool isRight;			//�����Ǻ��Ұ� ���� : false , ������ : true
	int maxHP;
	int currentHP;
	bool _isPlayer1;		//�÷��̾�1(true) ���� �÷��̾�2(false) ���� �Ǻ��ϴ� �Լ�
	float gravity;			//�߷°�
	int _upKey, _downKey, _rightKey, _leftKey, _punchKey, _kickKey;    //Ű�Է� ���� ����
	int CharacterNumber;	//ĳ���� ��ȣ
	bool cameraMove;		//ī�޶��̵� ���� �ް��ִ°�

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

	RECT getRect(void) { return rc; }


	//�⺻ �̵� �Լ�, �ӵ��� ���� ��ǥ���� ���Ѵ�
	virtual void basicMove();



	playerNode();
	~playerNode();
};

