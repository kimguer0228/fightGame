#include "stdafx.h"
#include "playerNode.h"


playerNode::playerNode()
{
}


playerNode::~playerNode()
{
}


//�÷��̾� ���� �ʱ�ȭ �Լ�
HRESULT playerNode::init(bool isPlayer1, float playerX, float playerY, float playerWidth, float playerHeight, int upKey, int downKey, int leftKey, int rightKey, int punchKey, int kickKey, int Num)
{
	//Ű ���� ����
	_upKey = upKey;
	_downKey = downKey;
	_leftKey = leftKey;
	_rightKey = rightKey;
	_punchKey = punchKey;
	_kickKey = kickKey;

	//�÷��̾� ��Ʈ ���� ����
	x = playerX;
	y = playerY;
	width = playerWidth;
	height = playerHeight;

	//�÷��̾� ��Ʈ
	rc = RectMakeCenter(x, y, width, height);

	//�÷��̾� ���� ��Ʈ
	pushRc = RectMakeCenter(x, y + 60, 100, 2);

	//�÷��̾��� ������
	speedX = 0;
	speedY = 0;
	state = idle;
	maxHP = 100;
	currentHP = 100;
	pushSpeedX = 0;

	//1�� ����
	_isPlayer1 = isPlayer1;

	//�߷��ʱ�ȭ
	gravity = 0;

	//ĳ���� ��ȣ �ʱ�ȭ
	CharacterNumber = Num;
	

	return S_OK;
};
void playerNode::release()
{

};
void playerNode::update()
{
	basicMove();
	if (currentHP < 0) currentHP = 0;
};
void playerNode::render()
{
	//Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	//Rectangle(getMemDC(), pushRc.left, pushRc.top, pushRc.right, pushRc.bottom);
};

void playerNode::basicMove()
{
	float elapsedTime = TIMEMANAGER->getElapsedTime();
	float moveTime = elapsedTime * 100;

	x += (speedX * moveTime + pushSpeedX); 
	y += speedY * moveTime;
	speedY += gravity * moveTime;

	// �����϶�           ���������϶�           ���������϶�         �¾Ƽ� �ٿ�ǰ� ������
	if (state == jump || state == jumpKick || state == jumpPunch || state == hit2)
	{
		gravity = 0.08;
	}
	else gravity = 0;

	rc = RectMakeCenter(x, y + 100, width, height);
	pushRc = RectMakeCenter(x, y + 100, 20, height / 2);
};


/*
//��3�� �߰��Ǵ� �Լ���

float playerNode::getX()
{
	return x;
}
int playerNode::getCurrentHP()
{
	return currentHP;
}

bool playerNode::getIsRight()
{
	return isRight;
}

void playerNode::HPChange(int damage)
{
	currentHP -= damage;
	if (currentHP >= 100) currentHP = 100;
	if (currentHP <= 0) currentHP = 0;
}

void playerNode::makeIsRight(bool _isRight)
{
	isRight = _isRight;
}

RECT playerNode::getRect()
{
	return rc;
}

RECT playerNode::getPushRect()
{
	return pushRc;
}

void playerNode::setX(float _x)
{
	x = _x;
}
*/