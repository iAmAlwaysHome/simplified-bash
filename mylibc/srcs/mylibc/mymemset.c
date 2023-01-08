 

#include "../../incs/mylibc.h"

void	*mymemset(void *s, int c, size_t n)
{
	unsigned char	*block;
	size_t			i;

	i = 0;
	block = (unsigned char *)s;
	while (i < n)
	{
		block[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
