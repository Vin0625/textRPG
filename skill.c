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
		printf("� ��ų�� ����Ͻðڽ��ϱ�?\n");
		if (element->fire_reinforcement > 0) {
			printf("1.ȭ�� �迭 ��ų\n");
		}
		if (element->fire_reinforcement > 0) {
			printf("2.���� �迭 ��ų\n");
		}
		if (element->fire_reinforcement > 0) {
			printf("3.���� �迭 ��ų\n");
		}
		printf("4.����â �̵�");
		kind_skill = key_input(4);
		switch (kind_skill) {
		case 1:
			if (element->fire_reinforcement > 0) {
				while (1) {
					system("cls");
					printf("� ��ų�� ����Ͻðڽ��ϱ�?\n");
					if (element->fire_reinforcement > 0) {
						printf("1.���̾� ��Ʈ Lv.1\t\t������:%d\t\t\n", skill[0]->skilldmg);
						if (element->fire_reinforcement > 1) {
							printf("2.���̾� ��Ʈ Lv.2\t\t������:%d\t\t\n", skill[1]->skilldmg);
							if (element->fire_reinforcement > 2) {
								printf("3.���̾� ��Ʈ Lv.3\t\t������:%d\t\t\n", skill[2]->skilldmg);
							}
						}
					}
					select_skill = key_input(3);
					switch (select_skill) {
					case 1:
						if (element->fire_reinforcement > 0) {
							printf("���̾� ��Ʈ Lv.1�� ���\n");
							printf("�������� %d �������ϴ�.\n", skill_dmg_calculate(skill[0]->skilldmg));
							dmg = skill_dmg_calculate(skill[0]->skilldmg);
							delay(2000);
							break;
						}
					case 2:
						if (element->fire_reinforcement > 1) {
							printf("���̾� ��Ʈ Lv.2�� ���\n");
							printf("�������� %d �������ϴ�.\n", skill_dmg_calculate(skill[1]->skilldmg));
							dmg = skill_dmg_calculate(skill[1]->skilldmg);
							delay(2000);
							break;
						}
					case 3:
						if (element->fire_reinforcement > 2) {
							printf("���̾� ��Ʈ Lv.3�� ���\n");
							printf("�������� %d �������ϴ�.\n", skill_dmg_calculate(skill[2]->skilldmg));
							dmg = skill_dmg_calculate(skill[2]->skilldmg);
							delay(2000);
							break;
						}
					}
					return dmg;
				}
			}
			else {
				printf("��ȭ ��ġ�� �����մϴ�.");
				return;
			}

		case 2:
			if (element->ice_reinforcement > 0) {
				while (1) {
					system("cls");
					printf("� ��ų�� ����Ͻðڽ��ϱ�?\n");
					if (element->fire_reinforcement > 0) {
						printf("1.���̽� ��Ʈ Lv.1\t\t������:%d\t\t\n", skill[3]->skilldmg);
						if (element->fire_reinforcement > 1) {
							printf("2.���̽� ��Ʈ Lv.2\t\t������:%d\t\t\n", skill[4]->skilldmg);
							if (element->fire_reinforcement > 2) {
								printf("3.���̽� ��Ʈ Lv.3\t\t������:%d\t\t\n", skill[5]->skilldmg);
							}
						}
					}
					select_skill = key_input(3);
					switch (select_skill) {
					case 1:
						if (element->ice_reinforcement > 0) {
							printf("���̽� ��Ʈ Lv.1�� ���\n");
							printf("�������� %d �������ϴ�.\n", skill_dmg_calculate(skill[3]->skilldmg));
							dmg = skill_dmg_calculate(skill[3]->skilldmg);
							delay(2000);
							break;
						}
					case 2:
						if (element->ice_reinforcement > 1) {
							printf("���̽� ��Ʈ Lv.2�� ���\n");
							printf("�������� %d �������ϴ�.\n", skill_dmg_calculate(skill[4]->skilldmg));
							dmg = skill_dmg_calculate(skill[4]->skilldmg);
							delay(2000);
							break;
						}
					case 3:
						if (element->ice_reinforcement > 2) {
							printf("���̽� ��Ʈ Lv.3�� ���\n");
							printf("�������� %d �������ϴ�.\n", skill_dmg_calculate(skill[5]->skilldmg));
							dmg = skill_dmg_calculate(skill[5]->skilldmg);
							delay(2000);
							break;
						}
					}
					return dmg;
				}
			}
			else {
				printf("��ȭ ��ġ�� �����մϴ�.");
				return;
			}
		case 3:
			if (element->thunder_reinforcement > 0) {
				while (1) {
					system("cls");
					printf("� ��ų�� ����Ͻðڽ��ϱ�?\n");
					if (element->thunder_reinforcement > 0) {
						printf("1.��� ��Ʈ Lv.1\t\t������:%d\t\t\n", skill[6]->skilldmg);
						if (element->thunder_reinforcement > 1) {
							printf("2.��� ��Ʈ Lv.2\t\t������:%d\t\t\n", skill[7]->skilldmg);
							if (element->thunder_reinforcement > 2) {
								printf("3.��� ��Ʈ Lv.3\t\t������:%d\t\t\n", skill[8]->skilldmg);
							}
						}
					}
					select_skill = key_input(3);
					switch (select_skill) {
					case 1:
						if (element->thunder_reinforcement > 0) {
							printf("��� ��Ʈ Lv.1�� ���\n");
							printf("�������� %d �������ϴ�.\n", skill_dmg_calculate(skill[6]->skilldmg));
							dmg = skill_dmg_calculate(skill[6]->skilldmg);
							delay(2000);
							break;
						}
					case 2:
						if (element->thunder_reinforcement > 1) {
							printf("��� ��Ʈ Lv.2�� ���\n");
							printf("�������� %d �������ϴ�.\n", skill_dmg_calculate(skill[7]->skilldmg));
							dmg = skill_dmg_calculate(skill[7]->skilldmg);
							delay(2000);
							break;
						}
					case 3:
						if (element->thunder_reinforcement > 2) {
							printf("��� ��Ʈ Lv.3�� ���");
							printf("�������� %d �������ϴ�.", skill_dmg_calculate(skill[8]->skilldmg));
							dmg = skill_dmg_calculate(skill[8]->skilldmg);
							delay(2000);
							break;
						}
					}
					return dmg;
				}
			}
			else {
			printf("��ȭ ��ġ�� �����մϴ�.");
			return;
		}
		case 4:
			system("cls");
			printf("����â���� �ǵ��ư��ϴ�.\n");
			delay(2000);
			return 0;
			}
		}
	}