#ifndef _GAME_H_
#define _GAME_H_

#include <list>

class CPlayer;
class CBonus;
class CEnemy;
class CBullet;

class CGame {
public:
	CGame();
	~CGame();
	void     ProcessInput();
	void     GenerateEnemy();
	void     GenerateBonus();
	void     GenerateRain();
	void     Update();
	void     UpdateBullets();
	void     UpdateEnemies();
	void     CheckBulletEnemyCollision();
	void     CheckPlayerEnemyCollision();
	void     CheckPlayerBonusCollision();
	void     ClearEnemies();
	void     ClearBullets();
	void     ClearBonus();
	void     RestartLevel();
	void     Print();
	void     PrintFloor();
	int      GetKey() const;
	CPlayer* GetPlayer() const;

private:
	CPlayer*            m_player;
	CBonus*             m_bonus;
	std::list<CEnemy*>  m_enemies;
	std::list<CBullet*> m_bullets;
	int                 m_score;
	char                m_key;

};

#endif

