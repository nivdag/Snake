#include "Direction.h"

bool Direction::isOppositeDirection(direction dir1, direction dir2) {
	if (dir1 == LEFT && dir2 == RIGHT)
		return true;
	else if (dir1 == RIGHT && dir2 == LEFT)
		return true;
	else if (dir1 == UP && dir2 == DOWN)
		return true;
	else if (dir1 == DOWN && dir2 == UP)
		return true;
	else return false;
}
