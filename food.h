#ifndef __SNAIKE_FOOD_H
#define __SNAIKE_FOOD_H

struct board;

typedef struct food
{
	int x;
	int y;
} food;

food *food_init();
void food_generate(struct board board);
int food_eaten(struct board board);

#endif /* __SNAIKE_FOOD_H */
