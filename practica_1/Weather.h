#ifndef _WEATHER_H_
#define _WEATHER_H_

#include <vector>

class CDrop;

class CWeather
{
public:
	~CWeather();

	void                       Update();
	const std::vector<CDrop*>& GetDrops() const;

private:	
	std::vector<CDrop*> m_drops;

};

#endif
