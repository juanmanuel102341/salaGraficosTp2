#ifndef GAME_H
#define GAME_H
#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include"EnemyManager.h"
#include"Player.h"
#include"Collision.h"
#include"Back.h"
#include"Gui.h"
#include"Menu.h"
class Game
{
public:
	Game();
	void Run();
	int target;

private:
	void ProcessEvents();
	void Update(sf::Time deltaTime);
	void Render();
	void Restart();
	void Exit();
	sf::RenderWindow window;
	Player* newPlayer;
	Menu* menu;
	Back*back;
	Gui*gui;
	EnemyManager* enemyManage;
	sf::Time timePerFrame;
	sf::Clock cSpawn;
	sf::Time timeSpawn;
	Collision* collision;
	bool gameOver=false;
	bool terminate = false;

};
#endif // !GAME_H
