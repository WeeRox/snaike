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
	int length;
	int **snake;
	direction direction;
} snake;

snake *snake_init(int w, int h);

#endif /* __SNAIKE_SNAKE_H */
