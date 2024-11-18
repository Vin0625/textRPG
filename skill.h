#pragma once

struct skillinfo {
	int skilldmg;
};
int skill_dmg_calculate(int skilldmg);
int use_skill(struct weapon_element* element, struct skillinfo* skill[]);