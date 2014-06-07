#ifndef BOARD_H
#define BOARD_H

#include "Square.h"
#include <vector>

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <windows.h>

#include "RedGhost.h"
#include "PinkGhost.h"
#include "BlueGhost.h"
#include "OrangeGhost.h"
#include "Player.h"

class Board
{
private:

	std::ifstream map_file;
	std::vector<std::vector<Square>> board;
	int height;
	int width;

	Player player;
	RedGhost reddy;
	PinkGhost pinky;
	BlueGhost bluey;
	OrangeGhost ory;

	CONSOLE_FONT_INFOEX default_font;
	CONSOLE_FONT_INFOEX actual_font;

public:
	Board(void);
	~Board(void);

public:
	void PrintBoard();
	void SetBoard(std::vector<std::vector<Square>> actual_board)
	{board=actual_board;}

	//Loads the map txt file
	void OpenMap(std::string map_route)
	{
		map_file.open(map_route, std::ios::in);
	}

	bool MapFileLoaded(){return map_file.is_open();}		//If the map file loaded correctly

	void InitializeMap();							//Initializes the map

private:

	void PlaceCharacters();
	void UpdateBoard();
	void MainLoop();
	bool CheckMove(Character *pj);
};

#endif