 

#include "../../incs/mylibc.h"

t_list	*mylstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
