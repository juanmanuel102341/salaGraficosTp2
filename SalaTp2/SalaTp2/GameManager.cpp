#include"GameManager.h"

void GameManager::Init() {
	//basePlayer = new Player();
	basePlayer->window = window;
	basePlayer->Initialize();
	basePlayer->Position(100, 300);

	//enemyManager = new EnemyManager();
	enemyManager->window = window;
	enemyManager->Init();
	//baseEnemyA = new EnemyA();
	//baseEnemyA->window = window;
	//baseEnemyA->Initialize();
}
void GameManager::UpdateDraw(){
	basePlayer->Draw();
	enemyManager->Draw();
	//baseEnemyA->Draw();

}
void GameManager::DestroyEntity() {
	basePlayer->Destroy();
}
GameManager::GameManager() {
	
	
}
