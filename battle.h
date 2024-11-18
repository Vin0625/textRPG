#pragma once
#include "monster.h"
#include "reinforce.h"
#include "skill.h"


int dmg_calculate1(struct char_stat* atkker, Monster* deffenser);
int dmg_calculate2(struct char_stat* deffenser, Monster* atkker);
int battle_page(struct char_stat* player, Monster* monster, struct char_inven* player_invenptr , struct weapon_element* element, struct skillinfo* skill[]);
void show_status(struct char_stat* player);
