#include "stdafx.h"
#include "GoalPoint.h"
#include "Brick.h"

int GoalPoint::goalCount = 0;

GoalPoint::GoalPoint(int width, int height)
{
    point = makePoint(width, height);
    Init();
}

GoalPoint::~GoalPoint()
{
}

void GoalPoint::Init()
{
    interval = 2;
    rect = makeRect(point, interval);
}

void GoalPoint::Update()
{
    if (isGoalMax())
    {
        //..게임 엔딩
    }

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

void GoalPoint::HowManyGoal(Brick& brick)
{
    RECT rt;
    if (IntersectRect(&rt, &brick.getRect(), &rect)) goalCount++;
}
