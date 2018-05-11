#ifndef GAME_MANAGER_H

#define GAME_MANAGER_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include<SFML/Window.hpp>
#include"Entity.h"
#include"Player.h"
#include"EnemyManager.h"
class GameManager
{
public:
	int screenWidth=800;
	int screenHeight=600;
	GameManager();
	void Init();
	void UpdateDraw();
	void DestroyEntity();
	sf::RenderWindow* window;
	Entity*basePlayer;
	EnemyManager*enemyManager;
private:
	

};




#endif // !GAME_MANAGER_H

