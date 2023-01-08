 

#include "../../incs/mylibc.h"

void	*mymemchr(const void *s, int c, size_t n)
{
	unsigned char	*buf;
	size_t			i;

	i = 0;
	buf = (unsigned char *) s;
	while (i < n)
	{
		if (*buf == (unsigned char)c)
			return (buf);
		buf++;
		i++;
	}
	return (0);
}
