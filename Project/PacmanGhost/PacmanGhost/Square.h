/**
*
* This class represents a Square on the board
*
**/
#ifndef SQUARE_H
#define SQUARE_H

class Square
{
private:
	int X;						//X position
	int Y;						//Y position

	char ActualType;			//Type of this Square, apart from initial, can be a character (0-4).
	char NaturalType;			//The initial type, if it is a block ('b'), null ('n') or a free ('f') Square.

public:
	int AStarWeight;			//Value of the square used for pathfinding
public:
	Square(){};
	~Square(void){};

	int GetX(){return X;};							//returns X position
	int GetY(){return Y;};							//returns Y position
	char GetType(){return ActualType;};				//returns this square type

	//Initializes the Square
	void Initialize(int x, int y, char ini_type)
	{
		X=x;
		Y=y;
		NaturalType = ini_type;
		ActualType = NaturalType;
		AStarWeight=0;
	};

	//Changes the type of this Square to a new one 
	void ResetType()
	{
		ActualType=NaturalType;
	}

	bool PutCharacter(char id)
	{
		if(id != ActualType)
		{
			if(!(ActualType == '0' || ActualType == '1' || ActualType == '2' || ActualType == '3'
				|| ActualType == '4' || ActualType == 'b' || ActualType == 'n'))
			{
				ActualType=id;
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return true;
		}
	}
};
#endif
