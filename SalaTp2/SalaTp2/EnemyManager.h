#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H
#include<vector>
#include<list>
#include"EnemyA.h"
#include"Entity.h"
#include"Enemigo.h"
#include<SFML/Window.hpp>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
using namespace std;
#include"Player.h"
class EnemyManager
{
public:
	EnemyManager(Player* _player);
	void Init();
	void Draw();
	void Move(sf::Time deltaTime);
//	~EnemyManager();
	void SpawnA();
	Enemigo* GetEnemy();
	void TakeOut();
	sf::RenderWindow* window;


	Enemigo* enemiesA;
	std::list<Enemigo*>listDead;
	std::list<Enemigo*>listLive;
	
private:
	sf::Clock clock;
	sf::Time elapsed;
	Player*player;
};

#endif // !ENEMY_MANAGER_H

