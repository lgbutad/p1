#include "stdafx.h"
#include "constants.h"
#include "Player.h"

CPlayer::CPlayer() {
	m_pos_x = LEVEL_WIDTH / 2;
	m_lifes = PLAYER_LIFES;	
	m_direction = Direction::NONE;
	m_symbol = SYMBOL_PLAYER;
}

void CPlayer::Move() {
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

void CPlayer::SetDirection(Direction direction) {
	m_direction = direction;
}

void CPlayer::Print() const {
	printf("%c", m_symbol);
}

int CPlayer::GetPosX() const {
	return m_pos_x;
}

int CPlayer::GetLifes() const {
	return m_lifes;
}
