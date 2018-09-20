#include <stdio.h>

int curr_x = 0;
int curr_y = 0;
int max_y = 0;

void draw(int x, int y, char c)
{
	while (max_y < y)
	{
		draw(curr_x, max_y, '\n');
		max_y++;
	}

	if (x - curr_x < 0)
	{
		printf("\x1B[%iD", curr_x - x);
	}
	else if (x - curr_x > 0)
	{
		printf("\x1B[%iC", x - curr_x);
	}

	if (y - curr_y < 0)
	{
		printf("\x1B[%iA", curr_y - y);
	}
	else if (y - curr_y > 0)
	{
		printf("\x1B[%iB", y - curr_y);
	}

	printf("%c", c);

	curr_x = x + 1;
	curr_y = y;
}
