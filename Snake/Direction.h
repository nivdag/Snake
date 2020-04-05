#ifndef _DIRECTION_H_
#define _DIRECTION_H_

enum direction { LEFT, RIGHT, UP, DOWN, STOP };

class Direction {

public:
	static bool isOppositeDirection(direction dir1, direction dir2);

};

#endif
