#include"EnemyA.h"

void EnemyA::Initialize() {
	if (!texture.loadFromFile("assets/_rept_1.png")) {
		std::cout << "error";
	};
	sprite.setTexture(texture);
	CreationBullet();
}
void EnemyA::Position(float x, float y) {
	sprite.setPosition(x, y);

}
void EnemyA::Draw(){
	window->draw(sprite);
	for (std::list<Entity*>::iterator it = listBulletLives.begin(); it != listBulletLives.end(); ++it) {
		Entity*e = *it;
		e->Draw();
	}
	
}
void EnemyA::Move(sf::Time deltaTime){
	sprite.move(-velocity*propx* deltaTime.asSeconds(),directiony*propy*velocity*deltaTime.asSeconds());
	//sprite.move(-velocity*deltaTime.asSeconds(), 0);
//	std::cout << "vec x" << vecPersuit.x << endl;
	//std::cout << "vec y" << vecPersuit.y << endl;
	timer = clock.getElapsedTime();
	if (timer.asSeconds() > fireRate) {
		listBulletLives.push_back(GetBullet());
		timer = clock.restart();
	}
	MoveBullets(deltaTime);
}
void EnemyA::Destroy(){

}
void EnemyA::Persuit(sf::Vector2f posPlayer){
	sf::Vector2f myPos = sprite.getPosition();
	distance = sqrt((myPos.x - posPlayer.x)*(myPos.x - posPlayer.x)) + sqrt((myPos.y - posPlayer.y)*(myPos.y - posPlayer.y));
	std::cout << "distancia " <<distance << endl;
	
	propx = (myPos.x - posPlayer.x)/distance; 
	propx = abs(propx);
	propy = (myPos.y - posPlayer.y) / distance;
	propy = abs(propy);
	if (posPlayer.y > myPos.y) {
		directiony = 1;
	}
	else {
		directiony = -1;
	}
	std::cout << "prop x " << propx;
	std::cout << "prop y " << propy;
}
void EnemyA::CreationBullet(){
	for (int i = 0; i < 10; i++) {
		Entity*e;
		e = new Bullet(-1);
		e->window = window;
		e->Initialize();
		listBulletDeads.push_back(e);
	}
}
Entity* EnemyA::GetBullet(){
	for (list<Entity*>::iterator it = listBulletDeads.begin(); it != listBulletDeads.end(); ++it) {
		Entity*e = *it;
		if (!e->live) {
			//cout << "position x" << sprite.getPosition().x << endl;
			//cout << "position y" << sprite.getPosition().y << endl;
			e->Position(sprite.getPosition().x, sprite.getPosition().y);
			e->live = true;
			return e;

		}
	}
}
void EnemyA::TakeOutBullet() {
	for (std::list<Entity*>::iterator it = listBulletLives.begin(); it != listBulletLives.end(); ++it) {
		Entity*e = *it;
		if (e->sprite.getPosition().x <0) {
			e->live = false;
			listBulletLives.erase(it);
			break;
		}
	}
}
void EnemyA::TakeOutAllBullets(){
	for (std::list<Entity*>::iterator it = listBulletLives.begin(); it != listBulletLives.end(); ++it) {
		Entity*e = *it;
		e->live = false;
	}
	listBulletLives.erase(listBulletLives.begin(), listBulletLives.end());
}
void EnemyA::DeleteBullet() {
	listBulletDeads.erase(listBulletDeads.begin(), listBulletDeads.end());
}
void EnemyA::MoveBullets(sf::Time deltaTime){
	for (std::list<Entity*>::iterator it = listBulletLives.begin(); it != listBulletLives.end(); ++it) {
		Entity*e = *it;
		e->Move(deltaTime);
	}
	TakeOutBullet();
}
EnemyA::EnemyA() {
	//timer= sf::seconds(0.01f);
	//vecPLayer = posPlayer;
	velocity = 350;
	fireRate = 1.8f;

}