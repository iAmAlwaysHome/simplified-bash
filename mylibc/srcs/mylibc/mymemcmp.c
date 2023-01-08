 

#include "../../incs/mylibc.h"

int	mymemcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*buf1;
	unsigned char	*buf2;
	size_t			i;

	i = 0;
	buf1 = (unsigned char *) s1;
	buf2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	while (i < n - 1 && buf1[i] == buf2[i])
		i++;
	return (buf1[i] - buf2[i]);
}
