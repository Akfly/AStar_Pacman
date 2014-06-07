/*
*	1
*	Increases speed by the time. o.O
*	Usually moves clockwise
*
*/
#ifndef REDGHOST_H
#define REDGHOST_H

#include "Ghost.h"
#include "AStar.h"

class RedGhost : public Ghost
{

public:

	RedGhost(void);
	~RedGhost(void);
	char FirstPractice(std::vector<std::vector<Square>> board, int width, int height);
	char SecondPractice(std::vector<std::vector<Square>> board, int width, int height);

protected:
	char returnNextDirection();
};

#endif
