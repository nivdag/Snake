#include "Board.h"
#include <iostream>
using namespace std;

void Board::initView() {
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < WIDTH; j++) {
			if (i == 0 || i == LENGTH-1) {
				view[i][j] = '*';
			}
			else if (j == 0 || j == WIDTH - 1) {
				view[i][j] = '*';
			}
			else {
				view[i][j] = ' ';
			}
		}
	}
}

void Board::initViewWithAsterisks()
{
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < WIDTH; j++) {
			view[i][j] = '*';
		}
	}
}

void Board::drawView()
{
	for (int i = 0; i < LENGTH; i++) {
		for (int j = 0; j < WIDTH; j++) {
			cout << view[i][j];
		}
		cout << '\n';
	}
}

