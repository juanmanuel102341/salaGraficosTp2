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
			back->Draw();
			menu->Draw();
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
	while (window.isOpen())
	{
		sf::Time deltaTime = clock.restart();
		//std::cout << deltaTime.asSeconds() << endl;
		ProcessEvents();
		Update(deltaTime);
		Render();
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
	if (isRelease) {
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);
	}

	target = 5;
	std::cout << "inicio juego" << endl;
	//window.create(sf::VideoMode(800, 600), "My window");
	
	window.create(sf::VideoMode(800, 600), "My window");
	back = new Back();
	back->window = &window;
	back->Initialize();
	menu = new Menu(&window);
	menu->Init();

	gui = new Gui();
	gui->window = &window;
	gui->initialTarget = target;
	gui->Initialize();
	newPlayer = new Player(&window);
	enemyManage = new EnemyManager(newPlayer);
	enemyManage->window =&window;
	enemyManage->Init();
	collision = new Collision(enemyManage,newPlayer);
	collision->gui = gui;
		
	
	Run();
}
Game::~Game() {
	std::cout << "destruccion game" << endl;

	delete enemyManage;
	delete newPlayer;
	delete back;
	delete menu;
	delete gui;
	delete collision;

}