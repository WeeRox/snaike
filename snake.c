#include <stdlib.h>
#include "snake.h"

snake *snake_init(int w, int h)
{
	snake *snake = malloc(sizeof(struct snake));

	snake->length = 1;

	snake->snake = malloc(sizeof(int *));
	snake->snake[0] = malloc(sizeof(int) * 2);
	snake->snake[0][0] = rand() % w;
	snake->snake[0][1] = rand() % h;

	snake->direction = rand() % 4;

	return snake;
}
