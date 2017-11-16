#ifndef _PLAYER_H_
#define _PLAYER_H_

class CBullet;

class CPlayer {
public:
	CPlayer();	
	void     SetDirection(Direction direction);
	void     Print() const;
	void     Update();
	CBullet* Shoot(int pos_x, Direction direction);
	void     Kill();
	int      GetPosX() const;
	int      GetLifes() const;

private:
	int         m_pos_x;	
	char        m_symbol;
	Direction   m_direction;
	int         m_lifes;

};

#endif
