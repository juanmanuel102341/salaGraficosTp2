#include "Player.h"

Player::Player(sf::RenderWindow* _window) {
	//timer = sf::seconds(0.01f);
	//velocity = 350;
	fireRate = 0.3f;
	window = _window;
	Initialize();
	velocity = 250;
	dead = false;
}
void Player::HandlePlayerInputs(sf::Keyboard::Key key, bool isPressed) {
	if (key == sf::Keyboard::Up)
		moveUp = isPressed;
	else if (key == sf::Keyboard::Down)
		moveDown = isPressed;
	else if (key == sf::Keyboard::Left)
		 moveLeft= isPressed;
	else if (key == sf::Keyboard::Right)
		moveRight = isPressed;
	if (key == sf::Keyboard::Space) {
		shoot = isPressed;
	}

}
void Player::Draw() {
	
	window->draw(sprite);
	
	for (std::list<Entity*>::iterator it = listBulletLives.begin(); it != listBulletLives.end(); ++it) {
		Entity*e = *it;
		e->Draw();
	}
	
}
void Player::Move(sf::Time deltaTime) {
	sf::Vector2f movement(0.f, 0.f);
	elapsed = clock.getElapsedTime();

	
	if (dead) {
	    timeSpawn = clockSpawn.getElapsedTime();
		RespawnPlayer();
		std::cout << "spawn!time ";
		std::cout <<timeSpawn.asSeconds() << endl;
	}
	
	if (moveUp)
		movement.y -= velocity;
	if (moveDown)
		movement.y += velocity;
	if (moveLeft)
		movement.x -= velocity;
	if (moveRight)
		movement.x += velocity;
	if (shoot&&elapsed.asSeconds() > fireRate)
		Atack();

	
	sprite.move(movement*deltaTime.asSeconds());
	MoveBullets(deltaTime);
}
void Player::MoveBullets(sf::Time deltaTime) {
	for (std::list<Entity*>::iterator it = listBulletLives.begin(); it != listBulletLives.end(); ++it) {
		Entity*e = *it;
		e -> Move(deltaTime);
	}
	TakeOutBullet();
}
void Player::Atack(){
	listBulletLives.push_back(GetBullet());
	elapsed = clock.restart();
}

void Player::CreationBullets(){
	for (int i = 0; i < 30;i++) {
		Entity*e;
		e = new Bullet(1);
		e->window = window;
		e->Initialize();
		listBulletDeads.push_back(e);
	}

}
void Player::RespawnPlayer(){
	if (timeSpawn.asSeconds() > 2.5f) {
		std::cout << "tiempo cumplido" << endl;
		dead = false;
		timeSpawn = clockSpawn.restart();
		Position(100, 300);
	}
}
Entity* Player::GetBullet() {
	for (list<Entity*>::iterator it = listBulletDeads.begin(); it != listBulletDeads.end(); ++it) {
		Entity*e = *it;
		if (!e->live) {
			cout << "position x" << sprite.getPosition().x << endl;
			cout << "position y" << sprite.getPosition().y << endl;
			e->Position(sprite.getPosition().x, sprite.getPosition().y);
			e->live = true;
			return e;

		}
	}
}
void Player::TakeOutBullet(){
	for (std::list<Entity*>::iterator it = listBulletLives.begin(); it != listBulletLives.end(); ++it) {
		Entity*e = *it;
		if (e->sprite.getPosition().x > 800) {
			e->live = false;
			listBulletLives.erase(it);
			break;
		}
	}
}
void Player::Initialize() {
	if (!texture.loadFromFile("assets/_h.png")) {
		std::cout << "error";
	};
	Position(0, 300);
	initialPos.x = 0;
	initialPos.y= 300;
	sprite.setTexture(texture);
	CreationBullets();

	//std::cout << "scale x" << sprite.getScale().x <<std::endl;
}
void Player::Position(float x, float y) {
	sprite.setPosition(x, y);
}
void Player::Destroy() {

}
Player::~Player() {
	std::list<Entity*>::iterator it = listBulletDeads.begin();
	for (int i = 0; i < 30; i++) {
		Entity* e = *it;
		delete e;
		it++;
	}
	listBulletDeads.clear();
	listBulletLives.clear();
}