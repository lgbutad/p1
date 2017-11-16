#ifndef _BONUS_H_
#define _BONUS_H_

class CBonus {
public:
	CBonus(int pos_x);
	void Print() const;
	int  GetPosX() const;	

private:
	int  m_pos_x;
	char m_symbol;

};

#endif
