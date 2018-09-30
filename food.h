#ifndef __SNAIKE_FOOD_H
#define __SNAIKE_FOOD_H

#include "snake.h"

typedef struct food
{
	int x;
	int y;
} food;

food *food_init();
void food_generate(food *food, int w, int h);
int food_eaten(snake *snake, food *food);

#endif /* __SNAIKE_FOOD_H */
