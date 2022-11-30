#pragma once
#include "GameNode.h"
class Brick : public GameNode
{
public:
	Brick() = delete;
	Brick(int width, int height);
	~Brick();
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual HBRUSH getBrush() override;
private:

};

