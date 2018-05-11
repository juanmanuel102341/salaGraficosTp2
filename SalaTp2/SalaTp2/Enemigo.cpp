#include"Enemigo.h"
/*void Enemigo::Initialize(){}
void Enemigo::Draw(){
}
void Enemigo::Position(float x, float y) {}
void Enemigo::Move(sf::Time delta) {}
void Enemigo::Destroy(){}
*/

Enemigo::Enemigo(){
}
Enemigo::~Enemigo() {
	std::list<Entity*>::iterator it = listBulletDeads.begin();
	for (int i = 0; i < listBulletDeads.size(); i++) {
		Entity*e = *it;
		delete e;
		it++;
	}
	listBulletDeads.clear();
}
