#include "stdafx.h"
#include "constants.h"
#include "Player.h"
#include "Bullet.h"
#include "windows.h"

CPlayer::CPlayer() {
	m_pos_x = LEVEL_WIDTH / 2;
	m_lifes = PLAYER_LIFES;	
	m_direction = Direction::NONE;
	m_symbol = SYMBOL_PLAYER;
}

void CPlayer::SetDirection(Direction direction) {
	m_direction = direction;
}

void CPlayer::Print() const {
	printf("%c", m_symbol);
}

void CPlayer::Update() {
	switch (m_direction) {
	case RIGHT:
		if (m_pos_x < LEVEL_WIDTH - 1)
			m_pos_x++;					
		break;
	case LEFT:
		if (m_pos_x > 0)
			m_pos_x--;		
		break;
	default:
		break;
	}
	m_direction = NONE;
}

CBullet* CPlayer::Shoot(int pos_x, Direction direction) {
	return new CBullet(pos_x, direction);	
}

void CPlayer::Kill() {
	m_lifes--;
	m_pos_x = LEVEL_WIDTH / 2;
	Sleep(400);
}

int CPlayer::GetPosX() const {
	return m_pos_x;
}

int CPlayer::GetLifes() const {
	return m_lifes;
}
