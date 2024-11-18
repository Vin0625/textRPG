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

double perclac(double hun, int rein);//확률반환
int goldcalc(int gold, int rein);//강화비용반환
void element_reinforceing(int select, struct weapon_element* element);//속성강화
void element_reinforce(struct char_inven* player_inven,struct weapon_element* element);//강화속성선택
void reinforceing(struct equipment_effect* equipments, struct equipment_element* equipment_element,struct char_inven* player_inven);//강화
void reinforce(struct char_inven* player_inven, struct equipment_effect* equipments[], struct equipment_element* equipment_element[], struct weapon_element* element); //강화선택