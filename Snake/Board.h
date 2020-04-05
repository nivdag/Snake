#ifndef _BOARD_H_
#define _BOARD_H_

#include "Resolution.h"

class Board {
	char view[LENGTH][WIDTH];

public:
	Board() {
		initView();
	}

	void initView();
	void drawView();
	
	// debug
	void initViewWithAsterisks();
};

#endif
