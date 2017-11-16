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

void CBullet::Update() {
	if (m_direction == RIGHT) {		
		m_pos_x++;		
	}
	else if (m_direction == LEFT) {
		m_pos_x--;
	}
}

void CBullet::Print() const {
	printf("%c", m_symbol);
}

int CBullet::GetPosX() const {
	return m_pos_x;
}

bool CBullet::CheckValidPosition() const {
	if (m_pos_x < 0 || m_pos_x > LEVEL_WIDTH - 1) 
		return false;
	return true;	
}