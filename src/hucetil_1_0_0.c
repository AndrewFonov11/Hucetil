
// Hucetil version 1.0.0

// Source code

// Released into the public domain under CC0

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int hp,bonus,rnd;
int pos,posa,posb;
int seed;
char world[11],a;

void new_posa()
{
	posa = rand() % 8 + 1;
}

void move_posb()
{
	if (posb > posa) posb--;
	if (posb < posa) posb++;
}

void tp()
{
	if (pos == 9) pos = 1;
	if (pos == 0) pos = 8;
	if (posb == 9) posb = 1;
	if (posb == 0) posb = 8;
}

void map()
{
	world[0] = '/';
	world[1] = ' ';
	world[2] = ' ';
	world[3] = ' ';
	world[4] = ' ';
	world[5] = ' ';
	world[6] = ' ';
	world[7] = ' ';
	world[8] = ' ';
	world[9] = '/';
	world[10] = '\0';
	world[pos] = '$';
	world[posa] = '%';
	world[posb] = '&';
}

int main()
{
	printf("\nPUBLIC DOMAIN SOFTWARE");
	printf("\nHucetil version 1.0.0\n");
	printf("\nS?(y/n)");
	scanf(" %c",&a);
	if (a == 'y') {
		printf("\n:");
		scanf("%d",&seed);
		srand(seed);
	}
	else {
		seed = 0;
		srand(time(NULL));
	}
	hp = 3,bonus = 0,pos = 1,posa = 2,posb = 8;
	do
	{
		map();
		if (bonus < 0) bonus = 0;
		printf("\nHP: %d,Bonus: %d\n",hp,bonus);
		printf("\n%s",world);
		a = getch();
		system("cls");
		if (a == 'e') pos--;
		if (a == 'r') pos++;
		if ((a == 'w') && (bonus > 2) && (hp < 3)) {
			bonus-=2,hp++;
		}
		if (a == 'x') hp = 0;
		if (a == 's') {
			printf("\nS: %d",seed);
		}
		move_posb();
		tp();
		if (posb == posa) {
			bonus--;
			new_posa();
		}
		if (pos == posb) {
			hp--;
			pos = rand() % 8 + 1;
			posb = rand() % 8 + 1;
			if (posb == pos) pos++;
		}
		if (pos == posa) {
			bonus++;
			new_posa();
		}
	}
	while (hp > 0);
	printf("\nGame Over");
	printf("\n%d",bonus);
	return 0;
}