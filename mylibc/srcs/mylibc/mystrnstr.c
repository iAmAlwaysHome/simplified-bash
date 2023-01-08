 

#include "../../incs/mylibc.h"

char	*mystrnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	i = 0;
	little_len = mystrlen(little);
	if (!little_len)
		return ((char *) big);
	while (len && big[i] && i + little_len <= len)
	{
		if (!mystrncmp(&big[i], little, little_len + 1))
			return ((char *) &big[i]);
		i++;
	}
	return (0);
}
