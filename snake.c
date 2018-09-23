#include <stdlib.h>
#include "snake.h"

snake snake_init(int w, int h)
{
	int x = rand() % w;
	int y = rand() % h;
	snake snake = {
		.head_x = x, 
		.head_y = y,
		.tail_x = x,
		.tail_y = y
	};
	return snake;
}
