#ifndef _BULLET_H_
#define _BULLET_H_

class CBullet {
public:
	CBullet(int pos, Direction direction);

	void Update();
	void Print() const;
	int  GetPos() const;
	int  GetSymbol() const;

private:
	int       m_pos;	
	char      m_symbol;
	Direction m_direction;

};

#endif
