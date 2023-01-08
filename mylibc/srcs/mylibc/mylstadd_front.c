 

#include "../../incs/mylibc.h"

void	mylstadd_front(t_list **lst, t_list *new)
{
	if (new)
	{
	new->next = *lst;
	*lst = new;
	}
}
