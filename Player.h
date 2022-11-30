#pragma once
#include "GameNode.h"

class Player : public GameNode
{
public:
	Player();
	~Player();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual HBRUSH getBrush() override;
private:

};

