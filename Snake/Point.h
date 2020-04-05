#ifndef _POINT_H_
#define _POINT_H_

class Point {
	int x;
	int y;

public:
	Point() {
		x = 10;
		y = 10;
	}

	int getX(){ return x; }
	int getY() { return y; }
	void setX(int in_x) { x = in_x; }
	void setY(int in_y) { y = in_y; }

	// Overload == operator to compare two Point objects.
	bool operator==(const Point& a) {
		if (x == a.x && y == a.y) {
			return true;
		}
		else return false;
	}

	// Generate a random Point object within the boarders.
	static Point generateRandomPoint();
};

#endif
