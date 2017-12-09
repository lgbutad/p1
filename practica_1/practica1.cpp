#include "stdafx.h"
#include "windows.h"

#include <list>

#include "constants.h"
#include "World.h"

int main() {
	printf("\n\n\n");
	
	CWorld world;
	
	while (world.GetKey() != KEY_ESC && world.GetLives() > 0) {
		world.ProcessInput();
		world.Update();
		world.Print();
		Sleep(200);		
	}

	return 0;
}
