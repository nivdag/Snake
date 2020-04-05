#include "Snake.h"
#include "Gotoxy.h"
#include "Resolution.h"
#include "Boarders.h"
#include "Direction.h"

#include <iostream>
using namespace std;

Snake::Snake()
{
	symbol = '@';
	currentBodySize = 7;
	currentDirection = UP;
}

void Snake::move(direction dir) {

	if (currentDirection == STOP) {
		return;
	}

	// rest of the body follows the head(body[0]).
	for (int i = currentBodySize -1 ; i > 0; i--) {
		body[i] = body[i - 1];
	}
	
	// if the next direction is not valid (opposite) keep the current direction unchanged.
	if (!Direction::isOppositeDirection(currentDirection, dir)) {
		currentDirection = dir;
	}
	else {
		dir = currentDirection;
	}

	if (dir == DOWN) {
		if (body[0].getY() == Boarders::BOTTOM) {
			body[0].setY(Boarders::UPPER);
		}
		else {
			body[0].setY((body[0].getY() + 1) % Resolution::LENGTH);
		}
	}
	else if(dir == UP) {
		if (body[0].getY() == Boarders::UPPER) {
			body[0].setY(Boarders::BOTTOM);
		}
		else {
			body[0].setY((body[0].getY() - 1) % Resolution::LENGTH);
		}
	}
	else if (dir == LEFT) {
		if (body[0].getX() == Boarders::LEFTSIDE) {
			body[0].setX(Boarders::RIGHTSIDE);
		}
		else {
			body[0].setX((body[0].getX() - 1) % Resolution::WIDTH);
		}
	}
	else if (dir == RIGHT) {
		if (body[0].getX() == Boarders::RIGHTSIDE) {
			body[0].setX(Boarders::LEFTSIDE);
		}
		else {
			body[0].setX((body[0].getX() + 1) % Resolution::WIDTH);
		}
	}	

	// check if snake collided with himself. if so, stop moving.
	if (selfCollision()) {
		currentDirection = STOP;
	}
}

// return the i'th body part, if index is invalid returns the head (body[0])
Point Snake::getBodyPart(int index) {
	if (index > 0 && index < currentBodySize) {
		return body[index];
	}
	else return body[0];
}

// checks if snake collided with himself
bool Snake::selfCollision() {
	for (int i = 1; i < currentBodySize; i++) {
		if (body[0] == body[i])
			return true;
	}

	return false;
}

void Snake::grow() {
	int xVal;
	int yVal;

	if (currentBodySize < SNAKE_MAX_SIZE) {
		xVal = body[currentBodySize - 1].getX();
		yVal = body[currentBodySize - 1].getY();
		currentBodySize++;
		body[currentBodySize - 1].setX(xVal);
		body[currentBodySize - 1].setY(yVal);
	}
}

direction Snake::getDirection() {
	return currentDirection;
}
