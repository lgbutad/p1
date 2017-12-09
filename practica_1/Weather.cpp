#include "stdafx.h"

#include <algorithm>

#include "constants.h"
#include "Drop.h"
#include "Weather.h"

CWeather::~CWeather() {
	for (auto it = m_drops.begin(); it != m_drops.end(); it++) {
		delete *it;
		*it = nullptr;
	}
}

void CWeather::Update() {	
	// Update existing drops.
	int s_drop_status_size = sizeof(CDrop::s_drop_status) / sizeof(CDrop::s_drop_status[0]);

	for (auto it = m_drops.begin(); it != m_drops.end();) {
		if ((*it)->GetStatus() < s_drop_status_size - 1) {
			(*it)->NextStatus();
			it++;
		}
		else {
			it = m_drops.erase(it);
		}
	}

	// Add new drops.
	int max_new_drops = LEVEL_WIDTH / MAX_DROPS_RATIO;
	int n_new_drops = rand() % max_new_drops + 1;

	for (int i = 0; i < n_new_drops; i++) {
		int pos = rand() % LEVEL_WIDTH;
		bool add_new = true;
		for (auto it = m_drops.begin(); it != m_drops.end(); ++it) {
			if ((*it)->GetPos() == pos) {
				add_new = false;
				break;
			}							
		}
		if (add_new) {
			m_drops.push_back(new CDrop(pos));
		}		
	}
}

const std::vector<CDrop*>& CWeather::GetDrops() const {
	return m_drops;
}
