#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "player.h"
#include "reinforce.h"

void element_reinforceing(int select, struct weapon_element *element) {
	switch (select) {
	case 1:
		if (element ->fire_reinforcement == 0) {
			if (rand() % 100 <= 10) {
				element->fire_reinforcement = element->fire_reinforcement + 1;
				printf("성공");
				printf("무기의 화염 속성 수치:%d", element->fire_reinforcement);
				delay(2000);
				system("cls");
			}
			else {
				printf("실패");
				delay(2000);
				system("cls");
			}
		}
		else if (element->fire_reinforcement == 1) {
			if (rand() % 100 <= 1) {
				element->fire_reinforcement = element->fire_reinforcement + 1;
				printf("성공");
				printf("무기의 화염 속성 수치:%d", element->fire_reinforcement);
				delay(2000);
				system("cls");
			}
			else {
				printf("실패");
				delay(2000);
				system("cls");
			}
		}
		else {
			if (rand() % 1000 <= 1) {
				element->fire_reinforcement = element->fire_reinforcement + 1;
				printf("성공");
				printf("무기의 화염 속성 수치:%d", element->fire_reinforcement);
				delay(2000);
				system("cls");
			}
			else {
				printf("실패");
				delay(2000);
				system("cls");
			}
		}
		break;
	case 2:
		if (element->ice_reinforcement == 0) {
			if (rand() % 100 <= 10) {
				element->ice_reinforcement = element->ice_reinforcement + 1;
				printf("성공");
				printf("무기의 빙결 속성 수치:%d", element->ice_reinforcement);
				delay(2000);
				system("cls");
			}
			else {
				printf("실패");
				delay(2000);
				system("cls");
			}
		}
		else if (element->ice_reinforcement == 1) {
			if (rand() % 100 <= 1) {
				element->ice_reinforcement = element->ice_reinforcement + 1;
				printf("성공");
				printf("무기의 빙결 속성 수치:%d", element->ice_reinforcement);
				delay(2000);
				system("cls");
			}
			else {
				printf("실패");
				delay(2000);
				system("cls");
			}
		}
		else {
			if (rand() % 1000 <= 1) {
				element->ice_reinforcement = element->ice_reinforcement + 1;
				printf("성공");
				printf("무기의 빙결 속성 수치:%d", element->ice_reinforcement);
				delay(2000);
				system("cls");
			}
			else {
				printf("실패");
				delay(2000);
				system("cls");
			}
		}
		break;
	case 3:
		if (element->thunder_reinforcement == 0) {
			if (rand() % 100 <= 10) {
				element->thunder_reinforcement = element->thunder_reinforcement + 1;
				printf("성공");
				printf("무기의 번개 속성 수치:%d", element->thunder_reinforcement);
				delay(2000);
				system("cls");
			}
			else {
				printf("실패");
				delay(2000);
				system("cls");
			}
		}
		else if (element->thunder_reinforcement == 1) {
			if (rand() % 100 <= 1) {
				element->thunder_reinforcement = element->thunder_reinforcement + 1;
				printf("성공");
				printf("무기의 번개 속성 수치:%d", element->thunder_reinforcement);
				delay(2000);
				system("cls");
			}
			else {
				printf("실패");
				delay(2000);
				system("cls");
			}
		}
		else {
			if (rand() % 1000 <= 1) {
				element->thunder_reinforcement = element->thunder_reinforcement + 1;
				printf("성공");
				printf("무기의 번개 속성 수치:%d", element->thunder_reinforcement);
				delay(2000);
				system("cls");
			}
			else {
				printf("실패");
				delay(2000);
				system("cls");
			}
		}
		break;
	}

	return;
}

void element_reinforce(struct char_inven* player_inven , struct weapon_element *element) {
	int select;
	while (1) {
		system("cls");
		printf("현재 재료 보유량\n");
		printf("화염:%d\n", player_inven->reinforce_fireskill_vehicle);
		printf("빙결:%d\n", player_inven->reinforce_iceskill_vehicle);
		printf("번개:%d\n", player_inven->reinforce_thunderskill_vehicle);
		printf("현재 속성 강화 수치\n");
		printf("1.화염\t\t현재 강화수치 %d\n", element ->fire_reinforcement);
		printf("2.빙결\t\t현재 강화수치 %d\n", element ->ice_reinforcement);
		printf("3.번개\t\t현재 강화수치 %d\n", element ->thunder_reinforcement);
		printf("4.선택창으로 돌아갑니다.\n");
		printf("어떤 속성을 부여하시겠습니까?");
		select = key_input(4);
		switch (select) {
		case 1:
			if (player_inven->reinforce_fireskill_vehicle <= 0) {
				printf("재료가 부족합니다.\n");
				printf("선택창으로 돌아갑니다.\n");
				delay(2000);
				system("cls");
				break;
			}
			element_reinforceing(1, element);
			return;
		case 2:
			if (player_inven->reinforce_iceskill_vehicle <= 0) {
				printf("재료가 부족합니다.\n");
				printf("선택창으로 돌아갑니다.\n");
				delay(2000);
				system("cls");
				break;
			}
			element_reinforceing(2, element);
			return;
		case 3:
			if (player_inven->reinforce_thunderskill_vehicle <= 0) {
				printf("재료가 부족합니다.\n");
				printf("선택창으로 돌아갑니다.\n");
				delay(2000);

				system("cls");
				break;
			}
			element_reinforceing(3, element);
			return;
		case 4:
			printf("선택창으로 되돌아갑니다.\n");
			delay(2000);

			system("cls");
			return;
		}
	}
}

double perclac(double hun, int rein) {
	for (int i = 1; i <= rein; i++) {
		hun = hun / 2.0;
	}
	return hun;
}

