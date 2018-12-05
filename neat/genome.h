#ifndef __SNAIKE_NEAT_GENOME_H
#define __SNAIKE_NEAT_GENOME_H

#include <hashmap.h>

enum type {
	INPUT,
	OUTPUT,
	HIDDEN
};

struct node_gene {
	unsigned int id;
	enum type type;
};

struct connection_gene {
	unsigned int id; // also known as innovation number
	struct node_gene in;
	struct node_gene out;
	float weight;
	int enabled;
};

struct genome {
	struct hashmap *connection_genes;
	struct hashmap *node_genes;
};

#endif /* __SNAIKE_NEAT_GENOME_H */
