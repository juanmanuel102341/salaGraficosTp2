#ifndef ENEMIGO_H
#define ENEMIGO_H
#include"Entity.h"
#include<list>
class Enemigo: public Entity

{
public:
	Enemigo();
	~Enemigo();
	virtual void Initialize()=0;
	virtual void Draw()=0;
	virtual void Position(float x, float y)=0;
	virtual void Move(sf::Time deltaTime)=0;
	virtual void Destroy()=0 ;
	virtual void Persuit(sf::Vector2f posPlayer) = 0;
	virtual void TakeOutBullet() = 0;
	virtual void DeleteBullet() = 0;
	list<Entity*>listBulletLives;
	list<Entity*>listBulletDeads;
private:

};

#endif // !ENEMIGO_H

