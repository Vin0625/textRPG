#include <stdio.h>
#include "player.h"
#include "loginfinsh (1).h"

void story_opening(struct char_stat* player) {
	system("cls");
	printf("���� ������ ��������.\n");
	printf("���������� ���� �ı� ���ؼ���\n");
	printf("������ �̷ε��� ����ϸ�\n");
	printf("�װ��� ��޴� �Ƿɵ�� �ο����Ѵ�.\n");
	player->map++;
	delay(10000);
	system("cls");

}

void story_ending(struct char_stat* player) {
	system("cls");
	printf("������ ���� �����ߴ�.\n");
	printf("������ ���������� ���� ���� ������ ����.\n");
	printf("���� ������ �ľ�� ����\n");
	printf("���� ���� �̷η� ���Ѵ�.\n");

	delay(10000);
	system("cls");

}