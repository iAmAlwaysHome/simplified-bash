 //   By: Arthur Prahin 

#include "halloc.h"

void	hobliterate(void)
{
	t_heap	*ptr;
	t_heap	*tmp;

	ptr = get_first_heap();
	if (!ptr)
		return ;
	while (ptr->next)
	{
		tmp = ptr->next;
		free(ptr);
		ptr = tmp;
	}
	free(ptr);
	ptr = NULL;
}
