#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
//#include <string.h>
//#include <ctype.h>
#include <Windows.h>

char* toString(int);
void add(int * total, int number);
void check(int total,bool * b_out);

//void eatline(void)
//{
//	while (getchar() != '\n')
//		continue;
//}

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
			
				if (bl)
				{
					printf("\nRound %d", round);

					if(b_one)
						if ((_Bool)(MessageBox(NULL, "Do you want the next one?", "Choose", MB_YESNO) == IDNO))
							b_one = false;

					if (b_one)
					{
						printf("		  %s", toString(*p));
						add(&total_a, *(p++));
						check(total_a, &b_out);
						if (!b_out)
						{
							b_two = false;
							printf("\nTotal:		  %d		    %d", total_a, total_b);
							printf("\nYou lost this game!\n");
						}
					}
					else
						printf("		    ");

					if(b_two)
						if ((_Bool)(MessageBox(NULL, "Do you want your opponent to have next one?", "Choose", MB_YESNO) == IDNO))
							b_two = false;

					if (b_two)
					{
						printf("		    %s", toString(*p));
						add(&total_b, *(p++));
						check(total_b, &b_out);
						if (!b_out)
						{
							printf("\nTotal:		  %d		    %d", total_a, total_b);
							printf("\nYou win this game!\n");
						}
					}
					else
						printf("              ");
				}
			}
			round++;

			if (!(b_one || b_two))
				bl = false;

		}
		if (b_out)
		{
			printf("\nTotal:		  %d		    %d", total_a, total_b);
			if (total_a == total_b)
				printf("		PUSH!\n");
			else
				printf("\nYou %s this game!\n", total_a > total_b ? "win" : "lose");
		}

		if ((_Bool)(MessageBox(NULL, "Expect another game ?", "Choose", MB_YESNO) == IDYES)){
			bl = b_one = b_out = b_two = true;
		} else {
			re = false;
		}
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
		switch ((_Bool)(MessageBox(NULL, "\"A as 11 or not?\"", "Choose", MB_YESNO)==IDYES)) {
		case 1:
			*total += 11;
			break;
		case 0:
			*total += 1;
		}
	else if (number > 10)
		*total += 10;
	else
		*total += number;
}

void check(int total,bool * b_out)
{
	if (total > 21)
	{
		*b_out = false;
	}

}