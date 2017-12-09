#include "stdafx.h"
#include "conio.h"
#include "windows.h"

#include "constants.h"
#include "Bullet.h"
#include "Drop.h"
#include "Weather.h"
#include "World.h"

CWorld::CWorld() {
	m_player_pos = LEVEL_WIDTH / 2;
	m_lives      = PLAYER_LIVES;
	m_weather    = new CWeather;
}

CWorld::~CWorld() {
	for (auto it = m_bullets.begin(); it != m_bullets.end(); it++) {
		delete *it;
		*it = nullptr;
	}
}

void CWorld::ProcessInput() {
	if (_kbhit()) {
		switch (m_key = _getch()) {
		case KEY_LEFT_1: 
		case KEY_LEFT_2: {			
			if (m_player_pos > 0)				
				m_player_pos--;			
			break;
		}			
		case KEY_RIGHT_1:
		case KEY_RIGHT_2: {			
			if (m_player_pos < LEVEL_WIDTH - 1)
				m_player_pos++;
			break;
		}			
		case KEY_SHOOT_LEFT_1:
		case KEY_SHOOT_LEFT_2: {
			CBullet* bullet = new CBullet(m_player_pos, LEFT);
			m_bullets.push_back(bullet);			
			break;
		}			
		case KEY_SHOOT_RIGHT_1: 
		case KEY_SHOOT_RIGHT_2: {
			CBullet* bullet = new CBullet(m_player_pos, RIGHT);
			m_bullets.push_back(bullet);			
			break;
		}			
		default:
			break;
		}
	}	
}

void CWorld::GenerateBonus() {
	if (m_bonus_pos == -1) {
		m_bonus_pos = rand() % LEVEL_WIDTH;
	}
}

void CWorld::GenerateEnemy() {
	int pos = 0;	
	int roll = rand() % 100 + 1;

	if (roll <= ENEMY_CHANCE) {
		int s = rand() % 2;
		if (s == 0) {
			pos = 0;			
		}
		else {
			pos = LEVEL_WIDTH - 1;			
		}		
		m_enemies_pos.push_back(pos);
	}	
}

void CWorld::UpdateBullets() {
	for (auto it = m_bullets.begin(); it != m_bullets.end();) {		
		(*it)->Update();

		if (!CheckValidPosition((*it)->GetPos())) {
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
	for (auto it = m_enemies_pos.begin(); it != m_enemies_pos.end();) {		
		if (m_player_pos > (*it))
			(*it)++;		
		else if (m_player_pos < (*it))		
			(*it)--;				

		if (!CheckValidPosition((*it)))
			it = m_enemies_pos.erase(it);		
		else
			++it;		
	}
}

void CWorld::UpdateWeather() {
	m_weather->Update();
}

void CWorld::CheckBulletEnemyCollision() {
	for (auto it_b = m_bullets.begin(); it_b != m_bullets.end();) {
		bool destroy_bullet = false;

		for (auto it_e = m_enemies_pos.begin(); it_e != m_enemies_pos.end();) {
			if ((*it_b)->GetPos() == (*it_e)) {				
				it_e = m_enemies_pos.erase(it_e);
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
	for (auto it = m_enemies_pos.begin(); it != m_enemies_pos.end();) {
		if (m_player_pos == (*it)) {						
			it = m_enemies_pos.erase(it);			
			RestartLevel();
			return;
		}
		else {
			++it;
		}
	}
}

void CWorld::CheckPlayerBonusCollision() {
	if (m_bonus_pos != -1 && m_player_pos == m_bonus_pos) {
		ClearBonus();			
		m_score += BONUS_SCORE;		
	}
}

void CWorld::ClearEnemies() {
	m_enemies_pos.clear();
}

void CWorld::ClearBullets() {
	for (auto it = m_bullets.begin(); it != m_bullets.end();) {
		delete *it;
		*it = nullptr;
		it = m_bullets.erase(it);
	}
}

void CWorld::ClearBonus() {
	m_bonus_pos = -1;
}

void CWorld::RestartLevel() {
	m_player_pos = LEVEL_WIDTH / 2;
	m_lives--;
	ClearEnemies();
	ClearBullets();
	ClearBonus();
	Sleep(400);
}

void CWorld::Update() {
	// Check collisions before and after updating player and bullets to prevent 'tunnel effect'.
	CheckBulletEnemyCollision();
	CheckPlayerEnemyCollision();
	
	UpdateBullets();	
	CheckBulletEnemyCollision();
	CheckPlayerEnemyCollision();
	CheckPlayerBonusCollision();
	GenerateEnemy();
	GenerateBonus();
	UpdateEnemies();
	UpdateWeather();
}

void CWorld::Print() {
	std::vector<char> level(LEVEL_WIDTH, SYMBOL_FLOOR);

	for (auto it = m_weather->GetDrops().begin(); it != m_weather->GetDrops().end(); ++it) {
		level[(*it)->GetPos()] = (*it)->GetSymbol();
	}

	level[m_player_pos] = SYMBOL_PLAYER;
	level[m_bonus_pos]  = SYMBOL_BONUS;

	for (auto it = m_bullets.begin(); it != m_bullets.end(); ++it) {
		level[(*it)->GetPos()] = (*it)->GetSymbol();
	}

	for (auto it = m_enemies_pos.begin(); it != m_enemies_pos.end(); ++it) {
		level[(*it)] = SYMBOL_ENEMY;
	}

	for (auto it = level.begin(); it != level.end(); ++it) {
		printf("%c", (*it));
	}

	printf("\t%s%d\t%s%d", "SCORE: ", m_score, "LIVES: ", m_lives);
	printf("\r");
}

int CWorld::GetKey() const {
	return m_key;
}

int CWorld::GetLives() const {
	return m_lives;
}

bool CWorld::CheckValidPosition(int pos) const {
	if (pos < 0 || pos > LEVEL_WIDTH - 1)
		return false;
	return true;
}
