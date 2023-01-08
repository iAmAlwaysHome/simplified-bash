 

#include "../../incs/mylibc.h"

char	*mystrdup(char *s)
{
	int		i;
	char	*newstr;

	i = 0;
	newstr = hmalloc((mystrlen(s) + 1) * sizeof(char));
	if (!newstr)
		return (NULL);
	while (s[i])
	{
		newstr[i] = s[i];
		++i;
	}
	newstr[i] = '\0';
	return (newstr);
}
