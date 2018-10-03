#include <termios.h>
#include <stdlib.h>
#include <unistd.h>
#include "board.h"

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
	term_new.c_cc[VMIN] = 1;
	term_new.c_cc[VTIME] = 0;

	tcsetattr(STDIN_FILENO, TCSANOW, &term_new);
}

void teardown(void)
{
	term_reset();
}

direction get_direction(board board)
{
}
