#pragma once
#include "player.h"

struct equipment_effect {
	int reinforcement;

};
struct equipment_element {
	int plus_atk;
	int plus_def;
	int plus_max_hp;
};
struct weapon_element {
	int fire_reinforcement;
	int ice_reinforcement;
	int thunder_reinforcement;
};

double perclac(double hun, int rein);//Ȯ����ȯ
int goldcalc(int gold, int rein);//��ȭ����ȯ
void element_reinforceing(int select, struct weapon_element* element);//�Ӽ���ȭ
void element_reinforce(struct char_inven* player_inven,struct weapon_element* element);//��ȭ�Ӽ�����
void reinforceing(struct equipment_effect* equipments, struct equipment_element* equipment_element,struct char_inven* player_inven);//��ȭ
void reinforce(struct char_inven* player_inven, struct equipment_effect* equipments[], struct equipment_element* equipment_element[], struct weapon_element* element); //��ȭ����