/*
*	3
*	Always same speed
*	Likes to follow red ^^
*
*/

#ifndef BLUEGHOST_H
#define BLUEGHOST_H

#include "Ghost.h"

class BlueGhost : public Ghost
{
protected:
	Square redPos;

public:
	BlueGhost(void);
	~BlueGhost(void);

	char FirstPractice(std::vector<std::vector<Square>> board, int width, int height);
	char SecondPractice(std::vector<std::vector<Square>> board, int width, int height);

protected:
	void InvestigateSquare(int _x, int _y, int count);
};
#endif

