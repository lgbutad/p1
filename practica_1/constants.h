#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

const int  LEVEL_WIDTH          = 30;
const int  ENEMY_CHANCE         = 10;
const int  BONUS_SCORE          = 100;
const int  PLAYER_LIFES         = 3;

const char SYMBOL_FLOOR         = '_';
const char SYMBOL_PLAYER        = '@';
const char SYMBOL_ENEMY         = 'g';
const char SYMBOL_BONUS         = '$';
const char SYMBOL_BULLET_LEFT   = '<';
const char SYMBOL_BULLET_RIGHT  = '>';
const char SYMBOL_RAIN_1        = '\'';
const char SYMBOL_RAIN_2		= '.';

const int  KEY_ESC              = 27;
const char KEY_LEFT_1           = 'a';
const char KEY_LEFT_2           = 'A';
const char KEY_RIGHT_1          = 'd';
const char KEY_RIGHT_2          = 'D';
const char KEY_SHOOT_LEFT_1     = 'k';
const char KEY_SHOOT_LEFT_2     = 'K';
const char KEY_SHOOT_RIGHT_1    = 'l';
const char KEY_SHOOT_RIGHT_2    = 'L';

enum Direction { NONE, RIGHT, LEFT };

#endif