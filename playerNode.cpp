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

	//�÷��̾��� ������
	speedX = 0;
	speedY = 0;
	state = idle;
	maxHP = 100;
	currentHP = 100;

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

};

void playerNode::basicMove()
{
	float elapsedTime = TIMEMANAGER->getElapsedTime();
	float moveTime = elapsedTime * 100;

	x += speedX * moveTime;
	y += speedY * moveTime;
	speedY += gravity * moveTime;

	// �����϶�           ���������϶�           ���������϶�         �¾Ƽ� �ٿ�ǰ� ������
	if (state == jump || state == jumpKick || state == jumpPunch || state == hit2)
	{
		gravity = 0.08;
	}
	else gravity = 0;
};