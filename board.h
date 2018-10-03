#ifndef __SNAIKE_BOARD_H
#define __SNAIKE_BOARD_H

#include "food.h"
#include "snake.h"

typedef struct board
{
	int w;
	int h;
	food *food;
	snake *snake;
} board;

board board_init();
void board_print(board board);
void board_border_print(board board);
int board_collision(board board);

#endif /* __SNAIKE_BOARD_H */
