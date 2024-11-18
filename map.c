#define _CRT_SECURE_NO_WARNINGS
#define LENGTH 20
#define TRUE 1
#define FALSE 0

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77

#define RED 4 
#define YELLOW 14
#define GREEN 10
#define WHITE 15

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "battle.h"
#include"potion.h"
#include "monster.h"
#include "player.h"
#include "reinforce.h"
#include "monsterfunc.h"


typedef struct _Room
{
	short visit;
}Room;

typedef struct _Map
{
	short empty;
	short visit;
}Map;

typedef struct _Path
{
	int x;
	int y;
}Path;

Room room[LENGTH][LENGTH];
Map bgrd[2 * LENGTH + 1][2 * LENGTH + 1] ;
Path path[LENGTH * LENGTH] ;

void call_random_monster(struct char_stat* player, Monster* monster1, Monster* monster2, Monster* monster3, Monster* monster4, Monster* monster5, struct char_inven *player_inven,struct weapon_element* element, struct skillinfo* skill[]) {
	srand((unsigned)clock(NULL));
	switch (rand() % 5) {
	case 0:
		battle_page(player,monster1,player_inven, element, skill);
		break;
	case 1:
		battle_page(player, monster1, player_inven, element, skill);
		break;
	case 2:
		battle_page(player, monster1, player_inven, element, skill);
		break;
	case 3:
		battle_page(player, monster1, player_inven, element, skill);
		break;
	case 4:
		battle_page(player, monster1, player_inven, element, skill);
		break;
	}
}

void FontColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}



void Visit_Room(int x, int y)
{
	room[y][x].visit = TRUE;
}

void Make_Map()
{
	for (int i = 0; i < LENGTH; i++)
	{
		for (int j = 0; j < LENGTH; j++)
		{
			bgrd[2 * i + 1][2 * j + 1].empty = TRUE;
		}
	}
	int path_count = 0;

	srand((long)time(NULL));

	int current_x = rand() % LENGTH;
	int current_y = rand() % LENGTH;
	int previous_x;
	int previous_y;

	Visit_Room(current_x, current_y);
	path[path_count].x = current_x;
	path[path_count].y = current_y;
	path_count++;

	// 반복
	// 방 랜덤 선택

	while (path_count != 0)
	{
		short available_room = 0;
		int i = 0;
		Path rand_room_list[4] = { {0,0}, };
		previous_x = current_x, previous_y = current_y;

		if (current_x > 0 && room[current_y][current_x - 1].visit == FALSE) //왼쪽 검사
		{
			rand_room_list[i].x = current_x - 1, rand_room_list[i].y = current_y;
			available_room++;
			i++;
		}
		if (current_x < LENGTH - 1 && room[current_y][current_x + 1].visit == FALSE) //오른쪽 검사
		{
			rand_room_list[i].x = current_x + 1, rand_room_list[i].y = current_y;
			available_room++;
			i++;
		}
		if (current_y > 0 && room[current_y - 1][current_x].visit == FALSE) //위쪽 검사
		{
			rand_room_list[i].x = current_x, rand_room_list[i].y = current_y - 1;
			available_room++;
			i++;
		}
		if (current_y < LENGTH - 1 && room[current_y + 1][current_x].visit == FALSE) //아래쪽 검사
		{
			rand_room_list[i].x = current_x, rand_room_list[i].y = current_y + 1;
			available_room++;
			i++;
		}

		if (available_room != 0)
		{
			short rand_num = rand() % available_room;
			current_x = rand_room_list[rand_num].x, current_y = rand_room_list[rand_num].y;

			Visit_Room(current_x, current_y);
			path[path_count].x = current_x;
			path[path_count].y = current_y;
			path_count++;

			int move_x = current_x - previous_x, move_y = current_y - previous_y;

			if (move_x == 0)
			{
				bgrd[2 * previous_y + 1 + move_y][2 * previous_x + 1].empty = TRUE;
			}
			else
			{
				bgrd[2 * previous_y + 1][2 * previous_x + 1 + move_x].empty = TRUE;
			}
		}
		else
		{
			path[path_count].x = 0;
			path[path_count].y = 0;
			path_count--;
			current_x = path[path_count].x, current_y = path[path_count].y;
		}
	}
}
void RemoveCursor() //커서깜빡이 제거
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

}

int getKeyDown()
{
	if (_kbhit())
	{
		return _getch();
	}
	else return -1;
}
void Display(int player_x, int player_y, int goal_x, int goal_y, int center_x, int center_y)
{
	gotoxy(0, 0);
	int count = 0;
	for (int m = 0; m < 2 * LENGTH + 1; m++)
	{
		for (int n = 0; n < 2 * LENGTH + 1; n++)
		{
			if (bgrd[m][n].empty == TRUE)
			{
				if (m == player_y && n == player_x)
				{
					FontColor(GREEN);
					printf("＠");
					FontColor(WHITE);
				}
				else if (m == goal_y && n == goal_x)
				{
					FontColor(YELLOW);
					printf("※");
					FontColor(WHITE);
				}
				else if (bgrd[m][n].visit == TRUE)
				{
					printf("·");
				}
				else if (m == center_x && n == center_y)
				{
					if (count == 0) {
						printf(" +");
						count++;
					}
					else
						printf("  ");
				}
				else if (m == center_x && n == center_y + 1)
				{
					if (count == 0) {
						printf(" +");
						count++;
					}
					else
						printf("  ");
				}
				else if (m == center_x + 1 && n == center_y)
				{
					if (count == 0) {
						printf(" +");
						count++;
					}
					else
						printf("  ");
				}
				else if (m == center_x + 1 && n == center_y + 1)
				{
					if (count == 0) {
						printf(" +");
						count++;
					}
					else
						printf("  ");
				}
				else
				{
					printf("  ");
				}
			}
			else
			{
				printf("■");
			}
		}
		printf("\n");
	}
}

