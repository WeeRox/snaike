#include <time.h>
#include <stdlib.h>
#include "snake.h"
#include "board.h"
#include "draw.h"

int main(int argc, char **argv)
{
	srand(time(NULL));
	atexit(draw_reset);
	struct timespec sleep;

	sleep.tv_sec = 0;
	sleep.tv_nsec = 900000000;

	int width = 5;
	int height = 5;
	snake *snake = snake_init(width, height);
	food *food = food_init();
	board board = board_init(width, height, food, snake);

	food_generate(food, snake, width, height);

	board_print(board);

	while (1)
	{
		snake_move(snake);
		if (snake_collision(snake) || board_collision(board))
		{
			return 1;
		}

		if (food_eaten(snake, food))
		{
			snake_grow(snake);
			food_generate(food, snake, width, height);
		}

		board_print(board);
		nanosleep(&sleep, NULL);
	}

	return 0;
}
