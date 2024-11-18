#include <time.h>
#include <stdio.h>
#include "player.h"
#include "skill.h"
#include "reinforce.h"

int death = 0;

int death_check() {
	return death;
}
void death_plus() {
	death++;
}
void death_clear() {
	death = 0;
}

int key_input(int choice) {
	int input;
	while (1) {
		scanf_s("%d", &input);
		if (choice < input) {
			printf("선택지에 없는 값입니다.");
		}
		else {
			return input;
		}
	}
}
void delay(clock_t n) {
	clock_t start = clock();
	while ((clock() - start) < n);
}

void initial_value(struct char_stat player,struct equipment_effect* equipment[], struct weapon_element* element[],struct equipment_element* equipment_element[]) {
	for (int i = 0; i <= 4; i++) {
		equipment[i]->reinforcement = 1;
		equipment_element[i]->plus_atk = equipment[i]->reinforcement;
		equipment_element[i]->plus_def = equipment[i]->reinforcement;
		equipment_element[i]->plus_max_hp = equipment[i]->reinforcement;
	}


	player.atk = 50 + equipment_element[0]->plus_atk + equipment_element[1]->plus_atk + equipment_element[2]->plus_atk + equipment_element[3]->plus_atk + equipment_element[4]->plus_atk;
	player.def = 10 + equipment_element[0]->plus_def + equipment_element[1]->plus_def + equipment_element[2]->plus_def + equipment_element[3]->plus_def + equipment_element[4]->plus_def;
	player.maxhp = 30 + equipment_element[0]->plus_max_hp + equipment_element[1]->plus_max_hp + equipment_element[2]->plus_max_hp + equipment_element[3]->plus_max_hp + equipment_element[4]->plus_max_hp;

}

void changeing_value(struct skillinfo* skill[], struct char_stat* playerptr, struct char_inven* player_invenptr, struct equipment_effect* equipment[], struct weapon_element* element, struct equipment_element* equipment_element[]) {
	for (int i = 0; i <= 4; i++) {
		equipment_element[i]->plus_atk = 1;
		equipment_element[i]->plus_def = 1;
		equipment_element[i]->plus_max_hp = 1;
		for (int j = 1; j < equipment[i]->reinforcement; j++) {
			equipment_element[i]->plus_atk = equipment[i]->reinforcement * 2;
			equipment_element[i]->plus_def = equipment[i]->reinforcement * 2;
			equipment_element[i]->plus_max_hp = equipment[i]->reinforcement * 2;
		}
	}
	int j = 0;
	playerptr->atk = 15 + equipment_element[0]->plus_atk + equipment_element[1]->plus_atk + equipment_element[2]->plus_atk + equipment_element[3]->plus_atk + equipment_element[4]->plus_atk;
	playerptr->def = 15 + equipment_element[0]->plus_def + equipment_element[1]->plus_def + equipment_element[2]->plus_def + equipment_element[3]->plus_def + equipment_element[4]->plus_def;
	playerptr->maxhp = 30 + equipment_element[0]->plus_max_hp + equipment_element[1]->plus_max_hp + equipment_element[2]->plus_max_hp + equipment_element[3]->plus_max_hp + equipment_element[4]->plus_max_hp;
	for (int i = 0; i <= 8; i++) {
		if (i % 3 == 0) {
			skill[i]->skilldmg = playerptr->atk * 1.0;
		}
		else if (i % 3 == 1) {
			skill[i]->skilldmg = playerptr->atk * 2.0;
		}
		else if (i % 3 == 2) {
			skill[i]->skilldmg = playerptr->atk * 10.0;
		}
	}
}