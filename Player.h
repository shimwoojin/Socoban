#pragma once
#include "GameNode.h"

class Player : public GameNode
{
public:
	enum class DIR{ left, right, up, down };
public:
	Player();
	~Player();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual HBRUSH getBrush() override;

	void pushBrick(class Brick& brick);

	const DIR& getDir() const { return dir; }

	void moveCancel(class Brick& brick);

private:
	void move();

	DIR dir;
};

