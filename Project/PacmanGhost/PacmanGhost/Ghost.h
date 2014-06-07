/*
*
*	The enemy!! O.o
*
*/
#ifndef GHOST_H
#define GHOST_H

#include "Character.h"

class Ghost : public Character
{
protected:
	Square playerPos;
	std::vector<std::vector<Square>> pathBoard;
	bool bSeeded;
	bool bPathCalculated;

public:
	Ghost(void)
	{
		bSeeded = false;
		bPathCalculated = false;
	}

	~Ghost(void){}

protected:
	char GoUp(std::vector<std::vector<Square>> board);
	char GoDown(std::vector<std::vector<Square>> board);
	char GoLeft(std::vector<std::vector<Square>> board);
	char GoRight(std::vector<std::vector<Square>> board);
	void PreFind(std::vector<std::vector<Square>> board, int width, int height);

	void CalculatePathFinding()		//Calculates the pathfinding
	{
		InvestigateSquare(x, y, 0);
	}
	void SetBoard(std::vector<std::vector<Square>> _board)
	{ pathBoard = _board;}

	char returnNextDirection();

	int GetHeuristic(int _x, int _y)		//returns the distance between my point and the goal.
	{
		return	int(	fabs( float(_x - playerPos.GetX()) )	+
						fabs( float(_y - playerPos.GetY()) )	);
	}

	int GetGhostMoves(int _x, int _y)
	{
		return		int(	fabs( float(_x - x) )		+
							fabs( float(_y - y) )		);
	}
	void setWeight(int _x, int _y)
	{
		pathBoard[_x][_y].AStarWeight = GetHeuristic(_x, _y) + GetGhostMoves(_x, _y);
	}

	void InvestigateSquare(int _x, int _y, int count);
};

#endif
