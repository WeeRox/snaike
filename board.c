#include "board.h"
#include "draw.h"

board board_init(int w, int h)
{
	board board = {.w = w, .h = h};
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
}
