#include "stdafx.h"

#include "constants.h"
#include "Bullet.h"

CBullet::CBullet(int pos, Direction direction) {
	m_pos       = pos;
	m_direction = direction;

	if (direction == RIGHT)
		m_symbol = SYMBOL_BULLET_RIGHT;
	else
		m_symbol = SYMBOL_BULLET_LEFT;	
}

void CBullet::Update() {
	if (m_direction == RIGHT) {		
		m_pos++;		
	}
	else if (m_direction == LEFT) {
		m_pos--;
	}
}

void CBullet::Print() const {
	printf("%c", m_symbol);
}

int CBullet::GetPos() const {
	return m_pos;
}

int CBullet::GetSymbol() const {
	return m_symbol;
}
