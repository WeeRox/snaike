#ifndef __SNAIKE_BOARD_H
#define __SNAIKE_BOARD_H

typedef struct board
{
	int width;
	int height;
} board;

board board_init(int width, int height);
void board_print(board board);
void board_update(board board);

#endif /* __SNAIKE_BOARD_H */
