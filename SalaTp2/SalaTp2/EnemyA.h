#ifndef ENEMY_A_H
#define ENEMY_A_H
#include"Enemigo.h"

#include<stdio.h>
#include<math.h>
#include<list>
#include"Bullet.h"
class EnemyA: public Enemigo
{
public:
	EnemyA();
	~EnemyA();
	virtual void Initialize();
	virtual void Position(float x, float y);
	virtual void Draw();
	virtual void Move(sf::Time deltaTime);
	virtual void Destroy();
	virtual void TakeOutAllBullets();
	virtual void DeleteBullet();
	void Persuit(sf::Vector2f posPlayer);
	
	
private:
	sf::Vector2f vecPersuit;
	float propx;
	float propy;
	float distance;
	int directiony = 1;
	
	void CreationBullet();
	Entity*GetBullet();
	void TakeOutBullet();

	void MoveBullets(sf::Time deltaTime);
	float fireRate;
	//sf::Vector2f vecPLayer;
};


#endif // !ENEMY_A_H
