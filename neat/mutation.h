#ifndef __SNAIKE_NEAT_MUTATION_H
#define __SNAIKE_NEAT_MUTATION_H

#include <neat/genome.h>

void mutate_weight(struct genome *genome);
void mutate_connection(struct genome *genome);
void mutate_node(struct genome *genome);

#endif /* __SNAIKE_NEAT_MUTATION_H */
