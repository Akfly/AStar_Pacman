#include "StdAfx.h"
#include "Player.h"


Player::Player(void)
{
	id='0';
	wantedDirection='w';
}


Player::~Player(void)
{
}

char Player::Move(std::vector<std::vector<Square>> board, int width, int height)
{
	if(wantedDirection == 'u')
	{
		if(board[x-1][y].GetType() == 'f')
		{
			return wantedDirection;
		}
		else return 'w';
	}
	else if(wantedDirection == 'd')
	{
		if(board[x+1][y].GetType() == 'f')
		{
			return wantedDirection;
		}
		else return 'w';
	}
	else if(wantedDirection == 'l')
	{
		if(board[x][y-1].GetType() == 'f')
		{
			return wantedDirection;
		}
		else return 'w';
	}
	else if(wantedDirection == 'r')
	{
		if(board[x][y+1].GetType() == 'f')
		{
			return wantedDirection;
		}
		else return 'w';
	}
	else return 'w';
}

void Player::SetDirection(char keyPressed)
{
	if(keyPressed == 'w' || keyPressed == 'W')
	{
		wantedDirection='u';
	}
	else if(keyPressed == 'a' || keyPressed == 'A')
	{
		wantedDirection='l';
	}
	else if(keyPressed == 's' || keyPressed == 'S')
	{
		wantedDirection='d';
	}
	else if(keyPressed == 'd' || keyPressed == 'D')
	{
		wantedDirection='r';
	}
	else
	{
		wantedDirection='w';
	}
}