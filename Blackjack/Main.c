#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>

char toString(int);
void eatline(void)
{
	while (getchar() != '\n')
		continue;
}

int main(void)
{
	int a[52];
	int b[52];
	int random;
	bool bl = true;
	bool b_one, b_two;
	b_one = b_two = true;
	int* p = b;

	for (int x = 0; x < 4; x++)
		for (int y = 0; y < 13; y++)
			a[x * 13 + y] = y + 1;

	srand((unsigned int)time(NULL));
	for (int z = 0; z < 52; z++)
	{
		random = rand() % (52-z) + 1;
		b[z] = a[random];
		a[random] = a[52 - z];
	}

	printf("Welcome to The Blackjack Game(by XZH)!\n");
	printf("		yours		the other's\n");
	while (bl)
	{
		static int round = 1;
		if (round == 1)
		{
		printf("Round %d", round);
			printf("		  %c		    %c", 
				toString(*(p++)), toString(*(p++)));
		}
		else
		{
			printf("		Want more?(y/n*2): ");
			if (getchar() == 'n')
				b_one = false;
			if (getchar() == 'n')
				b_two = false;
			if (!(b_one || b_two))
				bl = false;
			eatline();
			if (bl)
			{
				printf("Round %d", round);
				if (b_one)
				{
					printf("		  %c",toString(*(p++)));
				}
				else
					printf("		    ");
				if (b_two)
					printf("		    %c", toString(*(p++)));
				else
					printf("              ");
			}
		}
		round++;
	}
	system("pause");
	return 0;
}

char toString(int i)
{
	if (i == 1)
		return 'A';
	else if (i <= 10)
	{
		return ('1' + i - 1);
	}
	else if (i == 11)
		return 'J';
	else if (i == 12)
		return 'Q';
	else if (i == 13)
		return 'K';
}