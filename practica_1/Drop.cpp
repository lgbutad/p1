#include "stdafx.h"

#include "constants.h"
#include "Drop.h"

CDrop::CDrop(int pos) {
	m_status = 0;
	m_pos = pos;
}

int CDrop::GetStatus() const {
	return m_status;
}

int CDrop::GetPos() const {
	return m_pos;
}

char CDrop::GetSymbol() const {
	return s_drop_status[m_status];
}

void CDrop::NextStatus() {
	m_status++;
}

const char CDrop::s_drop_status[] = { SYMBOL_RAIN_1, SYMBOL_RAIN_2 };
