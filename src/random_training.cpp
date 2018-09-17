#include <stdafx.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>


HANDLE consoleHandle = 0;


void random_training() {
	srand(time(NULL));
	char c1, c2, c3, c4, c5, c;
	float z = -1;
	system("cls");
	printf("Ready?");
	_getch();
	system("cls");
	for (int i = 3; i>0; i--) {
		printf("%d", i);
		Sleep(500);
		system("cls");
	}

	c1 = rand() % 26 + 97;
	c2 = rand() % 26 + 97;
	c3 = rand() % 26 + 97;
	c4 = rand() % 26 + 97;
	c5 = rand() % 26 + 97;


	time_t t0 = time(0);
	do {
		c1 = c2;
		c2 = c3;
		c3 = c4;
		c4 = c5;
		c5 = rand() % 26 + 97;
		SetConsoleTextAttribute(consoleHandle, 10);
		printf("%60.c\n", c5);
		printf("%60.c\n", c4);
		printf("%60.c\n", c3);
		printf("%60.c\n", c2);
		for (int i = 0; i<56; i++) {
			printf(" ");
		}
		SetConsoleTextAttribute(consoleHandle, 15);
		printf("-->");
		SetConsoleTextAttribute(consoleHandle, 10);
		printf("%c", c1);
		SetConsoleTextAttribute(consoleHandle, 15);
		printf("<--\n");
		c = _getch();
		system("CLS");
		z++;
	} while (c1 == c);
	time_t t1 = time(0);

	float time_in_seconds = difftime(t1, t0);
	float simsec = (z / time_in_seconds);
	float score = simsec * z * 25;

	printf("sim/sec = %.2f\n", simsec);
	printf("Score = %.2f\n", score);
}