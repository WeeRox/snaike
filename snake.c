#include <stdlib.h>
#include <string.h>
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
	snake->pos_grow = malloc(sizeof(int) * 2);
	snake->pos_grow[0] = snake->snake[0][0];
	snake->pos_grow[1] = snake->snake[0][1];

	return snake;
}

void snake_move(snake *snake)
{
	int **new = malloc(sizeof(int *) * snake->length);
	new[0] = malloc(sizeof(int) * 2);

	switch (snake->direction)
	{
		case NORTH:
			new[0][0] = snake->snake[0][0];
			new[0][1] = snake->snake[0][1] - 1;
			break;
		case SOUTH:
			new[0][0] = snake->snake[0][0];
			new[0][1] = snake->snake[0][1] + 1;
			break;
		case EAST:
			new[0][0] = snake->snake[0][0] + 1;
			new[0][1] = snake->snake[0][1];
			break;
		case WEST:
			new[0][0] = snake->snake[0][0] - 1;
			new[0][1] = snake->snake[0][1];
			break;
	}

	snake->pos_grow[0] = snake->snake[snake->length - 1][0];
	snake->pos_grow[1] = snake->snake[snake->length - 1][1];

	memcpy(&new[1], snake->snake, sizeof(int *) * (snake->length - 1));

	snake->snake = new;
}

void snake_grow(snake *snake)
{
	snake->length++;

	snake->snake = realloc(snake->snake, sizeof(int *) * snake->length);
	snake->snake[snake->length - 1] = malloc(sizeof(int) * 2);

	snake->snake[snake->length - 1][0] = snake->pos_grow[0];
	snake->snake[snake->length - 1][1] = snake->pos_grow[1];
}

int snake_collision(snake *snake)
{
	int head_x = snake->snake[0][0];
	int head_y = snake->snake[0][1];

	for (int i = 1; i < snake->length; i++)
	{
		if (
			snake->snake[i][0] == head_x && 
			snake->snake[i][1] == head_y
		)
		{
			return 1;
		}
	}

	return 0;
}
