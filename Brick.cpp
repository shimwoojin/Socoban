#include "stdafx.h"
#include "Brick.h"
#include "Player.h"

Brick::Brick(int width, int height)
{
    point = makePoint(width, height);
    Init();
}

Brick::~Brick()
{
}

void Brick::Init()
{
    interval = 3;
    rect = makeRect(point, interval);
}

void Brick::Update()
{
}

void Brick::Render()
{
    HBRUSH mybrush = getBrush();
    SelectObject(g_hDC, mybrush);

    Rectangle(g_hDC, rect.left, rect.top, rect.right, rect.bottom);

    DeleteObject(mybrush);
}

HBRUSH Brick::getBrush()
{
    return (HBRUSH)CreateSolidBrush(RGB(0, 0xff, 0));
}

bool Brick::canBrickMove(Brick& brick, const Player* player)
{
    RECT rt;
    RECT ifMove;

    switch (player->getDir())
    {
    case Player::DIR::left:
    {
        ifMove = makeRect( { point.x - INTERVAL, point.y }, interval);
        if (IntersectRect(&rt, &brick.getRect(), &ifMove)) return false;
    }
        break;
    case Player::DIR::right:
    {
        ifMove = makeRect({ point.x + INTERVAL, point.y }, interval);
        if (IntersectRect(&rt, &brick.getRect(), &ifMove)) return false;
    }
        break;
    case Player::DIR::up:
    {
        ifMove = makeRect({ point.x, point.y - INTERVAL}, interval);
        if (IntersectRect(&rt, &brick.getRect(), &ifMove)) return false;
    }
        break;
    case Player::DIR::down:
    {
        ifMove = makeRect({ point.x, point.y + INTERVAL }, interval);
        if (IntersectRect(&rt, &brick.getRect(), &ifMove)) return false;
    }
        break;
    default:
        break;
    }

    return true;
}
