#include <stdafx.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>



int main() {
	srand(time(NULL));
	char c1, c2;
	float z = -1;
	printf("Ready?");
	_getch();
	system("cls");
	time_t t0 = time(0);
	do {
		c1 = rand() % 26 + 97;
		printf("%c", c1, c1);
		c2 = _getch();
		system("CLS");
		z++;
	} while (c1 == c2);
	time_t t1 = time(0);

	float time_in_seconds = difftime(t1, t0);
	float score = (z / time_in_seconds);
	printf("\nsim/min = %.2f\n", score);
	system("PAUSE");
}
