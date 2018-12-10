#include <hashmap.h>
#include <stdlib.h>

#include "neat/crossover.h"

#define DISABLE_INHERITED_GENE_PROBABILITY 0.75

struct genome *crossover(struct genome *king, struct genome *queen)
{
	struct genome *prince;
	if ((prince = malloc(sizeof(struct genome))) == NULL)
	{
		return NULL;
	}

	prince->connection_genes = hashmap_init(sizeof(unsigned int), sizeof(struct connection_gene), &hashmap_hash_int);
	prince->node_genes = hashmap_init(sizeof(unsigned int), sizeof(struct node_gene), &hashmap_hash_int);

	for (
		struct hashmap_iterator *iter = hashmap_iterator(king->connection_genes);
		iter != NULL;
		iter = hashmap_iterator_next(king->connection_genes, iter)
	)
	{
		struct connection_gene *child_gene;
		if ((child_gene = malloc(sizeof(struct connection_gene))) == NULL)
		{
			return NULL;
		}

		struct connection_gene *parent_gene = iter->entry->value;
		int enabled = 1;

		struct connection_gene *tmp = hashmap_get(queen->connection_genes, parent_gene->id);

		if (tmp != NULL)
		{
			/* if either gene is disabled */
			if (!parent_gene->enabled || !tmp->enabled)
			{
				if ((double)rand() / (double)RAND_MAX < DISABLE_INHERITED_GENE_PROBABILITY)
				{
					enabled = 0;
				}
			}

			if ((double)rand() / (double)RAND_MAX < 0.5)
			{
				parent_gene = tmp;
			}
		}
		else
		{
			enabled = parent_gene->enabled;
		}

		child_gene->id = parent_gene->id;
		child_gene->in = parent_gene->in;
		child_gene->out = parent_gene->out;
		child_gene->weight = parent_gene->weight;
		child_gene->enabled = enabled;

		hashmap_put(prince->connection_genes, child_gene->id, child_gene);
		hashmap_put(prince->node_genes, child_gene->in->id, child_gene->in);
		hashmap_put(prince->node_genes, child_gene->out->id, child_gene->out);
	}

	return prince;
}
