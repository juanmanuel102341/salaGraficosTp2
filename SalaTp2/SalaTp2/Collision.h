#ifndef COLLISION_H
#define COLLISION_H
#include"Player.h"
#include"EnemyManager.h"

class Collision
{
public:
	Collision(EnemyManager* _enemyManager,Player* _player );
	void CollideBulletEnemy();
	void CollideEnemyPlayer();
	void CollideBulletPlayer();
private:
	EnemyManager* enemyManager;
	Player* player;
	bool p;
};
#endif // !COLLISION_H

