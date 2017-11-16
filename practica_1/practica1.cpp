#include "stdafx.h"
#include "constants.h"
#include "windows.h"
#include <list>
#include "Player.h"
#include "Game.h"

// TODO: It's not necessary to have Bullet, Player, Enemy and Bonus classes.
// We can have the positions stored directly in Game (or World) class.
// We need only Game (World) and Meteo classes.

// TODO: Change Game class name to World.

// TODO: Change const global to macro defines.

// TODO: Change CGame::Print() building previously a char buffer[LEVEL_WIDTH] to
// simplify function.

// TODO: Finish Weather.

int main() {
	printf("\n\n\n");
	
	CGame game;

	while (game.GetKey() != KEY_ESC && game.GetPlayer()->GetLifes() > 0) { 
		game.ProcessInput();
		game.Update();
		game.Print();		
		Sleep(200);		
	}

	return 0;
}

