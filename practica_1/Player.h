#ifndef _PLAYER_H_
#define _PLAYER_H_

class CPlayer {
public:
	CPlayer();
	void Move();
	void SetDirection(Direction direction);
	void Print() const;
	int GetPosX() const;
	int GetLifes() const;

private:
	int         m_pos_x;
	int         m_lifes;	
	Direction   m_direction;
	char        m_symbol;

};

#endif
