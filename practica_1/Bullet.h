#ifndef _BULLET_H_
#define _BULLET_H_

class CBullet {
public:
	CBullet(int pos_x, Direction direction);
	~CBullet();
	void Move();
	void Print() const;
	int GetPosX() const;
private:
	int       m_pos_x;
	Direction m_direction;
	char      m_symbol;
};

#endif

