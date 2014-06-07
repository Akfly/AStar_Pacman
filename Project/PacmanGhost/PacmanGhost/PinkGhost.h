/*
*	2
*	Always same speed
*	Usually moves counter-clockwise
*	Likes going around blocks :3
*
*/
#ifndef PINKGHOST_H
#define PINKGHOST_H

#include "Ghost.h"

class PinkGhost : public Ghost
{
public:
	PinkGhost(void);
	~PinkGhost(void);
	/*void ChangeLocation(int new_x, int new_y);
	int GetX();
	int GetY();
	char GetID();*/
	char FirstPractice(std::vector<std::vector<Square>> board, int width, int height);
	char SecondPractice(std::vector<std::vector<Square>> board, int width, int height);
protected:
	char GoUp(std::vector<std::vector<Square>> board);
	char GoDown(std::vector<std::vector<Square>> board);
	char GoLeft(std::vector<std::vector<Square>> board);
	char GoRight(std::vector<std::vector<Square>> board);
};

#endif

