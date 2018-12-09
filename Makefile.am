AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = snaike-human

BASE_SOURCES = main.c draw.c board.c snake.c food.c normalization.c activation.c

LDADD = -lm

AM_CPPFLAGS = -DTIME_MOVE=500

snaike_human_SOURCES = $(BASE_SOURCES) human.c
snaike_human_CPPFLAGS = -DTIME_MOVE=900
