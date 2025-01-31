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


void classic_training() {
	system("cls");
	printf("1.Easy"
		"\n2.Medium"
		"\n3.Hard\n");

	FILE *file_ptr;
	char *a, c;
	int len;
repeat:;
	c = _getch();
	switch (c)
	{
	case '1':
		len = 95;
		a = new char[len + 1];
		fopen_s(&file_ptr, "Ez.txt", "r");
		fgets(a, len + 1, file_ptr);
		break;
	case '2':
		len = 167;
		a = new char[len + 1];
		fopen_s(&file_ptr, "Medium.txt", "r");
		fgets(a, len + 1, file_ptr);
		break;
	case '3':
		len = 297;
		a = new char[len + 1];
		fopen_s(&file_ptr,"Hard.txt", "r");
		fgets(a, len + 1, file_ptr);
		break;
	default:
		goto repeat;
		break;
	}
	system("cls");
	printf("Ready?");
	_getch();
	system("cls");
	for (int i = 3; i>0; i--) {
		printf("%d", i);
		Sleep(500);
		system("cls");
	}
	puts(a);
	char input;
	int triger, i;
	int step = 0;
	int z = 0;

	time_t t0 = time(0);

	do
	{
		input = _getch();
		triger = 0;
		if (input == a[step])
		{
			if (input == 32 && a[step] == 32) a[step] = '_';
			step++;
			system("cls");
			for (i = 0; i < len; i++)
			{
				if (i < step)
				{
					SetConsoleTextAttribute(consoleHandle, 10);
					printf("%c", a[i]);
					SetConsoleTextAttribute(consoleHandle, 15);
				}
				else
				{
					printf("%c", a[i]);

				}
			}
		}
		else
		{
			system("cls");
			for (i = 0; i < len; i++)
			{
				if (i < step)
				{
					SetConsoleTextAttribute(consoleHandle, 10);
					printf("%c", a[i]);
					z++;
				}
				else
				{
					if ((a[i] == a[step]) && (triger == 0))
					{
						SetConsoleTextAttribute(consoleHandle, 12);
						printf("%c", a[i]);
						triger = 1;
						z--;
					}
					else
					{
						SetConsoleTextAttribute(consoleHandle, 15);
						printf("%c", a[i]);

					}
				}
			}
			SetConsoleTextAttribute(consoleHandle, 15);
		}
	} while (step < len);
	time_t t1 = time(0);

	float time_in_seconds = difftime(t1, t0);

	if (z<0) z = 0;

	float simsec = (z / time_in_seconds);
	float score = simsec * z * 25;

	printf("\nsim/sec = %.2f\n", simsec);
	printf("Score = %.2f\n", score);
}


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


int main() {
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