#include <stdlib.h>
#include "food.h"

food *food_init()
{
	food *food = malloc(sizeof(struct food));
	return food;
}

void food_generate(food *food, snake *snake, int w, int h)
{
	food->x = rand() % w;
	food->y = rand() % h;

	for (int i = 0; i < snake->length; i++)
	{
		if (
			snake->snake[i][0] == food->x &&
			snake->snake[i][1] == food->y
		)
		{
			food_generate(food, snake, w, h);
			break;
		}
	}
}

int food_eaten(snake *snake, food *food)
{
	if (
		snake->snake[0][0] == food->x &&
		snake->snake[0][1] == food->y
	)
	{
		return 1;
	}
	return 0;
}
