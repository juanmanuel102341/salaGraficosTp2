#include"Bullet.h"


void Bullet::Initialize(){
	if (!texture.loadFromFile("assets/bullet_1.png")) {
		std::cout << "error";
	};
	sprite.setTexture(texture);
}
void Bullet::Position(float x, float y) {
	sprite.setPosition(x, y);
}
void Bullet::Draw(){
	window->draw(sprite);
}
void Bullet::Move(sf::Time deltaTime) {
	sprite.move(velocity*directionx*deltaTime.asSeconds() , 0);
}
void Bullet::Destroy(){

}
Bullet::Bullet(int _directionx){
	directionx = _directionx;
	velocity = 700;
	timer = sf::seconds(0.01f);
	Initialize();
}