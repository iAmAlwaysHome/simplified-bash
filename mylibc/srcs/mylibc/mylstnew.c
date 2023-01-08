 

#include "../../incs/mylibc.h"

t_list	*mylstnew(void *content)
{
	t_list	*node;

	node = hmalloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}
