#include <time.h>
#include <stdlib.h>
#include "board.h"
#include "draw.h"

direction get_direction(board board);
void setup();
void teardown();

int main(int argc, char **argv)
{
	setup();

	srand(time(NULL));
	atexit(draw_reset);
	atexit(teardown);

	struct timespec sleep;

	sleep.tv_sec = 0;
	sleep.tv_nsec = 900000000;

	board board = board_init();

	board_border_print(board);

	while (1)
	{
		board_print(board);
		nanosleep(&sleep, NULL);

		direction direction = get_direction(board);

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
