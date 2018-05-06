//#include"Window.hpp"
#include<SFML/Window.hpp>
#include<iostream>
#include"Game.h"
#include<Windows.h>
using namespace std;
#ifdef _DEBUG 
const bool is_debig = true;
#else 
const bool is_debig = false;
#endif 
int main() {

	if (is_debig == false) {
		HWND hWnd = GetConsoleWindow();
		ShowWindow(hWnd, SW_HIDE);
	}
	
	
	Game game;
	game.Run();
		
	
	//GameManager*gameManager = new GameManager();
	//sf::RenderWindow window(sf::VideoMode(gameManager->screenWidth, gameManager->screenHeight), "My window");
	//window.setFramerateLimit(60);
	//gameManager->window = &window;
	
//	gameManager->Init();
	
	//sf::Texture textureBack;
	//if (!textureBack.loadFromFile("assets/space.png")) {
		//std::cout << "error";
	//};
   // sf::Sprite spriteBack;
	//spriteBack.setTexture(textureBack);
	//sf::Event event;
	//sf::Clock clock;
	/*
	while (window.isOpen())
	{
		


		while (window.pollEvent(event))
		{
			switch (event.type)
			{
				
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				break;
			default:
				break;
			}
			
		}
		
		window.clear(sf::Color::Black);
		window.draw(spriteBack);
		gameManager->UpdateDraw();
		
		window.display();

	}
	*/
	return 0;
}
