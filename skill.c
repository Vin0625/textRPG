#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "reinforce.h"
#include "skill.h"

int skill_dmg_calculate(int skilldmg) {
	int dmg = skilldmg;
	return dmg;
}

int use_skill(struct weapon_element* element, struct skillinfo* skill[]) {
	int kind_skill, select_skill, dmg;
	while (1) {
		system("cls");
		printf("어떤 스킬을 사용하시겠습니까?\n");
		if (element->fire_reinforcement > 0) {
			printf("1.화염 계열 스킬\n");
		}
		if (element->fire_reinforcement > 0) {
			printf("2.얼음 계열 스킬\n");
		}
		if (element->fire_reinforcement > 0) {
			printf("3.번개 계열 스킬\n");
		}
		printf("4.전투창 이동");
		kind_skill = key_input(4);
		switch (kind_skill) {
		case 1:
			if (element->fire_reinforcement > 0) {
				while (1) {
					system("cls");
					printf("어떤 스킬을 사용하시겠습니까?\n");
					if (element->fire_reinforcement > 0) {
						printf("1.파이어 볼트 Lv.1\t\t데미지:%d\t\t\n", skill[0]->skilldmg);
						if (element->fire_reinforcement > 1) {
							printf("2.파이어 볼트 Lv.2\t\t데미지:%d\t\t\n", skill[1]->skilldmg);
							if (element->fire_reinforcement > 2) {
								printf("3.파이어 볼트 Lv.3\t\t데미지:%d\t\t\n", skill[2]->skilldmg);
							}
						}
					}
					select_skill = key_input(3);
					switch (select_skill) {
					case 1:
						if (element->fire_reinforcement > 0) {
							printf("파이어 볼트 Lv.1를 사용\n");
							printf("데미지를 %d 입혔습니다.\n", skill_dmg_calculate(skill[0]->skilldmg));
							dmg = skill_dmg_calculate(skill[0]->skilldmg);
							delay(2000);
							break;
						}
					case 2:
						if (element->fire_reinforcement > 1) {
							printf("파이어 볼트 Lv.2를 사용\n");
							printf("데미지를 %d 입혔습니다.\n", skill_dmg_calculate(skill[1]->skilldmg));
							dmg = skill_dmg_calculate(skill[1]->skilldmg);
							delay(2000);
							break;
						}
					case 3:
						if (element->fire_reinforcement > 2) {
							printf("파이어 볼트 Lv.3를 사용\n");
							printf("데미지를 %d 입혔습니다.\n", skill_dmg_calculate(skill[2]->skilldmg));
							dmg = skill_dmg_calculate(skill[2]->skilldmg);
							delay(2000);
							break;
						}
					}
					return dmg;
				}
			}
			else {
				printf("강화 수치가 부족합니다.");
				return;
			}

		case 2:
			if (element->ice_reinforcement > 0) {
				while (1) {
					system("cls");
					printf("어떤 스킬을 사용하시겠습니까?\n");
					if (element->fire_reinforcement > 0) {
						printf("1.아이스 볼트 Lv.1\t\t데미지:%d\t\t\n", skill[3]->skilldmg);
						if (element->fire_reinforcement > 1) {
							printf("2.아이스 볼트 Lv.2\t\t데미지:%d\t\t\n", skill[4]->skilldmg);
							if (element->fire_reinforcement > 2) {
								printf("3.아이스 볼트 Lv.3\t\t데미지:%d\t\t\n", skill[5]->skilldmg);
							}
						}
					}
					select_skill = key_input(3);
					switch (select_skill) {
					case 1:
						if (element->ice_reinforcement > 0) {
							printf("아이스 볼트 Lv.1를 사용\n");
							printf("데미지를 %d 입혔습니다.\n", skill_dmg_calculate(skill[3]->skilldmg));
							dmg = skill_dmg_calculate(skill[3]->skilldmg);
							delay(2000);
							break;
						}
					case 2:
						if (element->ice_reinforcement > 1) {
							printf("아이스 볼트 Lv.2를 사용\n");
							printf("데미지를 %d 입혔습니다.\n", skill_dmg_calculate(skill[4]->skilldmg));
							dmg = skill_dmg_calculate(skill[4]->skilldmg);
							delay(2000);
							break;
						}
					case 3:
						if (element->ice_reinforcement > 2) {
							printf("아이스 볼트 Lv.3를 사용\n");
							printf("데미지를 %d 입혔습니다.\n", skill_dmg_calculate(skill[5]->skilldmg));
							dmg = skill_dmg_calculate(skill[5]->skilldmg);
							delay(2000);
							break;
						}
					}
					return dmg;
				}
			}
			else {
				printf("강화 수치가 부족합니다.");
				return;
			}
		case 3:
			if (element->thunder_reinforcement > 0) {
				while (1) {
					system("cls");
					printf("어떤 스킬을 사용하시겠습니까?\n");
					if (element->thunder_reinforcement > 0) {
						printf("1.썬더 볼트 Lv.1\t\t데미지:%d\t\t\n", skill[6]->skilldmg);
						if (element->thunder_reinforcement > 1) {
							printf("2.썬더 볼트 Lv.2\t\t데미지:%d\t\t\n", skill[7]->skilldmg);
							if (element->thunder_reinforcement > 2) {
								printf("3.썬더 볼트 Lv.3\t\t데미지:%d\t\t\n", skill[8]->skilldmg);
							}
						}
					}
					select_skill = key_input(3);
					switch (select_skill) {
					case 1:
						if (element->thunder_reinforcement > 0) {
							printf("썬더 볼트 Lv.1를 사용\n");
							printf("데미지를 %d 입혔습니다.\n", skill_dmg_calculate(skill[6]->skilldmg));
							dmg = skill_dmg_calculate(skill[6]->skilldmg);
							delay(2000);
							break;
						}
					case 2:
						if (element->thunder_reinforcement > 1) {
							printf("썬더 볼트 Lv.2를 사용\n");
							printf("데미지를 %d 입혔습니다.\n", skill_dmg_calculate(skill[7]->skilldmg));
							dmg = skill_dmg_calculate(skill[7]->skilldmg);
							delay(2000);
							break;
						}
					case 3:
						if (element->thunder_reinforcement > 2) {
							printf("썬더 볼트 Lv.3를 사용");
							printf("데미지를 %d 입혔습니다.", skill_dmg_calculate(skill[8]->skilldmg));
							dmg = skill_dmg_calculate(skill[8]->skilldmg);
							delay(2000);
							break;
						}
					}
					return dmg;
				}
			}
			else {
			printf("강화 수치가 부족합니다.");
			return;
		}
		case 4:
			system("cls");
			printf("선택창으로 되돌아갑니다.\n");
			delay(2000);
			return 0;
			}
		}
	}