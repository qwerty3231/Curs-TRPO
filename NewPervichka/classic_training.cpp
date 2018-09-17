#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include "Header.h"

//HANDLE consoleHandle = 0;


void classic_training() {
	HANDLE consoleHandle = 0;
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
		fopen_s(&file_ptr, "Hard.txt", "r");
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