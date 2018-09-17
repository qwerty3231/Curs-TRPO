#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include "Header.h"

//HANDLE consoleHandle = 0;


int main() {
	HANDLE consoleHandle = 0;
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	char sim;
repeat:;
	system("cls");
	printf("1.Start""\n"
		"2.Records""\n"
		"3.Exit""\n");
	sim = _getch();
	switch (sim) {
	case '1':
		game();
		_getch();
		goto repeat;
		break;
	case '2':
		system("CLS");
		printf("\nin developing\n");
		_getch();
		goto repeat;
		break;
	case '3':
		system("cls");
		printf("\nGood bye\n");
		return 0;
		break;
	default:
		goto repeat;
		break;
	}

	system("PAUSE");
}