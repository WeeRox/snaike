#include <stdio.h>
#include "board.h"
#include "draw.h"

board board_init(int width, int height)
{
	board board = {.width = width, .height = height};
	return board;
}

void board_print(board board)
{
	for (int i = 0; i < board.width + 2; i++)
	{
		for (int j = 0; j < board.height + 2; j++)
		{
			if (i == 0 || j == 0 || i == board.width + 1 || j == board.height + 1)
			{
				draw(i, j, '#');
			}
		}
	}
}
