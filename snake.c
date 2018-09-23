#include <stdlib.h>
#include "snake.h"

snake snake_init(int w, int h)
{
	snake snake = {.head_x = rand() % w, .head_y = rand() % h};
	return snake;
}
