#ifndef _ENEMY_H_
#define _ENEMY_H_

class CEnemy {
public:
	CEnemy();
	void Print() const;
	int GetPosX() const;

private:
	int  m_pos_x;
	char m_symbol;

};

#endif
