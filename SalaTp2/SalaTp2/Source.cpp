//#include"Window.hpp"
#include<SFML/Window.hpp>
#include<iostream>
#include"Game.h"
using namespace std;
int main() {
	
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
