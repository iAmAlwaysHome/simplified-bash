 //   By: Arthur Prahin 
#include "halloc.h"

void	*hmalloc(int size)
{
	t_heap			*new;
	t_heap			*ptr;

	new = malloc(sizeof(t_heap) + size);
	if (new == NULL)
		return (NULL);
	new->data = ptr_move(new, sizeof(t_heap));
	new->next = NULL;
	ptr = get_first_heap();
	if (ptr != NULL)
	{
		while (ptr->next != NULL)
			ptr = ptr->next;
		ptr->next = new;
	}
	return (new->data);
}

/*#include <string.h>
#include <stdio.h>
int	main(void)
{
	char	*mem1 = hmalloc(10);
	char	*mem2 = hcalloc(10, 1);

	strcpy(mem1, "LOL");
	strcpy(mem2, "CAT");
	printf("%s %s\n", mem1, mem2);
	printf("[%p %p]\n", get_first_heap(), get_first_heap()->next);
	return (0);
}*/