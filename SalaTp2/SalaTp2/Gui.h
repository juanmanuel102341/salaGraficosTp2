#ifndef GUI_H
#define GUI_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include<SFML/Window.hpp>
#include<string>
class Gui
{
public:
	Gui();
	void Initialize();
	void Draw();
	void ChangeLife();
	void ChangePlanes();
	void ResetLife();
	void ResetPlanes();
	sf::RenderWindow* window;
	int num_Planes = 0;
	int n = 3;
	int initialLife;
	int initialTarget;
private:
	sf::Font fontLife;
	sf::Text textLife;
	sf::Text numLife;
	sf::Text texPlanes;
	sf::Text numPlanes;
	sf::Text textTarget;
	sf::Text numTarget;
	
	
};

#endif // !GUI_H
