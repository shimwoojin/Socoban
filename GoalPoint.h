#pragma once
#include "GameNode.h"
class GoalPoint : public GameNode
{
public:
	GoalPoint() = delete;
	GoalPoint(int width, int height);
	~GoalPoint();
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual HBRUSH getBrush() override;
private:

};

