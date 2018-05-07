#ifndef PLAYER_H
#define PLAYER_H

#include<list>
#include"Bullet.h"
#include<SFML/Graphics.hpp>
#include<iostream>
#include<SFML/Window.hpp>
using namespace std;
class Player 
{
public:
	Player (sf::RenderWindow* _window);
	virtual void Initialize();
	virtual void Position(float x, float y);
	virtual void Draw();
	virtual void Move(sf::Time deltaTime);
	virtual void Destroy();
	void HandlePlayerInputs(sf::Keyboard::Key key, bool isPressed);
	sf::Sprite sprite;
	list<Entity*>listBulletLives;
	bool dead = false;
	sf::Clock clockSpawn;
	sf::Vector2f initialPos;
private:
	void Atack();
	void CreationBullets();
	Entity*GetBullet();
	void TakeOutBullet();
	void RespawnPlayer();
	void MoveBullets(sf::Time deltaTime);
	bool moveUp=false;
	bool moveDown=false;
	bool moveLeft=false;
	bool moveRight=false;
	bool shoot=false;
	sf::RenderWindow* window;
	
	sf::Texture texture;
	sf::Clock clock;
	
	sf::Time elapsed;
	sf::Time timeSpawn;
	float fireRate;
	list<Entity*>listBulletDeads;
	
	float velocity=50;
};
#endif // !PLAYER_H