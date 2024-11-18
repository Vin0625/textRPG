#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "monster.h"

void pattern1(Monster mon) {
	mon.turn += 1;
	srand((unsigned int)time(NULL));
	if ((rand() % 100) <= 5) {
		mon.curhp += 100;
	}
}

void pattern2(Monster mon) {
	mon.turn += 1;
	if ((mon.turn%3)==0) {
		mon.atk += 5;
	}
}

void pattern3(Monster mon) {
	mon.turn += 1;
	if ((mon.turn % 2) == 0) {
		mon.def = 999;
	}
	else
		mon.def = 10;
}

void pattern4(Monster mon) {
	mon.turn += 1;
	srand((unsigned int)time(NULL));
	if ((rand() % 10000) <= 5) {
		mon.drop_gold = 9999;
	}
}

void pattern5(Monster mon) {
	mon.turn += 1;
	mon.curhp += 5;
}

void monster_implement(Monster* monster1, Monster* monster2, Monster* monster3, Monster* monster4, Monster* monster5) {
	
	monster1->atk = 30;
	monster1->def = 5;
	monster1->curhp = 30;
	monster1->drop_exp = 10;
	monster1->drop_gold = 10;
	monster1->turn = 0;
	monster1->pattern = pattern1;

	
	monster2->atk = 40;
	monster2->def = 6;
	monster2->curhp = 40;
	monster2->drop_exp = 20;
	monster2->drop_gold = 20;
	monster2->turn = 0;
	monster2->pattern = pattern2;

	
	monster3->atk = 50;
	monster3->def = 7;
	monster3->curhp = 50;
	monster3->drop_exp = 30;
	monster3->drop_gold = 30;
	monster3->turn = 0;
	monster3->pattern = pattern3;

	
	monster4->atk = 60;
	monster4->def = 8;
	monster4->curhp = 60;
	monster4->drop_exp = 40;
	monster4->drop_gold = 40;
	monster4->turn = 0;
	monster4->pattern = pattern4;

	
	monster5->atk = 70;
	monster5->def = 9;
	monster5->curhp = 70;
	monster5->drop_exp = 50;
	monster5->drop_gold = 50;
	monster5->turn = 0;
	monster5->pattern = pattern5;
}

