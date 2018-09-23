#ifndef __SNAIKE_BOARD_H
#define __SNAIKE_BOARD_H

typedef struct board
{
	int w;
	int h;
} board;

board board_init(int w, int h);
void board_print(board board);
void board_update(board board);

#endif /* __SNAIKE_BOARD_H */
