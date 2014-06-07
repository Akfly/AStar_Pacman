#include "StdAfx.h"
#include "Board.h"

#include <iostream>
#include <stdlib.h>
#include "windows.h"
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <conio.h>		//getch

#include "Master.h"

Board::Board(void)
{
	GetCurrentConsoleFontEx( GetStdHandle(STD_OUTPUT_HANDLE), false, &actual_font);
	default_font = actual_font;

	actual_font.dwFontSize.X = 20;
	actual_font.dwFontSize.Y = 20;
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, &actual_font);
}


Board::~Board(void)
{
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), false, &default_font);
}

void Board::PrintBoard()
{
	system("cls");
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			char ntype = board[i][j].GetType();
			if(ntype=='n')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0xff);
				//system("Color 0A");
				std::cout<<char(178);
			}
			else if(ntype=='b')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x999);
				//system("Color 0F");
				std::cout<<char(178);
			}
			else if(ntype=='f')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x01);

				std::cout<<' ';
			}
			else if(ntype=='0')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0E);
				std::cout<<char(2);
			}
			else if(ntype=='1')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0C);
				std::cout<<char(207);
			}
			else if(ntype=='2')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x06);
				std::cout<<char(207);
			}
			else if(ntype=='3')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0B);
				std::cout<<char(207);
			}
			else if(ntype=='4')
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x05);
				std::cout<<char(207);
			}
			else
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x00);
				std::cout<<' ';
			}
			
		}
		std::cout<<'\n';
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0x0f);
}

void Board::InitializeMap()
{
	std::string line1;
	std::string line2;

	std::getline(map_file, line1);
	std::getline(map_file, line2);

	std::istringstream iss1(line1);
	std::istringstream iss2(line2);
		

	if(!((iss1 >> height) && (iss2 >> width)))
	{
		std::cout<<"\nError getting line numbers.";
		system("pause");
	}

	std::vector<std::vector<Square>> aux_board(height);
	for(size_t i = 0; i<aux_board.size(); i++)
	{
		aux_board[i].resize(unsigned(width));
		std::string actualLine;
		std::getline(map_file, actualLine);
		for(size_t j = 0; j<aux_board[i].size(); j++)
		{
				aux_board[i][j].Initialize(i, j, actualLine[j]);
		}
	}

	board=aux_board;

	map_file.close();
	//close file?
	PlaceCharacters();
	MainLoop();
}

void Board::PlaceCharacters()
{
	int freeSpaces = 0;

	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			if(board[i][j].GetType() == 'f')
			{
				freeSpaces++;
			}
		}
	}

	if(freeSpaces >= 5)
	{
		Square *freeSquares = new Square[freeSpaces];
		
		int countfree = 0;
		for(int i = 0; i < height; i++)
		{
			for(int j = 0; j < width; j++)
			{
				if(board[i][j].GetType() == 'f')
				{
					freeSquares[countfree] = board[i][j];
					countfree++;
				}
			}
		}

		srand(time(0));
		int pos = rand() %(freeSpaces-1);
		Square playerSquare = freeSquares[pos];
		player.ChangeLocation(playerSquare.GetX(), playerSquare.GetY());

		Square redSquare;
		Square pinkSquare;
		Square blueSquare;
		Square orangeSquare;

		bool bRepeat= true;
		while(bRepeat)
		{
			int num = rand() % (freeSpaces-1);
			if (!(freeSquares[num].GetX() == playerSquare.GetX() && freeSquares[num].GetY() == playerSquare.GetY()))
			{
				bRepeat=false;
				redSquare = freeSquares[num];
			}
		}
		bRepeat=true;
		while(bRepeat)
		{
			int num = rand() % (freeSpaces-1);
			if (!(freeSquares[num].GetX() == playerSquare.GetX() && freeSquares[num].GetY() == playerSquare.GetY())
				&& !(freeSquares[num].GetX() == redSquare.GetX() && freeSquares[num].GetY() == redSquare.GetY()))
			{
				bRepeat=false;
				pinkSquare = freeSquares[num];
			}
		}
		bRepeat=true;
		while(bRepeat)
		{
			int num = rand() % (freeSpaces-1);
			if (!(freeSquares[num].GetX() == playerSquare.GetX() && freeSquares[num].GetY() == playerSquare.GetY())
				&& !(freeSquares[num].GetX() == redSquare.GetX() && freeSquares[num].GetY() == redSquare.GetY())
				&& !(freeSquares[num].GetX() == pinkSquare.GetX() && freeSquares[num].GetY() == pinkSquare.GetY()))
			{
				bRepeat=false;
				orangeSquare = freeSquares[num];
			}
		}
		bRepeat=true;
		while(bRepeat)
		{
			int num = rand() % (freeSpaces-1);
			if (!(freeSquares[num].GetX() == playerSquare.GetX() && freeSquares[num].GetY() == playerSquare.GetY())
				&& !(freeSquares[num].GetX() == redSquare.GetX() && freeSquares[num].GetY() == redSquare.GetY())
				&& !(freeSquares[num].GetX() == pinkSquare.GetX() && freeSquares[num].GetY() == pinkSquare.GetY())
				&& !(freeSquares[num].GetX() == orangeSquare.GetX() && freeSquares[num].GetY() == orangeSquare.GetY()))
			{
				bRepeat=false;
				blueSquare = freeSquares[num];
			}
		}
		
		reddy.ChangeLocation(redSquare.GetX(), redSquare.GetY());
		pinky.ChangeLocation(pinkSquare.GetX(), pinkSquare.GetY());
		bluey.ChangeLocation(blueSquare.GetX(), blueSquare.GetY());
		ory.ChangeLocation(orangeSquare.GetX(), orangeSquare.GetY());

		delete[] freeSquares;
	}
	else
	{
		std::cout<<"Error: invalid map";
	}
}

