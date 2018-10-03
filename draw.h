#ifndef __SNAIKE_DRAW_H
#define __SNAIKE_DRAW_H

#define DRAW_BORDER "\x1B[41m \x1B[0m"
#define DRAW_SNAKE "\x1B[47m \x1B[0m"
#define DRAW_FOOD "\x1B[42m \x1B[0m"
#define DRAW_VOID " "

void draw(int x, int y, char *c);
void draw_reset(void);

#endif /* __SNAIKE_DRAW_H  */
