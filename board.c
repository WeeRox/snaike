#include <stdio.h>
#include "board.h"
#include "draw.h"

#define BORDER 1
#define WIDTH 5
#define HEIGHT 5

board board_init()
{
	food *food = food_init();
	snake *snake  = snake_init(WIDTH, HEIGHT);

	board board = {.w = HEIGHT, .h = HEIGHT, .food = food, .snake = snake};
	food_generate(board);
	return board;
}

void board_border_print(board board)
{
	for (int i = 0; i < board.w + (2 * BORDER); i++)
	{
		for (int j = 0; j < board.h + (2 * BORDER); j++)
		{
			if (i < BORDER || j < BORDER || i >= board.w + BORDER || j >= board.h + BORDER)
			{
				draw(i, j, DRAW_BORDER);
			}
		}
	}
}

void board_print(board board)
{
	draw(board.snake->pos_grow[0] + BORDER, board.snake->pos_grow[1] + BORDER, DRAW_VOID);
	draw(board.food->x + BORDER, board.food->y + BORDER, DRAW_FOOD);

	for (int i = 0; i < board.snake->length; i++)
	{
		draw(board.snake->snake[i][0] + BORDER, board.snake->snake[i][1] + BORDER, DRAW_SNAKE);
	}
	fflush(stdout);
}

int board_collision(board board)
{
	int head_x = board.snake->snake[0][0];
	int head_y = board.snake->snake[0][1];

	if (
		head_x < 0 || head_x >= board.w ||
		head_y < 0 || head_y >= board.h
	)
	{
		return 1;
	}
	return 0;
}