void Board::UpdateBoard()
{
	for(int i = 0; i < height; i++)
	{
		for(int j = 0; j < width; j++)
		{
			if(board[i][j].GetType() == '0' || board[i][j].GetType() == '1' || board[i][j].GetType() == '2'
				|| board[i][j].GetType() == '3' || board[i][j].GetType() == '4')
			{
				board[i][j].ResetType();
			}
		}
	}

	board[player.GetX()][player.GetY()].PutCharacter(player.GetID());
	board[reddy.GetX()][reddy.GetY()].PutCharacter(reddy.GetID());
	board[pinky.GetX()][pinky.GetY()].PutCharacter(pinky.GetID());
	board[bluey.GetX()][bluey.GetY()].PutCharacter(bluey.GetID());
	board[ory.GetX()][ory.GetY()].PutCharacter(ory.GetID());
}

void Board::MainLoop()
{
	UpdateBoard();
	PrintBoard();

	bool bGameEnded = false;

	while(!bGameEnded)
	{
		//system("pause");	//get key
		player.SetDirection(_getwch());	//pass the key

		bGameEnded = CheckMove(&player);
		bGameEnded = CheckMove(&reddy);
		bGameEnded = CheckMove(&pinky);
		bGameEnded = CheckMove(&bluey);
		bGameEnded = CheckMove(&ory);

		PrintBoard();
	}
}

bool Board::CheckMove(Character *pj)
{
	//todos los moves de los fantasmas hay que cambiar de simbolo la X :(
	char move;
	if(pj->GetID() == '0')
	{
		move = pj->Move(board, width, height);
	}
	else
	{
		if(Master::SECOND_PRACTICE)
		{
			move = pj->SecondPractice(board, width, height);
		}
		else
		{
			move = pj->FirstPractice(board, width, height);
		}
	}
	int yVariant = 0;
	int xVariant = 0;

	if(move == 'u')
	{
		xVariant=-1;
	}
	else if(move == 'l')
	{
		yVariant=-1;
	}
	else if(move == 'r')
	{
		yVariant=1;
	}
	else if(move == 'd')
	{
		xVariant=1;
	}

	char newTileType = board[pj->GetX()+xVariant][pj->GetY()+yVariant].GetType();

	if(pj->GetID() != newTileType)
	{
		if(newTileType == 'f')
		{
			board[pj->GetX()][pj->GetY()].ResetType();
			pj->ChangeLocation(pj->GetX()+xVariant, pj->GetY()+yVariant);
			board[pj->GetX()][pj->GetY()].PutCharacter(pj->GetID());
		}
		else if (newTileType == '0' ||
			(pj->GetID() == '0' && (newTileType == '1' || newTileType == '2' || newTileType == '3' || newTileType == '4')))
		{
			player.Kill();
			return true;
		}
		else if (newTileType == 'b' || newTileType == 'n')
		{
			pj->Kill();
			if(pj->GetID() == '0')
			{
				return true;
			}
		}
	}

	return false;
}