AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = snaike-human snaike-neat

BASE_SOURCES = main.c draw.c board.c snake.c food.c normalization.c activation.c

LDADD = -lm -lhashmap

AM_CPPFLAGS = -DTIME_MOVE=500

snaike_human_SOURCES = $(BASE_SOURCES) human.c
snaike_human_CPPFLAGS = -DTIME_MOVE=900

snaike_neat_SOURCES = $(BASE_SOURCES) neat/neat.c neat/mutation.c neat/crossover.c
snaike_neat_CPPFLAGS = -DTIME_MOVE=0
