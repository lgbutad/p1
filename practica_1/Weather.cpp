#include "stdafx.h"
#include "constants.h"
#include "Weather.h"

CWeather::CWeather()
{
}

void CWeather::Update() {	
	// Update existing drops.
	int n_drops = m_drops.size();
	for (auto it = m_drops.begin(); it != m_drops.end();) {
		if (it->GetStatus() < n_drops + 1) {
			it->NextStatus();
			it++;
		}
		else {
			it = m_drops.erase(it);
		}
	}

	// TODO: Add new drops.
	int max_new_drops = LEVEL_WIDTH;
	int n_new_drops = rand() % max_new_drops;

	for (int i = 0; i < n_new_drops; i++) {
		
	}
}

int CDrop::GetStatus() const {
	return m_status;
}

void CDrop::NextStatus() {
	m_status++;
}

const char CWeather::s_rain_types[] = { SYMBOL_RAIN_1, SYMBOL_RAIN_2 };