void Player(struct char_stat* player, Monster* monster1, Monster* monster2, Monster* monster3, Monster* monster4, Monster* monster5, struct char_inven* player_inven, struct equipment_effect* equipments[], struct equipment_element* equipment_element[], struct weapon_element* element, struct skillinfo* skill[])
{
	int player_x = 1, player_y = 1;
	int goal_x = 2 * LENGTH - 1, goal_y = 2 * LENGTH - 1;
	int center_x = LENGTH, center_y = LENGTH;
	bgrd[player_y][player_x].visit = TRUE;
	Display(player_x, player_y, goal_x, goal_y, center_x, center_y);
	srand(time(NULL));
	int count = 0;
	int monster_x[50] = { NULL };
	int monster_y[50] = { NULL };
	for (int i = 0; i < 50; i++)
	{
		monster_x[i] = rand() % 78;
		monster_y[i] = rand() % 40;
	}
	while (player_x != goal_x || player_y != goal_y)
	{
		for (int i = 0; i < 50; i++)
		{
			if (monster_x[i] == player_x && monster_y[i] == player_y)
			{
				system("cls");
				call_random_monster(player, monster1, monster2, monster3, monster4, monster5, player_inven, element, skill );
				monster_implement(monster1, monster2, monster3, monster4, monster5);
				Display(player_x, player_y, goal_x, goal_y, center_x, center_y);
				monster_x[i] = 0;
				monster_y[i] = 0;
				break;
			}
		}

		if (death_check() == 1)
			break;
		
			if ((player_x == center_x && player_y == center_y) || (player_x == center_x + 1 && player_y == center_y) || (player_x == center_x + 1 && player_y == center_y + 1) || (player_x == center_x && player_y == center_y + 1))
			{
				shop(player_inven, equipments, equipment_element, element);
				center_x = 0;
				center_y = 0;
				Display(player_x, player_y, goal_x, goal_y, center_x, center_y);
			}
		
		
		int key = getKeyDown();
		if (key == UP)
		{
			if (bgrd[player_y - 1][player_x].empty == TRUE)
			{
				player_y--;
				bgrd[player_y][player_x].visit = TRUE;
				Display(player_x, player_y, goal_x, goal_y, center_x, center_y);
			}
		}
		else if (key == DOWN)
		{
			if (bgrd[player_y + 1][player_x].empty == TRUE)
			{
				player_y++;
				bgrd[player_y][player_x].visit = TRUE;
				Display(player_x, player_y, goal_x, goal_y, center_x, center_y);
			}
		}
		else if (key == LEFT)
		{
			if (bgrd[player_y][player_x - 1].empty == TRUE)
			{
				player_x--;
				bgrd[player_y][player_x].visit = TRUE;
				Display(player_x, player_y, goal_x, goal_y, center_x, center_y);
			}
		}
		else if (key == RIGHT)
		{
			if (bgrd[player_y][player_x + 1].empty == TRUE)
			{
				player_x++;
				bgrd[player_y][player_x].visit = TRUE;
				Display(player_x, player_y, goal_x, goal_y, center_x, center_y);
			}
		}
	}
	system("cls");
	return;
}

int mapstart(struct char_stat* player, struct char_inven* player_inven, struct equipment_effect* equipments[], struct equipment_element* equipment_element[], struct weapon_element* element, struct skillinfo* skill[])
{

	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < LENGTH; j++) {
			room[i][j].visit= FALSE;
		}
	}
	for (int i = 0; i < 2 * LENGTH + 1; i++) {
		for (int j = 0; j < 2 * LENGTH + 1; j++) {
			bgrd[i][j].empty = FALSE;
			bgrd[i][j].visit = FALSE;
		}
	}
	for (int i = 0; i < LENGTH * LENGTH; i++) {
		path[i].x = 0;
		path[i].y = 0;
	}

	

	Monster monster1, monster2, monster3, monster4, monster5;
	monster_implement(&monster1, &monster2, &monster3, &monster4, &monster5);

	system("mode con cols=82lines=42 | title 미로찾기");
	RemoveCursor();
	Make_Map();
	Player(player, &monster1, &monster2, &monster3, &monster4, &monster5, player_inven, equipments,equipment_element, element, skill);
	player->map++;
	printf("공격력:%d\n방어력:%d\n보유골드:%d\n레벨:%d\n경험치:%d\n", player->atk, player->def, player_inven->gold, player->level, player->exp);
	delay(3000);
	return 0;
}
