#include <iostream>
#include <cstdlib>

#include "Game.h"

int main(void) {
	char sele;

	do
	{
		Game game;

		sele = game.MainMenu();

		switch (sele)
		{
		case 49:
			system("cls");
			game.Set_size(4);
			game.Game_x();
			break;

		case 50:
			system("cls");
			game.Set_size(5);
			game.Game_x();
			break;


		default:
			sele = game.MainMenu();
			break;
		}


	} while (sele != 27);




	return 0;
}
