#include "board.h"
#include "draw.h"

board board_init(int w, int h, snake snake)
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
		}
	}

	draw(board.snake.tail_x + 1, board.snake.tail_y + 1, 't');
	draw(board.snake.head_x + 1, board.snake.head_y + 1, 'h');
}
