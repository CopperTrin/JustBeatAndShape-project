#include <iostream>
#include"Game.h"


int main()
{
	
	//Random seed
	srand(static_cast<unsigned>(time(0)));

	//Initialize Game Object
	Game game;
	game.run();

	return 0;
}