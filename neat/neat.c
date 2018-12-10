#include <stdlib.h>

#include "board.h"
#include "neat/genome.h"

#define POPULATION_SIZE 100
#define INPUT_NUM 5
#define OUTPUT_NUM 3

unsigned int innovation_number = 0;

struct genome *population;

void setup(void)
{
	/* create initial population */
	if ((population = malloc(sizeof(struct genome) * POPULATION_SIZE)) == NULL)
	{
		return;
	}

	for (int i = 0; i < POPULATION_SIZE; i++)
	{
		struct genome *genome;
		if ((genome = malloc(sizeof(struct genome))) == NULL)
		{
			return;
		}

		if ((genome->connection_genes = hashmap_init(sizeof(unsigned int), sizeof(struct connection_gene), &hashmap_hash_int)) == NULL)
		{
			return;
		}

		if ((genome->node_genes = hashmap_init(sizeof(unsigned int), sizeof(struct node_gene), &hashmap_hash_int)) == NULL)
		{
			return;
		}

		if ((genome->inputs = malloc(sizeof(struct node_gene) * INPUT_NUM)) == NULL)
		{
			return;
		}

		if ((genome->outputs = malloc(sizeof(struct node_gene) * OUTPUT_NUM)) == NULL)
		{
			return;
		}

		for (int j = 0; j < INPUT_NUM; j++)
		{
			struct node_gene *node;
			if ((node = malloc(sizeof(struct node_gene))) == NULL)
			{
				return;
			}

			node->id = innovation_number;
			innovation_number++;

			node->type = INPUT;

			hashmap_put(genome->node_genes, &node->id, node);
			*(genome->inputs + j) = node;
		}

		for (int j = 0; j < OUTPUT_NUM; j++)
		{
			struct node_gene *node;
			if ((node = malloc(sizeof(struct node_gene))) == NULL)
			{
				return;
			}

			node->id = innovation_number;
			innovation_number++;

			node->type = OUTPUT;

			hashmap_put(genome->node_genes, &node->id, node);
			*(genome->outputs + j) = node;
		}

		for (int j = 0; j < INPUT_NUM; j++)
		{
			for (int k = 0; k < OUTPUT_NUM; k++)
			{
				struct connection_gene *connection;
				if ((connection = malloc(sizeof(struct connection_gene))) == NULL)
				{
					return;
				}

				connection->id = innovation_number;
				innovation_number++;

				connection->in = *(genome->inputs + j);
				connection->out = *(genome->outputs + k);
				connection->enabled = 1;

				/* generate weight between -2 and 2 */
				connection->weight = (4.0 * ((double)rand() / (double)RAND_MAX)) - 2.0;
				hashmap_put(genome->connection_genes, &connection->id, connection);
			}
		}
	}
}

void teardown(void)
{
	return;
}

direction get_direction(board board)
{
	return NORTH;
}
