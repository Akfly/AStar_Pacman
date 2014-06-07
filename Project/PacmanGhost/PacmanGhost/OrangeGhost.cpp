#include "StdAfx.h"
#include "OrangeGhost.h"

#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

OrangeGhost::OrangeGhost(void)
{
	id='4';
	bPathCalculated=false;
}


OrangeGhost::~OrangeGhost(void)
{
}


char OrangeGhost::FirstPractice(std::vector<std::vector<Square>> board, int width, int height)
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

char OrangeGhost::SecondPractice(std::vector<std::vector<Square>> board, int width, int height)
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