#include "StdAfx.h"
#include "BlueGhost.h"
#include "Master.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */


BlueGhost::BlueGhost(void)
{
	id='3';
	bPathCalculated=false;
}


BlueGhost::~BlueGhost(void)
{
}

char BlueGhost::FirstPractice(std::vector<std::vector<Square>> board, int width, int height)
{
	if(!bSeeded)
	{
		bSeeded=true;
		srand(time(0));
	}

	for(int i = 0; i<height; i++)
	{
		for(int j = 0; j<width; j++)
		{
			if(board[i][j].GetType() == '0')
			{
				playerPos = board[i][j];
			}
			else if(board[i][j].GetType() == '1')
			{
				redPos=board[i][j];
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

char BlueGhost::SecondPractice(std::vector<std::vector<Square>> board, int width, int height)
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

void BlueGhost::InvestigateSquare(int _x, int _y, int count)
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

