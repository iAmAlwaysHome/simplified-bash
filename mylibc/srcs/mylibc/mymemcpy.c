 

#include "../../incs/mylibc.h"

void	*mymemcpy(void *dest, const void *src, size_t n)
{
	char		*dest_str;
	const char	*src_str;
	size_t		i;

	if (!dest && !src)
		return (NULL);
	dest_str = (char *) dest;
	src_str = (const char *) src;
	i = 0;
	while (i < n)
	{
		dest_str[i] = src_str[i];
		i++;
	}
	return (dest);
}
