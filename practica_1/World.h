#ifndef _WORLD_H_
#define _WORLD_H_

#include <list>

class CPlayer;
class CBonus;
class CEnemy;
class CBullet;

class CWorld {
public:
	CWorld(CPlayer* player);
	~CWorld();
	void Run();
	void Print();
	void PrintFloor();

private:
	CPlayer*            m_player;
	CBonus*             m_bonus;
	std::list<CEnemy*>  m_enemies;
	std::list<CBullet*> m_bullets;
	int                 m_score;
};

#endif

