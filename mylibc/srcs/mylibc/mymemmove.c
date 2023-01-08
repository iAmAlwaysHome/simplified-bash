 

#include "../../incs/mylibc.h"

void	*mymemmove(void *dest, const void *src, size_t n)
{
	char		*dest_ptr;
	const char	*src_ptr;

	dest_ptr = (char *) dest;
	src_ptr = (const char *) src;
	if (dest > src)
	{
		while (n > 0)
		{
			n--;
			dest_ptr[n] = src_ptr[n];
		}
	}
	else
		mymemcpy(dest, src, n);
	return (dest);
}
