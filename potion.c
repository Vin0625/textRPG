#include <stdio.h>
#include "player.h"
#include "reinforce.h"


void use_potion(struct char_inven* player_inven, struct char_stat* player_stat) {
	int healamount;
	healamount = player_stat->maxhp - player_stat->curhp;
	if (healamount == 0) {
		printf("���� hp���̻����� ȸ���� �� �����ϴ�..\n");
		printf("����â���� �̵��մϴ�\n");
		delay(2000);
		return;
	}

	if (player_inven->red_potion == 0 && player_inven->orange_potion == 0 && player_inven->white_potion == 0 && player_inven->full_potion == 0 && player_inven->blue_potion == 0) {
		printf("��밡���� �������� �����ϴ�.\n");
		printf("����â���� �ǵ��ư��ϴ�..\n");
		delay(2000);
		return;
	}
	else {
		while (1) {
			printf("���� hp��ġ:%d\n", player_stat->curhp);
			printf("���� ������:\n");
			printf("1.red_potion : %d", player_inven->red_potion);
			printf("									hp�� 5 ȸ���մϴ�.");
			printf("\n");
			printf("2.orange_potion : %d", player_inven->orange_potion);
			printf("									hp�� 20 ȸ���մϴ�.");
			printf("\n");
			printf("3.white_potion : %d", player_inven->white_potion);
			printf("									hp�� 50 ȸ���մϴ�.");
			printf("\n");
			printf("4.full_potion : %d", player_inven->full_potion);
			printf("									hp�� mp�� ��� ȸ���մϴ�.");
			printf("\n");
			printf("5.blue_potion : %d", player_inven->blue_potion);
			printf("									mp�� 10 ȸ���մϴ�.");
			printf("\n");
			printf("6.����â���� �̵�");
			printf("\n");
			printf("� ������ ����Ͻðڽ��ϱ�?");
			int potion = key_input(6);
			switch (potion) {
			case 1:
				if (player_inven->red_potion > 0) {
					if (healamount < 5) {
						printf("red_potion�� ����Ͽ����ϴ�.\nhp�� %dȸ���˴ϴ�.\n", healamount);
						player_stat->curhp = player_stat->maxhp;
						player_inven->red_potion -= 1;
						delay(2000);
						break;
					}
					else {
						printf("red_potion�� ����Ͽ����ϴ�.\nhp�� 5ȸ���˴ϴ�.\n");
						player_stat->curhp += 5;
						player_inven->red_potion -= 1;
						delay(2000);
						break;
					}
				}
				else {
					printf("������ �������� �����մϴ�.\n����â���� ���ư��ϴ�.\n");
					break;
				}
			case 2:
				if (player_inven->orange_potion > 0) {
					if (healamount < 20) {
						printf("orange_potion�� ����Ͽ����ϴ�.\nhp�� %dȸ���˴ϴ�.\n", healamount);
						player_stat->curhp = player_stat->maxhp;
						player_inven->orange_potion -= 1;
						delay(2000);
						break;
					}
					else {
						printf("orange_potion�� ����Ͽ����ϴ�.\nhp�� 20ȸ���˴ϴ�.\n");
						player_stat->curhp += 20;
						player_inven->orange_potion -= 1;
						delay(2000);
						break;
					}
				}
				else {
					printf("������ �������� �����մϴ�.\n����â���� ���ư��ϴ�.\n");
					break;
				}
			case 3:
				if (player_inven->white_potion > 0) {
					if (healamount < 50) {
						printf("white_potion�� ����Ͽ����ϴ�.\nhp�� %dȸ���˴ϴ�.\n", healamount);
						player_stat->curhp = player_stat->maxhp;
						player_inven->white_potion -= 1;
						delay(2000);
						break;
					}
					else {
						printf("white_potion�� ����Ͽ����ϴ�.\nhp�� 50ȸ���˴ϴ�.\n");
						player_stat->curhp += 50;
						player_inven->white_potion -= 1;
						delay(2000);
						break;
					}
				}
				else {
					printf("������ �������� �����մϴ�.\n����â���� ���ư��ϴ�.\n");
					break;
				}
			case 4:
				if (player_inven->full_potion > 0) {
					printf("full_potion�� ����Ͽ����ϴ�.\nhp�� mp�� ���� ȸ���˴ϴ�.\n");
					player_stat->curhp = player_stat->maxhp;
					player_inven->full_potion -= 1;
					delay(10000);
					break;
				}
				else {
					printf("������ �������� �����մϴ�.\n����â���� ���ư��ϴ�.\n");
					break;
				}
			case 5:
				if (player_inven->blue_potion > 0) {
					printf("blue_potion�� ����Ͽ����ϴ�.\nmp�� 5ȸ���˴ϴ�.\n");
					//player_stat->mp += 10;
					player_inven->blue_potion -= 1;
					delay(2000);
					break;
				}
				else {
					printf("������ �������� �����մϴ�.\n����â���� ���ư��ϴ�.\n");
					break;
				}
			case 6:
				printf("����â���� �ǵ��ư��ϴ�.\n");
				delay(2000);
				return;
			}
		}
	}
}
void potion_shop(struct char_inven* player_inven) {
	int potion, num;
	while (1) {
		system("cls");
		printf("���� ������:\n1.red_potion:%d\n2.orange.potion:%d\n3.white_potion:%d\n4.full_potion:%d\n5.blue_potion:%d\n6.�� �Ӽ� ��ȭ ���:%d\n7.���� �Ӽ� ��ȭ ���:%d\n8.���� �Ӽ� ��ȭ ���:%d\n", player_inven->red_potion, player_inven->orange_potion, player_inven->white_potion, player_inven->full_potion, player_inven->blue_potion, player_inven->reinforce_fireskill_vehicle,player_inven->reinforce_iceskill_vehicle, player_inven->reinforce_thunderskill_vehicle);
		printf("\n\n\n");
		printf("1.red_potion:ü���� 5 ȸ���մϴ�.								����:5g\n");
		printf("2.orange.potion:ü���� 20 ȸ���մϴ�.							����:10g\n");
		printf("3.white_potion:ü���� 50 ȸ���մϴ�.							����:20g\n");
		printf("4.full_potion:hp��mp�� ���� ȸ���մϴ�.						    ����:50g\n");
		printf("5.blue_potion:mp�� 10 ȸ���մϴ�.							    ����:10g\n");
		printf("6.�� �Ӽ� ��ȭ ���:�� �Ӽ� ��ȭ�� ���˴ϴ�.                  ����:100g\n");
		printf("7.���� �Ӽ� ��ȭ ���:���� �Ӽ� ��ȭ�� ���˴ϴ�.			    ����:100g\n");
		printf("8.���� �Ӽ� ��ȭ ���:���� �Ӽ� ��ȭ�� ���˴ϴ�.			    ����:100g\n");
		printf("9.����â���� �����մϴ�.\n	���� ���� ���:%d\n", player_inven->gold );
		
		printf("� ������ �����Ͻðڽ��ϱ�?:");
		potion = key_input(9);
		switch (potion) {
		case 1:
			printf("red_potion ��� �����Ͻðڽ��ϱ�?:");
			scanf_s("%d", &num);
			if (player_inven->gold >= 5 * num) {
				printf("red_potion %d���� ���� �Ϸ� �Ǿ����ϴ�\n", num);
				printf("����� �������� �̵��մϴ�");
				printf("\n");
				player_inven->red_potion = player_inven->red_potion + num;
				player_inven->gold = player_inven->gold - 5 * num;
				delay(2000);
				continue;
			}
			else {
				printf("��尡 �����մϴ�\n");
				printf("�������� �ǵ��ư��ϴ�..\n");
				delay(2000);
				continue;
			}
		case 2:
			printf("orange_potion ��� �����Ͻðڽ��ϱ�?:");
			scanf_s("%d", &num);
			if (player_inven->gold >= 10 * num) {
				printf("orange_potion %d���� ���� �Ϸ� �Ǿ����ϴ�\n", num);
				printf("�������� �ǵ��ư��ϴ�..\n");
				printf("\n");
				player_inven->orange_potion = player_inven->orange_potion + num;
				player_inven->gold = player_inven->gold - 10 * num;
				delay(2000);
				continue;
			}
			else {
				printf("��尡 �����մϴ�\n");
				printf("�������� �ǵ��ư��ϴ�..\n");
				delay(2000);
				continue;
			}
		case 3:
			printf("white_potion ��� �����Ͻðڽ��ϱ�?:");
			scanf_s("%d", &num);
			if (player_inven->gold >= 20 * num) {
				printf("white_potion %d���� ���� �Ϸ� �Ǿ����ϴ�\n", num);
				printf("�������� �ǵ��ư��ϴ�..\n");
				printf("\n");
				player_inven->white_potion = player_inven->white_potion + num;
				player_inven->gold = player_inven->gold - 20 * num;
				delay(2000);
				continue;
			}
			else {
				printf("��尡 �����մϴ�\n");
				printf("�������� �ǵ��ư��ϴ�..\n");
				delay(2000);
				continue;
			}
		case 4:
			printf("full_potion ��� �����Ͻðڽ��ϱ�?:");
			scanf_s("%d", &num);
			if (player_inven->gold >= 50 * num) {
				printf("full_potion %d���� ���� �Ϸ� �Ǿ����ϴ�\n", num);
				printf("�������� �ǵ��ư��ϴ�..\n");
				printf("\n");
				player_inven->full_potion = player_inven->full_potion + num;
				player_inven->gold = player_inven->gold - 50 * num;
				delay(2000);
				continue;
			}
			else {
				printf("��尡 �����մϴ�\n");
				printf("�������� �ǵ��ư��ϴ�..\n");
				delay(2000);
				continue;
			}
		case 5:
			printf("blue_potion ��� �����Ͻðڽ��ϱ�?:");
			scanf_s("%d", &num);
			if (player_inven->gold >= 10 * num) {
				printf("blue_potion %d���� ���� �Ϸ� �Ǿ����ϴ�\n", num);
				printf("�������� �ǵ��ư��ϴ�..\n");
				printf("\n");
				player_inven->blue_potion = player_inven->blue_potion + num;
				player_inven->gold = player_inven->gold - 10 * num;
				delay(2000);
				continue;
			}
			else {
				printf("��尡 �����մϴ�\n");
				printf("�������� �ǵ��ư��ϴ�..\n");
				delay(2000);
				continue;
			}
		case 6:
			printf("�ҼӼ� ��ȭ ��� ��� �����Ͻðڽ��ϱ�?:");
			scanf_s("%d", &num);
			if (player_inven->gold >= 100 * num) {
				printf("�ҼӼ� ��ȭ ��� %d���� ���� �Ϸ� �Ǿ����ϴ�\n", num);
				printf("�������� �ǵ��ư��ϴ�..\n");
				printf("\n");
				player_inven->reinforce_fireskill_vehicle = player_inven->reinforce_fireskill_vehicle + num;
				player_inven->gold = player_inven->gold - 100 * num;
				delay(2000);
				continue;
			}
			else {
				printf("��尡 �����մϴ�\n");
				printf("�������� �ǵ��ư��ϴ�..\n");
				delay(2000);
				continue;
		case 7:
			printf("����Ӽ� ��ȭ ��� ��� �����Ͻðڽ��ϱ�?:");
			scanf_s("%d", &num);
			if (player_inven->gold >= 100 * num) {
				printf("����Ӽ� ��ȭ ��� %d���� ���� �Ϸ� �Ǿ����ϴ�\n", num);
				printf("�������� �ǵ��ư��ϴ�..\n");
				printf("\n");
				player_inven->reinforce_iceskill_vehicle = player_inven->reinforce_iceskill_vehicle + num;
				player_inven->gold = player_inven->gold - 100 * num;
				delay(2000);
				continue;
			}
			else {
				printf("��尡 �����մϴ�\n");
				printf("�������� �ǵ��ư��ϴ�..\n");
				delay(2000);
				continue;
		case 8:
			printf("�����Ӽ� ��ȭ ��� ��� �����Ͻðڽ��ϱ�?:");
			scanf_s("%d", &num);
			if (player_inven->gold >= 100 * num) {
				printf("�����Ӽ� ��ȭ ��� %d���� ���� �Ϸ� �Ǿ����ϴ�\n", num);
				printf("�������� �ǵ��ư��ϴ�..\n");
				printf("\n");
				player_inven->reinforce_thunderskill_vehicle = player_inven->reinforce_thunderskill_vehicle + num;
				player_inven->gold = player_inven->gold - 100 * num;
				delay(2000);
				continue;
			}
			else {
				printf("��尡 �����մϴ�\n");
				printf("�������� �ǵ��ư��ϴ�..\n");
				delay(2000);
				continue;
			}
			}
			}
		case 9:
			printf("����â���� �ǵ��ư��ϴ�.\n");
			delay(2000);
			return;
		}


	}
}
// �������
void shop(struct char_inven* player_inven, struct equipment_effect* equipments[], struct equipment_element* equipment_element[], struct weapon_element* element) {
	int situlation;
	while (1) {
		system("cls");
		printf("1.��ȭ\n2.���Ǳ���\n3.����");
		printf("����:");
		situlation = key_input(3);
		switch (situlation) {
		case 1:
			reinforce(player_inven, equipments, equipment_element, element);
			return;
		case 2:
			potion_shop(player_inven);
			return;
		case 3:
			printf("������ ���ư��ϴ�.");
			return;
		}
	}
}
