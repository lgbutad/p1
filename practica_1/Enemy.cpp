#include "stdafx.h"
#include "constants.h"
#include "Enemy.h"
#include <stdlib.h>

CEnemy::CEnemy(int pos_x, Direction direction) {	
	m_pos_x = pos_x;
	m_direction = direction;	
	m_symbol = SYMBOL_ENEMY;
}

void CEnemy::Update() {
	if (m_direction == RIGHT)		
		m_pos_x++;
	else if (m_direction == LEFT)
		m_pos_x--;
}

void CEnemy::Print() const {
	printf("%c", m_symbol);
}

int CEnemy::GetPosX() const {
	return m_pos_x;
}

bool CEnemy::CheckValidPosition() const {
	if (m_pos_x < 0 || m_pos_x > LEVEL_WIDTH - 1)
		return false;
	return true;
}

