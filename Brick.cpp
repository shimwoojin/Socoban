#include "stdafx.h"
#include "Brick.h"

Brick::Brick(int width, int height)
{
    point = makePoint(width, height);
    rect = makeRect(point, 3);
}

Brick::~Brick()
{
}

void Brick::Init()
{
    
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
