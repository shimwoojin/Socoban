#include "stdafx.h"
#include "Player.h"
#include "Wall.h"

Player::Player()
{
    Init();
}

Player::~Player()
{
}

void Player::Init()
{
    point = makePoint(1, 1);
    rect = makeRect(point, 4);
}

void Player::Update()
{
	int indexX = point.x / INTERVAL;
	int indexY = point.y / INTERVAL;


	if (KeyManager::Get().IsDown(VK_LEFT)
		/*|| KeyManager::Get().IsState(VK_LEFT))*/)
	{
		if (point.x > 0 && map[indexY][indexX - 1] == 0 ) point.x -= INTERVAL;
	}

	if (KeyManager::Get().IsDown(VK_RIGHT)
		/*|| KeyManager::Get().IsState(VK_RIGHT))*/)
	{
		if (point.x < WINSIZE_X && map[indexY][indexX + 1] == 0) point.x += INTERVAL;
	}

	if (KeyManager::Get().IsDown(VK_UP))
	{
		if (point.y > 0 && map[indexY - 1][indexX] == 0) point.y -= INTERVAL;
	}

	if (KeyManager::Get().IsDown(VK_DOWN))
	{
		if (point.y < WINSIZE_Y && map[indexY + 1][indexX] == 0) point.y += INTERVAL;
	}
	
	rect = makeRect(point, 4);

}

void Player::Render()
{
    HBRUSH mybrush = getBrush();
    SelectObject(g_hDC, mybrush);

    Rectangle(g_hDC, rect.left, rect.top, rect.right, rect.bottom);

    DeleteObject(mybrush);
}

HBRUSH Player::getBrush()
{
    return (HBRUSH)CreateSolidBrush(RGB(0xff, 0, 0));
}
