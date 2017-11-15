#include "stdafx.h"
#include "constants.h"
#include "Bonus.h"
#include <stdlib.h>

CBonus::CBonus() {
	if (m_pos_x == -1) {
		int roll = rand() % 100 + 1;
		if (roll <= BONUS_CHANCE) {
			m_pos_x = rand() % LEVEL_WIDTH;
		}
	}
}

int CBonus::GetPosX() const {
	return m_pos_x;
}
