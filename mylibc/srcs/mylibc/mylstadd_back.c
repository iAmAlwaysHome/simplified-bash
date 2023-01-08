 

#include "../../incs/mylibc.h"

void	mylstadd_back(t_list **lst, t_list *new)
{
	if (lst == NULL)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
		mylstlast(*lst)->next = new;
}
