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
				printf("����");
				printf("������ ȭ�� �Ӽ� ��ġ:%d", element->fire_reinforcement);
				delay(2000);
				system("cls");
			}
			else {
				printf("����");
				delay(2000);
				system("cls");
			}
		}
		else if (element->fire_reinforcement == 1) {
			if (rand() % 100 <= 1) {
				element->fire_reinforcement = element->fire_reinforcement + 1;
				printf("����");
				printf("������ ȭ�� �Ӽ� ��ġ:%d", element->fire_reinforcement);
				delay(2000);
				system("cls");
			}
			else {
				printf("����");
				delay(2000);
				system("cls");
			}
		}
		else {
			if (rand() % 1000 <= 1) {
				element->fire_reinforcement = element->fire_reinforcement + 1;
				printf("����");
				printf("������ ȭ�� �Ӽ� ��ġ:%d", element->fire_reinforcement);
				delay(2000);
				system("cls");
			}
			else {
				printf("����");
				delay(2000);
				system("cls");
			}
		}
		break;
	case 2:
		if (element->ice_reinforcement == 0) {
			if (rand() % 100 <= 10) {
				element->ice_reinforcement = element->ice_reinforcement + 1;
				printf("����");
				printf("������ ���� �Ӽ� ��ġ:%d", element->ice_reinforcement);
				delay(2000);
				system("cls");
			}
			else {
				printf("����");
				delay(2000);
				system("cls");
			}
		}
		else if (element->ice_reinforcement == 1) {
			if (rand() % 100 <= 1) {
				element->ice_reinforcement = element->ice_reinforcement + 1;
				printf("����");
				printf("������ ���� �Ӽ� ��ġ:%d", element->ice_reinforcement);
				delay(2000);
				system("cls");
			}
			else {
				printf("����");
				delay(2000);
				system("cls");
			}
		}
		else {
			if (rand() % 1000 <= 1) {
				element->ice_reinforcement = element->ice_reinforcement + 1;
				printf("����");
				printf("������ ���� �Ӽ� ��ġ:%d", element->ice_reinforcement);
				delay(2000);
				system("cls");
			}
			else {
				printf("����");
				delay(2000);
				system("cls");
			}
		}
		break;
	case 3:
		if (element->thunder_reinforcement == 0) {
			if (rand() % 100 <= 10) {
				element->thunder_reinforcement = element->thunder_reinforcement + 1;
				printf("����");
				printf("������ ���� �Ӽ� ��ġ:%d", element->thunder_reinforcement);
				delay(2000);
				system("cls");
			}
			else {
				printf("����");
				delay(2000);
				system("cls");
			}
		}
		else if (element->thunder_reinforcement == 1) {
			if (rand() % 100 <= 1) {
				element->thunder_reinforcement = element->thunder_reinforcement + 1;
				printf("����");
				printf("������ ���� �Ӽ� ��ġ:%d", element->thunder_reinforcement);
				delay(2000);
				system("cls");
			}
			else {
				printf("����");
				delay(2000);
				system("cls");
			}
		}
		else {
			if (rand() % 1000 <= 1) {
				element->thunder_reinforcement = element->thunder_reinforcement + 1;
				printf("����");
				printf("������ ���� �Ӽ� ��ġ:%d", element->thunder_reinforcement);
				delay(2000);
				system("cls");
			}
			else {
				printf("����");
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
		printf("���� ��� ������\n");
		printf("ȭ��:%d\n", player_inven->reinforce_fireskill_vehicle);
		printf("����:%d\n", player_inven->reinforce_iceskill_vehicle);
		printf("����:%d\n", player_inven->reinforce_thunderskill_vehicle);
		printf("���� �Ӽ� ��ȭ ��ġ\n");
		printf("1.ȭ��\t\t���� ��ȭ��ġ %d\n", element ->fire_reinforcement);
		printf("2.����\t\t���� ��ȭ��ġ %d\n", element ->ice_reinforcement);
		printf("3.����\t\t���� ��ȭ��ġ %d\n", element ->thunder_reinforcement);
		printf("4.����â���� ���ư��ϴ�.\n");
		printf("� �Ӽ��� �ο��Ͻðڽ��ϱ�?");
		select = key_input(4);
		switch (select) {
		case 1:
			if (player_inven->reinforce_fireskill_vehicle <= 0) {
				printf("��ᰡ �����մϴ�.\n");
				printf("����â���� ���ư��ϴ�.\n");
				delay(2000);
				system("cls");
				break;
			}
			element_reinforceing(1, element);
			return;
		case 2:
			if (player_inven->reinforce_iceskill_vehicle <= 0) {
				printf("��ᰡ �����մϴ�.\n");
				printf("����â���� ���ư��ϴ�.\n");
				delay(2000);
				system("cls");
				break;
			}
			element_reinforceing(2, element);
			return;
		case 3:
			if (player_inven->reinforce_thunderskill_vehicle <= 0) {
				printf("��ᰡ �����մϴ�.\n");
				printf("����â���� ���ư��ϴ�.\n");
				delay(2000);

				system("cls");
				break;
			}
			element_reinforceing(3, element);
			return;
		case 4:
			printf("����â���� �ǵ��ư��ϴ�.\n");
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
	printf("�߰� ���ݷ�:%d  -> %d\n", equipment_element->plus_atk, equipment_element->plus_atk * 2);
	delay(2000);
	if (player_inven->gold >= use_gold) {
		if (per < 12.5) {
			if (rand() % 100 <= per) {
				printf("��ȭ ����!\n����� ��ȭ��ġ�� �����մϴ�.\n");
				printf("��ȭ ��ġ  :%d  -> %d\n", equipments->reinforcement, equipments->reinforcement + 1);
				printf("�߰� ���ݷ�:%d  -> %d\n", equipment_element->plus_atk, equipment_element->plus_atk * 2);
				printf("�߰� ����:%d  -> %d\n", equipment_element->plus_def, equipment_element->plus_def * 2);
				printf("�߰� ü��  :%d  -> %d\n", equipment_element->plus_max_hp, equipment_element->plus_max_hp * 2);
				equipments->reinforcement = equipments->reinforcement + 1;
				equipment_element->plus_atk = equipment_element->plus_atk * 2;
				equipment_element->plus_def = equipment_element->plus_def * 2;
				equipment_element->plus_max_hp = equipment_element->plus_max_hp * 2;
				player_inven->gold = player_inven->gold - use_gold;
				delay(2000);
				system("cls");
			}
			else if ((rand() % 100) >= 100 - per) {
				printf("��ȭ ����!\n����� ��ȭ��ġ�� �϶��մϴ�.\n");
				printf("��ȭ ��ġ  :%d  -> %d\n", equipments->reinforcement, equipments->reinforcement - 1);
				printf("�߰� ���ݷ�:%d  -> %d\n", equipment_element->plus_atk, equipment_element->plus_atk / 2);
				printf("�߰� ����:%d  -> %d\n", equipment_element->plus_def, equipment_element->plus_def / 2);
				printf("�߰� ü��  :%d  -> %d\n", equipment_element->plus_max_hp, equipment_element->plus_max_hp / 2);
				equipments->reinforcement = equipments->reinforcement - 1;
				equipment_element->plus_atk = equipment_element->plus_atk / 2;
				equipment_element->plus_def = equipment_element->plus_def / 2;
				equipment_element->plus_max_hp = equipment_element->plus_max_hp / 2;
				player_inven->gold = player_inven->gold - use_gold;
				delay(2000);
				system("cls");
			}
			else {
				printf("��ȭ ����!����� ��ȭ��ġ���� ������ �����ϴ�.");
				player_inven->gold = player_inven->gold - use_gold;
				delay(2000);
				system("cls");
			}
		}
		else {
			if (rand() % 100 <= per) {
				printf("��ȭ ����!\n����� ��ȭ��ġ�� �����մϴ�.\n");
				printf("��ȭ ��ġ  :%d  -> %d\n", equipments->reinforcement, equipments->reinforcement + 1);
				printf("�߰� ���ݷ�:%d  -> %d\n", equipment_element->plus_atk, equipment_element->plus_atk * 2);
				printf("�߰� ����:%d  -> %d\n", equipment_element->plus_def, equipment_element->plus_def * 2);
				printf("�߰� ü��  :%d  -> %d\n", equipment_element->plus_max_hp, equipment_element->plus_max_hp * 2);
				equipments->reinforcement = equipments->reinforcement + 1;
				equipment_element->plus_atk = equipment_element->plus_atk * 2;
				equipment_element->plus_def = equipment_element->plus_def * 2;
				equipment_element->plus_max_hp = equipment_element->plus_max_hp * 2;
				player_inven->gold = player_inven->gold - use_gold;
				delay(2000);
				system("cls");
			}
			else {
				printf("��ȭ ����!����� ��ȭ��ġ���� ������ �����ϴ�.");
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
		printf("���� ���� ���:%d\t\t\n", player_inven->gold);
		printf("1.����\t\t���� ��ȭ��ġ %d\n", equipments[0]->reinforcement);
		printf("2.����\t\t���� ��ȭ��ġ %d\n", equipments[1]->reinforcement);
		printf("3.�尩\t\t���� ��ȭ��ġ %d\n", equipments[2]->reinforcement);
		printf("4.����\t\t���� ��ȭ��ġ %d\n", equipments[3]->reinforcement);
		printf("5.����\t\t���� ��ȭ��ġ %d\n", equipments[4]->reinforcement);
		printf("6.����-�Ӽ���ȭ\n");
		printf("7.����â���� ���ư��ϴ�.\n");
		printf("� ��� ��ȭ�Ͻðڽ��ϱ�?");
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
			printf("����â���� �ǵ��ư��ϴ�.\n");
			delay(2000);
			return;
		}
	}
}