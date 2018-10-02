#include <stdlib.h>
#include "board.h"

food *food_init()
{
	food *food = malloc(sizeof(struct food));
	return food;
}

void food_generate(board board)
{
	board.food->x = rand() % board.w;
	board.food->y = rand() % board.h;

	for (int i = 0; i < board.snake->length; i++)
	{
		if (
			board.snake->snake[i][0] == board.food->x &&
			board.snake->snake[i][1] == board.food->y
		)
		{
			food_generate(board);
			break;
		}
	}
}

int food_eaten(board board)
{
	if (
		board.snake->snake[0][0] == board.food->x &&
		board.snake->snake[0][1] == board.food->y
	)
	{
		return 1;
	}
	return 0;
}
