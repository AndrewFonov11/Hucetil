
// Hucetil version 1.1.2

// Source code

// Released into the public domain under CC0

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int hp,bonus,rnd,armor,boom;
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

void armor_f()
{
	if (armor == 1) {
		world[pos] = 'X';
	}
}

void boom_f()
{
	if (boom == 1) {
		world[pos] = '!';
	}
}

void map()
{
	if ((pos > 9) || (pos < 0)) pos = 1;
	if ((posb > 9) || (posb < 0)) posb = 1;
	world[0] = '/';
	world[1] = '.';
	world[2] = '.';
	world[3] = '.';
	world[4] = '.';
	world[5] = '.';
	world[6] = '.';
	world[7] = '.';
	world[8] = '.';
	world[9] = '/';
	world[10] = '\0';
	world[pos] = '$';
	world[posa] = '%';
	world[posb] = '&';
}

int main()
{
	printf("\nPUBLIC DOMAIN SOFTWARE");
	printf("\nHucetil");
	printf("\nVersion 1.1.2\n");
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
	hp = 3,bonus = 0,pos = 1,posa = 2,posb = rand() % 6 + 3,armor = 0,boom = 0;
	do
	{
		map();
		armor_f();
		boom_f();
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
		if ((a == 'q') && (bonus > 5) && (armor == 0)) {
			armor = 1,bonus-=5;
		}
		if ((a == 'a') && (boom == 0) && (bonus > 5)) {
			boom = 1,bonus-=5;
		}
		move_posb();
		if ((a == 'b') && (boom == 1))
		{
			if (posb == pos + 1) posb++;
			if (posb == pos + 2) posb++;
			if (posb == pos - 1) posb--;
			if (posb == pos - 2) posb--;
			boom = 0,hp--;
		}
		if (a == 'x') hp = 0;
		if (a == 's') {
			printf("\nS: %d",seed);
		}
		tp();
		if (posb == posa) {
			bonus--;
			new_posa();
		}
		if (pos == posb) {
			if (armor == 1) {
				armor = 0;
			}
			else hp--;
			pos = rand() % 8 + 1;
			posb = rand() % 8 + 1;
			if (posb == pos) {
				if (pos == 9) pos--;
				else pos++;
			}
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