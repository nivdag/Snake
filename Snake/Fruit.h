#ifndef _FRUIT_H_
#define _FRUIT_H_

#include "Point.h"

class Fruit {
	Point position;
	int value;
	char symbol;

public:
	Fruit(int x, int y, int val);
	Fruit(Point pos, int val);
	Point getPosition();
	char getSymbol();
	int getValue();
	void setPoint(Point pos);
};

#endif