#include "Board.h"
#include "Snake.h"
#include "Gotoxy.h"
#include "Logger.h"
#include <Windows.h>
#include <iostream>
#include <conio.h>
#include "Fruit.h"
#include "Point.h"
#include <ctime>

using namespace std;

enum KEYS { ESC = 27 };

int main() {

	Logger logger;
	Board board;
	Snake snake;
	direction dir = direction::UP;
	char keyPressed;
	int score = 0;

	board.initView();
	board.drawView();

	keyPressed = 0;

	// Initializing time.
	srand((unsigned)time(0));

	// Generate random Point ( x,y values )
	// draw fruit
	Fruit fruit = { Point::generateRandomPoint(), 1 };
	gotoxy(fruit.getPosition().getX(), fruit.getPosition().getY());
	cout << fruit.getSymbol();

	while (1) {

		if (_kbhit()) {
			keyPressed = _getch(); 
			_getch(); // using _getch() again to "eat" the extra character after the keyboard press

			if (keyPressed == KEYS::ESC) {
				break;
			}
		}
		else {
			keyPressed = 0;
		}

		// move to method:
		if (keyPressed == 'a') {
			dir = LEFT;
		}
		else if (keyPressed == 'd') {
			dir = RIGHT;
		}
		else if (keyPressed == 'w') {
			dir = UP;
		}
		else if (keyPressed == 's') {
			dir = DOWN;
		}

		// Erasing the snake from the board.
		for (int i = 0; i < snake.getCurrentBodySize(); i++) {
			gotoxy(snake.getBodyPart(i).getX(), snake.getBodyPart(i).getY());
			cout << ' ';
		}

		snake.move(dir);

		// Snake collided with himself
		if (snake.getDirection() == STOP) {
			gotoxy(WIDTH / 2, LENGTH / 2);
			cout << "Game Over, your score is: " << score;
			while (!_kbhit()) {};
			break;
		}

		// Collision detected.
		if (snake.getHeadPosition() == fruit.getPosition()) {
			score += fruit.getValue();

			// Create new Fruit.
			fruit.setPoint(Point::generateRandomPoint());
			gotoxy(fruit.getPosition().getX(), fruit.getPosition().getY());
			cout << fruit.getSymbol();

			// Snake grows.
			snake.grow();
		}

		// Drawing the snake.
		for (int i = 0; i < snake.getCurrentBodySize(); i++) {
			gotoxy(snake.getBodyPart(i).getX(), snake.getBodyPart(i).getY());
			cout << snake.getSymbol();
		}

		// Draw score
		gotoxy(2, LENGTH);
		cout << "Score: " << score;

		//logger.printSnakeDetails(snake);	// debug

		Sleep(50);

	}
}

