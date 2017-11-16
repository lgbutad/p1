#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

const int  LEVEL_WIDTH          = 30;
const int  ENEMY_CHANCE         = 30;
//const int  BONUS_CHANCE       = 100;
const int  BONUS_SCORE          = 100;
const int  PLAYER_LIFES         = 3;
const char SYMBOL_FLOOR         = '_';
const char SYMBOL_PLAYER        = '@';
const char SYMBOL_ENEMY         = 'g';
const char SYMBOL_BONUS         = '$';
const char SYMBOL_BULLET_LEFT   = '<';
const char SYMBOL_BULLET_RIGHT  = '>';
const char KEY_ESC              = '27';
const char KEY_LEFT             = 'a';
const char KEY_RIGHT            = 'd';
const char KEY_SHOOT_LEFT       = 'k';
const char KEY_SHOOT_RIGHT      = 'l';
enum Direction { NONE, RIGHT, LEFT };

#endif