#include <stdio.h>
#include "player.h"
#include "loginfinsh (1).h"

void story_opening(struct char_stat* player) {
	system("cls");
	printf("나는 지옥에 떨어졌다.\n");
	printf("내세에서의 업을 씻기 위해서는\n");
	printf("지옥의 미로들을 통과하며\n");
	printf("그곳을 헤메는 악령들과 싸워야한다.\n");
	player->map++;
	delay(10000);
	system("cls");

}

void story_ending(struct char_stat* player) {
	system("cls");
	printf("지옥의 끝에 도달했다.\n");
	printf("하지만 지옥에서의 끝은 다음 굴레의 시작.\n");
	printf("업을 완전히 씻어내기 위해\n");
	printf("나는 다음 미로로 향한다.\n");

	delay(10000);
	system("cls");

}