#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include "Header.h"


void game() {
	char c;
repeat:;
	system("cls");
	printf("1.Random training\n"
		"2.Classic training\n");
	c = _getch();
	switch (c) {
	case '1':
		random_training();
		break;
	case '2':
		classic_training();
		break;
	default:
		goto repeat;
	}
}