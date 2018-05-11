#ifndef ENTITY_H
#define ENTITY_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include<SFML/Window.hpp>
using namespace std;
class Entity
{
public:
	Entity();
	virtual void Initialize()=0;
	virtual void Draw()=0;
	virtual void Position(float x, float y)=0;
	virtual void Move(sf::Time deltaTime)=0;
	virtual void Destroy()=0;
	
	sf::RenderWindow* window;
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Time timer;
	sf::Clock clock;
	float velocity;
	bool live = false;
private:
	
};

#endif // !ENTITY_H
