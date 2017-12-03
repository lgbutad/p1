#ifndef _WEATHER_H_
#define _WEATHER_H_

#include <list>

class CDrop
{
public:
	CDrop();
	int  GetStatus() const;
	void NextStatus();
private:
	int m_status;
	int m_pos_x;
};

class CWeather
{
public:
	CWeather();
	void Update();
private:
	const static char s_rain_types[2];
	std::list<CDrop> m_drops;	
};

#endif

