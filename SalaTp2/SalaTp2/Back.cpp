#include"Back.h"

Back::Back(){}
void Back::Initialize(){
	if (!texture.loadFromFile("assets/space.png")) {
		std::cout << "error";
	};
	
	sprite.setTexture(texture);
	sprite2.setTexture(texture);
	sprite2.setPosition(3000, 0);
	

}
void Back::Position(float x,float y){}
void Back::Draw(){
	window->draw(sprite);
	window->draw(sprite2);
}
void Back::Move(sf::Time deltaTime) {
	sprite.move(-50 * deltaTime.asSeconds(), 0);
	sprite2.move(-50 * deltaTime.asSeconds(), 0);

	
	if (sprite.getPosition().x < sprite2.getPosition().x) {
		//mas chico el 1er sprite
		if (sprite.getPosition().x <-3000) {
			std::cout << "entrando cambiando pos 1er sprite" << endl;
			sprite.setPosition(sprite2.getPosition().x + 3000, 0);
			//posMax -= 3000;
		}
	}
	else {
		//mas chico el 2d0
		if (sprite2.getPosition().x < -3000) {
			std::cout << "entrando cambiando pos 2do sprite" << endl;
			sprite2.setPosition(sprite.getPosition().x + 3000, 0);
			//posMax -= 3000;
		}
	}

	

	//std::cout << "back x" << sprite.getPosition().x << endl;
}
void Back::Destroy(){}