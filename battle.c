#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "monster.h"
#include "potion.h"
#include "reinforce.h"
#include "skill.h"
#include "loginfinsh (1).h"


int dmg_calculate1(struct char_stat* atkker, Monster* deffenser) {
	if ((rand() / 100) < 25) {
		printf("회피\n");
		return 0;
	}
	else {
		int dmg = (atkker->atk) / (deffenser->def);
		return dmg;
	}
}
int dmg_calculate2(struct char_stat* deffenser, Monster* atkker) {
	if ((rand() / 100) < 25) {
		printf("회피\n");
		return 0;
	}
	else {
		int dmg = (atkker->atk) / (deffenser->def);
		return dmg;
	}
}
void show_status(struct char_stat* player) {
	while (1) {
		system("cls");
		printf("공격력: %d\n", player->atk);
		printf("방어력: %d\n", player->def);
		printf("체력: %d/%d\n", player->curhp,player->maxhp);
		
		printf("1.상태창 닫기");
		if (key_input(1) == 1)
			return;
	}
}
int battle_page(struct char_stat* player, Monster* monster,struct char_inven* player_invenptr,struct weapon_element* element, struct skillinfo* skill[]) {
	while (1) {
		system("cls");
		
		if (monster->curhp <= 0) {
			printf("you win");
			printf("you earn %d exp, %d gold", monster->drop_exp, monster->drop_gold);
			player->exp += monster->drop_exp;
			player_invenptr->gold += monster->drop_gold;
			delay(2000);
			break;
		}
	
		else if (player->curhp <= 0) {
			printf("you die");
			death_plus();
			delay(2000);

			break;
		}
		printf("캐릭터 체력 : %d\n", player->curhp);
		printf("적 체력 : %d\n", monster->curhp);
		printf("1.공격 2.인벤토리 3. 상태창 확인 4.스킬 사용\n");
		int input = key_input(4);
		switch (input) {
		case 1:
			monster->curhp -= dmg_calculate1(player, monster);
			printf("공격 성공! 데미지를 주었다!\n");
			break;
		case 2:
			use_potion(player_invenptr, player);
			continue;
		case 3:
			show_status(player);
			continue;
		case 4:
			monster->curhp -= use_skill(element, &skill[0]);
			break;
		}
		printf("적 공격");
		monster->pattern();
		player->curhp -= dmg_calculate2(player,monster);
		delay(2000);
	}
}
