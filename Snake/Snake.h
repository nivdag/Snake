#ifndef _SNAKE_H_
#define _SNAKE_H_

#include "Point.h"
#include "Direction.h"
#include "Utils.h"



class Snake {
	//Point head; // getting default value from the Point default ctor
	Point body[SNAKE_MAX_SIZE];
	char symbol;
	int currentBodySize;
	direction currentDirection;

public:
	Snake();
	char getSymbol() { return symbol; }
	//Point getHeadPosition() { return head; }
	Point getHeadPosition() { return body[0]; }
	int getCurrentBodySize() { return currentBodySize; }
	Point getBodyPart(int index);
	void grow();
	bool selfCollision();
	void move(direction dir);
	direction getDirection();
};

#endif