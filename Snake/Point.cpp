#include "Point.h"
#include <cstdlib>
#include "Boarders.h"

Point Point::generateRandomPoint() {
	Point result;
	int randomXVal;
	int randomYVal;
	randomXVal = (rand() % RIGHTSIDE) + 1;
	randomYVal = (rand() % BOTTOM) + 1;
	result.setX(randomXVal);
	result.setY(randomYVal);
	return result;
}
