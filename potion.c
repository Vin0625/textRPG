#include <stdio.h>
#include "player.h"
#include "reinforce.h"


void use_potion(struct char_inven* player_inven, struct char_stat* player_stat) {
	int healamount;
	healamount = player_stat->maxhp - player_stat->curhp;
	if (healamount == 0) {
		printf("현재 hp량이상으로 회복할 수 없습니다..\n");
		printf("선택창으로 이동합니다\n");
		delay(2000);
		return;
	}

	if (player_inven->red_potion == 0 && player_inven->orange_potion == 0 && player_inven->white_potion == 0 && player_inven->full_potion == 0 && player_inven->blue_potion == 0) {
		printf("사용가능한 아이템이 없습니다.\n");
		printf("선택창으로 되돌아갑니다..\n");
		delay(2000);
		return;
	}
	else {
		while (1) {
			printf("현재 hp수치:%d\n", player_stat->curhp);
			printf("현재 보유량:\n");
			printf("1.red_potion : %d", player_inven->red_potion);
			printf("									hp을 5 회복합니다.");
			printf("\n");
			printf("2.orange_potion : %d", player_inven->orange_potion);
			printf("									hp을 20 회복합니다.");
			printf("\n");
			printf("3.white_potion : %d", player_inven->white_potion);
			printf("									hp을 50 회복합니다.");
			printf("\n");
			printf("4.full_potion : %d", player_inven->full_potion);
			printf("									hp와 mp를 모두 회복합니다.");
			printf("\n");
			printf("5.blue_potion : %d", player_inven->blue_potion);
			printf("									mp을 10 회복합니다.");
			printf("\n");
			printf("6.선택창으로 이동");
			printf("\n");
			printf("어떤 포션을 사용하시겠습니까?");
			int potion = key_input(6);
			switch (potion) {
			case 1:
				if (player_inven->red_potion > 0) {
					if (healamount < 5) {
						printf("red_potion을 사용하였습니다.\nhp가 %d회복됩니다.\n", healamount);
						player_stat->curhp = player_stat->maxhp;
						player_inven->red_potion -= 1;
						delay(2000);
						break;
					}
					else {
						printf("red_potion을 사용하였습니다.\nhp가 5회복됩니다.\n");
						player_stat->curhp += 5;
						player_inven->red_potion -= 1;
						delay(2000);
						break;
					}
				}
				else {
					printf("포션의 보유량이 부족합니다.\n선택창으로 돌아갑니다.\n");
					break;
				}
			case 2:
				if (player_inven->orange_potion > 0) {
					if (healamount < 20) {
						printf("orange_potion을 사용하였습니다.\nhp가 %d회복됩니다.\n", healamount);
						player_stat->curhp = player_stat->maxhp;
						player_inven->orange_potion -= 1;
						delay(2000);
						break;
					}
					else {
						printf("orange_potion을 사용하였습니다.\nhp가 20회복됩니다.\n");
						player_stat->curhp += 20;
						player_inven->orange_potion -= 1;
						delay(2000);
						break;
					}
				}
				else {
					printf("포션의 보유량이 부족합니다.\n선택창으로 돌아갑니다.\n");
					break;
				}
			case 3:
				if (player_inven->white_potion > 0) {
					if (healamount < 50) {
						printf("white_potion을 사용하였습니다.\nhp가 %d회복됩니다.\n", healamount);
						player_stat->curhp = player_stat->maxhp;
						player_inven->white_potion -= 1;
						delay(2000);
						break;
					}
					else {
						printf("white_potion을 사용하였습니다.\nhp가 50회복됩니다.\n");
						player_stat->curhp += 50;
						player_inven->white_potion -= 1;
						delay(2000);
						break;
					}
				}
				else {
					printf("포션의 보유량이 부족합니다.\n선택창으로 돌아갑니다.\n");
					break;
				}
			case 4:
				if (player_inven->full_potion > 0) {
					printf("full_potion을 사용하였습니다.\nhp와 mp가 전부 회복됩니다.\n");
					player_stat->curhp = player_stat->maxhp;
					player_inven->full_potion -= 1;
					delay(10000);
					break;
				}
				else {
					printf("포션의 보유량이 부족합니다.\n선택창으로 돌아갑니다.\n");
					break;
				}
			case 5:
				if (player_inven->blue_potion > 0) {
					printf("blue_potion을 사용하였습니다.\nmp가 5회복됩니다.\n");
					//player_stat->mp += 10;
					player_inven->blue_potion -= 1;
					delay(2000);
					break;
				}
				else {
					printf("포션의 보유량이 부족합니다.\n선택창으로 돌아갑니다.\n");
					break;
				}
			case 6:
				printf("선택창으로 되돌아갑니다.\n");
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
		printf("현재 보유량:\n1.red_potion:%d\n2.orange.potion:%d\n3.white_potion:%d\n4.full_potion:%d\n5.blue_potion:%d\n6.불 속성 강화 재료:%d\n7.빙결 속성 강화 재료:%d\n8.번개 속성 강화 재료:%d\n", player_inven->red_potion, player_inven->orange_potion, player_inven->white_potion, player_inven->full_potion, player_inven->blue_potion, player_inven->reinforce_fireskill_vehicle,player_inven->reinforce_iceskill_vehicle, player_inven->reinforce_thunderskill_vehicle);
		printf("\n\n\n");
		printf("1.red_potion:체력을 5 회복합니다.								가격:5g\n");
		printf("2.orange.potion:체력을 20 회복합니다.							가격:10g\n");
		printf("3.white_potion:체력을 50 회복합니다.							가격:20g\n");
		printf("4.full_potion:hp와mp을 전부 회복합니다.						    가격:50g\n");
		printf("5.blue_potion:mp을 10 회복합니다.							    가격:10g\n");
		printf("6.불 속성 강화 재료:불 속성 강화에 사용됩니다.                  가격:100g\n");
		printf("7.빙결 속성 강화 재료:빙결 속성 강화에 사용됩니다.			    가격:100g\n");
		printf("8.번개 속성 강화 재료:번개 속성 강화에 사용됩니다.			    가격:100g\n");
		printf("9.선택창으로 복귀합니다.\n	현재 보유 골드:%d\n", player_inven->gold );
		
		printf("어떤 포션을 구매하시겠습니까?:");
		potion = key_input(9);
		switch (potion) {
		case 1:
			printf("red_potion 몇개를 구입하시겠습니까?:");
			scanf_s("%d", &num);
			if (player_inven->gold >= 5 * num) {
				printf("red_potion %d개가 구매 완료 되었습니다\n", num);
				printf("잠시후 상점으로 이동합니다");
				printf("\n");
				player_inven->red_potion = player_inven->red_potion + num;
				player_inven->gold = player_inven->gold - 5 * num;
				delay(2000);
				continue;
			}
			else {
				printf("골드가 부족합니다\n");
				printf("상점으로 되돌아갑니다..\n");
				delay(2000);
				continue;
			}
		case 2:
			printf("orange_potion 몇개를 구입하시겠습니까?:");
			scanf_s("%d", &num);
			if (player_inven->gold >= 10 * num) {
				printf("orange_potion %d개가 구매 완료 되었습니다\n", num);
				printf("상점으로 되돌아갑니다..\n");
				printf("\n");
				player_inven->orange_potion = player_inven->orange_potion + num;
				player_inven->gold = player_inven->gold - 10 * num;
				delay(2000);
				continue;
			}
			else {
				printf("골드가 부족합니다\n");
				printf("상점으로 되돌아갑니다..\n");
				delay(2000);
				continue;
			}
		case 3:
			printf("white_potion 몇개를 구입하시겠습니까?:");
			scanf_s("%d", &num);
			if (player_inven->gold >= 20 * num) {
				printf("white_potion %d개가 구매 완료 되었습니다\n", num);
				printf("상점으로 되돌아갑니다..\n");
				printf("\n");
				player_inven->white_potion = player_inven->white_potion + num;
				player_inven->gold = player_inven->gold - 20 * num;
				delay(2000);
				continue;
			}
			else {
				printf("골드가 부족합니다\n");
				printf("상점으로 되돌아갑니다..\n");
				delay(2000);
				continue;
			}
		case 4:
			printf("full_potion 몇개를 구입하시겠습니까?:");
			scanf_s("%d", &num);
			if (player_inven->gold >= 50 * num) {
				printf("full_potion %d개가 구매 완료 되었습니다\n", num);
				printf("상점으로 되돌아갑니다..\n");
				printf("\n");
				player_inven->full_potion = player_inven->full_potion + num;
				player_inven->gold = player_inven->gold - 50 * num;
				delay(2000);
				continue;
			}
			else {
				printf("골드가 부족합니다\n");
				printf("상점으로 되돌아갑니다..\n");
				delay(2000);
				continue;
			}
		case 5:
			printf("blue_potion 몇개를 구입하시겠습니까?:");
			scanf_s("%d", &num);
			if (player_inven->gold >= 10 * num) {
				printf("blue_potion %d개가 구매 완료 되었습니다\n", num);
				printf("상점으로 되돌아갑니다..\n");
				printf("\n");
				player_inven->blue_potion = player_inven->blue_potion + num;
				player_inven->gold = player_inven->gold - 10 * num;
				delay(2000);
				continue;
			}
			else {
				printf("골드가 부족합니다\n");
				printf("상점으로 되돌아갑니다..\n");
				delay(2000);
				continue;
			}
		case 6:
			printf("불속성 강화 재료 몇개를 구입하시겠습니까?:");
			scanf_s("%d", &num);
			if (player_inven->gold >= 100 * num) {
				printf("불속성 강화 재료 %d개가 구매 완료 되었습니다\n", num);
				printf("상점으로 되돌아갑니다..\n");
				printf("\n");
				player_inven->reinforce_fireskill_vehicle = player_inven->reinforce_fireskill_vehicle + num;
				player_inven->gold = player_inven->gold - 100 * num;
				delay(2000);
				continue;
			}
			else {
				printf("골드가 부족합니다\n");
				printf("상점으로 되돌아갑니다..\n");
				delay(2000);
				continue;
		case 7:
			printf("빙결속성 강화 재료 몇개를 구입하시겠습니까?:");
			scanf_s("%d", &num);
			if (player_inven->gold >= 100 * num) {
				printf("빙결속성 강화 재료 %d개가 구매 완료 되었습니다\n", num);
				printf("상점으로 되돌아갑니다..\n");
				printf("\n");
				player_inven->reinforce_iceskill_vehicle = player_inven->reinforce_iceskill_vehicle + num;
				player_inven->gold = player_inven->gold - 100 * num;
				delay(2000);
				continue;
			}
			else {
				printf("골드가 부족합니다\n");
				printf("상점으로 되돌아갑니다..\n");
				delay(2000);
				continue;
		case 8:
			printf("번개속성 강화 재료 몇개를 구입하시겠습니까?:");
			scanf_s("%d", &num);
			if (player_inven->gold >= 100 * num) {
				printf("번개속성 강화 재료 %d개가 구매 완료 되었습니다\n", num);
				printf("상점으로 되돌아갑니다..\n");
				printf("\n");
				player_inven->reinforce_thunderskill_vehicle = player_inven->reinforce_thunderskill_vehicle + num;
				player_inven->gold = player_inven->gold - 100 * num;
				delay(2000);
				continue;
			}
			else {
				printf("골드가 부족합니다\n");
				printf("상점으로 되돌아갑니다..\n");
				delay(2000);
				continue;
			}
			}
			}
		case 9:
			printf("선택창으로 되돌아갑니다.\n");
			delay(2000);
			return;
		}


	}
}
// 상점기능
void shop(struct char_inven* player_inven, struct equipment_effect* equipments[], struct equipment_element* equipment_element[], struct weapon_element* element) {
	int situlation;
	while (1) {
		system("cls");
		printf("1.강화\n2.포션구매\n3.복귀");
		printf("선택:");
		situlation = key_input(3);
		switch (situlation) {
		case 1:
			reinforce(player_inven, equipments, equipment_element, element);
			return;
		case 2:
			potion_shop(player_inven);
			return;
		case 3:
			printf("맵으로 돌아갑니다.");
			return;
		}
	}
}
