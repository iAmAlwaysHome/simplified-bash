 

#include "../../incs/mylibc.h"

void	*mycalloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = hmalloc(nmemb * size);
	if (ptr == NULL)
		return (NULL);
	mybzero(ptr, nmemb * size);
	return (ptr);
}
