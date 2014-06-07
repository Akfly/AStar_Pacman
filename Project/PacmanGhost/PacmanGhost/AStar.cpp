#include "StdAfx.h"
#include "AStar.h"
#include "Master.h"


AStar::AStar(void)
{
}


AStar::~AStar(void)
{
}

void AStar::Calculate()
{
	InvestigateSquare(GhostPosition.GetX(), GhostPosition.GetY(), 0);
}

void AStar::InvestigateSquare(int x, int y, int count)
{
	if(!(x == GoalPosition.GetX() && y == GoalPosition.GetY()) && count<Master::AI_DEPTH)
	{
		if(board[x][y].AStarWeight == 0)
		{
			setWeight(x, y);

			if(!(board[x-1][y].GetType() == 'b' || board[x-1][y].GetType() == 'n'))
			{
				InvestigateSquare(x-1, y, count+1);
			}
			if(!(board[x+1][y].GetType() == 'b' || board[x+1][y].GetType() == 'n'))
			{
				InvestigateSquare(x+1, y, count+1);
			}
			if(!(board[x][y-1].GetType() == 'b' || board[x][y-1].GetType() == 'n'))
			{
				InvestigateSquare(x, y-1, count+1);
			}
			if(!(board[x][y+1].GetType() == 'b' || board[x][y+1].GetType() == 'n'))
			{
				InvestigateSquare(x, y+1, count+1);
			}
		}
	}
}

char AStar::returnNextDirection(int x, int y)
{
	int minWeight;
	char r;

	r='U';
	minWeight = 1000;
	char type = board[x][y+1].GetType();
	int tw = board[x][y+1].AStarWeight;
	if(board[x][y+1].AStarWeight != 0 && board[x][y+1].AStarWeight < minWeight)
	{
		minWeight= board[x][y+1].AStarWeight;
		r='R';
	}
	type = board[x+1][y].GetType();
	tw = board[x+1][y].AStarWeight;
	if(board[x+1][y].AStarWeight != 0 && board[x+1][y].AStarWeight < minWeight)
	{
		minWeight= board[x+1][y].AStarWeight;
		r='D';
	}
	type = board[x][y-1].GetType();
	tw = board[x][y-1].AStarWeight;
	if(board[x][y-1].AStarWeight != 0 && board[x][y-1].AStarWeight < minWeight)
	{
		minWeight= board[x][y-1].AStarWeight;
		r='L';
	}
	type = board[x-1][y].GetType();
	tw = board[x-1][y].AStarWeight;
	if(board[x-1][y].AStarWeight != 0 && board[x-1][y].AStarWeight < minWeight)
	{
		minWeight= board[x-1][y].AStarWeight;
		r='U';
	}

	return r;
}
