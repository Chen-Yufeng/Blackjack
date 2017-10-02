#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(void)
{
	int a[52];
	int b[52];
	int random;

	for (int x = 0; x < 4; x++)
	{
		for (int y = 0; y < 13; y++)
		{
			a[x * 13 + y] = y < 10 ? (y + 1) : 10;
		}
	}

	srand((unsigned int)time(NULL));
	for (int z = 0; z < 52; z++)
	{
		random = rand() % (52-z) + 1;
		b[z] = a[random];
		a[random] = a[52 - z];
	}

	printf("Welcome to The Blackjack Game(by XZH)!");


	return 0;
}