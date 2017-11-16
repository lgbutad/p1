#include "stdafx.h"
#include "constants.h"
#include "Bonus.h"
#include <stdlib.h>

CBonus::CBonus(int pos_x) {	
	m_pos_x = pos_x;
	m_symbol = SYMBOL_BONUS;
}

int CBonus::GetPosX() const {
	return m_pos_x;
}

void CBonus::Print() const {
	printf("%c", m_symbol);
}
