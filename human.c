#include <termios.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "board.h"

#define CONTROL_KEYS "wasd"

struct termios term_orig;

void term_reset(void)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &term_orig);
}

void setup(void)
{
	struct termios term_new;

	tcgetattr(STDIN_FILENO, &term_orig);
	atexit(term_reset);

	tcgetattr(STDIN_FILENO, &term_new);

	term_new.c_lflag &= ~(ICANON|ECHO);
	term_new.c_cc[VMIN] = 0;
	term_new.c_cc[VTIME] = 0;

	tcsetattr(STDIN_FILENO, TCSANOW, &term_new);
}

void teardown(void)
{
	term_reset();
}

direction get_direction(board board)
{
	char c = -1;
	unsigned int i;

	while (!feof(stdin))
	{
		i = fgetc(stdin);
		if (strchr(CONTROL_KEYS, i))
		{
			c = (char) i;
		}
	}

	clearerr(stdin);

	if (c == -1)
	{
		return board.snake->direction;
	}

	switch (c)
	{
		case 'w':
			return (board.snake->direction == SOUTH) ? SOUTH : NORTH;
		case 's':
			return (board.snake->direction == NORTH) ? NORTH : SOUTH;
		case 'd':
			return (board.snake->direction == WEST) ? WEST : EAST;
		case 'a':
			return (board.snake->direction == EAST) ? EAST : WEST;
	}
}
