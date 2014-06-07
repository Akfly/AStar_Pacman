#include "StdAfx.h"
#include "Ghost.h"
#include "Master.h"

#include <time.h>       /* time */

char Ghost::GoUp(std::vector<std::vector<Square>> board)
{
	if(board[x-1][y].GetType() == 'f')
	{
		return 'u';
	}
	else if(board[x][y+1].GetType() == 'f')
	{
		return 'r';
	}
	else if(board[x][y-1].GetType() == 'f')
	{
		return 'l';
	}
	else if(board[x+1][y].GetType() == 'f')
	{
		return 'd';
	}
	else
	{
		return 'w';
	}
}

char Ghost::GoDown(std::vector<std::vector<Square>> board)
{
	if(board[x+1][y].GetType() == 'f')
	{
		return 'd';
	}
	else if(board[x][y+1].GetType() == 'f')
	{
		return 'r';
	}
	else if(board[x][y-1].GetType() == 'f')
	{
		return 'l';
	}
	else if(board[x-1][y].GetType() == 'f')
	{
		return 'u';
	}
	else
	{
		return 'w';
	}
}

char Ghost::GoLeft(std::vector<std::vector<Square>> board)
{
	if(board[x][y-1].GetType() == 'f')
	{
		return 'l';
	}
	else if(board[x+1][y].GetType() == 'f')
	{
		return 'u';
	}
	else if(board[x-1][y].GetType() == 'f')
	{
		return 'd';
	}
	else if(board[x][y+1].GetType() == 'f')
	{
		return 'r';
	}
	else
	{
		return 'w';
	}
}

char Ghost::GoRight(std::vector<std::vector<Square>> board)
{
	if(board[x][y+1].GetType() == 'f')
	{
		return 'r';
	}
	else if(board[x-1][y].GetType() == 'f')
	{
		return 'd';
	}
	else if(board[x+1][y].GetType() == 'f')
	{
		return 'u';
	}
	else if(board[x][y-1].GetType() == 'f')
	{
		return 'l';
	}
	else
	{
		return 'w';
	}
}

void Ghost::InvestigateSquare(int _x, int _y, int count)
{
	if(!(_x == playerPos.GetX() && _y == playerPos.GetY()) && count<Master::AI_DEPTH)
	{
		if(pathBoard[_x][_y].AStarWeight == 0)
		{
			setWeight(_x, _y);

			if(!(pathBoard[_x-1][_y].GetType() == 'b' || pathBoard[_x-1][_y].GetType() == 'n'))
			{
				InvestigateSquare(_x-1, _y, count+1);
			}
			if(!(pathBoard[_x+1][_y].GetType() == 'b' || pathBoard[_x+1][_y].GetType() == 'n'))
			{
				InvestigateSquare(_x+1, _y, count+1);
			}
			if(!(pathBoard[_x][_y-1].GetType() == 'b' || pathBoard[_x][_y-1].GetType() == 'n'))
			{
				InvestigateSquare(_x, _y-1, count+1);
			}
			if(!(pathBoard[_x][_y+1].GetType() == 'b' || pathBoard[_x][_y+1].GetType() == 'n'))
			{
				InvestigateSquare(_x, _y+1, count+1);
			}
		}
	}
}

char Ghost::returnNextDirection()
{
	int minWeight;
	char r;

	r='U';
	minWeight = 1000;
	char type = pathBoard[x][y+1].GetType();
	int tw = pathBoard[x][y+1].AStarWeight;
	if(pathBoard[x][y+1].AStarWeight != 0 && pathBoard[x][y+1].AStarWeight < minWeight)
	{
		minWeight= pathBoard[x][y+1].AStarWeight;
		r='R';
	}
	type = pathBoard[x+1][y].GetType();
	tw = pathBoard[x+1][y].AStarWeight;
	if(pathBoard[x+1][y].AStarWeight != 0 && pathBoard[x+1][y].AStarWeight < minWeight)
	{
		minWeight= pathBoard[x+1][y].AStarWeight;
		r='D';
	}
	type = pathBoard[x][y-1].GetType();
	tw = pathBoard[x][y-1].AStarWeight;
	if(pathBoard[x][y-1].AStarWeight != 0 && pathBoard[x][y-1].AStarWeight < minWeight)
	{
		minWeight= pathBoard[x][y-1].AStarWeight;
		r='L';
	}
	type = pathBoard[x-1][y].GetType();
	tw = pathBoard[x-1][y].AStarWeight;
	if(pathBoard[x-1][y].AStarWeight != 0 && pathBoard[x-1][y].AStarWeight < minWeight)
	{
		minWeight= pathBoard[x-1][y].AStarWeight;
		r='U';
	}

	return r;
}

void Ghost::PreFind(std::vector<std::vector<Square>> board, int width, int height)
{
	//initializes a new seed if a random is used (when the path is not ready)
	if(!bSeeded)
	{
		bSeeded=true;
		srand(time(0));
	}

	//Get the player pos
	for(int i = 0; i<height; i++)
	{
		for(int j = 0; j<width; j++)
		{
			if(board[i][j].GetType() == '0')
			{
				playerPos = board[i][j];
			}
		}
	}

	this->SetBoard(board);
	this->CalculatePathFinding();
	bPathCalculated=true;
}