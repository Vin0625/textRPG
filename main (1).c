#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include "monster.h"
#include "monsterfunc.h"
#include "battle.h"
#include "skill.h"
#include "reinforce.h"
#include "map.h"
#include "story.h"


int main() {
	int success_login = -1;

	
	
	srand((long)time(NULL));
	struct char_stat player;
	struct char_inven player_inven;
	
	struct equipment_effect helmet, armor, glove, boot, weapon;
	struct equipment_effect* equipment[5] = { &helmet, &armor, &glove, &boot, &weapon };
	struct equipment_element helmet_element, armor_element, glove_element, boot_element, weapon_element;
	struct equipment_element* equipment_element[5] = { &helmet_element, &armor_element, &glove_element, &boot_element, &weapon_element };
	struct weapon_element element;
	struct skillinfo fire1, fire2, fire3, ice1, ice2, ice3, thunder1, thunder2, thunder3;
	struct skillinfo* skill[9] = { &fire1, &fire2, &fire3, &ice1, &ice2, &ice3, &thunder1, &thunder2, &thunder3};
	struct char_inven* player_invenptr = &player_inven;
	struct char_stat* playerptr = &player;
	login(&player, &player_inven, &helmet, &armor, &glove, &boot, &weapon,&element);
	


	while (1) {
		switch (player.map) {
		case 0:
			changeing_value(&skill, playerptr, player_invenptr, equipment, &element, equipment_element);
			story_opening(&player);
			break; 
		case 1:
			changeing_value(&skill, playerptr, player_invenptr, equipment, &element, equipment_element);
			mapstart(&player,&player_inven, equipment, equipment_element, &element,skill);
			break;
		case 2:
			changeing_value(&skill, playerptr, player_invenptr, equipment, &element, equipment_element);
			mapstart(&player, &player_inven, equipment, equipment_element, &element, skill);
			break;
		case 3:
			changeing_value(&skill, playerptr, player_invenptr, equipment, &element, equipment_element);
			mapstart(&player, &player_inven, equipment, equipment_element, &element, skill);
			break;
		case 4:
			changeing_value(&skill, playerptr, player_invenptr, equipment, &weapon_element, equipment_element);
			story_ending(&player);
			Data_Reset(&player, &player_inven, &helmet, &armor, &glove, &boot, &weapon, &element);
			break;
		}
		Data_save(&player, &player_inven, &helmet, &armor, &glove, &boot, &weapon, &element);
		if (death_check() == 1) {
			Data_Reset(&player, &player_inven, &helmet, &armor, &glove, &boot, &weapon, &element);
			Data_save(&player, &player_inven, &helmet, &armor, &glove, &boot, &weapon, &element);
			exit(1);
		}
	}
}
