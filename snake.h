#ifndef __SNAIKE_SNAKE_H
#define __SNAIKE_SNAKE_H

typedef enum direction
{
	NORTH,
	SOUTH,
	EAST,
	WEST
} direction;

typedef struct snake
{
	int head_x;
	int head_y;
	int tail_x;
	int tail_y;
	direction direction;
} snake;

snake snake_init(int w, int h);

#endif /* __SNAIKE_SNAKE_H */
