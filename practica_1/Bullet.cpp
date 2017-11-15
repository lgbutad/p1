#include "stdafx.h"
#include "constants.h"
#include "Bullet.h"

CBullet::CBullet(int pos_x, Direction direction) {
	m_pos_x     = pos_x;
	m_direction = direction;

	if (direction == RIGHT)
		m_symbol = SYMBOL_BULLET_RIGHT;
	else
		m_symbol = SYMBOL_BULLET_LEFT;	
}

CBullet::~CBullet() {
}

void CBullet::Move() {
	switch (m_direction) {
	case RIGHT:
		if (m_pos_x < LEVEL_WIDTH - 1) {
			m_pos_x++;
			break;
		}
	case LEFT:
		if (m_pos_x >= 0) {
			m_pos_x--;
			break;
		}
	}
}

void CBullet::Print() const {
	printf("%c", m_symbol);
}

int CBullet::GetPosX() const {
	return m_pos_x;
}