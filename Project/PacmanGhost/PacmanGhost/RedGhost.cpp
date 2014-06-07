#include "StdAfx.h"
#include "RedGhost.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

RedGhost::RedGhost(void)
{
	id='1';
	bPathCalculated=false;
}


RedGhost::~RedGhost(void)
{
}

char RedGhost::FirstPractice(std::vector<std::vector<Square>> board, int width, int height)
{
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

	switch(rand() % 4 + 1)
	{
	case 1:
		return GoUp(board);
	case 2:
		return GoRight(board);
	case 3:
		return GoDown(board);
	case 4:
		return GoLeft(board);
	default:
		return 'w';
	}
}

char RedGhost::SecondPractice(std::vector<std::vector<Square>> board, int width, int height)
{
	this->PreFind(board, width, height);

	if(bPathCalculated)
	{
		char ReturnDir = this->returnNextDirection();

		switch(ReturnDir)
		{
		case 'U':
			return GoUp(board);
		case 'R':
			return GoRight(board);
		case 'D':
			return GoDown(board);
		case 'L':
			return GoLeft(board);
		default:
			return 'w';
		}
	}
	else
	{
		switch(rand() % 4 + 1)
		{
		case 1:
			return GoUp(board);
		case 2:
			return GoRight(board);
		case 3:
			return GoDown(board);
		case 4:
			return GoLeft(board);
		default:
			return 'w';
		}
	}
}

char RedGhost::returnNextDirection()
{
	int minWeight;
	char r;

	r='U';
	minWeight = 1000;

	if(pathBoard[x-1][y].AStarWeight != 0 && pathBoard[x-1][y].AStarWeight < minWeight)
	{
		minWeight= pathBoard[x-1][y].AStarWeight;
		r='U';
	}

	if(pathBoard[x][y-1].AStarWeight != 0 && pathBoard[x][y-1].AStarWeight < minWeight)
	{
		minWeight= pathBoard[x][y-1].AStarWeight;
		r='L';
	}

	if(pathBoard[x+1][y].AStarWeight != 0 && pathBoard[x+1][y].AStarWeight < minWeight)
	{
		minWeight= pathBoard[x+1][y].AStarWeight;
		r='D';
	}

	if(pathBoard[x][y+1].AStarWeight != 0 && pathBoard[x][y+1].AStarWeight < minWeight)
	{
		minWeight= pathBoard[x][y+1].AStarWeight;
		r='R';
	}

	return r;
}

