/*
*
*	A character ingame, player or enemy
*
*/
#ifndef CHARACTER_H
#define CHARACTER_H

#include "Square.h"
#include <vector>

class Character
{
protected:
	int x;
	int y;
	bool bAlive;
	char id;

public:
	Character(void)
	{
		bAlive=true;
	}
	~Character(void)
	{}
	int GetX(){return x;}
	int GetY(){return y;}
	void ChangeLocation(int new_x, int new_y)
	{
		this->x=new_x;
		this->y=new_y;
	}

	void Kill(){bAlive=false;}
	bool IsAlive(){return bAlive;}
	char GetID(){return id;}
	virtual char Move(std::vector<std::vector<Square>> board, int width, int height){return '0';};
	virtual char FirstPractice(std::vector<std::vector<Square>> board, int width, int height){return '0';};
	virtual char SecondPractice(std::vector<std::vector<Square>> board, int width, int height){return '0';};
};

#endif

