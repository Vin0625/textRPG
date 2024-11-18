#pragma once
typedef struct {
	int atk;
	int def;
	int curhp;
	int drop_exp;
	int drop_gold;
	int turn;
	void (*pattern) (Monster);
}Monster;