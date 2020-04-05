#include "Fruit.h"

Fruit::Fruit(int x, int y, int val) {
	position.setX(x);
	position.setY(y);
	value = val;
	symbol = '$';
}

Fruit::Fruit(Point pos, int val) {
	position = pos;
	value = val;
	symbol = '$';
}

Point Fruit::getPosition() {
	return position;
}

char Fruit::getSymbol() { return symbol; }

int Fruit::getValue() { return value; }

void Fruit::setPoint(Point pos) {
	position.setX(pos.getX());
	position.setY(pos.getY());
}