#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include "monster.h"
#include "monsterfunc.h"
#include "battle.h"
#include "reinforce.h"
#include <string.h>


char ID[20];
char Ps[20];

void Data_Reset(struct char_stat* player, struct char_inven* player_inven, struct equipment_effect* helmet, struct equipment_effect* armor
	, struct equipment_effect* glove, struct equipment_effect* boot, struct equipment_effect* weapon, struct weapon_element* we) {
	player->atk = 15;//기본 정보 설정
	player->def = 15;
	player->curhp = 30;
	player->maxhp = 30;
	player->map = 1;
	player->equipment = 0;
	player->exp = 0;
	player->level = 1;
	player_inven->gold = 100;
	player_inven->red_potion = 0;
	player_inven->orange_potion = 0;
	player_inven->white_potion = 0;
	player_inven->full_potion = 0;
	player_inven->blue_potion = 0;
	player_inven->reinforce_fireskill_vehicle = 0;
	player_inven->reinforce_iceskill_vehicle = 0;
	player_inven->reinforce_thunderskill_vehicle = 0;
	helmet->reinforcement = 1;
	armor->reinforcement = 1;
	glove->reinforcement = 1;
	boot->reinforcement = 1;
	weapon->reinforcement = 1;
	we->fire_reinforcement = 0;
	we->ice_reinforcement = 0;
	we->thunder_reinforcement = 0;
}

void Check_ID() {
	FILE* fp = NULL;
	printf("아이디를 입력하세요:");
	scanf("%s", ID);
	fp = fopen(ID, "r");
	if (fp != NULL) {
		printf("이미 사용된 아이디입니다.\n");
		Check_ID();
	}
}
void Data_save(struct char_stat* player, struct char_inven* player_inven, struct equipment_effect* helmet, struct equipment_effect* armor
	, struct equipment_effect* glove, struct equipment_effect* boot, struct equipment_effect* weapon, struct weapon_element* we) {
	FILE* fp = NULL;
	fp = fopen(ID, "w");
	fprintf(fp, "%s %d %d %d %d %d %d %d %d\n", Ps, player->atk, player->def, player->curhp, player->maxhp, player->map, player->equipment, player->exp, player->level);
	fprintf(fp, "%d %d %d %d %d %d %d %d %d\n", player_inven->gold, player_inven->red_potion, player_inven->orange_potion, player_inven->white_potion, player_inven->full_potion, player_inven->blue_potion
		, player_inven->reinforce_fireskill_vehicle, player_inven->reinforce_iceskill_vehicle, player_inven->reinforce_thunderskill_vehicle);
	fprintf(fp, "%d %d %d %d %d\n", helmet->reinforcement, armor->reinforcement, glove->reinforcement, boot->reinforcement, weapon->reinforcement);
	fprintf(fp, "%d %d %d\n", we->fire_reinforcement, we->ice_reinforcement, we->thunder_reinforcement);
	fclose(fp);
}



void login(struct char_stat* player, struct char_inven* player_inven, struct equipment_effect* helmet, struct equipment_effect* armor
	, struct equipment_effect* glove, struct equipment_effect* boot, struct equipment_effect* weapon, struct weapon_element* we) {
	int login_success = 0;
	int trash;
	while (login_success != 1) {
		FILE* fp = NULL;
		char Ps2[20];
		printf("1.회원가입 2.로그인");

		switch (key_input(2)) {
		case 1:
			Check_ID();
			printf("비밀번호를 입력하세요(5자리):");
			scanf("%s", Ps);

			fp = fopen(ID, "w");
			if (fp == NULL) {
				printf("생성에 실패했습니다.");
				continue;
			}


			player->atk = 15;//기본 정보 설정
			player->def = 15;
			player->curhp = 30;
			player->maxhp = 30;
			player->map = 1;
			player->equipment = 0;
			player->exp = 0;
			player->level = 1;
			player_inven->gold = 100;
			player_inven->red_potion = 0;
			player_inven->orange_potion = 0;
			player_inven->white_potion = 0;
			player_inven->full_potion = 0;
			player_inven->blue_potion = 0;
			player_inven->reinforce_fireskill_vehicle = 0;
			player_inven->reinforce_iceskill_vehicle = 0;
			player_inven->reinforce_thunderskill_vehicle = 0;
			helmet->reinforcement = 1;
			armor->reinforcement = 1;
			glove->reinforcement = 1;
			boot->reinforcement = 1;
			weapon->reinforcement = 1;
			we->fire_reinforcement = 0;
			we->ice_reinforcement = 0;
			we->thunder_reinforcement = 0;
			printf("생성에 성공했습니다.");
			fprintf(fp, "%s %d %d %d %d %d %d %d %d\n", Ps, player->atk, player->def, player->curhp, player->maxhp, player->map, player->equipment, player->exp, player->level);
			fprintf(fp, "%d %d %d %d %d %d %d %d %d\n", player_inven->gold, player_inven->red_potion, player_inven->orange_potion, player_inven->white_potion, player_inven->full_potion, player_inven->blue_potion
				, player_inven->reinforce_fireskill_vehicle, player_inven->reinforce_iceskill_vehicle, player_inven->reinforce_thunderskill_vehicle);
			fprintf(fp, "%d %d %d %d %d\n", helmet->reinforcement, armor->reinforcement, glove->reinforcement, boot->reinforcement, weapon->reinforcement);
			fprintf(fp, "%d %d %d\n", we->fire_reinforcement, we->ice_reinforcement, we->thunder_reinforcement);

			delay(2000);
			fclose(fp);

			break;

		case 2:
			printf("아이디를 입력하세요:");
			scanf("%s", ID);

			printf("비밀번호를 입력하세요:");
			scanf("%s", Ps);

			if ((fp = fopen(ID, "r")) == NULL) {
				printf("아이디를 먼저 만들어주세요");
			}

			fgets(Ps2, 6, fp);
			if (strstr(Ps, Ps2)) {
				printf("로그인되었습니다");
			}
		}
		fseek(fp, 0, SEEK_SET);
		fscanf(fp, "%s %d %d %d %d %d %d %d %d\n", Ps, &player->atk, &player->def, &player->curhp, &player->maxhp, &player->map, &player->equipment, &player->exp, &player->level);
		fscanf(fp, "%d %d %d %d %d %d %d %d %d\n", &player_inven->gold, &player_inven->red_potion, &player_inven->orange_potion, &player_inven->white_potion, &player_inven->full_potion, &player_inven->blue_potion
			, &player_inven->reinforce_fireskill_vehicle, &player_inven->reinforce_iceskill_vehicle, &player_inven->reinforce_thunderskill_vehicle);
		fscanf(fp, "%d %d %d %d %d\n", &helmet->reinforcement, &armor->reinforcement, &glove->reinforcement, &boot->reinforcement, &weapon->reinforcement);
		fscanf(fp, "%d %d %d\n", &we->fire_reinforcement, &we->ice_reinforcement, &we->thunder_reinforcement);

		delay(2000);
		fclose(fp);
		login_success = 1;
		break;
	}
}

