#include "stdafx.h"
#include "constants.h"
#include "windows.h"
#include <list>
#include "Player.h"
#include "Game.h"

int main() {
	printf("\n\n\n");

	CPlayer player;
	CGame game(&player);

	while (game.GetKey() != KEY_ESC && player.GetLifes() > 0) { // TODO Fix esc exit.
		game.ProcessInput();
		game.Update();
		game.Print();
		Sleep(100);		
	}

	return 0;
}

