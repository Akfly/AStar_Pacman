// PacmanGhost.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include "Square.h"
#include "Board.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Board map;
	int mapnum;
	std::cout<<"Choose map 1 or 2. (Wrire 1 or 2 and press enter).\n";
	std::cin>>mapnum;
	switch(mapnum)
	{
	case 1:
		map.OpenMap("map1.txt");
		break;
	case 2:
		map.OpenMap("map2.txt");
		break;
	default:
		return 0;
		break;
	}

	if(map.MapFileLoaded())
	{
		map.InitializeMap();
		system("cls");
		//map.PrintBoard();
	}
	else
	{
		std::cout<<"\nError reading file.";
	}

	system("pause");
	return 0;
}

