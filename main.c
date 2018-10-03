#include <time.h>
#include <stdlib.h>
#include "board.h"
#include "draw.h"

int main(int argc, char **argv)
{
	srand(time(NULL));
	atexit(draw_reset);
	struct timespec sleep;

	sleep.tv_sec = 0;
	sleep.tv_nsec = 900000000;

	board board = board_init();

	board_border_print(board);

	while (1)
	{
		board_print(board);
		nanosleep(&sleep, NULL);

		snake_move(board);
		if (snake_collision(board) || board_collision(board))
		{
			return 1;
		}

		if (food_eaten(board))
		{
			snake_grow(board);
			food_generate(board);
		}
	}

	return 0;
}
