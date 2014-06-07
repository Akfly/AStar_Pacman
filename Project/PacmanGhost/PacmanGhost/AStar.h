/*
*
*	A class to implement the ghost pathfinding
*	using the A* method (^u^)
*
*/
#ifndef ASTAR_H
#define ASTAR_H

#include "Square.h"
#include <vector>

class AStar
{
private:
	std::vector<std::vector<Square>> board;

	Square GhostPosition;
	Square GoalPosition;

public:
	AStar(void);
	~AStar(void);

	void Calculate();		//Calculates the pathfinding
	void SetGoal(Square Goal)
	{GoalPosition = Goal;}
	void SetPosition(Square Position)
	{GhostPosition = Position;}

	void SetBoard(std::vector<std::vector<Square>> _board)
	{ board = _board;}

	char returnNextDirection(int x, int y);

private:

	int GetHeuristic(int x, int y)		//returns the distance between my point and the goal.
	{
		return	int(	fabs( float(x - GoalPosition.GetX()) )	+
						fabs( float(y - GoalPosition.GetY()) )	);
	}

	int GetGhostMoves(int x, int y)
	{
		return		int(	fabs( float(x - GhostPosition.GetX()) )		+
							fabs( float(y - GhostPosition.GetY()) )		);
	}
	void setWeight(int x, int y)
	{
		board[x][y].AStarWeight = GetHeuristic(x, y) + GetGhostMoves(x, y);
	}

	void InvestigateSquare(int x, int y, int count);
};

#endif

