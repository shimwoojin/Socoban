#include "stdafx.h"
#include "GoalPoint.h"

GoalPoint::GoalPoint(int width, int height)
{
    point = makePoint(width, height);
    rect = makeRect(point, 3);
}

GoalPoint::~GoalPoint()
{
}

void GoalPoint::Init()
{
}

void GoalPoint::Update()
{
}

void GoalPoint::Render()
{
    HBRUSH mybrush = getBrush();
    SelectObject(g_hDC, mybrush);

    Rectangle(g_hDC, rect.left, rect.top, rect.right, rect.bottom);

    DeleteObject(mybrush);
}

HBRUSH GoalPoint::getBrush()
{
    return (HBRUSH)CreateSolidBrush(RGB(0, 0, 0xff));
}
