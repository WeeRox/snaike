#ifndef __SNAIKE_NEAT_CROSSOVER_H
#define __SNAIKE_NEAT_CROSSOVER_H

#include <neat/genome.h>

/* where p1 is more fit than p2 */
struct genome *crossover(struct genome *p1, struct genome *p2);

#endif /* __SNAIKE_NEAT_CROSSOVER_H */
