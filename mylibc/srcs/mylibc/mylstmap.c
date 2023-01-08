 

#include "../../incs/mylibc.h"

t_list	*mylstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*newnode;

	if (!lst || !f || !del)
		return (NULL);
	res = NULL;
	while (lst)
	{
		newnode = mylstnew(f(lst->content));
		if (!newnode)
		{
			mylstclear(&res, del);
			return (NULL);
		}
		mylstadd_back(&res, newnode);
		lst = lst->next;
	}
	return (res);
}
