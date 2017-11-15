#include "stdafx.h"
#include "constants.h"
#include "Enemy.h"
#include <stdlib.h>

CEnemy::CEnemy() {
	int roll = rand() % 100 + 1;
	if (roll <= ENEMY_CHANCE) {
		int s = rand() % 2;		
		if (s == 0) {
			m_pos_x = 0;
		}
		else {
			m_pos_x = LEVEL_WIDTH - 1;
		}		
	}
	m_symbol = SYMBOL_ENEMY;
}

void CEnemy::Print() const {
	printf("%c", SYMBOL_PLAYER);
}

int CEnemy::GetPosX() const {
	return m_pos_x;
}

