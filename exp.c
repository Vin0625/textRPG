#include<stdio.h>
#include<windows.h>
#include"player.h"

enum ColorType {
	BLACK,  	//0
	darkBLUE,	//1
	DarkGreen,	//2
	darkSkyBlue,    //3
	DarkRed,  	//4
	DarkPurple,	//5
	DarkYellow,	//6
	GRAY,		//7
	DarkGray,	//8
	BLUE,		//9
	GREEN,		//10
	SkyBlue,	//11
	RED,		//12
	PURPLE,		//13
	YELLOW,		//14
	WHITE		//15
} COLOR;
void changing_level(int get_exp, struct char_stat player)
{
	int max_exp[11] = { 0,10,20,30,50,70,90,120,150,180,220 };
	while (1)
	{
		if (get_exp >= max_exp[player.level])
		{
			player.level++;
			get_exp -= max_exp[player.level];
		}
		else
		{
			get_exp = player.exp;
			break;
		}
	}
}
void exp_bar(int get_exp, struct char_stat player)
{
	int max_exp[11] = { 0,10,20,30,50,70,90,120,150,180,220 };
	float room_exp = (float)get_exp / max_exp[player.level] * 10;
	for (int i = 0; i <= room_exp; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), GREEN);
		printf("¦¡");
	}
	for (room_exp; room_exp <= 10; room_exp++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
		printf("¦¡");
	}
}