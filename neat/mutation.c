#include <hashmap.h>
#include <stdlib.h>

#include "neat/mutation.h"

#define MUTATION_WEIGHT_PROBABILITY 0.5

void mutate_weight(struct genome *genome)
{
	struct connection_gene *gene;
	for (struct hashmap_iterator *iter = hashmap_iterator(genome->connection_genes); iter != NULL; iter = hashmap_iterator_next(genome->connection_genes, iter))
	{
		if ((double)rand() / (double)RAND_MAX < MUTATION_WEIGHT_PROBABILITY)
		{
			gene = iter->entry->value;
			gene->weight = gene->weight * 
					((2.0 * ((double)rand() / (double)RAND_MAX)) - 1.0);
		}
	}	
}

void mutate_connection(struct genome *genome)
{
	struct connection_gene *connection;
	while (1)
	{
		unsigned int rand_id = rand() % innovation_number;
		connection = hashmap_get(genome->connection_genes, &rand_id);
		if (connection != NULL) {
			if (connection->enabled == 1)
			{
				struct node_gene *new;
				if ((new = malloc(sizeof(struct node_gene))) == NULL)
				{
					return;
				}

				new->id = innovation_number;
				innovation_number++;
				new->type = HIDDEN;

				struct connection_gene *first, *second;
				if ((first = malloc(sizeof(struct connection_gene))) == NULL)
				{
					return;
				}

				if ((second = malloc(sizeof(struct connection_gene))) == NULL)
				{
					return;
				}

				first->id = innovation_number;
				innovation_number++;

				second->id = innovation_number;
				innovation_number++;

				first->in = connection->in;
				first->out = new;
				
				second->in = new;
				second->out = connection->out;

				first->weight = 1;
				second->weight = connection->weight;

				first->enabled = 1;
				second->enabled = 1;
				connection->enabled = 0;

				hashmap_put(genome->connection_genes, &first->id, first);
				hashmap_put(genome->connection_genes, &second->id, second);
				hashmap_put(genome->node_genes, &new->id, new);
				return;
			}
		}
	}
}

struct list
{
	struct node *head;
	struct node *tail;
	unsigned int size;
};

struct node
{
	int data;
	struct node *next;
};

void mutate_node(struct genome *genome)
{
	struct node_gene *from, *to;
	while (1)
	{
		unsigned int rand_from = rand() % innovation_number;
		unsigned int rand_to = rand() % innovation_number;
		from = (struct node_gene *)hashmap_get(genome->node_genes, &rand_from);
		to = (struct node_gene *)hashmap_get(genome->node_genes, &rand_to);

		if (from->id == to->id)
		{
			continue;
		}

		if (from->type == OUTPUT)
		{
			continue;
		}

		if (to->type == INPUT)
		{
			continue;
		}

		/* check if connection already exist */
		int exist = 0;

		for (
			struct hashmap_iterator *iter = hashmap_iterator(genome->connection_genes);
			iter != NULL;
			iter = hashmap_iterator_next(genome->connection_genes, iter)
		)
		{
			struct connection_gene *curr = iter->entry->value;
			if (curr->in->id == from->id && curr->out->id == to->id)
			{
				exist = 1;
				break;
			}

			/* also check if there exist a backwards connection */
			if (curr->in->id == to->id && curr->out->id == from->id)
			{
				exist = 1;
				break;
			}
		}

		if (exist)
		{
			continue;
		}

		/* check that this connection */
		/* won't create circular dependency */
		struct list *list;
		if ((list = malloc(sizeof(struct list))) == NULL)
		{
			return;
		}

		struct node *node;
		if ((node = malloc(sizeof(struct node))) == NULL)
		{
			return;
		}
		
		node->data = to->id;
		node->next = NULL;

		list->head = node;
		list->tail = node;
		list->size = 1;

		int dependency = 0;

		while (list->size != 0)
		{
			for (
				struct hashmap_iterator *iter = hashmap_iterator(genome->connection_genes);
				iter != NULL;
				iter = hashmap_iterator_next(genome->connection_genes, iter)
			)
			{
				struct connection_gene *curr = iter->entry->value;
				if (curr->in->id == list->head->data)
				{
					struct node *n;
					if ((n = malloc(sizeof(struct node))) == NULL)
					{
						return;
					}

					n->data = curr->out->id;
					n->next = NULL;
					list->tail->next = n;
					list->tail = n;

					if (n->data == from->id)
					{
						dependency = 1;
						break;
					}

					struct node *tmp = list->head;
					list->head = list->head->next;
					free(tmp);
				}
			}

			if (dependency)
			{
				break;
			}
		}

		/* free list */
		struct node *tmp;
		struct node *n = list->head;
		while (node != NULL)
		{
			tmp = node;
			node = node->next;
			free(tmp);
		}
		free(list);

		if (dependency)
		{
			continue;
		}

		/* add the new connection */
		struct connection_gene *new;
		if ((new = malloc(sizeof(struct connection_gene))) == NULL)
		{
			return;
		}

		new->id = innovation_number;
		innovation_number++;

		new->in = from;
		new->out = to;
		new->weight = ((2.0 * ((double)rand() / (double)RAND_MAX)) - 1.0);
		new->enabled = 1;

		hashmap_put(genome->connection_genes, &new->id, new);
		return;
	}
}
