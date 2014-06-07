/**
*
*	The player
*
**/

#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"

class Player : public Character
{
	char wantedDirection;
public:
	Player(void);
	~Player(void);
	void SetDirection(char keyPressed);
	/*void ChangeLocation(int new_x, int new_y);
	int GetX();
	int GetY();
	char GetID();*/

	char Move(std::vector<std::vector<Square>> board, int width, int height);
};

#endif