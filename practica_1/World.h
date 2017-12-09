#ifndef _WORLD_H_
#define _WORLD_H_

#include <list>
#include <vector>

class CWeather;
class CPlayer;
class CBonus;
class CEnemy;
class CBullet;

class CWorld {
public:
	CWorld();
	~CWorld();

	void     ProcessInput();
	void     GenerateEnemy();
	void     GenerateBonus();
	void     Update();
	void     UpdateBullets();
	void     UpdateEnemies();
	void     UpdateWeather();
	void     CheckBulletEnemyCollision();
	void     CheckPlayerEnemyCollision();
	void     CheckPlayerBonusCollision();
	void     ClearEnemies();
	void     ClearBullets();
	void     ClearBonus();
	void     RestartLevel();
	void     Print();
	int      GetKey() const;	
	bool     CWorld::CheckValidPosition(int pos) const;
	int      GetLives() const;

private:
	CWeather*           m_weather;	
	int                 m_player_pos;
	int                 m_bonus_pos;	
	std::list<int>      m_enemies_pos;
	std::list<CBullet*> m_bullets;
	int                 m_score;
	int                 m_lives;
	char                m_key;

};

#endif
