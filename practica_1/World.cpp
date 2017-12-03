#include "stdafx.h"
#include "conio.h"
#include "constants.h"
#include "World.h"
#include "Player.h"
#include "Bonus.h"
#include "Enemy.h"
#include "Bullet.h"

CWorld::CWorld() {
	m_player = new CPlayer;	 
	m_bonus = nullptr;
}

CWorld::~CWorld() {
	for (auto it = m_bullets.begin(); it != m_bullets.end(); it++) {
		delete *it;
		*it = nullptr;
	}

	for (auto it = m_enemies.begin(); it != m_enemies.end(); it++) {
		delete *it;
		*it = nullptr;
	}

	delete m_player;
	m_player = nullptr;

	delete m_bonus;
	m_bonus = nullptr;
}

void CWorld::ProcessInput() {
	if (_kbhit()) {
		switch (m_key = _getch()) {
		case KEY_LEFT_1: 
		case KEY_LEFT_2: {
			m_player->SetDirection(LEFT);
			break;
		}			
		case KEY_RIGHT_1:
		case KEY_RIGHT_2: {
			m_player->SetDirection(RIGHT);
			break;
		}			
		case KEY_SHOOT_LEFT_1:
		case KEY_SHOOT_LEFT_2: {
			CBullet* bullet = m_player->Shoot(m_player->GetPosX(), LEFT);
			m_bullets.push_back(bullet);
			break;
		}			
		case KEY_SHOOT_RIGHT_1: 
		case KEY_SHOOT_RIGHT_2: {
			CBullet* bullet = m_player->Shoot(m_player->GetPosX(), RIGHT);
			m_bullets.push_back(bullet);
			break;
		}			
		default:
			break;
		}
	}	
}

void CWorld::GenerateBonus() {
	if (m_bonus == nullptr) {
		m_bonus = new CBonus(rand() % LEVEL_WIDTH);		
	}
}

void CWorld::GenerateEnemy() {
	int pos_x = 0;
	Direction direction = NONE;
	int roll = rand() % 100 + 1;
	if (roll <= ENEMY_CHANCE) {
		int s = rand() % 2;
		if (s == 0) {
			pos_x = 0;
			direction = RIGHT;
		}
		else {
			pos_x = LEVEL_WIDTH - 1;
			direction = LEFT;
		}
		CEnemy* enemy = new CEnemy(pos_x, direction);
		m_enemies.push_back(enemy);
	}	
}

void CWorld::GenerateRain() {	
	int pos_x = 0;
	int roll = rand() % LEVEL_WIDTH;	
}

void CWorld::UpdateBullets() {
	for (auto it = m_bullets.begin(); it != m_bullets.end();) {		
		(*it)->Update();

		if (!(*it)->CheckValidPosition()) {
			delete *it;
			*it = nullptr;
			it = m_bullets.erase(it);
		}			
		else {
			++it;
		}
	}
}

void CWorld::UpdateEnemies() {
	for (auto it = m_enemies.begin(); it != m_enemies.end();) {
		(*it)->Update();

		if (!(*it)->CheckValidPosition()) {
			delete *it;
			*it = nullptr;
			it = m_enemies.erase(it);
		}			
		else {
			++it;
		}
	}
}

void CWorld::CheckBulletEnemyCollision() {
	for (auto it_b = m_bullets.begin(); it_b != m_bullets.end();) {
		bool destroy_bullet = false;
		for (auto it_e = m_enemies.begin(); it_e != m_enemies.end();) {
			if ((*it_b)->GetPosX() == (*it_e)->GetPosX()) {
				delete *it_e;
				*it_e = nullptr;
				it_e = m_enemies.erase(it_e);
				destroy_bullet = true;
			}
			else {
				++it_e;
			}
		}
		if (destroy_bullet) {
			delete *it_b;
			*it_b = nullptr;
			it_b = m_bullets.erase(it_b);
		}
		else {
			++it_b;
		}
	}
}

void CWorld::CheckPlayerEnemyCollision() {
	for (auto it = m_enemies.begin(); it != m_enemies.end();) {
		if (m_player->GetPosX() == (*it)->GetPosX()) {			
			delete *it;
			*it = nullptr;
			it = m_enemies.erase(it);			
			RestartLevel();
			return;
		}
		else {
			++it;
		}
	}
}

void CWorld::CheckPlayerBonusCollision() {
	if (m_bonus != nullptr) {
		if (m_player->GetPosX() == m_bonus->GetPosX()) {
			delete m_bonus;
			m_bonus = nullptr;
			m_score += BONUS_SCORE;
		}
	}
}

void CWorld::ClearEnemies() {
	for (auto it = m_enemies.begin(); it != m_enemies.end();) {
		delete *it;
		*it = nullptr;
		it = m_enemies.erase(it);
	}
}

void CWorld::ClearBullets() {
	for (auto it = m_bullets.begin(); it != m_bullets.end();) {
		delete *it;
		*it = nullptr;
		it = m_bullets.erase(it);
	}
}

void CWorld::ClearBonus() {
	delete m_bonus;
	m_bonus = nullptr;
}

void CWorld::RestartLevel() {
	m_player->Kill();	
	ClearEnemies();
	ClearBullets();
	ClearBonus();
}

void CWorld::Update() {
	// Check collisions before and after updating player and bullets to prevent 'tunnel effect'.
	CheckBulletEnemyCollision();
	CheckPlayerEnemyCollision();

	m_player->Update();
	UpdateBullets();	
	CheckBulletEnemyCollision();
	CheckPlayerEnemyCollision();
	CheckPlayerBonusCollision();
	GenerateEnemy();
	GenerateBonus();
	UpdateEnemies();
}

void CWorld::Print() {
	std::vector<char> level(LEVEL_WIDTH, SYMBOL_FLOOR);

	level[m_player->GetPosX()] = SYMBOL_PLAYER;
	level[m_bonus->GetPosX()]  = SYMBOL_BONUS;

	for (auto it = m_bullets.begin(); it != m_bullets.end(); ++it) {
		level[(*it)->GetPosX()] = (*it)->GetSymbol();
	}

	for (auto it = m_enemies.begin(); it != m_enemies.end(); ++it) {
		level[(*it)->GetPosX()] = SYMBOL_ENEMY;
	}

	for (auto it = level.begin(); it != level.end(); ++it) {
		printf("%c", (*it));
	}

	printf("\t%s%d\t%s%d", "SCORE: ", m_score, "LIVES: ", m_player->GetLifes());
	printf("\r");
}

void CWorld::PrintFloor() {
	printf("%c", SYMBOL_FLOOR);
}

int CWorld::GetKey() const {
	return m_key;
}

CPlayer* CWorld::GetPlayer() const {
	return m_player;
}
