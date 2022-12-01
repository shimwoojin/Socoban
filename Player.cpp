#include "stdafx.h"
#include "Player.h"
#include "Wall.h"
#include "Brick.h"
#include "GameNode.h"

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
	interval = 4;
    rect = makeRect(point, interval);
	dir = (DIR)NULL;
}

void Player::Update()
{
	move();
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

void Player::pushBrick(Brick& brick)
{
	RECT rt;
	RECT brickRect;
	int indexX = brick.getPoint().x / INTERVAL;
	int indexY = brick.getPoint().y / INTERVAL;

	if (IntersectRect(&rt, &brick.getRect(), &rect))
	{
		switch (dir)
		{
		case Player::DIR::left:
		{
			if (brick.getPoint().x > 0 && map[indexY][indexX - 1] == 0)
			{
				brick.setPoint({ brick.getPoint().x - INTERVAL, brick.getPoint().y } );
			}
		}
			break;
		case Player::DIR::right:
		{
			if (brick.getPoint().x < WINSIZE_X && map[indexY][indexX + 1] == 0)
			{
				brick.setPoint({ brick.getPoint().x + INTERVAL, brick.getPoint().y });
			}
		}
			break;
		case Player::DIR::up:
		{
			if (brick.getPoint().y > 0 && map[indexY - 1][indexX] == 0)
			{
				brick.setPoint({ brick.getPoint().x, brick.getPoint().y - INTERVAL });
			}
		}
			break;
		case Player::DIR::down:
		{
			if (brick.getPoint().y < WINSIZE_Y && map[indexY + 1][indexX] == 0)
			{
				brick.setPoint({ brick.getPoint().x, brick.getPoint().y + INTERVAL });
			}
		}
			break;
		default:
			break;
		}
	}
	brickRect = makeRect(brick.getPoint(), brick.getInterval());
	brick.setRect(brickRect);
}

void Player::moveCancel(Brick& brick)
{
	RECT rt;
	if (IntersectRect(&rt, &rect, &brick.getRect()))
	{
		switch (dir)
		{
		case Player::DIR::left:
		{
			point.x += INTERVAL;
				rect = makeRect(point, interval);
		}
		break;
		case Player::DIR::right:
		{
			point.x -= INTERVAL;
			rect = makeRect(point, interval);
		}
		break;
		case Player::DIR::up:
		{
			point.y += INTERVAL;
			rect = makeRect(point, interval);
		}
		break;
		case Player::DIR::down:
		{
			point.y -= INTERVAL;
			rect = makeRect(point, interval);
		}
		break;
		default:
			break;
		}
	}
}

void Player::move()
{
	int indexX = point.x / INTERVAL;
	int indexY = point.y / INTERVAL;

	if (KeyManager::Get().IsDown(VK_LEFT)
		/*|| KeyManager::Get().IsState(VK_LEFT))*/)
	{
		if (point.x > 0 && map[indexY][indexX - 1] == 0)
		{
			point.x -= INTERVAL;
			dir = DIR::left;
		}
	}

	if (KeyManager::Get().IsDown(VK_RIGHT)
		/*|| KeyManager::Get().IsState(VK_RIGHT))*/)
	{
		if (point.x < WINSIZE_X && map[indexY][indexX + 1] == 0)
		{
			point.x += INTERVAL;
			dir = DIR::right;
		}
	}

	if (KeyManager::Get().IsDown(VK_UP))
	{
		if (point.y > 0 && map[indexY - 1][indexX] == 0)
		{
			point.y -= INTERVAL;
			dir = DIR::up;
		}
	}

	if (KeyManager::Get().IsDown(VK_DOWN))
	{
		if (point.y < WINSIZE_Y && map[indexY + 1][indexX] == 0)
		{
			point.y += INTERVAL;
			dir = DIR::down;
		}
	}

	rect = makeRect(point, interval);
}
