#include <stdlib.h>
#include "snake.h"

snake *snake_init(int w, int h)
{
	int x = rand() % w;
	int y = rand() % h;
	int dir = rand() % 4;

	snake *snake = malloc(sizeof(snake));

	snake->length = 1;
	snake->snake = malloc(sizeof(int *));
	snake->direction = dir;

	snake->snake[0] = malloc(sizeof(int) * 2);
	snake->snake[0][0] = x;
	snake->snake[0][1] = y;

	return snake;
}
