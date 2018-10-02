#include <stdlib.h>
#include <string.h>
#include "board.h"

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

void snake_move(board board)
{
	int **new = malloc(sizeof(int *) * board.snake->length);
	new[0] = malloc(sizeof(int) * 2);

	switch (board.snake->direction)
	{
		case NORTH:
			new[0][0] = board.snake->snake[0][0];
			new[0][1] = board.snake->snake[0][1] - 1;
			break;
		case SOUTH:
			new[0][0] = board.snake->snake[0][0];
			new[0][1] = board.snake->snake[0][1] + 1;
			break;
		case EAST:
			new[0][0] = board.snake->snake[0][0] + 1;
			new[0][1] = board.snake->snake[0][1];
			break;
		case WEST:
			new[0][0] = board.snake->snake[0][0] - 1;
			new[0][1] = board.snake->snake[0][1];
			break;
	}

	board.snake->pos_grow[0] = board.snake->snake[board.snake->length - 1][0];
	board.snake->pos_grow[1] = board.snake->snake[board.snake->length - 1][1];

	memcpy(&new[1], board.snake->snake, sizeof(int *) * (board.snake->length - 1));

	board.snake->snake = new;
}

void snake_grow(board board)
{
	board.snake->length++;

	board.snake->snake = realloc(board.snake->snake, sizeof(int *) * board.snake->length);
	board.snake->snake[board.snake->length - 1] = malloc(sizeof(int) * 2);

	board.snake->snake[board.snake->length - 1][0] = board.snake->pos_grow[0];
	board.snake->snake[board.snake->length - 1][1] = board.snake->pos_grow[1];
}

int snake_collision(board board)
{
	int head_x = board.snake->snake[0][0];
	int head_y = board.snake->snake[0][1];

	for (int i = 1; i < board.snake->length; i++)
	{
		if (
			board.snake->snake[i][0] == head_x && 
			board.snake->snake[i][1] == head_y
		)
		{
			return 1;
		}
	}

	return 0;
}
