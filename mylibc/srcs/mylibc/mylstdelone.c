 

#include "../../incs/mylibc.h"

void	mylstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		hfree(lst);
		lst = NULL;
	}
}
