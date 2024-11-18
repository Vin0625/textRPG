#pragma once
#include <time.h>


struct char_stat {
	int atk;
	int def;
	int curhp;
	int map;
	int exp;
	int maxhp;
	int equipment;
	int level;
};
struct char_inven {
		int gold;
		int red_potion;
		int orange_potion;
		int white_potion;
		int full_potion;
		int blue_potion;
		int reinforce_fireskill_vehicle;
		int reinforce_iceskill_vehicle;
		int reinforce_thunderskill_vehicle;
	};
int key_input(int choice);
void delay(clock_t n);
void initial_value(struct char_stat player, struct equipment_effect* equipment[], struct equipment_element* element[]);//ȸ������ �� �ʱⰪ ����
void changeing_value(struct skillinfo* skill[], struct char_stat* playerptr, struct char_inven* player_invenptr, struct equipment_effect* equipment[], struct weapon_element* element, struct equipment_element* equipment_element[]);//���ӳ����� ���������� ���� �� ����
int death_check();
void death_plus();
void death_clear();