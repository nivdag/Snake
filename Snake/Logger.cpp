#include "Logger.h"
#include "Gotoxy.h"
#include "Snake.h"

#include <iostream>
using namespace std;

void Logger::printSnakeDetails(Snake snake)
{
	gotoxy(95, 20);
	cout << "                 ";
	cout << "                 ";

	gotoxy(95, 20);
	cout << "X: " << snake.getHeadPosition().getX();
	cout << " Y: " << snake.getHeadPosition().getY();
}
