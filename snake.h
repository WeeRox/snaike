#ifndef __SNAIKE_SNAKE_H
#define __SNAIKE_SNAKE_H

struct board;

typedef enum direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST,
	FORWARD,
	RIGHT,
	LEFT
} direction;

typedef struct snake
{
	int length;
	int **snake;
	direction direction;
	int *pos_grow;
} snake;

snake *snake_init(int w, int h);
void snake_move(struct board board);
void snake_grow(struct board board);
int snake_collision(struct board board);

direction direction_ltog(struct board board, direction local);

#endif /* __SNAIKE_SNAKE_H */
