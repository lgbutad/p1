#ifndef _DROP_H_
#define _DROP_H_

class CDrop
{
public:
	CDrop(int pos);

	int  GetStatus() const;
	int  GetPos() const;
	char GetSymbol() const;
	void NextStatus();

	const static char s_drop_status[2];

private:
	int m_status;
	int m_pos;

};

#endif