int goldcalc(int gold, int rein) {
	for (int i = 1; i <= rein; i++) {
		gold += 5;
	}
	return gold;
}


void reinforceing(struct equipment_effect* equipments, struct equipment_element* equipment_element,struct char_inven* player_inven) {
	double per = perclac(100.0, equipments->reinforcement);
	int use_gold = goldcalc(5, equipments->reinforcement);
	printf("%d %lf",use_gold , per);
	printf("추가 공격력:%d  -> %d\n", equipment_element->plus_atk, equipment_element->plus_atk * 2);
	delay(2000);
	if (player_inven->gold >= use_gold) {
		if (per < 12.5) {
			if (rand() % 100 <= per) {
				printf("강화 성공!\n장비의 강화수치가 증가합니다.\n");
				printf("강화 수치  :%d  -> %d\n", equipments->reinforcement, equipments->reinforcement + 1);
				printf("추가 공격력:%d  -> %d\n", equipment_element->plus_atk, equipment_element->plus_atk * 2);
				printf("추가 방어력:%d  -> %d\n", equipment_element->plus_def, equipment_element->plus_def * 2);
				printf("추가 체력  :%d  -> %d\n", equipment_element->plus_max_hp, equipment_element->plus_max_hp * 2);
				equipments->reinforcement = equipments->reinforcement + 1;
				equipment_element->plus_atk = equipment_element->plus_atk * 2;
				equipment_element->plus_def = equipment_element->plus_def * 2;
				equipment_element->plus_max_hp = equipment_element->plus_max_hp * 2;
				player_inven->gold = player_inven->gold - use_gold;
				delay(2000);
				system("cls");
			}
			else if ((rand() % 100) >= 100 - per) {
				printf("강화 실패!\n장비의 강화수치가 하락합니다.\n");
				printf("강화 수치  :%d  -> %d\n", equipments->reinforcement, equipments->reinforcement - 1);
				printf("추가 공격력:%d  -> %d\n", equipment_element->plus_atk, equipment_element->plus_atk / 2);
				printf("추가 방어력:%d  -> %d\n", equipment_element->plus_def, equipment_element->plus_def / 2);
				printf("추가 체력  :%d  -> %d\n", equipment_element->plus_max_hp, equipment_element->plus_max_hp / 2);
				equipments->reinforcement = equipments->reinforcement - 1;
				equipment_element->plus_atk = equipment_element->plus_atk / 2;
				equipment_element->plus_def = equipment_element->plus_def / 2;
				equipment_element->plus_max_hp = equipment_element->plus_max_hp / 2;
				player_inven->gold = player_inven->gold - use_gold;
				delay(2000);
				system("cls");
			}
			else {
				printf("강화 실패!장비의 강화수치에는 변동이 없습니다.");
				player_inven->gold = player_inven->gold - use_gold;
				delay(2000);
				system("cls");
			}
		}
		else {
			if (rand() % 100 <= per) {
				printf("강화 성공!\n장비의 강화수치가 증가합니다.\n");
				printf("강화 수치  :%d  -> %d\n", equipments->reinforcement, equipments->reinforcement + 1);
				printf("추가 공격력:%d  -> %d\n", equipment_element->plus_atk, equipment_element->plus_atk * 2);
				printf("추가 방어력:%d  -> %d\n", equipment_element->plus_def, equipment_element->plus_def * 2);
				printf("추가 체력  :%d  -> %d\n", equipment_element->plus_max_hp, equipment_element->plus_max_hp * 2);
				equipments->reinforcement = equipments->reinforcement + 1;
				equipment_element->plus_atk = equipment_element->plus_atk * 2;
				equipment_element->plus_def = equipment_element->plus_def * 2;
				equipment_element->plus_max_hp = equipment_element->plus_max_hp * 2;
				player_inven->gold = player_inven->gold - use_gold;
				delay(2000);
				system("cls");
			}
			else {
				printf("강화 실패!장비의 강화수치에는 변동이 없습니다.");
				player_inven->gold = player_inven->gold - use_gold;
				delay(2000);
				system("cls");
			}
		}
	}
}


void reinforce(struct char_inven* player_inven, struct equipment_effect* equipments[], struct equipment_element* equipment_element[], struct weapon_element* element) {

	int select;
	while (1) {
		system("cls");
		printf("현재 보유 골드:%d\t\t\n", player_inven->gold);
		printf("1.투구\t\t현재 강화수치 %d\n", equipments[0]->reinforcement);
		printf("2.갑옷\t\t현재 강화수치 %d\n", equipments[1]->reinforcement);
		printf("3.장갑\t\t현재 강화수치 %d\n", equipments[2]->reinforcement);
		printf("4.부츠\t\t현재 강화수치 %d\n", equipments[3]->reinforcement);
		printf("5.무기\t\t현재 강화수치 %d\n", equipments[4]->reinforcement);
		printf("6.무기-속성강화\n");
		printf("7.선택창으로 돌아갑니다.\n");
		printf("어떤 장비를 강화하시겠습니까?");
		select = key_input(7);
		switch (select) {
		case 1:
			reinforceing(equipments[0], equipment_element[0],player_inven);
			break;
		case 2:
			reinforceing(equipments[1], equipment_element[1], player_inven);
			break;
		case 3:
			reinforceing( equipments[2], equipment_element[2], player_inven);
			break;
		case 4:
			reinforceing (equipments[3], equipment_element[3], player_inven);
			break;
		case 5:
			reinforceing(equipments[4], equipment_element[4], player_inven);
			break;
		case 6:
			element_reinforce(player_inven,element);
			break;
		case 7:
			system("cls");
			printf("선택창으로 되돌아갑니다.\n");
			delay(2000);
			return;
		}
	}
}