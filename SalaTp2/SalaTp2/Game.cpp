#include"Game.h"


void Game::Render(){
	window.clear();
	back->Draw();
	if(!newPlayer->dead)
	newPlayer->Draw();
	
	enemyManage->Draw();
	window.display();

}
void Game::Update(sf::Time deltaTime){
	back->Move(deltaTime);
	newPlayer->Move(deltaTime);
	enemyManage->Move(deltaTime);
	collision->CollideBulletEnemy();
	collision->CollideEnemyPlayer();
	collision->CollideBulletPlayer();
}
void Game::ProcessEvents(){
	sf::Event event;
	
	while (window.pollEvent(event)) {
		switch (event.type)
		{

		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::KeyPressed:
			newPlayer->HandlePlayerInputs(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			newPlayer->HandlePlayerInputs(event.key.code, false);
			break;
		default:
			break;
		}
	}
}
void Game::Run(){
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (window.isOpen())
	{
		sf::Time deltaTime = clock.restart();
		//sf::Time elapsed = clock.restart();
		//std::cout << deltaTime.asSeconds() << endl;
		ProcessEvents();
		Update(deltaTime);
		//timeSinceLastUpdate += clock.restart();
		/*while (timeSinceLastUpdate > timePerFrame)
		{//[ara garantizarme q corra con la misma cantidad de frames y no haya problemas en colisiones 
			timeSinceLastUpdate -= timePerFrame;
			ProcessEvents();
			Update(timePerFrame);
		
		}*/
		
		Render();
		//clock.restart();
	}
	
}




Game::Game() {
	std::cout << "inicio juego" << endl;
	window.create(sf::VideoMode(800, 600), "My window");

	back = new Back();
	back->window = &window;
	back->Initialize();
	newPlayer = new Player(&window);
	enemyManage = new EnemyManager(newPlayer);
	enemyManage->window =&window;
	enemyManage->Init();

	collision = new Collision(enemyManage,newPlayer);
	//timePerFrame = sf::seconds(1.f / 60.f);
	

}