#ifndef __SNAIKE_SNAKE_H
#define __SNAIKE_SNAKE_H

typedef struct snake
{
	int head_x;
	int head_y;
} snake;

snake snake_init(int w, int h);

#endif /* __SNAIKE_SNAKE_H */
