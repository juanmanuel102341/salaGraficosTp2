#include"Collision.h"


Collision::Collision(EnemyManager* _enemyManager, Player* _player){
	enemyManager = _enemyManager;
	player = _player;

}
void Collision::CollideBulletEnemy() {

	for (std::list<Entity*>::iterator it = player->listBulletLives.begin(); it != player->listBulletLives.end(); ++it) {
		Entity*eBullet = *it;
		for (std::list<Enemigo*>::iterator it2 = enemyManager->listLive.begin(); it2 != enemyManager->listLive.end(); ++it2) {
			
			Enemigo*eEnemy = *it2;
		if(eBullet->sprite.getGlobalBounds().intersects(eEnemy->sprite.getGlobalBounds())){
		
			std::cout << "contacto" << endl;
			gui->ChangePlanes();
			eBullet->live = false;
			player->listBulletLives.erase(it);
			eEnemy->live = false;
			enemyManager->listLive.erase(it2);
	
			return;
		}
	}
}

}
void Collision::CollideEnemyPlayer() {
	for (std::list<Enemigo*>::iterator it =enemyManager->listLive.begin(); it != enemyManager->listLive.end(); ++it) {
		Enemigo*enemy=*it;
		if (enemy->sprite.getGlobalBounds().intersects(player->sprite.getGlobalBounds())) {
			std::cout << "contacto " << endl;
			player->dead = true;
			player->Position(-100, -100);
			player->clockSpawn.restart();
			gui->ChangeLife();
			enemy->live = false;
			enemyManager->listLive.erase(it);
			return;
		}
	}
}

void Collision::CollideBulletPlayer() {
	for (std::list<Enemigo*>::iterator it = enemyManager->listLive.begin(); it != enemyManager->listLive.end(); ++it) {

		Enemigo*enemy = *it;
		for (std::list<Entity*>::iterator it2 = enemy->listBulletLives.begin(); it2 != enemy->listBulletLives.end(); ++it2) {
			Entity*bullet = *it2;
			if (bullet->sprite.getGlobalBounds().intersects(player->sprite.getGlobalBounds())) {
				std::cout << "contacto " << endl;
				player->dead = true;
				player->Position(-100, -100);
				player->clockSpawn.restart();
				gui->ChangeLife();
				bullet->live = false;
				enemy->listBulletLives.erase(it2);
				return;
				//enemy->live = false;
				//enemyManager->listLive.erase(it);

			}

		}

	}
}
