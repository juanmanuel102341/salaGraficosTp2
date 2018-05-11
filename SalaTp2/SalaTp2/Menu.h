#ifndef MENU_H
#define MENU_H
#include<SFML/Graphics.hpp>
#include<iostream>
#include<SFML/Window.hpp>

class Menu
{
public:
	enum Result{restart,exit};
	Menu(sf::RenderWindow* _window);
	void Init();
	void Draw();
	void HandleMouseEvent(int x, int y);
	bool Finish();
	sf::Sprite spriteBack;
	sf::Texture textureBack;

	sf::Sprite spriteRestart;
	sf::Texture textureRestart;

	sf::Sprite spriteExit;
	sf::Texture textureExit;

	sf::Font fontFinal;

	sf::Text textWin;
	sf::Text textLoose;

	bool win = false;
	bool myFinish=false;
	Result res;
private:
	sf::RenderWindow* window;
	

};
#endif // !MENU_H
