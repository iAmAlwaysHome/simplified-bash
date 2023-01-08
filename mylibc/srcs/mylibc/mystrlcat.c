 
#include "../../incs/mylibc.h"

size_t	mystrlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	src_len = mystrlen(src);
	if (!dst && !size)
		return (src_len);
	dst_len = mystrlen(dst);
	i = 0;
	if (size > dst_len)
	{
		while (src[i] && dst_len + i < size - 1)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
		return (src_len + dst_len);
	}
	else
		return (src_len + size);
}
