#ifndef _CONSTANTS_H_
#define _CONSTANTS_H_

#define LEVEL_WIDTH         30
#define ENEMY_CHANCE        10
#define BONUS_SCORE         100
#define PLAYER_LIFES        3

#define SYMBOL_FLOOR        '_'
#define SYMBOL_PLAYER       '@'
#define SYMBOL_ENEMY        'g'
#define SYMBOL_BONUS        '$'
#define SYMBOL_BULLET_LEFT  '<'
#define SYMBOL_BULLET_RIGHT '>'
#define SYMBOL_RAIN_1       '\''
#define SYMBOL_RAIN_2       '.'

#define KEY_ESC             27
#define KEY_LEFT_1          'a'
#define KEY_LEFT_2          'A'
#define KEY_RIGHT_1         'd'
#define KEY_RIGHT_2         'D'
#define KEY_SHOOT_LEFT_1    'k'
#define KEY_SHOOT_LEFT_2    'K'
#define KEY_SHOOT_RIGHT_1   'l'
#define KEY_SHOOT_RIGHT_2   'L'

enum Direction { NONE, RIGHT, LEFT };

#endif