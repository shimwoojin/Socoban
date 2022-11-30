#pragma once

class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update();
	void Render();

private:
	class Player* player;
	class Wall* wall;
	class Brick* brick;
	class GoalPoint* goalpoint;
};

