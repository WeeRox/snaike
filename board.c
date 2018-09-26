#include "board.h"
#include "draw.h"

board board_init(int w, int h, snake *snake)
{
	board board = {.w = w, .h = h, .snake = snake};
	return board;
}

void board_print(board board)
{
	for (int i = 0; i < board.w + 2; i++)
	{
		for (int j = 0; j < board.h + 2; j++)
		{
			if (i == 0 || j == 0 || i == board.w + 1 || j == board.h + 1)
			{
				draw(i, j, '#');
			}
			else
			{
				draw(i, j, ' ');
			}
		}
	}

	for (int i = 0; i < board.snake->length; i++)
	{
		draw(board.snake->snake[i][0] + 1, board.snake->snake[i][1] + 1, '0');
	}
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
