#include "stdafx.h"
#include "Game.h"
#include "Wall.h"
#include "Player.h"
#include "GoalPoint.h"
#include "Brick.h"

Game::Game()
{
	Init();
}

Game::~Game()
{
	if(player)
	{
		delete player;
		player = nullptr;
	}
	if (wall)
	{
		delete wall;
		wall = nullptr;
	}
	if (brick)
	{
		delete[] brick;
		brick = nullptr;
	}
	if (goalpoint)
	{
		delete[] goalpoint;
		goalpoint = nullptr;
	}
}

void Game::Init()
{
	player = new Player;
	wall = new Wall;
	brick = new Brick[GOAL]
	{ 
	Brick(1,10), Brick(2,8), Brick(10,8), Brick(11,3),
	Brick(12,3), Brick(14,16), Brick(18,8), Brick(19,9),
	Brick(24,7), Brick(28,15), Brick(30,14)
	};
	goalpoint = new GoalPoint[GOAL]
	{
	GoalPoint(1,14), GoalPoint(2,14), GoalPoint(2,16), GoalPoint(15,8),
	GoalPoint(21,13), GoalPoint(27,1), GoalPoint(27,2), GoalPoint(22,13),
	GoalPoint(27,4), GoalPoint(29,1), GoalPoint(30,1)
	};
}

void Game::Update()
{
	KeyManager::Get().Update();

	if (wall != nullptr) wall->Update();
	if (brick != nullptr){
		for (int i = 0; i < GOAL; i++){
			brick[i].Update();
		}
	}
	if (goalpoint != nullptr) {
		for (int i = 0; i < GOAL; i++) {
			goalpoint[i].Update();
		}
	}
	if(player != nullptr) player->Update();
}

void Game::Render()
{
	PAINTSTRUCT ps;

	HDC hdc = BeginPaint(g_hWnd, &ps);

	PatBlt(g_hDC, 0, 0, WINSIZE_X, WINSIZE_Y, WHITENESS);

	drawLine();

	if (wall != nullptr) wall->Render();
	if (brick != nullptr) {
		for (int i = 0; i < GOAL; i++) {
			brick[i].Render();
		}
	}
	if (goalpoint != nullptr) {
		for (int i = 0; i < GOAL; i++) {
			goalpoint[i].Render();
		}
	}
	if (player != nullptr)	player->Render();

	BitBlt(hdc, 0, 0, WINSIZE_X, WINSIZE_Y, g_hDC, 0, 0, SRCCOPY);

	EndPaint(g_hWnd, &ps);
}
