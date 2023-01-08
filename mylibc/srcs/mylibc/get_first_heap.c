 //   By: Arthur Prahin 

#include "halloc.h"

t_heap	*get_first_heap(void)
{
	static t_heap	*start = NULL;

	if (start == NULL)
	{
		start = malloc(sizeof(t_heap));
		start->data = NULL;
		start->next = NULL;
	}
	return (start);
}
