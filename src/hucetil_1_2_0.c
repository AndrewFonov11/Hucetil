
// Hucetil version 1.2.0

// Source code

// Released into the public domain under CC0

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

int hp,bonus,rs,armor,boom,frz,sfrz,com;
int pos,posa,posb;
int seed;
char world[11],a;

void new_posa()
{
	posa = rand() % 8 + 1;
}

void move_posb()
{
	if (frz == 0) {
		if (posb > posa) posb--;
		if (posb < posa) posb++;
	}
	else {
		sfrz--;
	}
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

void freezing_f()
{
	if (frz == 1) {
		world[posb] = '*';
	}
}

void sfrz_f()
{
	if (sfrz < 0) sfrz = 0;
	if (sfrz == 0) frz = 0;
}

void com_tp_f()
{
	printf("\nPos:");
	scanf("%d",&pos);
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
	printf("\nVersion 1.2.0\n");
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
	printf("\nC?(y/n)");
	scanf(" %c",&a);
	if (a == 'y') {
		com = 1;
	}
	else {
		com = 0;
	}
	hp = 3,bonus = 0,pos = 1,posa = 2,posb = rand() % 6 + 3,armor = 0,boom = 0,rs = 0,frz = 0,sfrz = 0;
	do
	{
		map();
		armor_f();
		boom_f();
		freezing_f();
		sfrz_f();
		if (bonus < 0) bonus = 0;
		printf("\nHP: %d,Bonus: %d,Resources: %d\n",hp,bonus,rs);
		printf("\n%s",world);
		printf("\n\nS.C. - ");
		if (com == 0) printf("off");
		if (com == 1) printf("on");
		a = getch();
		system("cls");
		if ((a == 't') && (com == 1)) com_tp_f();
		if (a == 'e') pos--;
		if (a == 'r') pos++;
		if ((a == 'w') && (bonus > 2) && (hp < 3)) {
			bonus-=2,hp++;
		}
		if ((a == 'z') && (bonus > 3) && (rs < 10)) {
			bonus-=3,rs++;
		}
		if ((a == 'q') && (rs > 2) && (armor == 0)) {
			armor = 1,rs-=2;
		}
		if ((a == 'a') && (boom == 0) && (rs > 3)) {
			boom = 1,rs-=3;
		}
		if ((a == 'f') && (frz == 0) && (bonus > 3) && (rs > 4)) {
			frz = 1,sfrz = 3,bonus-=3,rs-=4;
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
		if ((posb == posa) && (pos != posa)) {
			bonus--;
			new_posa();
		}
		if ((pos == posa) && (posb != posa)) {
			bonus++;
			new_posa();
		}
		if ((pos == posa) && (posb == posa)) {
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
	}
	while (hp > 0);
	printf("\nGame Over");
	printf("\n%d",bonus);
	return 0;
}