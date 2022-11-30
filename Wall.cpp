#include "stdafx.h"
#include "Wall.h"

Wall::Wall()
{
	Init();
}

Wall::~Wall()
{
}

void Wall::Init()
{
	point = makePoint(0, 0);
	rect = makeRect(point, 2);
}

void Wall::Update()
{
}

void Wall::Render()
{
	HBRUSH mybrush = getBrush();
	SelectObject(g_hDC, mybrush);

	int left, right, top, bottom;
	int interval = 4;

	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			left = j * INTERVAL + interval;
			right = (j + 1) * INTERVAL - interval;
			top = i * INTERVAL + interval;
			bottom = (i + 1) * INTERVAL - interval;

			if (map[i][j] == 1)
				Rectangle(g_hDC, left, top, right, bottom);
		}
	}

	DeleteObject(mybrush);
}

HBRUSH Wall::getBrush()
{
	return (HBRUSH)CreateSolidBrush(RGB(0, 0, 0));	//black
}
