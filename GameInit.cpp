#include "stdafx.h"
#include "GameInit.h"

void drawLine()
{
	for (int i = 0; i < HEIGHT + 1; i++)
	{
		MoveToEx(g_hDC, 0, i * INTERVAL, NULL);
		LineTo(g_hDC, WINSIZE_X, i * INTERVAL);
	}

	for (int i = 0; i < WIDTH + 1; i++)
	{
		MoveToEx(g_hDC, i * INTERVAL, 0, NULL);
		LineTo(g_hDC, i * INTERVAL, WINSIZE_Y);
	}
}

POINT makePoint(int width, int height)
{
	POINT point;
	point.x = width * INTERVAL;
	point.y = height * INTERVAL;

	return point;
}

RECT makeRect(const POINT& point, int interval)
{
	RECT rect;
	rect.left = point.x + interval;
	rect.right = point.x + INTERVAL - interval;
	rect.top = point.y + interval;
	rect.bottom = point.y + INTERVAL - interval;

	return rect;
}
