#ifndef _BULLET_H_
#define _BULLET_H_

class CBullet {
public:
	CBullet(int pos_x, Direction direction);
	void Update();
	void Print() const;
	int  GetPosX() const;
	int  GetSymbol() const;
	bool CheckValidPosition() const;
private:
	int       m_pos_x;	
	char      m_symbol;
	Direction m_direction;

};

#endif

