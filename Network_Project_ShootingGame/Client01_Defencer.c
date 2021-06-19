# include <windows.h>
# include <stdio.h>
#include <stdlib.h>
# include "console.h"
# include "shooting_game.h"

int main(void) {
	SetConsoleSize(30, 30);
	SetTitle("Flight Shooting Game");

	GotoXY(14, 28);
	printf("*");
	return 0;
}