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
	int *pos_grow;
} snake;

snake *snake_init(int w, int h);
void snake_move(snake *snake);
void snake_grow(snake *snake);
int snake_collision(snake *snake);

#endif /* __SNAIKE_SNAKE_H */
