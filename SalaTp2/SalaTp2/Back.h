#ifndef BACK_H
#define BACK_H
#include"Entity.h"
class Back: public Entity
{
public:
	Back();
	virtual void Initialize();
	virtual void Position(float x, float y);
	virtual void Draw();
	virtual void Move(sf::Time deltaTime);
	virtual void Destroy();

private:
	sf::Sprite sprite2;


};
#endif // !BACK_H
