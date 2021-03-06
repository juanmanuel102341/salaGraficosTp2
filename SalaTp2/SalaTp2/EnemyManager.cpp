#include"EnemyManager.h"
void EnemyManager::Init(){
	for (int i = 0; i < 30; i++) {
		Enemigo*e;
		e = new EnemyA();
		
		e->window = window;
		e->Initialize();
		listDead.push_back(e);
	}
	
	}
void EnemyManager::Draw() {
	
	for(std::list<Enemigo*>::iterator it = listLive.begin(); it != listLive.end(); ++it) {
	
		Enemigo*e=*it;
		e->Draw();
}
	//std::cout<<"tiempo "<<timing
	
}
void EnemyManager::Move(sf::Time deltaTime){
	for (std::list<Enemigo*>::iterator it = listLive.begin(); it != listLive.end(); ++it) {
		Enemigo*e = *it;
		e->Move(deltaTime);
	}
	SpawnA();

	TakeOut();
}
Enemigo* EnemyManager::GetEnemy() {
	for (std::list<Enemigo*>::iterator it = listDead.begin(); it != listDead.end(); ++it) {
		Enemigo*e = *it;
		if (!e->live) {
			float y =50+ rand() %   600;
			std::cout << "y " << y<<endl;
			e->Position(800, y);
			e->live = true;
			e->Persuit(player->sprite.getPosition());
			return e;
		}
	}
	return NULL;
}
void EnemyManager::TakeOut() {
	for (std::list<Enemigo*>::iterator it = listLive.begin(); it != listLive.end(); ++it) {
		Enemigo*e = *it;
		if (e->sprite.getPosition().x < 0) {
			e->live = false;
			listLive.erase(it);
			break;
		}
	}
	
}
void EnemyManager::TakeOutAll(){
	for (std::list<Enemigo*>::iterator it = listLive.begin(); it != listLive.end(); ++it) {
		Enemigo*e = *it;
		e->TakeOutBullet();
		e->live = false;
	}
	listLive.erase(listLive.begin(), listLive.end());

}

void EnemyManager::SpawnA(){
	elapsed = clock.getElapsedTime();
	if (elapsed.asSeconds() > 2) {

		listLive.push_back(GetEnemy());
		elapsed = clock.restart();
	}
}
void EnemyManager::DeleteMe() {
	for (std::list<Enemigo*>::iterator it = listLive.begin(); it != listLive.end(); ++it) {
		Enemigo*e=*it;
		e->DeleteBullet();
	}
	listDead.erase(listDead.begin(), listDead.end());

}
EnemyManager::EnemyManager(Player* _player) {
	srand(time(NULL));
	player=_player;

}
void EnemyManager::DestroyPlayerPtr(){
	delete player;
}
EnemyManager::~EnemyManager() {
	std::list<Enemigo*>::iterator it = listDead.begin();
	for (int i = 0; i < 30; i++) {
		Enemigo* e=*it;
		delete e;
		it++;
	}
	//delete player;
	listDead.clear();
}
