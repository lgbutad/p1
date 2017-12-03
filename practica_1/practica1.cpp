#include "stdafx.h"
#include "constants.h"
#include "windows.h"
#include <list>
#include "Player.h"
#include "World.h"

// TODO: It's not necessary to have Bullet, Player, Enemy and Bonus classes.
// We can have the positions stored directly in Game (or World) class.
// We need only World and Meteo classes.

// TODO: Finish Weather.

int main() {
	printf("\n\n\n");
	
	CWorld game;

	while (game.GetKey() != KEY_ESC && game.GetPlayer()->GetLifes() > 0) { 
		game.ProcessInput();
		game.Update();
		game.Print();		
		Sleep(200);		
	}

	return 0;
}
