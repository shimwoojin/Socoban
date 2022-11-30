#include "stdafx.h"
#include "GameNode.h"

GameNode::GameNode()
{
	point = makePoint(0, 0);
	rect = makeRect(point, 1);
}
