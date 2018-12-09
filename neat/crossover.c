#include <hashmap.h>

#define DISABLE_INHERITED_GENE_PROBABILITY 0.75

struct genome *crossover(struct genome *king, struct genome *queen)
{
	struct genome *prince;
	if ((prince = malloc(sizeof(struct genome))) == NULL)
	{
		return NULL;
	}

	prince->connection_genes = hashmap_init();
	prince->node_genes = hashmap_init();

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

		child_gene->id = iter->entry->id;

		struct connection_gene *gene = hashmap_get(queen->connections_genes, iter->entry->id);
		if (gene != NULL)
		{
			if ((double)rand() / (double)RAND_MAX < 0.5)
			{
				child_gene->in = iter->entry->in;
				child_gene->out = iter->entry->out;
				child_gene->weight = iter->entry->weight;
				child_gene->enabled = iter->entry->enabled;
			}
			else
			{
				child_gene->in = gene->in;
				child_gene->out = gene->out;
				child_gene->weight = gene->weight;
				child_gene->enabled = gene->enabled;
			}

			/* if either gene is disabled */
			if (!iter->entry->enabled || !gene->enabled)
			{
				if ((double)rand() / (double)RAND_MAX < DISABLE_INHERITED_GENE_PROBABILITY)
				{
					child_gene->enabled = 0;
				}
			}
		}
		else
		{
			child_gene->in = iter->entry->in;
			child_gene->out = iter->entry->out;
			child_gene->weight = iter->entry->weight;
			child_gene->enabled = iter->entry->enabled;
		}

			hashmap_put(prince->connection_genes, child_gene->id, child_gene);
			hashmap_put(prince->node_genes, child_gene->in->id, child_gene->in);
			hashmap_put(prince->node_genes, child->gene->out->id, child_gene->out);
	}

	return prince;
}
