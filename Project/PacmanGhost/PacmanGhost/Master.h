#ifndef MASTER_H
#define MASTER_H

//#include "Board.h"

#include "Square.h"

class Master
{
private:

public:
	static const int FONT_WIDTH = 20;
	static const int FONT_HEIGHT = 20;
	static const bool SECOND_PRACTICE = true;
	static const int BLOCKS_FAST_CALC = 5;
	static const int TURNS_TO_RECALL = 5;
	static const int AI_DEPTH = 3;
public:
	static Master& getInstance()
    {
        static Master    instance;
        return instance;
    }

private:
    Master() {}
};
#endif