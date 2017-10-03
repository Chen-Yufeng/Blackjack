#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

char* toString(int);
void add(int * total, int number);
void check(int total, int choice,bool * b_out);
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
	bool b_out = true;
	b_one = b_two = true;
	bool re = true;
	int* p = b;
	int total_a, total_b;
	int round;

	while (re)
	{
		for (int x = 0; x < 4; x++)
			for (int y = 0; y < 13; y++)
				a[x * 13 + y] = y + 1;

		srand((unsigned int)(time(NULL)*time(NULL)));  //???rand in for ???
		for (int z = 0; z < 51; z++)
		{
			random = rand() % (52 - z);
			b[z] = a[random];
			a[random] = a[51 - z];
		}
		b[51] = a[0];

		//code for test:
		//int t[13] = { 0 };
		//for (int x = 0; x < 52; x++)
		//	t[b[x]-1]++;
		//for (int x = 0; x < 13; x++)
		//	printf("%d ", t[x]);


		printf("Welcome to The Blackjack Game(by XZH)!\n");
		printf("		yours		the other's\n");

		total_a =total_b = 0;

		round = 1;
		while (bl&&b_out)
		{
			if (round == 1)
			{
				printf("Round %d", round);
				printf("		  %s", toString(*p));
				add(&total_a, *(p++));
				printf("		    %s", toString(*p));
				add(&total_b, *(p++));
			}
			else
			{
				printf("		Want more?(y/n*2 eg:yy): ");

				if (tolower(getchar()) == 'n')
					b_one = false;
				if (tolower(getchar()) == 'n')
					b_two = false;
				if (!(b_one || b_two))
					bl = false;
				eatline();
				if (bl)
				{
					printf("Round %d", round);
					if (b_one)
					{
						printf("		  %s", toString(*p));
						add(&total_a, *(p++));
						check(total_a, 1, &b_out);
						if (!b_out)
						{
							b_two = false;
							putchar('\n');
						}
					}
					else
						printf("		    ");
					if (b_two)
					{
						printf("		    %s", toString(*p));
						add(&total_b, *(p++));
						check(total_b, 2, &b_out);
					}
					else
						printf("              ");
				}
			}
			round++;
		}
		if (b_out)
		{
			printf("\nTotal:		  %d		%d", total_a, total_b);
			if (total_a == total_b)
				printf("		PUSH!\n");
			else
				printf("\nYou %s this game!\n", total_a > total_b ? "win" : "lose");
		}
		printf("Want another game?(y/n)");
		if (getchar() == 'y'){
			bl = b_one = b_out = b_two = true;
		} else {
			re = false;
		}
			eatline();
	}
	system("pause");
	return 0;
}

char* toString(int i)
{
	if (i == 1)
		return "A";
	else if (i <= 10)
	{
		static char s[3];
		_itoa(i, s, 10);
		return s;
	}
	else if (i == 11)
		return "J";
	else if (i == 12)
		return "Q";
	else if (i == 13)
		return "K";
}

void add(int * total,int number)
{
	if (number == 1)
		*total += 11;
	else if (number > 10)
		*total += 10;
	else
		*total += number;
}

void check(int total, int choice,bool * b_out)
{
	switch (choice)
	{
	case 1:
		if (total > 21)
		{
			printf("\nYou lose this game!\n");
			*b_out = false;
		}
		break;
	case 2:
		if (total > 21)
		{
			printf("\nYou win this game!\n");
			*b_out = false;
		}
		break;
	default:
		break;
	}
}