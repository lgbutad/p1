#include "stdafx.h"
#include "constants.h"
#include "World.h"
#include "Player.h"
#include "Bonus.h"
#include "Enemy.h"
#include "Bullet.h"

CWorld::CWorld(CPlayer* player) {
	m_player = player;
}

CWorld::~CWorld() {
}

void CWorld::Run() {

}

void CWorld::Print() {
	for (int i = 0; i < LEVEL_WIDTH; ++i) {
		if (i == m_player->GetPosX()) {
			m_player->Print();
		}
		else if (i == m_bonus->GetPosX()) {
			m_player->Print();
		}
		else {
			bool print = false;
			for (auto it = m_bullets.begin(); it != m_bullets.end(); ++it) {
				if (i == (*it)->GetPosX()) {
					(*it)->Print();
					print = true;
				}
			}
			for (auto it = m_enemies.begin(); it != m_enemies.end(); ++it) {
				if (i == (*it)->GetPosX()) {
					(*it)->Print();
					print = true;
				}
			}
			if (!print) {
				PrintFloor();
			}
		}
	}

	printf("\t%s%d\t%s%d", "SCORE: ", m_score, "LIVES: ", m_player->GetLifes());

	printf("\r");
}

void CWorld::PrintFloor() {
	printf("%c", SYMBOL_FLOOR);
}
