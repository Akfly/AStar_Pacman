/*
*	4
*	Always same speed
*	Usually moves clockwise
*	Is scared of the player :(
*
*/
#ifndef ORANGEGHOST_H
#define ORANGEGHOST_H

#include "Ghost.h"

class OrangeGhost : public Ghost
{
public:
	OrangeGhost(void);
	~OrangeGhost(void);
	/*void ChangeLocation(int new_x, int new_y);
	int GetX();
	int GetY();
	char GetID();*/
	char FirstPractice(std::vector<std::vector<Square>> board, int width, int height);
	char SecondPractice(std::vector<std::vector<Square>> board, int width, int height);
};

#endif
