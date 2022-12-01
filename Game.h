#pragma once

class Game
{
public:
	Game();
	~Game();

	void Init();
	void Update();
	void Render();

	bool getGameEnd() const { return gameEnd; }
	void setGameEnd(bool state) { gameEnd = state; }

	bool getReStartGame() const { return reStartGame; }
	void setReStartGame(bool state) { reStartGame = state; }
	void reGame();

private:
	class Player* player;
	class Wall* wall;
	class Brick* brick;
	class GoalPoint* goalpoint;

	bool gameEnd;
	bool reStartGame;
};

