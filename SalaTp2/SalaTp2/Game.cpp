#include"Game.h"


void Game::Render() {
	window.clear();
	if (!gameOver) {
		back->Draw();
		gui->Draw();
		newPlayer->Draw();
		enemyManage->Draw();
	}
	else {
		if (!terminate) {
			back->Draw();
			menu->Draw();
		}

	}

	window.display();

}
void Game::Update(sf::Time deltaTime) {
	if (!gameOver) {
		back->Move(deltaTime);
		newPlayer->Move(deltaTime);
		enemyManage->Move(deltaTime);
		collision->CollideBulletEnemy();
		collision->CollideEnemyPlayer();
		collision->CollideBulletPlayer();
		if (target == gui->num_Planes) {
			std::cout << "victory" << endl;
			enemyManage->TakeOutAll();
			gameOver = true;
			menu->win = true;
		}
		if (gui->n <= 0) {
			std::cout << "loose" << endl;
			enemyManage->TakeOutAll();
			gameOver = true;
			menu->win = false;
		}
	}
	else {
	//	std::cout << "final menu" << endl;
		if (menu->Finish()) {
			std::cout << "eleccion final" << endl;
			if (menu->res == Menu::Result::restart) {
				std::cout << "restart" << endl;
				Restart();
			}
			else {
				std::cout << "exit" << endl;
				Exit();
				window.close();
			}
		}
	}
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
		case sf::Event::MouseButtonPressed:
			if (gameOver) {
				menu->HandleMouseEvent(event.mouseButton.x, event.mouseButton.y);
			}
		
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



void Game::Restart(){

	gameOver = false;
	menu->myFinish = false;
	menu->win = false;
	gui->n =gui->initialLife;
	gui->ResetLife();
	gui->num_Planes = 0;
	gui->ResetPlanes();
	
	newPlayer->Position(newPlayer->initialPos.x,newPlayer->initialPos.y);
	enemyManage->clock.restart();

}
void Game::Exit(){
	terminate = true;//me tira error posteriormente cuando ingresa a render por eso booleano, asi puedo borrar back y gui
	enemyManage->DeleteMe();
	delete newPlayer;
	delete menu;
	delete back;
	delete gui;
	delete enemyManage;
	delete collision;
	
}
Game::Game() {
	target = 5;
	std::cout << "inicio juego" << endl;
	window.create(sf::VideoMode(800, 600), "My window");
	
	menu = new Menu(&window);
	menu->Init();

	gui = new Gui();
	gui->window = &window;
	gui->initialTarget = target;
	gui->Initialize();
	
	back = new Back();
	back->window = &window;
	back->Initialize();

	newPlayer = new Player(&window);
	enemyManage = new EnemyManager(newPlayer);
	enemyManage->window =&window;
	enemyManage->Init();

	collision = new Collision(enemyManage,newPlayer);
	collision->gui = gui;
	//timePerFrame = sf::seconds(1.f / 60.f);
	timeSpawn = cSpawn.restart();

}